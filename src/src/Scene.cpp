#include "Scene.h"

#include "Application.h"
#include "Window.h"

Scene::Scene(void)
{
}

Scene::~Scene(void)
{
}

void Scene::onStart(void)
{
}

void Scene::onRender(float dt)
{
	Application* _app = Application::getInstance();
	Window _window = _app->getWindow();

	// draw sad face
	_window.drawRect({ 0,0 }, { 75, 75 });
	_window.drawRect(Vec2f(30, 30), { 20, 20 });
	_window.drawRect(Vec2f(-30, 30), { 20, 20 });
	_window.drawLine(Vec2f(-30, -30), Vec2f(0, -20));
	_window.drawLine(Vec2f(30, -30), Vec2f(0, -20));
}

void Scene::onEnd(void)
{
}
