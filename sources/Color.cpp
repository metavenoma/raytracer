/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Color.cpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-04                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"

Color::Color(void) {}

Color::Color(float r, float g, float b) : Tuple(r, g, b, 0) {}

Color::~Color(void) {}

float	Color::r(void) const
{
	return (this->x());
}

float	Color::g(void) const
{
	return (this->y());
}

float	Color::b(void) const
{
	return (this->z());
}

Color Color::operator*(const Color o) {
  return Color(this->r() * o.r(), this->g() * o.g(), this->b() * o.b());
}

Color Color::operator*(float scalar) {
  return Color(this->r() * scalar, this->g() * scalar, this->b() * scalar);
}

Color Color::operator+(const Color o) {
  return Color(this->r() + o.r(), this->g() + o.g(), this->b() + o.b());
}

Color Color::operator-(const Color o) {
  return Color(this->r() - o.r(), this->g() - o.g(), this->b() - o.b());
}

std::ostream &operator<<(std::ostream &out, const Color &color)
{
	out << "(r: " << color.r() << ", g: " << color.g() \
		<< ", b: " << color.b() << ")" << std::endl;
	return (out);
}
