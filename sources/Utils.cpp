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

Projectile	tick(const Projectile &proj, const Environment &env)
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
