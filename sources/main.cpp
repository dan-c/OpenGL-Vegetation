#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>

#include "Math.h"
#include "Skybox.h"
#include "Terrain.h"
#include "Camera.h"

Skybox *skybox;
Terrain *terrain;
Camera *camera;

void displayCallback ()
{
    // Clear the background of our window to black  
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Clear the colour buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Camera e in 0.0 (pe z), planul apropiat e in 1.0 (pe z negativ)
    // Tot ce in intre (0.0, 1.0) nu se vede
    // Pentru a se vedea este mutata toata scena cu 5 unitati pe z neg 
    //glTranslatef(0.0f, 0.0f, -4.0f);

    skybox->draw ();    
    terrain->draw ();
    
    // In a single buffered window, we want to just do a straight flush from OpenGL to the window
    glutSwapBuffers();
}

void reshapeCallback (int width, int height) 
{
    glViewport(0, 0, (GLint)width, (GLint)height);

    // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glMatrixMode(GL_PROJECTION);   
    
    // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
    glLoadIdentity(); 

    // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 0.01, 100.0);

    // Switch back to the model view matrix, so that we can start drawing shapes correctly  
    glMatrixMode(GL_MODELVIEW);
}

void keyboardCallback (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w': case 'W':
            camera->move(0, MOVE_STEP);
        break;
        case 's': case 'S':
            camera->move(0, -MOVE_STEP);
        break;
        case 'a': case 'A':
            camera->move(1, MOVE_STEP);
        break;
        case 'd': case 'D':
            camera->move(1, -MOVE_STEP);
        break;

        case 'r': case 'R':
            camera->move(2, MOVE_STEP);
        break;
        case 'f': case 'F':
            camera->move(2, -MOVE_STEP);
        break;

        case 'q': case 'Q':
            camera->rotate(OX, 2);
            break;
        case 'e': case 'E':
            camera->rotate(OX, -2);
            break;
        case 'z': case 'Z':
            camera->rotate(OY, 2);
            break;
        case 'c': case 'C':
            camera->rotate(OY, -2);
            break;
    }

    glutPostRedisplay();
}

void init ()
{    
    glPushAttrib(GL_ENABLE_BIT);
    glEnable (GL_TEXTURE_2D);
    //glEnable (GL_DEPTH_TEST);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);

    skybox = new Skybox ();
    terrain = new Terrain (10, 10);
    
    Math::init();

    camera = new Camera(0, 0, 0, 0, 0, -1, 0, 1, 0, 180);
    camera->setUp();
}

int main (int argc, char **argv) 
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    //glutInitDisplayMode (GLUT_DOUBLE);

    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (0, 0);
    
    glutCreateWindow ("OpenGL Vegetation");

    init();

    glutDisplayFunc (displayCallback);
    glutIdleFunc (displayCallback);
    glutReshapeFunc (reshapeCallback);
    glutKeyboardFunc (keyboardCallback);
    
    glutMainLoop ();
    
    return 0;
}