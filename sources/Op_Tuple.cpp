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

bool	equal(double a, double b)
{
	return ((std::fabs(a - b) < EPSILON) ? true : false);
}

double	magnitude(Tuple &t)
{
	return(std::sqrt(t.getX() * t.getX() + t.getY() * t.getY()
				+ t.getZ() * t.getZ() + t.getW() * t.getW()));
}

Tuple	normalize(Tuple &v)
{
	return (Tuple(v.getX() / magnitude(v), v.getY() / magnitude(v), \
				v.getZ() / magnitude(v), v.getW() / magnitude(v)));
}

double	dot(Tuple &v1, Tuple &v2)
{
	return (v1.getX() * v2.getX() + v1.getY() * v2.getY()
			+ v1.getZ() * v2.getZ() + v1.getW() * v2.getW());
}

Tuple	cross(Tuple &v1, Tuple &v2)
{
	return(Tuple(v1.getY() * v2.getZ() - v1.getZ() * v2.getY(), \
			v1.getZ() * v2.getX() - v1.getX() * v2.getZ(), \
			v1.getX() * v2.getY() - v1.getY() * v2.getX(), 0));
}
