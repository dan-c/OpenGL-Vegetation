#ifndef TERRAIN_H
#define TERRAIN_H

#include "Texture.h"

class Terrain
{
	private:
		Texture *groundTexture;
		float groundXi, groundZi, groundXf, groundZf;
	public:
		Terrain (float patchSize, int patchCount);
		void draw();
};

#endif

