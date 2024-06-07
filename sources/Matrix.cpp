/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Matrix.cpp                                    ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-05                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"
#include <cstddef>

Matrix::Matrix(void) : _size(4)
{
	_matrix = new float*[_size];
	for (int i = 0; i < _size; i++)
		_matrix[i] = new float[_size];
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_matrix[i][j] = 0.0;
		}
	}
}

Matrix::Matrix(int size) : _size(size)
{
	_matrix = new float*[_size];
	for (int i = 0; i < _size; i++)
		_matrix[i] = new float[_size];
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < size; j++)
			_matrix[i][j] = 2.0;
	}
}

Matrix::~Matrix(void) 
{
	for (int i = 0; i < _size; i++)
		delete[] _matrix[i];
	delete[] _matrix;
}

float	**Matrix::getMatrix(void) const
{
	return (_matrix);
}

int	Matrix::getSize(void) const
{
	return (_size);
}

void	Matrix::set(float value, int rol, int col)
{
	_matrix[rol][col] = value;
}

bool	Matrix::operator==(const Matrix &m)
{
	if (this->_size != m._size)
		return (false);
	for (int i = 0; i < m._size; i++)
	{
		for (int j = 0; j < m._size; j++)
		{
			if (!equal(this->_matrix[i][j], m._matrix[i][j]))
				return (false);
		}
	}
	return (true);
}

bool	Matrix::operator!=(const Matrix &m)
{
	if (this->_size != m._size)
		return (true);
	for (int i = 0; i < m._size; i++)
	{
		for (int j = 0; j < m._size; j++)
		{
			if (!equal(this->_matrix[i][j], m._matrix[i][j]))
				return (true);
		}
	}
	return (false);
}

float	Matrix::operator()(const int &row, const int &col) const
{
	return (_matrix[row][col]);
}

const Matrix	Matrix::operator*(const Matrix &m)
{
	std::cout << "hi";
	if (this->_size != m.getSize())
	{
		std::cerr << "Matrices are different sizes" << std::endl;
		return (m);
	}
	Matrix	res = Matrix(m.getSize());
	float	value;
	for (int i = 0; i < m.getSize(); i++)
	{
		for (int j = 0; j < m.getSize(); j++)
		{
			value = 0.0;
			std::cout << value;
			for (int k = 0; k < m._size; k++)
				value += this->_matrix[i][k] * m(k, j);
			std::cout << value;
			res.set(value, i, j);
		}
	}
	return (res);
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
	float **matrix = m.getMatrix();
	int	size = m.getSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
				out << "| ";
			out << matrix[i][j] << " | ";
			if (j == size - 1)
				out << "\n";
		}
	}
	return (out);
}
