// Thanks to Peter Shirley for his guide @ https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class
// Thanks to Dan for the framework I am not using

// Header magic
#pragma once

// Necessary includes
#include "vec3.h"

// Function, squares each member of vector and adds together
double lengthSquared(Vec3 vector)
{
	return (vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z);
}

// Function to find dot product
double dotProduct(Vec3 lhs, Vec3 rhs)
{
	return (lhs.x * rhs.x + lhs.y * rhs.y + rhs.z * lhs.z);
}

// Function to find unit vector
Vec3 unitVector(Vec3 vector)
{
	return vector / sqrt(lengthSquared(vector));
}