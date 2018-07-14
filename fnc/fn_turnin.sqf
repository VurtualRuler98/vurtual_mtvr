_par = params [["_veh",objNull,[objNull]],["_unit",objNull,[objNull]],["_turret",[],[[]]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
if ((_turret select 0)==0) then {
	_veh animateSource ["gunnerTurn",0,true];
};
true
