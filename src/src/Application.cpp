#include "Application.h"

#include "SDL.h"
#include "Window.h"
#include "Scene.h"

#include <iomanip>
#include <sstream>

Application* Application::s_Instance;

Application::Application(const char * windowName, int width, int height)
{
	s_Instance = this;

	m_TimeStep = 1 / 60.0f;

	m_Window = new Window(windowName, width, height);
	m_Scene = new Scene();
}

Application::~Application(void)
{
	delete this;
}

void Application::run(void)
{
	if (m_IsRunning) { return; }

	m_IsRunning = true;

	float _timer = 0.0f;
	float _prevTime = 0.0f;


	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		if (SDL_CreateWindowAndRenderer(m_Window->getWidth(), m_Window->getHeight(), 0, m_Window->getWindow(), m_Window->getRenderer()) == 0)
		{
			while (m_IsRunning)
			{
				// update input
				SDL_Event event;
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT)
					{
						m_IsRunning = false;
					}
				}

				// clear frame
				m_Window->clear();

				// ++++++++++++++++ TIMER
				float _currTime = SDL_GetTicks() * 0.001f;
				float _delta = _currTime - _prevTime;
				_prevTime = _currTime;

				_timer += _delta;

				bool _willUpdate = _timer >= m_TimeStep;
				if (_willUpdate)
				{
					// update delta time
					float _rem = std::fmod(_timer, m_TimeStep);

					float _delta = _timer - _rem;
					m_GameTime += _delta;

					//float _fps = roundf(1 / _delta * 100) / 100;

					std::stringstream stream;
					stream << std::fixed << std::setprecision(2) << 1 / _delta;
					//std::string s = stream.str();

					m_Window->setTitle("[FPS: " + stream.str() + "] " + m_Window->getTitle());

					if (!m_SceneIsInitialized)
					{
						m_SceneIsInitialized = true;
						m_Scene->onStart();
					}
					m_Scene->onRender(_delta);

					m_Window->submit();

					_timer = _rem;
				}
				// ---------------- TIMER
			}
		}

		m_Scene->onEnd();
		m_Window->destroy();
	}

	SDL_Quit();
}
