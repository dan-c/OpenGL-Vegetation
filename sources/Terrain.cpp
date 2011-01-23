#include "Terrain.h"

Terrain::Terrain (float patchSize, int patchCount)
{
	groundTexture = new Texture ("textures/ground.raw", 1024, 512);

	groundXi = - (patchSize * patchCount)/2;
	groundZi = (patchSize * patchCount)/2;

	groundXf = (patchSize * patchCount)/2;
	groundZf = - (patchSize * patchCount)/2;
}

void Terrain::draw ()
{
	glBindTexture (GL_TEXTURE_2D, groundTexture->getTexture());

	glBegin (GL_QUADS);
		glTexCoord2d (0, 10); glVertex3d (-1, +0, +1);
		glTexCoord2d (10, 10); glVertex3d (+1, +0, +1);

		glTexCoord2d (10, 0); glVertex3d (+1, +0, -1);

		glTexCoord2d (0, 0); glVertex3d (-1, -0, -1);
	glEnd();
}
