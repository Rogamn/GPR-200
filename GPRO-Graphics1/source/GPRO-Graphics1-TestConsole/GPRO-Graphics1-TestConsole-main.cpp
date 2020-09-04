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


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "gpro/gpro-math/gproVector.h"


void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}

using namespace std;

int main(int const argc, char const* const argv[])
{
	testVector();

	// Define image size
	const int IMAGE_HEIGHT = 256;
	const int IMAGE_WIDTH = 256;

	// Variable declarations
	float red, green, blue;
	int ired, igreen, iblue;

	// Guide says to output this
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
			// Get new RGB values
			red = float(j) / (IMAGE_WIDTH - 1);
			green = float(i) / (IMAGE_HEIGHT - 1);
			blue = 0.25;

			// Get values to output
			ired = static_cast<int>(255.999 * red);
			igreen = static_cast<int>(255.999 * green);
			iblue = static_cast<int>(255.999 * blue);

			// Output values
			cout << ired << ' ' << igreen << ' ' << iblue << '\n';
		}
	}
}
