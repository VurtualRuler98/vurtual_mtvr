_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
 if (local _veh) then {[_veh, """", [], true] call bis_fnc_initVehicle;};
if (_veh getVariable ["mtvr_init",false]) exitWith {false};
_veh setVariable ["mtvr_init",true];
_veh addAction ["Lights: Blackout",{_veh = (_this select 0);_veh animateSource ["blackout_hide",0]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'blackout_hide')==1"];
_veh addAction ["Lights: Stoplight",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",0];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'brakelight_normal_hide')==1"];
_veh addAction ["Lights: None",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && ((_target animationSourcePhase 'brakelight_normal_hide')==0 || (_target animationSourcePhase 'blackout_hide')==0)"];


_veh addAction ["Load vehicle",{
	(_this select 0) setVehicleCargo (vehicle (_this select 1));
},[],1.5,false,true,"","!boxloader_maxload_enabled && (_this != vehicle _this) && (_this == driver vehicle _this) && (_target canVehicleCargo vehicle _this) select 0 && ((vehicle _this distance _target)<15) && ([(_target modeltoworld (_target selectionPosition 'VTV_exit_1')),(getDir _target+180),30,position vehicle _this] call bis_fnc_inAngleSector)"];

//HAZMAT part
_veh addAction ["Cycle HAZMAT Sign",{
	[(_this select 0)] call vurtual_mtvr_fnc_hazmat_cycle;
},[_hazmat_signs],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && (_target animationSourcePhase 'sign_hide')==0",15,false,"sign_action"];

_veh addAction ["Toggle HAZMAT Sign",{
	(_this select 0) animateSource ["sign_hide",(abs (((_this select 0) animationSourcePhase "sign_hide")-1))];
},[_x select 1],1.5,false,true,"","(alive _target) && (vehicle _this == _this)",5,false,"cover_action"];


if (_veh isKindOf "vurtual_MTVRBase_Passenger") then {[_veh] call vurtual_mtvr_fnc_passenger;};

if (isClass(configFile >> "CfgPatches" >> "Boxloader")) then {
	[_veh,"VTV_exit_1"] call boxloader_fnc_driveon;
	if (_veh isKindOf "vurtual_mtvr_lhs16_boxloader") then {
		[_veh] call boxloader_fnc_init_pls;
	};
};

if (isServer) then {
	[_veh] spawn {
		_veh = (_this select 0);
		while {alive (_veh)} do {
			sleep 0.1;
			if (isNull attachedTo _veh && ((AGLToASL (_veh modelToWorld (_veh selectionPosition "fording_depth"))) select 2 < 0)) then {
				_veh setHitPointDamage ["hitEngine",(_veh getHitPointDamage "hitEngine")+0.0025];
			};
			if (isNull attachedTo _veh && ((AGLToASL (_veh modelToWorld (_veh selectionPosition "fording_kill"))) select 2 < 0)) then {
				_veh setHitPointDamage ["hitEngine",1];
			};
			if ((isLightOn _veh) && ((_veh animationSourcePhase 'blackout_hide')==0 || (_veh animationSourcePhase 'brakelight_normal_hide')==1)) then {
				_veh animateSource ["brakelight_normal_hide",0];
				_veh animateSource ["blackout_hide",1];
			};
			if !((isVehicleCargo _veh) isEqualTo (_veh getVariable ["cargoParent",objNull])) then { //Parent transport has changed.
					if (isNull isVehicleCargo _veh) then { //If we're not being transported...
						_veh animateSource ["cab_transported",0]; //Unfold ourselves.
					} else { //otherwise we're being transported, check if we fit unfolded.
						_parent = (isVehicleCargo _veh);
						if (({(_parent) isKindOf _x} count ["sab_C130_J_Base","CUP_C130J_Base"])>0) then { //Some have extra big cargo areas.
							_veh animateSource ["cab_transported",1,true]; //Fold anyway, it's authentic.
						} else { //otherwise check manually
							_memPoints =  getArray (configFile >> "CfgVehicles" >> (typeOf (isVehicleCargo _veh)) >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions"); //Get the cargo bay size of our transport.
							
							//Get the memory point locations of the cargo bay.
							_memBase = (isVehicleCargo _veh) selectionPosition [(_memPoints select 0),"Memory"]; 
							_memCorner = (isVehicleCargo _veh) selectionPosition [(_memPoints select 1),"Memory"]; 
							_height = abs (_memCorner select 2)-(_memBase select 2); //Get the height difference.
							if (_height < 3.6) then { //If it's shorter than our unpacked height. (to the exhaust)
								_veh animateSource ["cab_transported",1,true]; //Fold cab instantly.
							} else { //We fit unfolded!
								_veh animateSource ["cab_transported",0]; //Unfold cab.
							};
						};
					};
				_veh setVariable["cargoParent",(isVehicleCargo _veh)]; //Update our parent.
			};
		};
	};
};


true
