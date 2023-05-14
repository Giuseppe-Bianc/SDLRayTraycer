/* ***********************************************************
	ray.hpp
	
	The ray class implementation - A class to handle rays that can
	be cast around the scene.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 2 of the series,
	which may be found here:
	https://youtu.be/KBK6g6RFgdA
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

// ray.cpp

#include "Ray.h"

SDLRT::Ray::Ray() noexcept {
	m_point1 = {0.0, 0.0, 0.0};
	m_point2 = {0.0, 0.0, 1.0};
	m_lab = m_point2 - m_point1;
}

SDLRT::Ray::Ray(const glm::dvec3 &point1, const glm::dvec3&point2) noexcept
{
	m_point1 = point1;
	m_point2 = point2;
	m_lab = m_point2 - m_point1;
}

glm::dvec3 SDLRT::Ray::GetPoint1() const noexcept
{
	return m_point1;
}

glm::dvec3 SDLRT::Ray::GetPoint2() const noexcept
{
	return m_point2;
}
