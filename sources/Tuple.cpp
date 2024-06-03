/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Tuple.cpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-03                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Tuple.hpp"

Tuple::Tuple(void) : _x(0), _y(0), _z(0), _w(0) {}

Tuple::Tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) {}

Tuple::Tuple(const Tuple &t) : _x(t._x), _y(t._y), _z(t._z), _w(t._w) {}

Tuple::~Tuple(void) {}

Tuple &Tuple::operator=(const Tuple &t)
{
	if (this != &t)
	{
		_x = t._x;
		_y = t._y;
		_z = t._z;
		_w = t._w;
	}
	return (*this);
}

Tuple	Tuple::operator+(const Tuple &t)
{
	return (Tuple(t._x + _x, t._y + _y, t._z + _z, t._w + _w));
}

Tuple	Tuple::operator-(const Tuple &t)
{
	return (Tuple(_x - t._x, _y - t._y, _z - t._z, _w - t._w));
}

Tuple	Tuple::operator-(void)
{
	return (Tuple(-_x, -_y, -_z, -_w));
}

Tuple	Tuple::operator*(double scalar)
{
	return (Tuple(_x * scalar, _y * scalar, _z * scalar, _w * scalar));
}

Tuple	Tuple::operator/(double scalar)
{
	return (Tuple(_x / scalar, _y / scalar, _z / scalar, _w / scalar));
}

double	Tuple::getX(void)
{
	return (_x);
}

double	Tuple::getY(void)
{
	return (_y);
}

double	Tuple::getZ(void)
{
	return (_z);
}

double	Tuple::getW(void)
{
	return (_w);
}

Tuple	Tuple::point(double x, double y, double z)
{
	return (Tuple(x, y, z, 1));
}

Tuple	Tuple::vector(double x, double y, double z)
{
	return (Tuple(x, y, z, 0));
}
