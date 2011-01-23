#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>

class Texture
{
	private:
		GLuint texture;
	public:
		Texture (const char * filename, int width, int height);
		~Texture ();
		
		GLuint getTexture ();
};

#endif