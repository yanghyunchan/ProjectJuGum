#pragma once
#include "NNObject.h"
#include "NNSpriteNode.h"

class NNAnimation : public NNObject
{
public:
	NNAnimation();
	virtual ~NNAnimation();

	void Render();
	void Update( float dTime );

	static NNAnimation* Create( int count, float frameTime, ... );
	static NNAnimation* Create();

	int GetFrameCount() const { return m_FrameCount; }
	int GetNowFrame() const { return m_Frame; }
	void SetImageWidth( float width ) { m_ImageWidth = width; }
	void SetImageHeight( float height ) { m_ImageHeight = height; }
	bool IsLoop() const { return m_Loop; }

	void AddSpriteNode( wchar_t* path );
	void SetLoop( bool loop ) { m_Loop = loop; }

	bool IsAnimationEnd() const { return m_AnimationEnd; }

	void SetOpacity( float opacity ) { m_Opacity = opacity; }

private:
	std::vector<NNSpriteNode*> m_SpriteList;

	int m_FrameCount;
	int m_Frame;
	float m_Time;
	bool m_Loop;
	bool m_AnimationEnd;
	float m_ImageWidth;
	float m_ImageHeight;

	float m_Opacity;
};