_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
 if (local _veh) then {[_veh, """", [], true] call bis_fnc_initVehicle;};
if (_veh getVariable ["mtvr_init",false]) exitWith {false};
_veh setVariable ["mtvr_init",true];
_veh addAction ["Lights: Blackout",{_veh = (_this select 0);_veh animateSource ["blackout_hide",0]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'blackout_hide')==1"];
_veh addAction ["Lights: Stoplight",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",0];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'brakelight_normal_hide')==1"];
_veh addAction ["Lights: None",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && ((_target animationSourcePhase 'brakelight_normal_hide')==0 || (_target animationSourcePhase 'blackout_hide')==0)"];
if (_veh isKindOf "vurtual_MTVRBase_Passenger") then {[_veh] call vurtual_mtvr_fnc_passenger;};
[_veh] spawn {
	_veh = (_this select 0);
	while {alive (_veh)} do {
		sleep 1;
		if ((isLightOn _veh) && ((_veh animationSourcePhase 'blackout_hide')==0 || (_veh animationSourcePhase 'brakelight_normal_hide')==1)) then {
			_veh animateSource ["brakelight_normal_hide",0];
			_veh animateSource ["blackout_hide",1];
		};
	};
};
true
