#include "raytracer.h"

bool	equal(float a, float b)
{
	return ((std::fabs(a - b) < EPSILON) ? true : false);
}
