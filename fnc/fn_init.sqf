_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
 if (local _veh) then {[_veh, """", [], true] call bis_fnc_initVehicle;};
if (_veh getVariable ["mtvr_init",false]) exitWith {false};
_veh setVariable ["mtvr_init",true];
_veh addAction ["Lights: Blackout",{_veh = (_this select 0);_veh animateSource ["blackout_hide",0]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'blackout_hide')==1"];
_veh addAction ["Lights: Stoplight",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",0];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'brakelight_normal_hide')==1"];
_veh addAction ["Lights: None",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && ((_target animationSourcePhase 'brakelight_normal_hide')==0 || (_target animationSourcePhase 'blackout_hide')==0)"];
if (_veh isKindOf "vurtual_MTVRBase_Passenger") then {[_veh] call vurtual_mtvr_fnc_passenger;};
if (isServer) then {
	[_veh] spawn {
		_veh = (_this select 0);
		while {alive (_veh)} do {
			sleep 0.1;
			if ((isLightOn _veh) && ((_veh animationSourcePhase 'blackout_hide')==0 || (_veh animationSourcePhase 'brakelight_normal_hide')==1)) then {
				_veh animateSource ["brakelight_normal_hide",0];
				_veh animateSource ["blackout_hide",1];
			};
			if !((isVehicleCargo _veh) isEqualTo (_veh getVariable ["cargoParent",objNull])) then { //Parent transport has changed.
					if (isNull isVehicleCargo _veh) then { //If we're not being transported...
						_veh animateSource ["cab_transported",0]; //Unfold ourselves.
					} else { //otherwise we're being transported, check if we fit unfolded.
						if ((isVehicleCargo _veh) isKindOf "CUP_C130J_Base") then { //CUP C-130's volume is too high.
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
