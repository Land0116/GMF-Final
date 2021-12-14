#include "TextManager.h"

TextManager* TextManager::s_pInstance = nullptr;

void TextManager::WriteText(const char* str, int x, int y, int size, SDL_Color color, SDL_Renderer* pRenderer)
{
	clean();
	TTF_Init();

	TTF_Font* font = TTF_OpenFont("Assets/Font/arialbi.ttf", size);

	m_surface = TTF_RenderText_Solid(font, str, color);
	m_texture = SDL_CreateTextureFromSurface(pRenderer, m_surface);

	int width = 0; int height = 0;
	SDL_QueryTexture(m_texture, NULL, NULL, &width, &height);
	SDL_Rect FontRect = { x, y, width, height };
	SDL_RenderCopy(pRenderer, m_texture, NULL, &FontRect);
}

void TextManager::clean()
{
	SDL_DestroyTexture(m_texture);
	SDL_FreeSurface(m_surface);
	TTF_Quit();
}