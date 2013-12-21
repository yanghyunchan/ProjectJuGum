#pragma once

#define WINDOW_WIDTH							1280
#define WINDOW_HEIGHT						800

#define MAIN_MAP_WIDTH						2000.f
#define MAIN_MAP_HEIGHT						1200.f
#define FRAME_WIDTH							750.f
#define FRAME_HEIGHT							750.f

#define MAX_BULLET_NUM						2000
#define MAX_FAIRY_NUM						50

#define BASIC_COST							50000

#define MAIN_MENU_LABEL_VERTICAL_SPACE		50.f
#define MAIN_MENU_LABEL_HORIZONTAL_SPACE	200.f
#define MAIN_MENU_FONT_WIDTH				16.f
#define MAIN_MENU_MAX_BUFFER_SIZE			30

#define UI_LABEL_FONT_SIZE					40.f

// MainMenuScene Resources
#define MAIN_MENU_SCENE_BACKGROUND_IMAGE			L"Sprite/MainBackground.jpg"
#define MAIN_MENU_LOADING_SCENE					L"Sprite/Loading.jpg"
#define MAIN_MENU_SCENE_BACKGROUND_SOUND		"Sound/Eternal Dream.mp3"
#define MAIN_MENU_INSTRUCTION					L"Sprite/font/instruction.png"
#define MAIN_MENU_LABEL_TEST					L"Sprite/font/TEST.png"
#define MAIN_MENU_LABEL_SERVER					L"Sprite/font/SERVER.png"
#define MAIN_MENU_LABEL_CLIENT					L"Sprite/font/CLIENT.png"
#define MAIN_MENU_LABEL_QUIT					L"Sprite/font/QUIT.png"
#define MAIN_MENU_HIGHLIGHT_TEST				L"Sprite/font/TEST_ON.png"
#define MAIN_MENU_HIGHLIGHT_SERVER				L"Sprite/font/SERVER_ON.png"
#define MAIN_MENU_HIGHLIGHT_CLIENT				L"Sprite/font/CLIENT_ON.png"
#define MAIN_MENU_HIGHLIGHT_QUIT				L"Sprite/font/QUIT_ON.png"
#define MAIN_MENU_SERVER_COMMAND				L"Sprite/font/SERVER_COMMAND.png"
#define MAIN_MENU_CLIENT_COMMAND				L"Sprite/font/CLIENT_COMMAND.png"
#define MAIN_MENU_NUMBER_FONT					L"Sprite/font/NUMBERS.png"
#define EFFECT_SOUND_OK							"Sound/se_ok00.wav"
#define EFFECT_SOUND_CANCEL						"Sound/se_cancel00.wav"
#define EFFECT_SOUND_SELECT						"Sound/se_select00.wav"

// MainMap Resources
#define MAIN_MAP_BACKGROUND_IMAGE				L"Sprite/background/IMG00000.jpg"

// UImanager Resources
#define VERTICAL_FONT							L"AEZ outline vertical"
#define GAME_FONT								L"Bleeding Cowboys"
#define RAYMU_PORTRAIT							L"Sprite/Raymu Portraits.png"
#define MARISA_PORTRAIT							L"Sprite/Marisa Portraits.png"

// PlayScene Resources
#define GAME_BACKGROUND_SOUND					"Sound/the Mooned Incects.mp3"

// Character Resources
#define EFFECT_SOUND_DEAD						"Sound/se_pldead00.wav"
#define EFFECT_SOUND_CHAR_SHOT					"Sound/se_plst00.wav"
#define EFFECT_SOUND_SUBCHAR_SHOT				"Sound/se_graze.wav"
#define EFFECT_SOUND_BIG_SKILL_SHOT				"Sound/se_enep00.wav"

enum ECharcterType
{
	RAYMU,
	MARISA
};
enum ESubCharType
{
	YUKARI,
	ALICE
};
enum ESubCharState
{
	NONE_STATE,
	SUMMON_STATE,
	SKILL_STATE
};
#define CHAR_SPEED						300.f
#define CHAR_SLOW_SPEED					150.f
#define CHAR_HIT_RADIUS					5.f


#define BULLET_TYPE_NUM	7
enum EBulletType
{
	RAYMU_NORMAL_BULLET,
	RAYMU_ACCEL_BULLET,
	RAYMU_CURVE_BULLET,
	MARISA_NORMAL_BULLET,
	MARISA_BIG_BULLET,
	MARISA_RETAR_BULLET,
	FAIRY_NORMAL_BULLET,
};
#define FAIRY_NORMAL_BULLET_SPEED		100.f

#define RAYMU_ACCEL_BULLET_SPEED			20.f
#define RAYMU_ACCEL_BULLET_ACCEL			150.f

#define RAYMU_CURVE_BULLET_SPEED			50.f
#define RAYMU_CURVE_BULLET_ANGULAR		5.f

#define MARISA_BIG_BULLET_SPEED			50.f

#define MARISA_RETAR_BULLET_SPEED		300.f
#define MARISA_RETAR_BULLET_ACCEL		-50.f

#define BULLET_HIT_RADIUS				7.f
#define BULLET_CURVE_HIT_RADIUS			15.f
#define BULLET_BIG_HIT_RADIUS			50.f

#define SHOT_POINT						20.f
#define CURVE_SHOT_POINT					30.f
#define BIG_SHOT_POINT					70.f


enum ESkill
{
	RAYMU_NORMAL_ATTACK,
	YUKARI_FAN_ATTACK,
	MARISA_NORMAL_ATTACK,
	SUMMON_FAIRY,
	FAIRY_SKILL_1
};
#define RAYMU_NORMAL_ATTACK_COST			1
#define YUKARI_FAN_ATTACK_COST			10
#define MARISA_NORMAL_ATTACK_COST		1
#define SUMMON_FAIRY_COST				10
#define FAIRY_SKILL_1_COST				20

enum EInputSetUp
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LEFT_UP,
	RIGHT_UP,
	LEFT_DOWN,
	RIGHT_DOWN,
	SKILL_KEY_ONE,
	SKILL_KEY_TWO,
	SKILL_KEY_THREE,
	SKILL_KEY_FOUR,
	SKILL_KEY_FIVE,
	SKILL_KEY_SIX,
	UPGRADE_KEY,
	CHANGE_SPEED,
	PAUSE
};

enum EMenuList
{
	MENU_TEST,
	MENU_SERVER,
	MENU_CLIENT,
	MENU_QUIT,
	MENU_NUM,
};

enum ENetMenuList
{
	NET_MENU_SERVER,
	NET_MENU_CLIENT,
	NET_MENU_NUM,
};

enum ENetworkMode
{
	TEST_MODE,
	CLIENT_MODE,
	SERVER_MODE,
	MODE_NONE,
};

enum EGameResult
{
	GAME_NOT_END,
	GAME_RESULT_DRAW,
	GAME_RESULT_WIN,
	GAME_RESULT_LOSE
};