// Thanks to Peter Shirley for his guide @ https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class
// Thanks to Dan for the framework I am not using

// Header magic
#pragma once

// Necessary include
#include "vec3.h"

// Ray struct 
struct Ray
{
	// Member variables
	Vec3 origin, direction;

	// Default constructor
	Ray() {}

	// Alternate constructor
	Ray(Vec3 newOrigin, Vec3 newDirection)
	{
		origin = newOrigin;
		direction = newDirection;
	}

	// Guide included this function
	Vec3 at(double num)
	{
		Vec3 temp(direction.x * num, direction.y * num, direction.z * num);

		return origin + temp;
	}
};