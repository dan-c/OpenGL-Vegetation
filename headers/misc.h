#ifndef MISC_H
#define MISC_H

#define MOVE_STEP 0.025

typedef struct
{
	float x, y, z;
} Point;

enum Axis
{
	OX, OY, OZ
};

Point makePoint (float x, float y, float z);

#endif