#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneNew.h"
#include "DxLib.h"

void SceneTitle::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	// �����̈ړ�
	m_textPosY += m_textVecY;
	if (m_textPosY < 0)
	{
		m_textPosY = 0;
		m_textVecY = 4;
	}
	if (m_textPosY > 200)
	{
		m_textPosY = 200;
		m_textVecY = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		//Main�ɐ؂�ւ�
		return(new SceneMain);
	}
	else if ( padState & PAD_INPUT_3)
	{
		//New�ɐ؂�ւ�
		return(new SceneNew);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(0, m_textPosY,"�^�C�g�����",GetColor(GetRand(255), GetRand(255), GetRand(255)));
}