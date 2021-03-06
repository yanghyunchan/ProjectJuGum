#pragma once
#include "GameMoveObj.h"

class CMaincharacter;
class NNAnimation;
class NNSprite;
class NNSound;

class CSubChar :
	public CGameMoveObj
{
public:
	CSubChar(ESubCharType type_of_char);
	virtual ~CSubChar(void);

	void			Init();

	void			Render();
	void			Update(float dTime, CMaincharacter* enemy);
	
	ESubCharState	GetState() const { return m_State; }
	void			SetState(ESubCharState val) { m_State = val; }

	void			YukariAccelAttack( float dTime );
	void			YukariFanAttack( float dTime );
	void			YukariCurveAttack( float dTime );
	void			AliceNormalAttack( float dTime );
	void			AliceStarAttack( float dTime );
	void			AliceBoomerangAttack( float dTime );

	NNAnimation*	GetFlyMotion() const { return m_FlyMotion; }
	void			SetFlyMotion(NNAnimation* val) { m_FlyMotion = val; }
	NNSprite*		GetBackgroundEffect() const { return m_BackgroundEffect; }
	void			SetBackgroundEffect(NNSprite* val) { m_BackgroundEffect = val; }

protected:
	ESubCharType	m_Type;
	ESubCharState	m_State;
	float			m_ShotTimeSum;
	float			m_FanAttackBulletTime;

	NNSound*		m_Shotsound;

	NNAnimation*	m_FlyMotion;

	NNSprite*		m_BackgroundEffect;
	
};

