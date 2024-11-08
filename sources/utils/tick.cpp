#include "raytracer.h"

Projectile	tick(const Projectile &proj, const Environment &env)
{
	Tuple position = proj._position + proj._velocity;
	Tuple velocity = proj._velocity + env._gravity + env._wind;
	return (Projectile(position, velocity));
}
