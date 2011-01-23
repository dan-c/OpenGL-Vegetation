#ifndef SKYBOX_H
#define SKYBOX_H

#include "Texture.h"

class Skybox
{
	private:
		Texture *frontTexture, *backTexture, *rightTexture, *leftTexture, *topTexture;
	public:
		Skybox ();
		~Skybox ();
		
		void draw();
};

#endif

