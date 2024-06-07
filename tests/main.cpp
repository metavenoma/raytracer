/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          main.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-04                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"

int	main(void)
{
	Color c1 = Color(0.9, 0.6, 0.75);
	Color c2 = Color(0.7, 0.1, 0.25);
		
	Color sum = c1 + c2;

	std::cout << sum;

	Color hp = hadamardProduct(c1, c2);

	std::cout << hp;

	/*Canvas	canvas = Canvas(900, 550);
	Color	red = Color(1, 0, 0);
	Tuple start = Tuple::point(0, 1, 0);
	Tuple vel = Tuple::vector(1, 1.8, 0);
	Tuple velocity = vel.normalized() * 11.25;
	Projectile p = Projectile(start, velocity);
	Tuple gravity = Tuple::vector(0, -0.1, 0);
	Tuple wind = Tuple::vector(-0.01, 0, 0);
	Environment e = Environment(gravity, wind);
	while (p._position.y() > 0)
	{
		canvas.writePixel(red, 900 - p._position.x(), 550 - p._position.y());
		p = tick(p, e);
	}
	canvasToPpm(canvas);*/
	Matrix	m = Matrix(4);
	Matrix	m1 = Matrix(3);
	Matrix	m2 = Matrix(4);
	Matrix	m3 = Matrix(5);
	std::cout << m << m1 << m2 << m3;
	Matrix m4 = Matrix(2);
	if (m == m4)
		std::cout << "m == m4" << std::endl;
	else
		std::cout << "m != m4" << std::endl;
	if (m != m1)
		std::cout << "m != m1" << std::endl;
	else	
		std::cout << "m == m1" << std::endl;
	Matrix m5 = m * m2;
	std::cout << m5 << std::endl;
}
