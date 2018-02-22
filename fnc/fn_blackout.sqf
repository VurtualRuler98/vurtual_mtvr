_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
if (_veh getVariable ["mtvr_init_blackout_done",false]) exitWith {false};
_veh setVariable ["mtvr_init_blackout_done",true];
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