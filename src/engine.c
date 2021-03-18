#include "shared.h"
#include "structs.h"

const float PI = 3.14159265359;


float deg2rad(float degree)
{
	if (degree < 0)
		return (degree + 360) * (PI / 180);
	else if (degree > 360)
		return (degree - 360) * (PI / 180);
	return degree * (PI / 180);
}

struct Vector normalizeVector(struct Vector vector)
{
	float d = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector.x /= d;
	vector.y /= d;
	return vector;
}

float calculateDistance(struct Vector origin, struct Vector destination)
{
	float dx = origin.x - destination.x;
	float dy = origin.y - destination.y;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void renderFrame(struct Camera camera, int map[MAP_HEIGHT][MAP_WIDTH], int screenWidth, int screenHeight, float raySpeedModifier)
{
	// init
	#include "graphics/init.h"
	int block;
	float slice = (float) camera.FOV / screenWidth;
	// render
	for (int rayN = 0; rayN < screenWidth; ++rayN)
	{
		// init rayPosition
		float rayDistance = 0;
		struct Vector rayPosition;
		rayPosition.x = camera.position.x;
		rayPosition.y = camera.position.y;
		// calculate rayVector
		struct Vector rayVector;
		float angle = deg2rad(rayN * slice + camera.angle);
		// printf("%f\n", angle);
		rayVector.x = cos(angle) * raySpeedModifier;
		rayVector.y = sin(angle) * raySpeedModifier;	
		// printf("%f %f\n", rayVector.x, rayVector.y);
		while ((map[(int) rayPosition.y][(int) rayPosition.x] == 0) && (rayDistance <= camera.renderDistance))
		{
			rayPosition.x += rayVector.x;
			rayPosition.y += rayVector.y;
			rayDistance += raySpeedModifier;
		}
		block = map[(int) rayPosition.y][(int) rayPosition.x];
		#include "graphics/draw.h"
	}
	#include "graphics/flip.h"
}

