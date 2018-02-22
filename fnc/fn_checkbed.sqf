_par = params [["_veh",objNull,[objNull]],["_cargomode",false,[false]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
_bedseats = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVPassengers");
_bedgunners = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVGunners");
_troopmode = false;
if (({(alive (_x select 0)) && ((_x select 2) in _bedseats)} count fullCrew [(_this select 0), 'cargo',true])>0) then {_cargomode = false;};
if (({(alive (_x select 0)) && ((_x select 2) in _bedseats)} count fullCrew [(_this select 0), 'turret',true])>0) then {_cargomode = false;};
if (!_cargomode && (count getVehicleCargo _veh)>0) then { //There are passengers in the cargo bed! We can't kick them out, so dump the cargo and fold down the seats.
	_veh setVehicleCargo objNull;
	_veh animateSource["bedseat_fold",0]; //This will call this again probably but oh well.
	{(_this select 0) lockCargo [_x,false];} forEach _bedseats+_bedgunners;
	_veh enableVehicleCargo false;
};
if (_cargomode) then {
	_veh animateSource["bedseat_fold",1];
	_veh enableVehicleCargo true;
	{(_this select 0) lockCargo [_x,true];} forEach _bedseats+_bedgunners;
};
true
