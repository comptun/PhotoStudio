#include "Utilities.h"

namespace glm
{
	glm::vec3 lerp(glm::vec3 x, glm::vec3 y, float t) {
		return x * (1.f - t) + y * t;
	}
}