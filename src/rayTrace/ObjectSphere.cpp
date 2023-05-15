#include "ObjectSphere.h"
#include <cmath>

// Function to test for intersections.
bool SDLRT::ObjSphere::TestIntersection(const SDLRT::Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, glm::dvec3 &localColor) {
	Ray bck = m_transformMatrix.Apply(castRay, SDLRT
	::BCKTF);
	// Compute the values of a, b and c.
	glm::dvec3 vhat = bck.m_lab;
	vhat = glm::normalize(vhat);
	
	/* Note that a is equal to the squared magnitude of the
		direction of the cast ray. As this will be a unit vector,
		we can conclude that the value of 'a' will always be 1. */
	// a = 1.0;
	
	// Calculate b.
	double b = 2.0 * glm::dot(bck.m_point1, vhat);
	
	// Calculate c.
	double c = glm::dot(bck.m_point1, bck.m_point1) - 1.0;
	
	// Test whether we actually have an intersection.
	double intTest = (b*b) - 4.0 * c;
	glm::dvec3 poi{};
	if (intTest > 0.0) {
		double numSQRT = sqrt(intTest);
		double t1 = (-b + numSQRT) / 2.0;
		double t2 = (-b - numSQRT) / 2.0;
		
		/* If either t1 or t2 are negative, then at least part of the object is
			behind the camera and so we will ignore it. */
		if ((t1 < 0.0) || (t2 < 0.0)) {
			return false;
		} else {
			// Determine which point of intersection was closest to the camera.
			if (t1 < t2) {
				poi = bck.m_point1 + (vhat * t1);
			} else {
				poi = bck.m_point1 + (vhat * t2);
			}

			intPoint = m_transformMatrix.Apply(poi, SDLRT::FWDTF);
			
			// Compute the local normal (easy for a sphere at the origin!).
			glm::dvec3 objOrigin{};
			glm::dvec3 newObjOrigin = m_transformMatrix.Apply(objOrigin, SDLRT::FWDTF);
			localNormal = intPoint - newObjOrigin;
			localNormal = glm::normalize(localNormal);
			localColor = m_baseColor;
		}
		
		return true;
	}
	else
	{
		return false;
	}
	
}
