#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Math.h"

double Math::SIN[360];
double Math::COS[360];

void Math::init ()
{
	for (int i = 0; i < 360; i++)
	{
		SIN[i] = sin(i * RAD);
		COS[i] = cos(i * RAD);
	}
}

double Math::degToRad(double deg)
{
	return deg * RAD;
}

double Math::radToDeg(double rad)
{
	return rad * _RAD;
}

GLfloat Math::advanceX(int angle, GLfloat stepSize)
{
		float advance = 0;
		int posAngle = angle;

		if (angle < 0)
		{
			posAngle = 360 + angle;
		}

		if (posAngle < 0 && posAngle >= 360)
		{
			printf("dezastru la X\n");
		}

		advance = SIN[posAngle];

		return advance * stepSize;
}

GLfloat Math::advanceZ(int angle, GLfloat stepSize)
{
	float advance = 0;
	int posAngle = angle;

	if (angle < 0)
	{
		posAngle = 360 + angle;
	}
	if (posAngle < 0 && posAngle >= 360)
	{
		printf("dezastru la Z\n");
	}

	advance = COS[posAngle];

	return advance * stepSize;
}

float * Math::rotateAbout(float cX, float cY, float cZ, float pX, float pY, float pZ, int angle, int axis)
{

	float *newPoint = (float*) malloc(3 * sizeof(float));

	double delta1, delta2;
	float r1 = sqrt((cX - pX) * (cX - pX) + (cZ - pZ) * (cZ - pZ)),
		r = sqrt((cX - pX) * (cX - pX) + (cY - pY) * (cY - pY) + (cZ - pZ) * (cZ - pZ));

	newPoint[0] = pX;
	newPoint[1] = pY;
	newPoint[2] = pZ;

	delta1 = Math::COS[angle];
	delta2 = Math::SIN[angle];

	switch (axis)
	{
		case 0:
			newPoint[1] = cY + r * delta2;
			break;
		case 1:
			newPoint[0] = cX + r1 * delta2;
			newPoint[2] = cZ + r1 * delta1;
			break;
		case 2:
			break;
	}

	return newPoint;
}