#include "SceneManager.h"
#include <cassert>

#include "SceneTitle.h"
#include "SceneMain.h"

#include "SceneNew.h"

SceneManager::SceneManager()
{
	m_kind = kSceneKindTitle;
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init(SceneKind kind)
{
	m_kind = kind;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_pScene = new SceneTitle;
		//m_pScene = new SceneNew;
		break;
	case SceneManager::kSceneKindMain:
		m_pScene = new SceneMain;
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
	m_pScene->init();
}

void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene) return;
	SceneBase* pSceme = m_pScene->update();

	if (pSceme != m_pScene)
	{
		// �O�̃V�[���̏I������
		m_pScene->end();
		delete m_pScene;

		m_pScene = pSceme;
		m_pScene->init();
	}

}

void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene) return;

	m_pScene->draw();
}