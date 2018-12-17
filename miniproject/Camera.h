//#pragma once
//#include "Player.h"
//#include<SDL.h>
//#include<SDL_image.h>
//#include<stdio.h>
//#include <map>
//#include "TextureManager.h"
//
//SDL_Window *window;
//SDL_Renderer *renderer;
//
//const int LEVEL_WIDTH = 1920;
//const int LEVEL_HEIGHT = 1080;
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//class Camera 
//{
//public:
//	int cameraX = 0, cameraY = 0;
//	void Cameras();
//	int PlayerX = 300, PlayerY = 200, PlayerW, PlayerH;
//	//void clipDrawImage(std::string id, double x, double y, double clipX, double clipY, double clipW, double clipH);
//	//void multDrawImage(std::string id, double x, double y, double multX, double multY);
//
//private:
//	std::map<std::string, SDL_Texture*> m_texture;
//	SDL_Texture* loadTexture(const char* path)
//	{
//		//��ȯ�� �ؽ���
//		SDL_Texture* newTexture = NULL;
//
//		//��θ� ���� �̹��� �ε�
//		SDL_Surface* loadedSurface = IMG_Load(path);
//		if (loadedSurface == NULL)
//		{
//			printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
//		}
//		else
//		{
//			//SurfaceŸ���� Texture ���Ϸ� ��ȯ
//			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
//			if (newTexture == NULL)
//			{
//				printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
//			}
//
//			//����ߴ� Surface�� �޸𸮿��� �����ش�
//			SDL_FreeSurface(loadedSurface);
//		}
//
//		return newTexture;
//	}
//};
