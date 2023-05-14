#pragma once
#include "headers.h"
#include "ObjectBase.h"

namespace SDLRT
{
	class ObjSphere : public ObjectBase
	{
		public:
			/* The default constructor.
				Note that this will define a unit sphere at the origin. */
			ObjSphere() noexcept = default;
			
			// Override the destructor.
			virtual ~ObjSphere() noexcept override = default;
			
			// Override the function to test for intersections.
			virtual bool TestIntersection(const SDLRT::Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, glm::dvec3 &localColor);
			
		private:
		
		
	};
}
