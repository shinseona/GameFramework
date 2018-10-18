#pragma once
#include <iostream>
#include <map>
#include "SDL_image.h"
class TextureManager
{
public:
	TextureManager() {}
	~TextureManager() {}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame2,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame2(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:

	std::map<std::string, SDL_Texture*> m_textureMap;
private:
	TextureManager() {}

	// �Լ� �߰�
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	// type  �߰�
	typedef TextureManager TheTextureManager;

};
