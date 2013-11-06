#pragma once

#define CHARIC_SPEED				200.f

#define MAX_BULLET_NUM			100
#define MAX_ACCELBULLET_NUM		100

#define BULLET_SPEED				300.f
#define ACCELBULLET_SPEED		100.f

#define ACCELBULLET_ACCELERATION	2.f

#define SHOTBULLET_COST			5
#define SHOTACCELBULLET_COST		10

enum Skill
{
	NORMAL,
	SHOTBULLET,
	SHOTACCELBULLET,
	SHOTSECTORNORMAL,
	SHOTSECTORACCEL,
};

enum InputSetUp
{
	ELSE,
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
	UPGRADE_KEY
};

enum MENU_LIST
{
	MENU_PLAY,
	MENU_TEST,
	MENU_QUIT,
	MENU_LAST,
};

