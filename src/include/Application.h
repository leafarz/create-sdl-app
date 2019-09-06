#ifndef		APPLICATION_H
#define		APPLICATION_H
#pragma once

#include <memory>

class Window;
class Scene;

class Application
{
public:
	Application(const char* windowName, int width, int height);
	~Application(void);

	inline static Application* getInstance(void) { return s_Instance; }

	inline Window& getWindow(void) const { return *m_Window; }

	void run(void);

private:
	static Application* s_Instance;

	std::unique_ptr<Window> m_Window;
	std::unique_ptr<Scene> m_Scene;

	float m_TimeStep;
	float m_GameTime = 0.0f;

	bool m_IsRunning = false;
	bool m_SceneIsInitialized = false;
};

#endif
