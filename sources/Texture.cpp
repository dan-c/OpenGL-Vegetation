// Standard C libraries
#include <stdio.h> // fopen, fread
#include <stdlib.h> // calloc, freee

// Standard C++ libraries
#include <iostream>

// 3rd party libraries
#include <GL/gl.h>
#include <GL/glut.h>

// Header implemented by this file
#include "texture.h"

using namespace std;

Texture::Texture (const char * filename, int width, int height)
{
	int rc;

	unsigned char * data;
	FILE * file;

	file = fopen (filename, "rb");

	if (file == NULL)
	{
		cerr << "Cannot open " << filename << endl;

		return;
	}

	size_t rawFileSize = width * height * 3;

	data = (unsigned char *) calloc (rawFileSize, sizeof (char));

	size_t sizeRead = fread (data, sizeof (char), rawFileSize, file );

	if (sizeRead != rawFileSize)
	{
		cerr << "Reading error for " << filename << endl;
	}

	rc = fclose (file);

	if (rc == EOF)
	{
		cerr << "Error closing file " << filename << endl;

		return;
	}

	glGenTextures (1, &texture);  //generate the texture with the loaded data
	glBindTexture (GL_TEXTURE_2D, texture ); //bind the texture to it’s array
    glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //set texture environment parameters

 	/*
 	 * here we are setting what textures to use and when. The MIN filter is which quality to show
 	 * when the texture is near the view, and the MAG filter is which quality to show when the texture
     * is far from the view.
     */
	
	// The qualities are (in order from worst to best)
    //GL_NEAREST
    //GL_LINEAR
    //GL_LINEAR_MIPMAP_NEAREST
    //GL_LINEAR_MIPMAP_LINEAR

    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Here we are setting the parameter to repeat the texture instead of clamping the texture to the edge of our shape. 

    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); // Generate the texture
    
    free (data); 
}

Texture::~Texture ()
{
	glDeleteTextures(1, &texture);
}

GLuint Texture::getTexture ()
{
	return texture;
}
