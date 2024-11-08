#include "raytracer.h"

Color	hadamardProduct(Color c1, Color c2)
{
	return (Color(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b()));
}
