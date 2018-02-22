_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
if (_veh getVariable ["mtvr_init_bed_done",false]) exitWith {false};
_veh setVariable ["mtvr_init_bed_done",true];
_bedseats = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVPassengers");
_bedgunners = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVGunners");
//_veh enableVehicleCargo ((_veh animationSourcePhase "bedseat_fold")==1);
_veh addAction ["MTVR Passenger mode",{
	if (count getVehicleCargo (_this select 0)>0) exitWith {hint "Cargo bed must be empty."};
	(_this select 0) enableVehicleCargo false;
	{(_this select 0) lockCargo [_x,false];} forEach (_this select 3 select 0)+(_this select 3 select 1);
	(_this select 0) animateSource ["bedseat_fold",0];
},[_bedseats,_bedgunners],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && (count getVehicleCargo _target)==0 && (vehicleCargoEnabled _target)",15,false,"sides"];
_veh addAction ["MTVR Cargo mode",{
	if (({(alive (_x select 0)) && ((_x select 2) in (_this select 3 select 0))} count fullCrew [(_this select 0), 'cargo',true])>0) exitWith {hint "Cargo bed must be empty."};
	if (({(alive (_x select 0)) && ((_x select 2) in (_this select 3 select 1))} count fullCrew [(_this select 0), 'turret',true])>0) exitWith {hint "Cargo bed must be empty."};
	(_this select 0) enableVehicleCargo true;
	{(_this select 0) lockCargo [_x,true];} forEach (_this select 3 select 0)+(_this select 3 select 1);
	(_this select 0) animateSource ["bedseat_fold",1];
},[_bedseats,_bedgunners],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(vehicleCargoEnabled _target)",15,false,"sides"];
_veh addAction ["Install cargo cover",{(_this select 0) animateSource ["cargo_cover_hide",0];},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(isEngineOn _target) && (_target animationSourcePhase 'cargo_cover_hide')==1",5,false,"cover_action"];
_veh addAction ["Store cargo cover",{(_this select 0) animateSource ["cargo_cover_hide",1];},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(isEngineOn _target) && (_target animationSourcePhase 'cargo_cover_hide')==0",5,false,"cover_action"];
[_veh] call vurtual_mtvr_fnc_blackout;
//[_veh, vehicleCargoEnabled _veh] call vurtual_mtvr_fnc_checkbed;
//if ((_veh animationSourcePhase "bedseat_fold")<1) then {_veh setVehicleCargo objNull};
true
