#include <GL/gl.h>
#include <GL/glut.h>

#include "Math.h"

#include "Camera.h"
#include <stdio.h>

Camera::Camera (float eye_x, float eye_y, float eye_z, float c_x, float c_y, float c_z, float up_x, float up_y, float up_z, int angle_)
{
	eye = makePoint (eye_x, eye_y, eye_z);
	center = makePoint (c_x, c_y, c_z);
	up = makePoint (up_x, up_y, up_z);
	angle = angle_;
	xRot = 180;
}

void Camera::setUp ()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
}

void Camera::rotate (Axis axis, int dir)
{	
	int _angle;

	switch (axis)
	{
		case OX:
			xRot += dir;
			
			if (xRot < 135)
			{
				xRot = 135;
			}

			if (xRot > 235)
			{
				xRot = 235;
			}

			_angle = xRot;
			break;
		case OY:
			angle += dir;
			if (angle < 0)
			{
				angle += 360;
			}
			else
				if (angle > 360)
				{
					angle -= 360;
				}
			_angle = angle;
			break;
		case OZ:
			break;
	}

	float *newCenter = Math::rotateAbout(eye.x, eye.y, eye.z, center.x, center.y, center.z, _angle, (int) axis);

	center.x = newCenter[0];
	center.y = newCenter[1];
	center.z = newCenter[2];

	free(newCenter);


	setUp();
}

void Camera::move (int type, float step)
{
	int _angle;

	switch (type)
	{
		case 0:
			float dx, dz;
			dx = Math::advanceX(angle, step);
			dz = Math::advanceZ(angle, step);

			eye.x += dx;
			eye.z += dz;

			center.x += dx;
			center.z += dz;
			break;
		case 1:
			_angle = angle + 90;

			if (_angle < 0)
			{
				_angle += 360;
			}
			else
			{
				if (_angle > 360)
				{
					angle -= 360;
				}
			}
		
			dx = Math::advanceX (_angle, step);
			dz = Math::advanceZ (_angle, step);
			
			eye.x += dx;
			eye.z += dz;
			center.x += dx;
			center.z += dz;

			break;
		case 2:
			eye.y += step;
			center.y += step;
			break;
	}

	setUp();
}

Point Camera::getPosition()
{
	return eye;
}
