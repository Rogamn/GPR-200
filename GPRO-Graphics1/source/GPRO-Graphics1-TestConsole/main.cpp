/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: Aaron Lurie
	Modified because: Assignment
*/

// Thanks to Peter Shirley for his guide @ https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class
// Thanks to Dan for the framework I am not using

// Necessary includes
#include "vec3.h"
#include "ray.h"
#include "hittable.h"
#include "Functions.h"

// Detects if sphere hit using quadratic formula
double sphereHit(Vec3 center, double radius, Ray ray)
{
	Vec3 oc = ray.origin - center;

	double a = lengthSquared(ray.direction);
	double b = dotProduct(oc, ray.direction);
	double c = lengthSquared(oc) - radius * radius;
	double discriminant = b * b - a * c;

	if (discriminant < 0)
	{
		return -1.0;
	}
	
	else
	{
		return(-b - sqrt(discriminant)) / a;
	}
}

// Color blender
Vec3 color(Ray ray)
{
	double num = sphereHit(Vec3(0, 0, -1), 0.5, ray);

	if (num > 0.0)
	{
		Vec3 temp = unitVector(ray.at(num) - Vec3(0, 0, -1));
		return Vec3(temp.x + 1, temp.y + 1, temp.z + 1) * .5;
	}

	Vec3 direction = unitVector(ray.direction);

	num = 0.5 * (direction.y + 1.0);

	return Vec3(1.0, 1.0, 1.0) * (1.0 - num) + Vec3(0.5, 0.7, 1.0) * num;
}

int main()
{
	// Define image size
	const double ASPECT_RATIO = 16.0 / 9.0;
	const int IMAGE_WIDTH = 400, IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

	// Camera definitions
	double viewportHeight = 2.0, focalLength = 1.0, viewportWidth = ASPECT_RATIO * viewportHeight, u, v;

	Vec3 origin(0, 0, 0), horizontal(IMAGE_WIDTH, 0, 0), vertical(0, IMAGE_HEIGHT, 0), 
		lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

	// File header
	cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

	// Main printing loop
	// Column controller
	for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
	{
		// Progress indicator
		cerr << "\rScanlines remaining: " << i << ' ' << flush;

		// Row controller
		for (int j = 0; j < IMAGE_WIDTH; ++j)
		{
			u = double(j) / (IMAGE_WIDTH - 1);
			v = double(i) / (IMAGE_HEIGHT - 1);

			Ray ray(origin, lowerLeftCorner + horizontal * u + vertical * v - origin);
			Vec3 pixels = color(ray);
			pixels.writeColor(cout, pixels);
		}
	}

	return EXIT_SUCCESS;
}