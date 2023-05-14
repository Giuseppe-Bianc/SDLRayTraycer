#pragma once
#include "headers.h"
#include "LightBase.h"
namespace SDLRT
{
	class PointLight : public LightBase
	{
		public:
			// The default constructor.
			PointLight() noexcept;
			
			// Override the default destructor.
			virtual ~PointLight() noexcept override = default;
			
			// Function to compute illumination.
			virtual bool ComputeIllumination(const glm::dvec3 &intPoint, const glm::dvec3 &localNormal,
				const std::vector<std::shared_ptr<SDLRT::ObjectBase>> &objectList,
				const std::shared_ptr<SDLRT::ObjectBase> &currentObject,
				glm::dvec3 &color, double &intensity) override;
	};
}
