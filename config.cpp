enum {
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXESXYZ = 4,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

#include "basicdefines_A3.hpp"
//default strength=5 default damper=0.8
#define WHEEL_STRENGTH 10
#define WHEEL_DAMPER 3
#define WHEEL_SPRINGS(MASS,WHEELS,STRENGTH,DAMPER) sprungMass = MASS/WHEELS; \
springStrength = (MASS/WHEELS)*STRENGTH^2; \
springDamperRate = DAMPER*2*((MASS/WHEELS)*STRENGTH^2*(MASS/WHEELS))^0.5;

class DefaultEventhandlers;	// External class reference

class CfgPatches {
	class vurtual_mtvr {
		units[] = {
			"vurtual_mtvr_mk23",
			"vurtual_mtvr_lhs16",
			"vurtual_mtvr_4x4"
			};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Soft_F"};
	};
};

class CfgFunctions {
	
	class vurtual_mtvr {
		tag = "vurtual_mtvr";
		class vurtual_mtvrFunctions {
			file = "\vurtual_mtvr\fnc";
			class init {};
			class blackout {};
		};
	};
};

class CfgVehicleClasses {
	class DARMil_Vehicles_vurtual {
		displayName = "DAR MTVR";
	};
};

class WeaponFireGun;	
class WeaponCloudsGun;	
class WeaponFireMGun;	
class WeaponCloudsMGun;	
class RCWSOptics;	
class CBA_Extended_EventHandlers_base;
class CfgMovesBasic {
	class DefaultDie;
	
	class ManActions {};
};

class CfgMovesMaleSdr : CfgMovesBasic {
	
	class States {
	
		class Crew;
		class AmovPercMstpSnonWnonDnon;
		
		class HMMWV_KIA_Cargo01_EP1 : DefaultDie {
			actions = "DeadActions";
			file = "\vurtual_mtvr\Anim\HMWVW_KIA_Cargo01";
			speed = 1e+010;
			terminal = true;
			soundEnabled = false;
			looped = false;
			connectTo[] = {"Unconscious", 0.1};
		};
	};
};


class CfgVehicles {
	class LandVehicle;
	
	class Car : LandVehicle {
		class NewTurret;	
	};
	
	class Car_F : Car {
		class AnimationSources;	
		
		class Turrets {
			class MainTurret : NewTurret {};
			class ViewOptics;
		};
		
		class HitPoints {
			class HitLFWheel;	
			class HitLF2Wheel;	
			class HitRFWheel;	
			class HitRF2Wheel;	
			class HitGlass1;	
			class HitGlass2;	
			class HitGlass3;	
			class HitGlass4;	
			class HitGlass5;	
			class HitGlass6;	
		};
	};
	
	class vurtual_MTVRBase : Car_F {
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		class SpeechVariants {
			class Default {
				speechSingular[] = {"veh_vehicle_armedcar_s"};
				speechPlural[] = {"veh_vehicle_armedcar_p"};
			};
		};
		maxSpeed = 105;
		textSingular = "$STR_A3_nameSound_veh_vehicle_armedcar_s";
		textPlural = "$STR_A3_nameSound_veh_vehicle_armedcar_p";
		nameSound = "veh_vehicle_armedcar_s";
		author = "vurtual, Richards.D, Bohemia Interactive";
		_generalMacro = "";
		scope = 0; 
		Model = "\vurtual_mtvr\mtvr_mk23.p3d";
		picture = "\vurtual_mtvr\Data\UI\picture_mtvr_ca.paa";
		Icon = "\vurtual_mtvr\Data\UI\icon_mtvr_ca.paa";
		mapSize = 6;
		displayName = "MTVR Base";
		vehicleClass = "DARMil_Vehicles";
		crew = "B_Soldier_F";
		typicalCargo[] = {};
		side = TWest;
		faction = BLU_F;
		wheelCircumference = 4.08407044; 	
		antiRollbarForceCoef = 2;
		antiRollbarForceLimit = 2;
		antiRollbarSpeedMin = 0;
		antiRollbarSpeedMax = 20;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1","Compartment1", "Compartment2"};
		cargoIsCoDriver[] = {1,1,0};
		cargoProxyIndexes[] = {1,2,3,4,5,6,7,8,9,10,11,12};
		soundAttenuationCargo[] = {1,1,0};
		crewVulnerable = true;
		ejectDeadCargo = false;
		ejectDeadDriver = false;
		crewCrashProtection = 0.8;
		weapons[] = {"TruckHorn2"};
		magazines[] = {};
		damperSize = 0.1;	// max. damper amplitude
		damperForce = 5;	// larger number more stiffness dampers
		damperDamping = 1;	// larger number less movement in dampers
		armor = 80;
		damageResistance = 0.05;
		turnCoef = 3;
		steerAheadPlan = 0.2;
		steerAheadSimul = 0.4;
		predictTurnPlan = 0.9;
		predictTurnSimul = 0.5;
		brakeDistance = 1.0;	// vehicle movement precision
		terrainCoef = 2.5;
		wheelDamageThreshold = 0.9;
		wheelDestroyThreshold = 0.99;
		wheelDamageRadiusCoef = 0.95;
		wheelDestroyRadiusCoef = 0.45;
		cost = 200000;
		precision = 15;
		armorGlass = 0.9;
		armorWheels = 0.8;
		soundServo[] = {"A3\sounds_f\dummysound", db-40, 1.0, 10};
		soundEnviron[] = {"", 0.562341, 1};
		transportMaxBackpacks = 50;
		transportSoldier = 12;
		hiddenSelections[] = {"camo1","camo2","cargo_tarp"};
		hiddenSelectionsTextures[] = {"vurtual_mtvr\data\mtvr_body_co.paa","vurtual_mtvr\data\mtvr_body2_co.paa","vurtual_mtvr\data\mtvr_tarp_co.paa"};
		animationList[] = {"brakelight_normal_hide",0,"blackout_hide",1};
		class AnimationSources: AnimationSources {
			class brakelight_normal_hide {
				displayName = "Turn normal brake lights off";
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
				forceAnimatePhase = 0;
				forceAnimate[] = {"blackout_hide",1};
			};
			class blackout_hide {
				displayName = "Turn blackout lights off"
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				forceAnimatePhase = 0;
				forceAnimate[] = {"brakelight_normal_hide",1};
			};
		};
		class VehicleTransport {
			class Cargo {
				parachuteClass				= "B_Parachute_02_F";
				canBeTransported            = 1;
				parachuteHeightLimit		= 10;
			};
			class Carrier {
				cargoBayDimensions[]        = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				cargoAlignment[]            = {"front","left"};
				maxLoadMass                 = 15558;
				disableHeightLimit			= 1;
				exits[]						= {"VTV_exit_1"};
				unloadingInterval			= 2;
				loadingDistance				= 10;
				loadingAngle				= 60;
				parachuteClassDefault       = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10000;
			};
		};
		class textureSources {
			class woodland {
				displayname = "Woodland";
				author = "vurtual";
				textures[] = {"vurtual_mtvr\data\mtvr_body_co.paa","vurtual_mtvr\data\mtvr_body2_co.paa","vurtual_mtvr\data\mtvr_tarp_co.paa"};
				factions[] = {};
			};
			class green {
				displayname = "Green";
				author = "vurtual";
				textures[] = {"vurtual_mtvr\data\mtvr_body_green_co.paa","vurtual_mtvr\data\mtvr_body2_green_co.paa","vurtual_mtvr\data\mtvr_tarp_green_co.paa"};
				factions[] = {};
			};
			class desert {
				displayname = "desert";
				author = "vurtual";
				textures[] = {"vurtual_mtvr\data\mtvr_body_desert_co.paa","vurtual_mtvr\data\mtvr_body2_desert_co.paa","vurtual_mtvr\data\mtvr_tarp_desert_co.paa"};
				factions[] = {};
			};
		};
		class Library {
			libTextDesc = "DAR MTVRs";
		};
		castDriverShadow = "false";
		driverAction = "driver_offroad01";
		cargoAction[] = {"passenger_low01", "passenger_generic01_leanright", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands"};
		
		// threat (VSoft, VArmor, VAir), how threatening vehicle is to unit types
		threat[] = {0.8, 0.6, 0.3};

		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";
		
		class TransportMagazines {};
		
		class TransportItems {};
		
		class TransportWeapons {};
		
		idleRpm = 800;
		redRpm = 2100;
		brakeIdleSpeed = 1.78;
		fuelCapacity = 295;
		
		class complexGearbox {
			GearboxRatios[] = {"R1", -4.8, "N", 0, "D1", 7.63, "D2", 3.51, "D3", 1.91, "D4", 1.43, "D5", 1, "D6", 0.74, "D7", 0.64};
			TransmissionRatios[] = {"High", 1.271*6};
			gearBoxMode = "auto";
			moveOffGear = 2;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		simulation = "carx";
		dampersBumpCoef = 6.0;
		differentialType = "all_limited";
		frontRearSplit = 0.32;
		frontBias = 1.3;
		rearBias = 1.3;
		centreBias = 1.3;
		clutchStrength = 55.0;
		enginePower = 317;
		maxOmega = 220;
		peakTorque = 2101;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 2.0;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		torqueCurve[] = {{0, "125/165"},{"12/21","165/165"},{"14/21","150/165"},{"16/21","130/165"},{"18/21","125/165"},{"20/21","105/165"},{"21/21","100/165"}};
		changeGearMinEffectivity[] = {0.95, 0.15, 0.85, 0.85, 0.85, 0.85, 0.85,0.85,0.85};
		switchTime = 0.1;
		latency = 1;
		maxFordingDepth=1.54;
		numberPhysicalWheels=6;
		class MTVRBaseWheel {
			//boneName = "wheel_1_1_damper";
			//steering = 1;
			//side = "left";
			//center   = "wheel_1_1_axis";
			//boundary = "wheel_1_1_bound";
			//suspForceAppPointOffset = "wheel_1_1_axis";
			//tireForceAppPointOffset = "wheel_1_1_axis";
			mass = 150;
			MOI = 40;
			dampingRate = 0.1;
			dampingRateDamaged = 1;
			dampingRateDestroyed = 1000;
			maxBrakeTorque = 14000;
			maxHandBrakeTorque = 0;
			suspTravelDirection[] = {0, -1, 0};
			maxCompression = 0.15;
			maxDroop = 0.15;
			//sprungMass = 12610.0/6;
			//sprungMass = 3152.5;
			//springStrength = 78812.5;
			//springDamperRate = 12610;
			//WHEEL_SPRINGS(12610,6,5,0.8)
			longitudinalStiffnessPerUnitGravity = 15000;
			latStiffX = 35;
			latStiffY = 180;
			frictionVsSlipGraph[] = {{0, 0.8}, {0.5, 0.9}, {1, 1}};
			width = 0.45;
		};
		class Wheels {
			class LF: MTVRBaseWheel {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center   = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				WHEEL_SPRINGS(12610*2,6,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR : LF
			{
				boneName = "wheel_1_2_damper";
				steering = 0;
				center   = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;
				WHEEL_SPRINGS(12610,6,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			
			class LR1 : LR
			{
				boneName = "wheel_1_3_damper";
				center   = "wheel_1_3_axis";
				boundary = "wheel_1_3_bound";
				suspForceAppPointOffset = "wheel_1_3_axis";
				tireForceAppPointOffset = "wheel_1_3_axis";
			};
			
			class RF : LF
			{
				boneName = "wheel_2_1_damper";
				center   = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				side = "right";
			};
			class RR : RF
			{
				boneName = "wheel_2_2_damper";
				steering = 0;
				center   = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3000;
				WHEEL_SPRINGS(12610,6,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			
			class RR1 : RR
			{
				boneName = "wheel_2_3_damper";
				center   = "wheel_2_3_axis";
				boundary = "wheel_2_3_bound";
				suspForceAppPointOffset = "wheel_2_3_axis";
				tireForceAppPointOffset = "wheel_2_3_axis";	
			};

		};
		
		#include "sounds.hpp"

		class Exhausts {
			class Exhaust1 {
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustEffectOffroad";
			};
		};
		
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				body = "mainTurret";
				gun = "mainGun";
				hasGunner = true;
				weapons[] = {HMG_M2};
				magazines[] = {"100Rnd_127x99_mag_Tracer_Yellow", "100Rnd_127x99_mag_Tracer_Yellow", "100Rnd_127x99_mag_Tracer_Yellow", "100Rnd_127x99_mag_Tracer_Yellow", "100Rnd_127x99_mag_Tracer_Yellow", "100Rnd_127x99_mag_Tracer_Yellow"};
				soundServo[] = {"A3\sounds_f\dummysound", db-40, 1.0, 10};
				minElev = -25;
				maxElev = 60;
				gunnerAction = "gunner_standup01";
				viewGunnerInExternal = "true";
				castGunnerShadow = true;
				stabilizedInAxes = "StabilizedInAxesBoth";
				gunnerRightHandAnimName = "OtocHlaven_shake";
				gunnerLeftHandAnimName = "OtocHlaven_shake";
			
				class ViewOptics : ViewOptics {
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				
				class ViewGunner : ViewOptics {};
			};
		};
		
		class HitPoints : HitPoints {
			class HitGlass1 : HitGlass1 {
				armor = 0.1;
			};
			
			class HitGlass2 : HitGlass2 {
				armor = 0.1;
			};
			
			class HitGlass3 : HitGlass3 {
				armor = 0.1;
			};
			
			class HitGlass4 : HitGlass4 {
				armor = 0.1;
			};
			
			class HitLFWheel : HitLFWheel {
				armor = 0.38;
			};
			
			class HitLBWheel : HitLF2Wheel {
				armor = 0.38;
			};
			
			class HitRFWheel : HitRFWheel {
				armor = 0.38;
			};
			
			class HitRBWheel : HitRF2Wheel {
				armor = 0.38;
			};
			
			class HitFuel {
				armor = 1.4;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = true;
			};
		};
		class UserActions {
			class lights_blackout {
				displayName = "Lights: Blackout";
				priority=1;
				radius=5;
				showWindow=0;
				hideOnUse=1;
				onlyForPlayer=false;
				condition = "(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'blackout_hide')==1";
				statement = "_veh = (_this select 0);_veh animateSource ['blackout_hide',0]; _veh animateSource ['brakelight_normal_hide',1];";
			};
			class lights_stoplight: lights_blackout {
				displayName = "Lights: Stoplight";
				condition = "(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'brakelight_normal_hide')==1";
				statement = "_veh = (_this select 0);_veh animateSource ['blackout_hide',1]; _veh animateSource ['brakelight_normal_hide',0];";
			};
			class lights_none: lights_blackout {
				displayName = "Lights: None";
				condition = "(alive _target) && !(isLightOn _target) && (driver _target == _this) && ((_target animationSourcePhase 'brakelight_normal_hide')==0 || (_target animationSourcePhase 'blackout_hide')==0)";
				statement =  statement = "_veh = (_this select 0);_veh animateSource ['blackout_hide',1]; _veh animateSource ['brakelight_normal_hide',1];";
			};
		class Reflectors {
			class LightCarHeadL01 {
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				position = "LightCarHeadL01";
				direction = "LightCarHeadL01_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 1;
				dayLight = 0;
				flareSize = 1;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			
			class LightCarHeadL02 : LightCarHeadL01 {
				position = "LightCarHeadL02";
				direction = "LightCarHeadL02_end";
				FlareSize = 0.5;
			};
			
			class LightCarHeadR01 : LightCarHeadL01 {
				position = "LightCarHeadR01";
				direction = "LightCarHeadR01_end";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			
			class LightCarHeadR02 : LightCarHeadR01 {
				position = "LightCarHeadR02";
				direction = "LightCarHeadR02_end";
				FlareSize = 0.5;
			};
		};
		aggregateReflectors[] = {{"Left", "Right", "Left2", "Right2"}};
		
		class RenderTargets {
			class LeftMirror {
				renderTarget = "rendertarget0";
				
				class CameraView1 {
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
			
			class RightMirror {
				renderTarget = "rendertarget2";
				
				class CameraView1 {
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
		};
	};
	class vurtual_mtvr_lhs16: vurtual_MTVRBase {
		numberPhysicalWheels=8;
		scope = 2;
		model = "\vurtual_mtvr\mtvr_lhs16.p3d";
		displayname = "MTVR LHS 16-Ton";
		class VehicleTransport: VehicleTransport {
			class Carrier: Carrier {
				cargoSpacing[]              = {0, 0, 0};
				cargoAlignment[]            = {"front","center"};
				maxLoadMass                 = 19233;
				disableHeightLimit			= 1;
			};
		};
		class Turrets {};
		class Library {
			libTextDesc = "MTVR LHS 16-Ton";
		};
		class Wheels {
			class LF: MTVRBaseWheel {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center   = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				WHEEL_SPRINGS(18869*3,8,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR: LF {
				boneName = "wheel_1_2_damper";
				steering = 0;
				center   = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;
				WHEEL_SPRINGS(18869,8,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR1: LR {
				boneName = "wheel_1_3_damper";
				center   = "wheel_1_3_axis";
				boundary = "wheel_1_3_bound";
				suspForceAppPointOffset = "wheel_1_3_axis";
				tireForceAppPointOffset = "wheel_1_3_axis";
			};
			class LR2: LR {
				boneName = "wheel_1_4_damper";
				center   = "wheel_1_4_axis";
				boundary = "wheel_1_4_bound";
				suspForceAppPointOffset = "wheel_1_4_axis";
				tireForceAppPointOffset = "wheel_1_4_axis";
			};
			

			class RF: LF {
				boneName = "wheel_2_1_damper";
				center   = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				side = "right";
			};
			class RR: RF {
				boneName = "wheel_2_2_damper";
				steering = 0;
				center   = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3000;		
				WHEEL_SPRINGS(18869,8,WHEEL_STRENGTH,WHEEL_DAMPER)				
			};
			class RR1: RR {
				boneName = "wheel_2_3_damper";
				center   = "wheel_2_3_axis";
				boundary = "wheel_2_3_bound";
				suspForceAppPointOffset = "wheel_2_3_axis";
				tireForceAppPointOffset = "wheel_2_3_axis";	
			};
			class RR2: RR {
				boneName = "wheel_2_4_damper";
				center   = "wheel_2_4_axis";
				boundary = "wheel_2_4_bound";
				suspForceAppPointOffset = "wheel_2_4_axis";
				tireForceAppPointOffset = "wheel_2_4_axis";	
			};
		};
		hasGunner = false;
		transportSoldier = 2;
		threat[] = {0.0, 0.0, 0.0};
		class TransportWeapons {};
		class EventHandlers {
			init = "_this call vurtual_mtvr_fnc_blackout; if (local (_this select 0)) then {[(_this select 0), """", [], true] call bis_fnc_initVehicle;};";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
	};

	class vurtual_MTVRBase_Passenger: vurtual_MTVRBase {
		VIVPassengers[] = {};
		VIVGunners[] = {};
		threat[] = {0.0, 0.0, 0.0};
		class CargoTurret;

		class Turrets {
			class CargoTurret_01: CargoTurret {
				gunnerAction = "passenger_inside_3";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_L";
				gunnerCompartments = "Compartment2";
				proxyIndex = 13;
				isPersonTurret = 1;
				maxElev = 90;
				minElev = -30;
				maxTurn = 15;
				minTurn = -95;
			};
			class CargoTurret_02: CargoTurret_01 {
				proxyIndex = 14;
				maxTurn = 95;
				minTurn = -15;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_R";
			};
		};
		animationList[] =  {"brakelight_normal_hide",0,"blackout_hide",1,"bedseat_fold",0,"cargo_cover_hide",0};
		class AnimationSources: AnimationSources {
			class bedseat_fold {
				lockCargo[] = {};
				lockCargoAnimationPhase = 1;
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				displayName = "Enable cargo mode";
				onPhaseChanged = "(_this select 0) enableVehicleCargo ((_this select 1)==1); (_this select 0) animateSource ['bedseat_fold',(_this select 1),is3den];";
			};
			class cargo_cover_hide {
				displayName = "Store cargo cover";
				source = "user";
				initPhase = 0;
				animPeriod = 3;
				onPhaseChanged = "(_this select 0) animateSource ['cargo_cover_hide',(_this select 1),is3den];"
			};
		};
		hasGunner = false;
		transportMaxBackpacks = 25;
		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			init = "_this call vurtual_mtvr_fnc_blackout;if (local (_this select 0)) then {[(_this select 0), """", [], true] call bis_fnc_initVehicle;};_this call vurtual_mtvr_fnc_init;";
		};
	};
	class vurtual_mtvr_mk23: vurtual_MTVRBase_Passenger {
		scope = 2;
		model = "\vurtual_mtvr\mtvr_mk23.p3d";
		displayname = "MTVR Mk 23 Cargo";
		VIVPassengers[] = {4,5,6,7,8,9,10,11,12,13};
		VIVGunners[] = {0,1};
		class Turrets: Turrets {
			class CargoTurret_01: CargoTurret_01 {
				proxyIndex = 13;
			};
			class CargoTurret_02: CargoTurret_02 {
				proxyIndex = 14;
			};
		};
		
		class Library {
			libTextDesc = "Mk23 Cargo";
		};
		class AnimationSources: AnimationSources {
			class bedseat_fold: bedseat_fold {
				lockCargo[] = {0,1,4,5,6,7,8,9,10,11,12,13};
			};
		};


	};
	class vurtual_mtvr_4x4: vurtual_MTVRBase_Passenger {
		scope = 2;
		model = "\vurtual_mtvr\mtvr_4x4.p3d";
		displayname = "MTVR 4x4 Short Bed Cargo";
		VIVPassengers[] = {4,5,6,7,8,9};
		VIVGunners[] = {0,1};
		cargoProxyIndexes[] = {1,2,3,4,5,6,7,8};
		transportSoldier = 8;
		class Turrets: Turrets {
			class CargoTurret_01: CargoTurret_01 {
				proxyIndex = 9;
			};
			class CargoTurret_02: CargoTurret_02 {
				proxyIndex = 10;
			};
		};
		
		class Library {
			libTextDesc = "4x4 Short Bed Cargo";
		};
		class AnimationSources: AnimationSources {
			class bedseat_fold: bedseat_fold {
				lockCargo[] = {0,1,4,5,6,7,8,9};
			};
		};
		class VehicleTransport: VehicleTransport {
			class Carrier: Carrier {
				maxLoadMass                 = 9475;
			};
		};
		numberPhysicalWheels=4;
		class Wheels {
			class LF: MTVRBaseWheel {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center   = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				WHEEL_SPRINGS(9893,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR : LF
			{
				boneName = "wheel_1_2_damper";
				steering = 0;
				center   = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;		
			};
			class RF : LF
			{
				boneName = "wheel_2_1_damper";
				center   = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				side = "right";
			};
			class RR : RF
			{
				boneName = "wheel_2_2_damper";
				steering = 0;
				center   = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3000;			
			};
		};
	};
};
