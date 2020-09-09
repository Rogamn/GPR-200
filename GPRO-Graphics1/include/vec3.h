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
		output << static_cast<int>(color.x) << ' ' << static_cast<int>(color.y) << ' ' << static_cast<int>(color.z) << '\n';
	}

	// Function to find unit vector
	Vec3 unitVector(Vec3 vector)
	{
		return vector / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	}

	// Overloaded + operator
	Vec3 operator+(Vec3 rhs)
		{
			Vec3 temp;

			temp.x += rhs.x;
			temp.y += rhs.y;
			temp.z += rhs.z;

			return temp;
		}

	// Overloaded - operator
	Vec3 operator-(Vec3 rhs)
		{
			Vec3 temp;

			temp.x -= rhs.x;
			temp.y -= rhs.y;
			temp.z -= rhs.z;

			return temp;
		}

	// Overloaded * operator
	Vec3 operator*(Vec3 rhs)
		{
			Vec3 temp;

			temp.x *= rhs.x;
			temp.y *= rhs.y;
			temp.z *= rhs.z;

			return temp;
		}

	// Overloaded * operator again
	Vec3 operator*(double num)
	{
		Vec3 temp(num * this->x, num * this->y, num * this->z);

		return temp;
	}

	// Overloaded / operator 
	Vec3 operator/(double num)
	{
		double tempDoub = (1 / num);
		Vec3 tempVec( this-> x * tempDoub, this->y * tempDoub, this->z * tempDoub);

		return tempVec;
	}

	// Overloaded << operator
	friend ostream& operator<<(ostream& output, Vec3& data);
};

// Overloaded << operator
ostream& operator<<(ostream& output, Vec3& data)
{
	output << data.x << ' ' << data.y << ' ' << data.z;

	return output;
}