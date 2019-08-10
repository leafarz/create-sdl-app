#ifndef		APPLICATION_H
#define		APPLICATION_H
#pragma once

class Window;
class Scene;

class Application
{
public:
	Application(const char* windowName, int width, int height);
	~Application(void);

	static Application* getInstance(void) { return s_Instance; }

	Window* getWindow(void) const { return m_Window; }

	void run(void);

private:
	static Application* s_Instance;

	Window* m_Window;
	Scene* m_Scene;

	float m_TimeStep;
	float m_GameTime = 0.0f;

	bool m_IsRunning = false;
	bool m_SceneIsInitialized = false;
};

#endif
