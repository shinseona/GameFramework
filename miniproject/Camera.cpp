//#include "Camera.h"
//#include "TextureManager.h"
// void Camera::Cameras()
//{
//	cameraX = (PlayerX + PlayerW / 2) - SCREEN_WIDTH / 2;
//	cameraY = (PlayerY + PlayerH / 2) - SCREEN_HEIGHT / 2;
//	//Keep the camera in bounds
//	if (cameraX < 0)
//	{
//		cameraX = 0;
//	}
//	if (cameraY < 0)
//	{
//		cameraY = 0;
//	}
//	if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH)
//	{
//		cameraX = LEVEL_WIDTH - SCREEN_WIDTH;
//	}
//	if (cameraY > LEVEL_HEIGHT - SCREEN_HEIGHT)
//	{
//		cameraY = LEVEL_HEIGHT - SCREEN_HEIGHT;
//	}
//
//	SDL_Texture *BG = loadTexture("Rectangle.png");
//	
//
//	clipDrawImage(BG, 0, 0, cameraX, cameraY, SCREEN_WIDTH, SCREEN_HEIGHT);
//	//multDrawImage("helicopter", PlayerX - cameraX, PlayerY - cameraY, 0.5, 0.5);
//}
// void multDrawImage(SDL_Texture *texture, double x, double y, double multX, double multY)
// {
//	 SDL_Rect src, dst;
//	 SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
//	 src.x = 0;
//	 src.y = 0;
//	 dst.x = x;
//	 dst.y = y;
//	 dst.w = src.w*multX;
//	 dst.h = src.h*multY;
//	 SDL_RenderCopy(renderer, texture, &src, &dst);
// }
//
//	 void clipDrawImage(SDL_Texture *texture, double x, double y, double clipX, double clipY, double clipW, double clipH)
// {
//	 SDL_Rect src, dst;
//	 src.x = clipX;
//	 src.y = clipY;
//	 src.w = clipW;
//	 src.h = clipH;
//	 dst.x = x;
//	 dst.y = y;
//	 dst.w = src.w;
//	 dst.h = src.h;
//	 SDL_RenderCopy(renderer, texture, &src, &dst);
// }
