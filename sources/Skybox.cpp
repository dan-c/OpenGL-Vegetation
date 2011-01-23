#include <GL/glut.h>

#include "Skybox.h"

Skybox::Skybox ()
{
    frontTexture = new Texture ("textures/front.raw", 512, 256);
    rightTexture = new Texture ("textures/right.raw", 512, 256);
    leftTexture = new Texture ("textures/left.raw", 512, 256);
    backTexture = new Texture ("textures/back.raw", 512, 256);
    topTexture = new Texture ("textures/top.raw", 512, 512);
}

void Skybox::draw ()
{
    glBindTexture (GL_TEXTURE_2D, frontTexture->getTexture());
    
    glBegin (GL_QUADS);
        glTexCoord2d (0, 1); glVertex3d (-1, +0, -1); 
        glTexCoord2d (1, 1); glVertex3d (+1, +0, -1);
        glTexCoord2d (1, 0); glVertex3d (+1, +1, -1);
        glTexCoord2d (0, 0); glVertex3d (-1, +1, -1);
    glEnd();

    glBindTexture (GL_TEXTURE_2D, rightTexture->getTexture());

    glBegin (GL_QUADS);
        glTexCoord2d (0, 1); glVertex3d (+1, +0, -1);
        glTexCoord2d (1, 1); glVertex3d (+1, +0, +1);
        glTexCoord2d (1, 0); glVertex3d (+1, +1, +1);
        glTexCoord2d (0, 0); glVertex3d (+1, +1, -1);
    glEnd();

    glBindTexture (GL_TEXTURE_2D, leftTexture->getTexture());

    glBegin (GL_QUADS);
        glTexCoord2d (1, 1); glVertex3d (-1, +0, -1);
        glTexCoord2d (0, 1); glVertex3d (-1, +0, +1);
        glTexCoord2d (0, 0); glVertex3d (-1, +1, +1);
        glTexCoord2d (1, 0); glVertex3d (-1, +1, -1);
    glEnd();

    glBindTexture (GL_TEXTURE_2D, backTexture->getTexture());

    
    glBegin (GL_QUADS);
        glTexCoord2d (1, 1); glVertex3d (-1, +0, +1); 
        glTexCoord2d (0, 1); glVertex3d (+1, +0, +1);
        glTexCoord2d (0, 0); glVertex3d (+1, +1, +1);
        glTexCoord2d (1, 0); glVertex3d (-1, +1, +1);
    glEnd();
    
    glBindTexture (GL_TEXTURE_2D, topTexture->getTexture());

    glBegin (GL_QUADS);
        glTexCoord2d (0, 0); glVertex3d (-1, +1, +1);
        glTexCoord2d (1, 0); glVertex3d (+1, +1, +1);
        glTexCoord2d (1, 1); glVertex3d (+1, +1, -1);
        glTexCoord2d (0, 1); glVertex3d (-1, +1, -1);
    glEnd();
}

Skybox::~Skybox ()
{
    frontTexture->~Texture ();
    backTexture->~Texture ();
    rightTexture->~Texture ();
    leftTexture->~Texture ();
    topTexture->~Texture ();
}