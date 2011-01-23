#ifndef MATH_H
#define MATH_H

#include <GL/gl.h>

#define PI 3.141592653589793238462
#define RAD PI / 180
#define _RAD 180 / PI

class Math
{
	public:
		static double SIN[360], COS[360];

		static void init ();
		static double degToRad(double deg);
		static double radToDeg(double rad);
		static GLfloat advanceX(int angle, GLfloat stepSize);
		static GLfloat advanceZ(int angle, GLfloat stepSize);
		static float *rotateAbout(float cX, float cY, float cZ, float pX, float pY, float pZ, int angle, int axis);
};

#endif