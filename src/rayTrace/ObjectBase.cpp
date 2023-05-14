#include "ObjectBase.h"
#include <math.h>


// Function to test for intersections.
bool SDLRT::ObjectBase::TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, glm::dvec3 &localColor)
{
	return false;
}

// Function to test whether two floating-point numbers are close to being equal.
bool SDLRT::ObjectBase::CloseEnough(const double f1, const double f2)
{
	return fabs(f1 - f2) < EPSILON;
}
