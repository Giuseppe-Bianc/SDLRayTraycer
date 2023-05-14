/* ***********************************************************
	pointlight.cpp
	
	The pointlight class implementation - A class to implement
	a very simple point light source.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 4 of the series,
	which may be found here:
	https://youtu.be/dUtkihuUvvo
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

#include "PointLight.h"

// Default constructor.
SDLRT::PointLight::PointLight() noexcept
{
	m_color = {1.0, 1.0, 1.0};
	m_intensity = 1.0;
}

// Function to compute illumination.
bool SDLRT::PointLight::ComputeIllumination(const glm::dvec3 &intPoint, const glm::dvec3 &localNormal,
	const std::vector<std::shared_ptr<SDLRT::ObjectBase>> &objectList,
	const std::shared_ptr<SDLRT::ObjectBase> &currentObject,
	glm::dvec3 &color, double &intensity) {
	// Construct a vector pointing from the intersection point to the light.
	glm::dvec3 lightDir = glm::normalize(m_location - intPoint);
	
	// Compute a starting point.
	glm::dvec3 startPoint = intPoint;
	
	// Compute the angle between the local normal and the light ray.
	// Note that we assume that localNormal is a unit vector.
	double angle = acos(glm::dot(localNormal, lightDir));
	
	// If the normal is pointing away from the light, then we have no illumination.
	color = m_color;
	double half_Pi = glm::half_pi<double>();
	if (angle > half_Pi){
		intensity = 0.0;
		return false;
	} else{
		// We do have illumination.
		intensity = m_intensity * (1.0 - (angle / half_Pi));
	}
	
	return true;
}
