_par = params [["_veh",objNull,[objNull]],["_sign",-1,[-1]]];
if ((isNull _veh) || !(_veh isKindOf "vurtual_MTVRBase")) exitWith {false};
_signtex = [
	"vurtual_mtvr\Data\hazmat\flammable_ca.paa", //0
	"vurtual_mtvr\Data\hazmat\explosive_ca.paa", //1
	"vurtual_mtvr\Data\hazmat\chemical_ca.paa", //2
	"vurtual_mtvr\Data\hazmat\biohazard_ca.paa", //3
	"vurtual_mtvr\Data\hazmat\radioactive_ca.paa" //4
];

if (_sign>=(count _signtex) || _sign<0 || _sign!=(floor _sign)) then {
	_sign = (_veh getVariable ["hazmat_sign",0])+1;
	if (_sign == count _signtex) then {
		_sign = 0;
	};
};
_veh setObjectTexture[3,_signtex select (_sign)];
_veh setVariable ["hazmat_sign",_sign,true];
true
