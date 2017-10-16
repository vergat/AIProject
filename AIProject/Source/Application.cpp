#include "Application.h"
#include <ctime>
#include <cassert>
#include "IScene.h"
#include "LoadingScene.h"
#include "MainMenuScene.h"
#include "AStarScene.h"
#include "MinerScene.h"
#include "FifteenPuzzleScene.h"

void Application::Init(bool /*fullscreen*/)
{
	sf::VideoMode mode;
	mode.width = 1024;
	mode.height = 768;
	mode.bitsPerPixel = 32;

	m_window = new sf::RenderWindow(mode,
		"AI Sandbox",
		sf::Style::Titlebar || sf::Style::Close);

	m_window->setFramerateLimit(60);

	m_inputPauseTime = 0.f;

	m_currentSceneName = SceneEnum::Scene_Invalid;

	SetScene(SceneEnum::Scene_Loading);
}

void Application::Destroy()
{
	for (SceneMap::iterator it = m_scenes.begin(); it != m_scenes.end(); ++it)
	{
		delete it->second;
	}
}

void Application::SetScene(const SceneEnum eScene, const bool bDeleteCurrent)
{
	std::cout << "Application::SetScene() called - New Scene ->" << eScene << "\n\n";

	if (bDeleteCurrent && m_currentSceneName != SceneEnum::Scene_Invalid)
	{
		SceneMap::iterator sceneToDelete = m_scenes.find(m_currentSceneName);
		if(sceneToDelete != m_scenes.end())
		{
			delete sceneToDelete->second;
			m_scenes.erase(sceneToDelete);
		}
	}
	
	SceneMap::iterator scene = m_scenes.find(eScene);
	if (scene == m_scenes.end())
	{
		IScene* newScene = NULL;
		switch (eScene)
		{
			case SceneEnum::Scene_Loading:
				newScene = new LoadingScene();
				break;
	
			case SceneEnum::Scene_MainMenu:
				newScene = new MainMenuScene();
				break;

			case SceneEnum::Scene_AStar:
				newScene = new AStarScene();
				break;

			case  SceneEnum::Scene_Gioco15:
				newScene = new FifteenPuzzleScene();
				break;

			case  SceneEnum::Scene_Miner:
				newScene = new MinerScene();
				break;

			default:
				break;
		}

		if (newScene != NULL)
		{
			m_scenes.insert(std::pair<SceneEnum, IScene*>(eScene, newScene));
		}

		scene = m_scenes.find(eScene);
	}

	if (scene != m_scenes.end())
	{
		m_currentScene = scene->second;
		m_currentSceneName = eScene;
	}
}

IScene* Application::GetScene(const SceneEnum eScene)
{
	SceneMap::iterator scene = m_scenes.find(eScene);
	
	//if not find, ent == m_entMap.End()
	if(scene == m_scenes.end())
		return NULL;
	else
		return scene->second;
}

void Application::Run()
{
	sf::Event event;
	while ( m_window->isOpen())
	{
		m_window->setActive(true);

		if (m_currentScene != NULL)
			m_currentScene->OnIdle();

		m_fpsCounter.Update();

        Render();
        
		while (m_window->pollEvent(event) && IsInputAvaible())
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					Exit();
					break;
                
                default:
                    break;
			}
			
			switch (event.key.code)
			{
				case sf::Keyboard::Escape:
                    if (m_currentSceneName == SceneEnum::Scene_MainMenu)
                        Exit();
                    else
                        SetScene(SceneEnum::Scene_MainMenu);
                    
                    PauseInput();
                    
					break;
                    
                default:
                    break;
			}
		}
	}
}

void Application::Render()
{
	m_window->clear(sf::Color(100,100,100));

	if (m_currentScene != NULL)
		m_currentScene->OnDraw(*m_window);

	m_fpsCounter.Draw(*m_window);

	m_window->display();
}


