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

#include "raytracer.h"

Tuple::Tuple(void) : _x(0), _y(0), _z(0), _w(0) {}

Tuple::Tuple(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w) {}

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

bool	Tuple::operator==(const Tuple &t) const
{
	return (equal(_x, t.x()) && equal(_y, t.y()) && equal(_z, t.z()) && equal(_w, t.w()));
}

Tuple	Tuple::operator+(const Tuple &t) const
{
	return (Tuple(t._x + _x, t._y + _y, t._z + _z, t._w + _w));
}

Tuple	Tuple::operator-(const Tuple &t) const
{
	return (Tuple(_x - t._x, _y - t._y, _z - t._z, _w - t._w));
}

Tuple	Tuple::operator-(void) const
{
	return (Tuple(-_x, -_y, -_z, -_w));
}

Tuple	Tuple::operator*(float scalar) const
{
	return (Tuple(_x * scalar, _y * scalar, _z * scalar, _w * scalar));
}

Tuple	Tuple::operator/(float scalar) const
{
	return (Tuple(_x / scalar, _y / scalar, _z / scalar, _w / scalar));
}

float	Tuple::x(void) const
{
	return (_x);
}

float	Tuple::y(void) const
{
	return (_y);
}

float	Tuple::z(void) const
{
	return (_z);
}

float	Tuple::w(void) const
{
	return (_w);
}

Tuple	Tuple::point(float x, float y, float z)
{
	return (Tuple(x, y, z, 1));
}

Tuple	Tuple::vector(float x, float y, float z)
{
	return (Tuple(x, y, z, 0));
}

bool	Tuple::isPoint(void) const
{
	return (equal(1.0, _w));
}

bool	Tuple::isVector(void) const
{
	return (equal(0.0, _w));
}

float	Tuple::magnitude(void) const
{
	return (std::sqrt(this->x() * this->x() + this->y() * this->y()
				+ this->z() * this->z() + this->w() * this->w()));
}

Tuple	Tuple::normalized(void) const
{
	float	mag = this->magnitude();
	return (Tuple(this->x() / mag, this->y() / mag, \
			this->z() / mag, this->w() / mag));
}

float	Tuple::dot(Tuple other) const
{
	return (this->x() * other.x() + this->y() * other.y()
		+ this->z() * other.z() + this->w() * other.w());
}

Tuple	Tuple::cross(Tuple other) const
{
	return (Tuple(this->y() * other.z() - this->z() * other.y(), \
			this->z() * other.x() - this->x() * other.z(), \
			this->x() * other.y() - this->y() * other.x(), 0));
}

std::ostream &operator<<(std::ostream &out, const Tuple &tuple)
{
	out << "(x: " << tuple.x() << ", y: " << tuple.y() \
		<< ", z: " << tuple.z() << ", w: " << tuple.w() \
		<< ")" << std::endl;
	return (out);
}
