#pragma once
#include "Ray.h"
#include "Gtfm.h"

namespace SDLRT
{
	class ObjectBase
	{
		public:
			// Constructor and destructor.
			ObjectBase() noexcept = default;
			virtual ~ObjectBase() noexcept = default;
			
			// Function to test for intersections.
			virtual bool TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, glm::dvec3 &localColor);
			
			void SetTransformMatrix(const GTform& transformMatrix);
			// Function to test whether two floating-point numbers are close to being equal.
			bool CloseEnough(const double f1, const double f2);
			
		// Public member variables.
		public:
			// The base colour of the object.
			glm::dvec3 m_baseColor {};
			GTform m_transformMatrix;
	};
}
