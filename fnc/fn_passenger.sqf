_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase") || !(alive _veh)) exitWith {false};
_veh addAction ["MTVR Passenger mode",{[(_this select 0),false,false] call vurtual_mtvr_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && (count getVehicleCargo _target)==0 && (vehicleCargoEnabled _target)",15,false,"sides"];
_veh addAction ["MTVR Cargo mode",{[(_this select 0),true,false] call vurtual_mtvr_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(vehicleCargoEnabled _target)",15,false,"sides"];
_veh addAction ["Install cargo cover",{(_this select 0) animateSource ["cargo_cover_hide",0];},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(isEngineOn _target) && (_target animationSourcePhase 'cargo_cover_hide')==1",5,false,"cover_action"];
_veh addAction ["Store cargo cover",{(_this select 0) animateSource ["cargo_cover_hide",1];},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(isEngineOn _target) && (_target animationSourcePhase 'cargo_cover_hide')==0",5,false,"cover_action"];

{ _veh addAction [_x select 0,{(_this select 0) animateSource [(_this select 3 select 0),(abs (((_this select 0) animationSourcePhase (_this select 3 select 0))-1))];},[_x select 1],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && (_target animationSourcePhase 'cargo_cover_hide')==1 && (_target animationSourcePhase 'bedseat_fold')==1",5,false,_x select 2]; } forEach [
["Raise/Lower front left bed side","bedside_left1_fold","bedside_left1"],
["Raise/Lower rear left bed side","bedside_left2_fold","bedside_left2"],
["Raise/Lower front right bed side","bedside_right1_fold","bedside_right1"],
["Raise/Lower rear right bed side","bedside_right2_fold","bedside_right2"]
];
_veh addAction ["Raise/Lower tailgate",{(_this select 0) animateSource ["tailgate_fold",(abs (((_this select 0) animationSourcePhase "tailgate_fold")-1))];},[_x select 1],1.5,false,true,"","(alive _target) && (vehicle _this == _this)",5,false,"sides"];
