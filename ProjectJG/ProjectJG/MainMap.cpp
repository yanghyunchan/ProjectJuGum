#include "NNConfig.h"
#include "MainMap.h"
#include "GameOption.h"
#include "NNSprite.h"
#include "Maincharacter.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "Satellite.h"
#include "Asteroid.h"

#include "NNInputSystem.h"		// for 운석 테스트


CMainMap::CMainMap(void)
{
	++m_CurrentFrame;

	m_Width = MAIN_MAP_WIDTH;
	m_Height = MAIN_MAP_HEIGHT;

	m_MainFrame = NNRect::Create(m_Width, m_Height);
	m_MainFrame->SetPosition(0.f,0.f);
	AddChild(m_MainFrame);

	
	// 맵 배경 이미지
	m_BackGround = NNSprite::Create( MAIN_MAP_BACKGROUND_IMAGE );
	m_BackGround->SetImageWidth( GetWidth() );
	m_BackGround->SetImageHeight( GetHeight() );
	AddChild( m_BackGround );

	//플레이어 생성
	m_Player1 = new CMaincharacter;
	m_Player2 = new CMaincharacter;

	m_Player1->SetPosition( 0.f, GetBotLine() *0.5f );
	m_Player2->SetPosition( 0.f, GetTopLine() *0.5f );
//	m_Player2->SetPosition( 0.f, 0.f );
//	m_Player1->SetPosition( GetWidth() *0.5f, GetHeight() *0.25f );
//	m_Player2->SetPosition( GetWidth() *0.5f, GetHeight() *0.75f );

	AddChild( m_Player1 );
	AddChild( m_Player2 );

	//총알 장전
	for (int i = 0 ; i < MAX_BULLET_NUM ; ++i)
	{
		CBulletManager::GetInstance()->GetBulletArray()[i] = new CBullet;
		AddChild( CBulletManager::GetInstance()->GetBulletArray()[i] );
		CBulletManager::GetInstance()->GetBulletArray()[i]->SetVisible(false);
	}

	//운석 로딩
	for (int i = 0 ; i < MAX_ASTEROID_NUM ; ++i)
	{
		CBulletManager::GetInstance()->GetAsteroidArray()[i] = new CAsteroid;
		AddChild( CBulletManager::GetInstance()->GetAsteroidArray()[i] );
		CBulletManager::GetInstance()->GetAsteroidArray()[i]->SetVisible(false);
	}

	//인공위성 로딩
	for (int i = 0; i <MAX_SATELLITE_NUM; ++i)
	{
		CBulletManager::GetInstance()->GetSatelliteArray()[i] = new CSatellite;
		AddChild( CBulletManager::GetInstance()->GetSatelliteArray()[i]);
		CBulletManager::GetInstance()->GetSatelliteArray()[i]->SetVisible(false);
	}

	
}


CMainMap::~CMainMap(void)
{
}

void CMainMap::Render()
{
	NNObject::Render();
}

void CMainMap::Update( float dTime )
{
	//총알 및 오브젝트의 업데이트와 라이프타임 채크
	CBulletManager::GetInstance()->UpdateObj(dTime, m_Player2, this);

	//캐릭터 업데이트
	if (m_GameMode == TEST_MODE)
	{	
		m_Player1->Update(dTime, m_Player2, this);
	}
	else
	{
		m_Player1->Update(dTime, m_Player2, this, m_CurrentFrame);
		m_Player2->UpdateByPeer(dTime, m_Player1, this, m_CurrentFrame);
	}

	//맵과 캐릭터의 충돌체크
	SetPlayerMoveArea(m_Player1);
	SetPlayerMoveArea(m_Player2);

	//총알과 캐릭터의 충돌체크
	if(CBulletManager::GetInstance()->CharacterHitCheck(m_Player1))
		m_Player1->SetHit( true );

	//운석 테스트용 코드
	if(NNInputSystem::GetInstance()->GetKeyState('P') == KEY_DOWN)
	{
		CBulletManager::GetInstance()->ShotAsteroid(this);
	}
}

void CMainMap::SetPlayerMoveArea(CMaincharacter * Player)
{
	float leftline = GetLeftLine();
	float rightline = GetRightLine();
	float botline = GetBotLine();
	float topline = GetTopLine();

	if (Player->GetPositionX() < leftline)
	{
		Player->SetPosition(NNPoint(leftline, Player->GetPositionY()));
	}
	if (Player->GetPositionX() > rightline)
	{
		Player->SetPosition(NNPoint(rightline, Player->GetPositionY()));
	}
	if (Player->GetPositionY() > botline)
	{
		Player->SetPosition(NNPoint(Player->GetPositionX(), botline));
	}
	if (Player->GetPositionY() < topline)
	{
		Player->SetPosition(NNPoint(Player->GetPositionX(),topline));
	}
}

bool CMainMap::IsGameEnd()
{
	return ( m_Player1->IsHit() || m_Player2->IsHit() );
}
