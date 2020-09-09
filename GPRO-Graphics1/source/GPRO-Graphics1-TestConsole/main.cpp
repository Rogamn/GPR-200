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

// Guide says to have this
Vec3 color(Ray data)
{
	Vec3 direction = data.direction.unitVector(data.direction);

	double num = 0.5 * (direction.y + 1.0);

	return Vec3(1.0, 1.0, 1.0) * (1.0 - num) + Vec3(0.5, 0.7, 1.0) * num;
}

int main()
{
	// Define image size
	const double ASPECT_RATIO = 16.0 / 9.0;
	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

	// Camera definitions
	double viewportHeight = 2.0, focalLength = 1.0;
	double viewportWidth = ASPECT_RATIO * viewportHeight;

	Vec3 origin(0, 0, 0);
	Vec3 horizontal(IMAGE_WIDTH, 0, 0);
	Vec3 vertical(0, IMAGE_HEIGHT, 0);
	Vec3 lowerLeftCorner = origin - (horizontal / 2) - (vertical / 2) - Vec3(0, 0, focalLength);

	// File header
	cout << "P3\n" << IMAGE_HEIGHT << ' ' << IMAGE_WIDTH << "\n255\n";

	// Main printing loop
	// Column controller
	for (int i = IMAGE_HEIGHT - 1; i >= 0; --i)
	{
		// Progress indicator
		cerr << "\rScanlines remaining: " << i << ' ' << flush;

		// Row controller
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			double u = double(j) / (IMAGE_WIDTH - 1);
			double v = double(i) / (IMAGE_HEIGHT - 1);

			Ray ray(origin, lowerLeftCorner + (horizontal * u) + (vertical * v) - origin);
			Vec3 pixels = color(ray);
			pixels.writeColor(cout, pixels);
		}
	}

	return EXIT_SUCCESS;
}