#include "Window.h"

#include "SDL.h"

Window::Window(const std::string& windowTitle, int width, int height)
	: m_WindowTitle(windowTitle), m_Width(width), m_Height(height), m_Center({(float)width * 0.5f, (float)height * 0.5f})
{
}

void Window::setTitle(const std::string& windowTitle)
{
	SDL_SetWindowTitle(m_Window, windowTitle.c_str());
}

void Window::clear(const Color& bg)
{
	SDL_SetRenderDrawColor(m_Renderer, bg.r, bg.g, bg.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_Renderer);
	m_CurrentColorID = 0;
}

void Window::submit(void)
{
	SDL_RenderPresent(m_Renderer);
}

void Window::destroy(void)
{
	if (m_Renderer) { SDL_DestroyRenderer(m_Renderer); }
	if (m_Window) { SDL_DestroyWindow(m_Window); }
}

void Window::drawLine(const Vec2f& from, const Vec2f& to, const Color& color)
{
	if (m_CurrentColorID != color.getID())
	{
		m_CurrentColorID = color.getID();
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
	}

	SDL_RenderDrawLineF(m_Renderer, m_Center.x + from.x, m_Height - (m_Center.x + from.y), m_Center.x + to.x, m_Height - (m_Center.y + to.y));
}

void Window::drawPoint(const Vec2f& position, const Color& color)
{
	if (m_CurrentColorID != color.getID())
	{
		m_CurrentColorID = color.getID();
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
	}

	SDL_RenderDrawPointF(m_Renderer, position.x + m_Center.x, m_Height - (m_Center.y + position.y));
}

void Window::drawRect(const Vec2f& position, const Vec2f& extents, const Color& color)
{
	if (m_CurrentColorID != color.getID())
	{
		m_CurrentColorID = color.getID();
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
	}

	SDL_RenderDrawRectF(
		m_Renderer,
		&SDL_FRect({
			m_Center.x + position.x - extents.x,
			m_Height - (m_Center.y + position.y + extents.y),
			extents.x + extents.x,
			extents.y + extents.y,
			})
		);
}
