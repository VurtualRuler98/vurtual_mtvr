_par = params [["_veh",objNull,[objNull]],["_cargo",false,[false]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};

_bedseats = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVPassengers");
_bedgunners = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVGunners");

if (!_cargo && (count getVehicleCargo (_this select 0)>0)) exitWith {hint "Cargo bed must be empty.";false};
if (_cargo && ({(alive (_x select 0)) && ((_x select 2) in _bedseats+_bedgunners)} count fullCrew [(_this select 0), "",true])>0) exitWith {hint "Cargo bed must be empty.";false};
(_this select 0) enableVehicleCargo _cargo;
{(_this select 0) lockCargo [_x,!_cargo];} forEach _bedseats+_bedgunners;
(_this select 0) animateSource ["bedseat_fold",parseNumber _cargo];
true
