// Thanks to Peter Shirley for his guide @ https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class
// Thanks to Dan for the framework I am not using

// Header magic
#pragma once

// Necessary include
#include "ray.h"
#include "Functions.h"

// Struct used to record hits
struct Hit_Record
{
	// Member variables
	Vec3 point, normal;
	double num;
};

// Parent hittable class
class Hittable
{
	public:
		// Function to check if hit
		virtual bool hit(Ray& ray, double min, double max, Hit_Record& record) const = 0;
};

// Child sphere class
class Sphere : public Hittable
{
	public:
		// Member variables
		Vec3 center;
		double radius;

		// Default constructor
		Sphere()
		{
			radius = 0.0;
		}

		// Alternate constructor
		Sphere(Vec3 cent, double rad) : center(cent), radius(rad) {};

		// Function to check if hit
		virtual bool hit(Ray& ray, double min, double max, Hit_Record& record) const override
		{
			// Quadratic formula
			Vec3 oc = ray.origin - center;
			double a = lengthSquared(ray.direction);
			double b = dotProduct(oc, ray.direction);
			double c = lengthSquared(oc) - radius * radius;
			double discriminant = b * b - a * c;

			if (discriminant > 0) 
			{
				double root = sqrt(discriminant);

				// Check -
				double temp = (-b - root) / a;
				if (temp < max && temp > min) 
				{
					record.num = temp;
					record.point = ray.at(record.num);
					record.normal = (record.point - center) / radius;
					return true;
				}

				// Check +
				temp = (-b + root) / a;
				if (temp < max && temp > min) 
				{
					record.num = temp;
					record.point = ray.at(record.num);
					record.normal = (record.point - center) / radius;
					return true;
				}
			}

			return false;
		}
};