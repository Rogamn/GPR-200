// Thanks to Peter Shirley for his guide @ https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class
// Thanks to Dan for the framework I am not using

// Header magic
#pragma once

// Necessary includes
#include <iostream>
#include <cmath>

// namespace declaration
using namespace std;

// Vec3 struct
struct Vec3
{
	// Member variables
	double x, y, z;

	// Default constructors
	Vec3()
		{
			x = y = z = 0.0;
		}

	// Alternate constructor
	Vec3(double newX, double newY, double newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}

	// Function used to output colors
	void writeColor(ostream& output, Vec3 color)
	{
		output << static_cast<int>(255.99 * color.x) << ' ' << static_cast<int>(255.99 * color.y) << ' ' << static_cast<int>(255.99 * color.z) << '\n';
	}

	// Overloaded + operator
	Vec3 operator+(Vec3 rhs)
		{
			return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
		}

	// Overloaded - operator
	Vec3 operator-(Vec3 rhs)
		{
			return Vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
		}

	// Overloaded * operator
	Vec3 operator*(Vec3 rhs)
		{
			return Vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
		}

	// Overloaded * operator again
	Vec3 operator*(double num)
	{
		return Vec3(this->x * num, this->y * num, this->z * num);
	}

	// Overloaded / operator 
	Vec3 operator/(double num)
	{
		return Vec3(this-> x / num, this->y / num, this->z / num);
	}
};