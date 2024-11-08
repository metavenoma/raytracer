/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Canvas.cpp                                    ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-04                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"

Canvas::Canvas(int w, int h) : _width(w), _height(h)
{
	_data = (float*)calloc(sizeof(float), _width * _height * 3);
}

Canvas::~Canvas(void) {}

int	Canvas::width(void)
{
	return (_width);
}

int	Canvas::height(void)
{
	return (_height);
}

float	*Canvas::data(void)
{
	return (_data);
}

int	Canvas::pixelIndex(int x, int y)
{
	assert(x >= 0);
	//assert(x < _width);
	assert(y >= 0);
	//assert(y < _height);

	return ((x + y * _width));
}

Color	Canvas::pixelAt(int x, int y)
{
	int index = pixelIndex(x, y);
	float r = _data[index++];
	float g = _data[index++];
	float b = _data[index++];

	return (Color(r, g, b));
}

int	Canvas::getIntValue(float f)
{
	if (f < 0.0)
		f = 0.0;
	else if (f > 1.0)
		f = 1.0;
	return ((int)(f * 255.0));
}

void	Canvas::writePixel(Color c, int x, int y)
{
	int	index = pixelIndex(x, y);
	_data[index++] = c.r();
	_data[index++] = c.g();
	_data[index++] = c.b();
}
