#ifndef		SCENE_H
#define		SCENE_H
#pragma once

class Scene
{
public:
	Scene(void);
	~Scene(void);

	void onStart(void);
	void onRender(float dt);
	void onEnd(void);
};
#endif
