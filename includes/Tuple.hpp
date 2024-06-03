/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Tuple.hpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-03                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once 

class Tuple
{
	private:
		double	_x;
		double	_y;
		double	_z;
		double	_w;
	public:
		Tuple(void);
		Tuple(double x, double y, double z, double w);
		Tuple(const Tuple &t);

		~Tuple(void);

		Tuple	&operator=(const Tuple &t);
		Tuple	operator+(const Tuple &t);
		Tuple	operator-(const Tuple &t);
		Tuple	operator-(void);
		Tuple	operator*(double scalar);
		Tuple	operator/(double scalar);

		static Tuple point(double x, double y, double z);
		static Tuple vector(double x, double y, double z);

		double	getX(void);
		double	getY(void);
		double	getZ(void);
		double	getW(void);
};
