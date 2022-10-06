#include "SceneNew.h"
#include "DxLib.h"

void SceneNew::init()
{
	m_textPosY = 0;
	m_textVecY = 4;
	m_textVecX = 4;

	m_isEnd = false;
}

SceneBase* SceneNew::update()
{
	// ï∂éöÇÃà⁄ìÆ
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

	if (CheckHitKey(KEY_INPUT_1))
	{
		PlaySoundFile("sound/cursor0.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_2))
	{
		PlaySoundFile("sound/cursor1.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_3))
	{
		PlaySoundFile("sound/cursor2.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_4))
	{
		PlaySoundFile("sound/cursor3.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_5))
	{
		PlaySoundFile("sound/cursor4.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_6))
	{
		PlaySoundFile("sound/cursor5.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_7))
	{
		PlaySoundFile("sound/cursor6.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_0))//ã©Ç—
	{
		PlaySoundFile("sound/Syo sakebi.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_9))//ã©Ç—
	{
		PlaySoundFile("sound/Syosan-sakebi.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_8))//ã©Ç—
	{
		PlaySoundFile("sound/kisei1.mp3", DX_PLAYTYPE_BACK);
	}
	if (CheckHitKey(KEY_INPUT_P))//ã©Ç—
	{
		PlaySoundFile("sound/atotyotto.mp3", DX_PLAYTYPE_BACK);
	}

	if (padState & PAD_INPUT_3)
	{
		m_isEnd = true;
	}

	return this;
}

void SceneNew::draw()
{
	DrawString(m_textVecX, m_textPosY, "Ç‡Ç§Z,XâüÇµÇƒÇ‡ñﬂÇÍÇ»Ç¢ÇÊ(êVÇµÇ¢âÊñ )", GetColor(GetRand(255), GetRand(255), GetRand(255)));
	DrawString(m_textVecX + 20, m_textPosY + 20, "âπÇ»ÇÈÇÊ", GetColor(GetRand(255), GetRand(255), GetRand(255)));
	DrawString(m_textVecX + 50, m_textPosY + 50, "1,2,3,4,5,6,7,8,9,0Ç≈âπÇ™ñ¬ÇÈÇÊ", GetColor(GetRand(255), GetRand(255), GetRand(255)));
}