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
/*   Date: 2024-06-03                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"
#include "Tuple.hpp"

int	main(void)
{
	Tuple p = Tuple::point(2.0, 1.0, 3.0);
	Tuple v = Tuple::vector(3.0, 2.0, 1.0);

	std::cout <<
		"Point[x: " << p.getX() << ", y: " << p.getY()
		<< ", z: " << p.getZ() << ", w: " << p.getW()
		<< "]" << std::endl;
	std::cout <<
		"Vector[x: " << v.getX() << ", y: " << v.getY()
		<< ", z: " << v.getZ() << ", w: " << v.getW()
		<< "]" << std::endl;

	std::cout << equal(p.getX(), v.getY()) << std::endl;
	Tuple res = p + v;
	std::cout <<
		"p+v[x: " << res.getX() << ", y: " << res.getY()
		<< ", z: " << res.getZ() << ", w: " << res.getW()
		<< "]" << std::endl;
	res = p - v;
	std::cout <<
		"Vector[x: " << res.getX() << ", y: " << res.getY()
		<< ", z: " << res.getZ() << ", w: " << res.getW()
		<< "]" << std::endl;
	Tuple neg = -v;
	std::cout <<
		"-Vector[x: " << neg.getX() << ", y: " << neg.getY()
		<< ", z: " << neg.getZ() << ", w: " << neg.getW()
		<< "]" << std::endl;
	Tuple mul = v * 3.5;
	std::cout <<
		"Vector[x: " << mul.getX() << ", y: " << mul.getY()
		<< ", z: " << mul.getZ() << ", w: " << mul.getW()
		<< "]" << std::endl;
	Tuple div = v / 2;
	std::cout <<
		"Vector[x: " << div.getX() << ", y: " << div.getY()
		<< ", z: " << div.getZ() << ", w: " << div.getW()
		<< "]" << std::endl;
	Tuple mag = Tuple::vector(0, 1.0, 0);
	std::cout << "Magnitude of v: " << magnitude(mag) << std::endl;
	Tuple vn = Tuple::vector(4, 0, 0);
	Tuple norm = normalize(vn);
	std::cout <<
		"Norm[x: " << norm.getX() << ", y: " << norm.getY()
		<< ", z: " << norm.getZ() << ", w: " << norm.getW()
		<< "]" << std::endl;
	std::cout << "Magnitude of norm: " << magnitude(norm) << std::endl;
	Tuple v1 = Tuple::vector(1, 2, 3);
	Tuple v2 = Tuple::vector(2, 3, 4);
	std::cout << "Dot product of v1 and v2: " << dot(v1, v2) << std::endl;
	Tuple cross1 = cross(v1, v2);
	Tuple cross2 = cross(v2, v1);
	std::cout <<
		"Cross1[x: " << cross1.getX() << ", y: " << cross1.getY()
		<< ", z: " << cross1.getZ() << ", w: " << cross1.getW()
		<< "]" << std::endl;
	std::cout <<
		"Cross2[x: " << cross2.getX() << ", y: " << cross2.getY()
		<< ", z: " << cross2.getZ() << ", w: " << cross2.getW()
		<< "]" << std::endl;
	return (0);
}

