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
	_data = (int*)calloc(sizeof(int), _width * _height * 3);
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

int	*Canvas::data(void)
{
	return (_data);
}

int	Canvas::pixelIndex(int x, int y)
{
	/*assert(x >= 0);
	assert(x < _width);
	assert(y >= 0);
	assert(y < _height);*/

	return (3 * (x + y * _width));
}

Color	Canvas::pixelAt(int x, int y)
{
	int index = pixelIndex(x, y);
	float r = (float)_data[index++];
	float g = (float)_data[index++];
	float b = (float)_data[index++];

	return (Color(r, g, b));
}

int	Canvas::getIntValue(float f)
{
	if (f < 0)
		f = 0;
	else if (f > 1)
		f = 1;
	return ((int)(f * 255));
}

void	Canvas::writePixel(Color c, int x, int y)
{
	int	index = pixelIndex(x, y);
	_data[index++] = getIntValue(c.r());
	_data[index++] = getIntValue(c.g());
	_data[index++] = getIntValue(c.b());
}
