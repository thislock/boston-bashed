
#include <SDL.h>
#include <iostream>

using std::cout;


#include "../../include.h"


void IMAGE::renderTexture(SDL_Renderer *ren, int x, int y) {
	//Setup the destination rectangle to be at the position we want

	SDL_Rect dst;
	dst.x = x; dst.y = y;

	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void IMAGE::renderScaledTexture(SDL_Renderer *ren, int x, int y, int w, int h){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

IMAGE::IMAGE(SDL_Renderer * renderer, const std::string &file) {
	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (tex == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
      EXIT
		}
	}
	else {
		cout << "failed to load bmp image, check filename and drivers and try again.\n";
    EXIT
  }
}
