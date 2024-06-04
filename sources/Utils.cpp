/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Tuple_Op.cpp                                  ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-03                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"

bool	equal(float a, float b)
{
	return ((std::fabs(a - b) < EPSILON) ? true : false);
}

/*float	magnitude(Tuple &t)
{
	return(std::sqrt(t.x() * t.x() + t.y() * t.y()
				+ t.z() * t.z() + t.w() * t.w()));
}

Tuple	normalize(Tuple &v)
{
	return (Tuple(v.x() / magnitude(v), v.y() / magnitude(v), \
				v.z() / magnitude(v), v.w() / magnitude(v)));
}

float	dot(Tuple &v1, Tuple &v2)
{
	return (v1.x() * v2.x() + v1.y() * v2.y()
			+ v1.z() * v2.z() + v1.w() * v2.w());
}

Tuple	cross(Tuple &v1, Tuple &v2)
{
	return(Tuple(v1.y() * v2.z() - v1.z() * v2.y(), \
			v1.z() * v2.x() - v1.x() * v2.z(), \
			v1.x() * v2.y() - v1.y() * v2.x(), 0));
}*/

Projectile	tick(Projectile proj, Environment env)
{
	Tuple position = proj._position + proj._velocity;
	Tuple velocity = proj._velocity + env._gravity + env._wind;
	return (Projectile(position, velocity));
}

Color	hadamardProduct(Color c1, Color c2)
{
	return (Color(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b()));
}

void	canvasToPpm(Canvas c)
{
	std::ofstream	ppm("canvas.ppm");
	if (!ppm.is_open())
	{
		std::cerr << "File cannot be created" << std::endl;
		return ;
	}
	ppm << "P3" << std::endl;
	ppm << c.width() << " " << c.height() << std::endl;
	ppm << "255" << std::endl;
	for (int i = 0; i < c.height(); i++)
	{
		for (int j = 0; j < c.width(); j++)
		{
			ppm << c.pixelAt(i, j).r() << " " << \
				c.pixelAt(i, j).g() << " " << \
				c.pixelAt(i, j).b();
			if (j < c.width())
				ppm << " ";
		}
		ppm << std::endl;
	}
	ppm.close();
}
