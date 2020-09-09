#pragma once

#include "vec3.h"

void writeColor(ostream& output, Vec3 color)
{
	output << static_cast<int>(color.x) << ' ' << static_cast<int>(color.y) << ' ' << static_cast<int>(color.z) << '\n';
}