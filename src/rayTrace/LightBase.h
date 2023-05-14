#pragma once
#include "headers.h"
#include "Ray.h"
#include "ObjectBase.h"

namespace SDLRT
{
	class LightBase
	{
		public:
			// Constructor / destructor.
			LightBase() noexcept = default;
			virtual ~LightBase() noexcept = default;
			
			// Function to compute illumination contribution.
			virtual bool ComputeIllumination(const glm::dvec3 &intPoint, const glm::dvec3&localNormal,
				const std::vector<std::shared_ptr<SDLRT::ObjectBase>> &objectList,
				const std::shared_ptr<SDLRT::ObjectBase> &currentObject,
				glm::dvec3 &color, double &intensity);
		public:
			glm::dvec3 m_color{};
			glm::dvec3 m_location{};
			double m_intensity =0.0;
	};
}
