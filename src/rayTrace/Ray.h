#pragma once
#include "headers.h"

namespace SDLRT
{
	class Ray
	{
		public:
			Ray() noexcept ;
			Ray(const glm::dvec3 &point1, const glm::dvec3&point2) noexcept;
			
			glm::dvec3 GetPoint1() const noexcept;
			glm::dvec3 GetPoint2() const noexcept;
			
		public:
			glm::dvec3 m_point1{};
			glm::dvec3 m_point2{};
			glm::dvec3 m_lab{};
			
	};
}
