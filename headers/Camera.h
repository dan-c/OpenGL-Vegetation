#ifndef CAMERA_H
#define CAMERA_H

#include "misc.h"

class Camera
{
private:
	Point eye, center, up;
	int angle, xRot;

public:
	Camera(float eye_x, float eye_y, float eye_z, float c_x, float c_y, float c_z, float up_x, float up_y, float up_z, int angle_);
	
	void setUp();
	void rotate(Axis axis, int dir);
	void move(int type, float step);
	Point getPosition();
};

#endif