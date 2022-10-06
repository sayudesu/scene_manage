#pragma once
#include "SceneBase.h"

class SceneNew : public SceneBase
{
public:
	SceneNew()
	{
		m_textPosY = 0;
		m_textVecY = 0;
		m_isEnd = false;
	}
	virtual ~SceneNew() {}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	// テキスト表示位置変更
	int m_textPosY;
	int m_textVecY;
	int m_textVecX;

	bool m_isEnd;
};
