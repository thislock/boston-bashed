
#include <SDL.h>
#include <iostream>

using std::cout;
using std::endl;

#include "rendering.h"

void butFix(
	SDL_Renderer * renderer, 
	SDL_Texture * tex,
  int x, int y,
	int width, int height,
	SDL_Rect *clip = nullptr
) {

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;

	if (clip != nullptr){
		dst.w = width;
		dst.h = height;
	} else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}

	SDL_RenderCopy(renderer, tex, clip, &dst);
}


void IMAGE::renderCutTexture(
	SDL_Renderer * renderer, 
  int x, int y,
	int width, int height,
	int clippings[4]
) {
	
	clip.x = clippings[0];
	clip.y = clippings[1];
	clip.w = clippings[2];
	clip.h = clippings[3];

	butFix(
		renderer, 
		tex, 
		x, y, 
		width, height,
		&clip
	);
}


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

	// sets the filename for error handling
	filename = file;

	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (tex == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
		}
	}
	else {
		cout << "failed to load " << filename << ", check filename and try again.\n";
  }
}

void IMAGE::setTexture(SDL_Renderer * renderer, const std::string &file) {

	// sets the filename for error handling
	filename = file;

	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (tex == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
		}
	}
	else {
		cout << "failed to load " << filename << ", check filename and try again.\n";
  }
}

IMAGE::IMAGE() {
	// pointless processing
	int x;
}

IMAGE::~IMAGE() {
	SDL_DestroyTexture(tex);
	cout << "destroyed texture, " << filename << endl;
}
