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
		float	_x;
		float	_y;
		float	_z;
		float	_w;
	public:
		Tuple(void);
		Tuple(float x, float y, float z, float w);
		Tuple(const Tuple &t);

		~Tuple(void);

		Tuple	&operator=(const Tuple &t);
		bool	operator==(const Tuple &t) const;
		Tuple	operator+(const Tuple &t) const;
		Tuple	operator-(const Tuple &t) const;
		Tuple	operator-(void) const;
		Tuple	operator*(float scalar) const;
		Tuple	operator/(float scalar) const;

		static Tuple point(float x, float y, float z);
		static Tuple vector(float x, float y, float z);

		float	x(void) const;
		float	y(void) const;
		float	z(void) const;
		float	w(void) const;

		bool	isPoint(void) const;
		bool	isVector(void) const;
		
		float	magnitude(void) const;
		Tuple	normalized(void) const;
		float	dot(Tuple other) const;
		Tuple	cross(Tuple other) const;
};
std::ostream &operator<<(std::ostream &out, const Tuple &tuple);
