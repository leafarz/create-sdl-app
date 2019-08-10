#ifndef		WINDOW_H
#define		WINDOW_H
#pragma once

#include "Vec2f.h"
#include "Color.h"
#include <string>

namespace gg { namespace math { struct Vec2f; } }
using namespace gg::math;

struct SDL_Renderer;
struct SDL_Window;

class Window
{
public:
	Window(const std::string& windowTitle, int width, int height);

	SDL_Renderer** getRenderer(void) { return &m_Renderer; }
	SDL_Window** getWindow(void) { return &m_Window; }
	int getWidth(void) const { return m_Width; }
	int getHeight(void) const { return m_Height; }

	const std::string& getTitle(void) const { return m_WindowTitle; }
	void setTitle(const std::string& windowTitle);

	void clear(const Color& bg = Color::Black);
	void submit(void);
	void destroy(void);

	void drawLine(const Vec2f& from, const Vec2f& to, const Color& color = Color::White);
	void drawPoint(const Vec2f& position, const Color& color = Color::White);
	void drawRect(const Vec2f& position, const Vec2f& extents, const Color& color = Color::White);


private:
	SDL_Renderer* m_Renderer = nullptr;
	SDL_Window* m_Window = nullptr;

	std::string m_WindowTitle;

	Vec2f m_Center;

	int m_Width, m_Height;
	
	uint8_t m_CurrentColorID = 0;
};

#endif
