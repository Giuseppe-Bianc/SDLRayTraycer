/* ***********************************************************
	lightbase.cpp
	
	The lightbase class implementation - A base class for all
	different types of light.
	
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

#include "LightBase.h"


// Function to compute illumination.
bool SDLRT::LightBase::ComputeIllumination(const glm::dvec3 &intPoint, const glm::dvec3&localNormal,
	const std::vector<std::shared_ptr<SDLRT::ObjectBase>> &objectList,
	const std::shared_ptr<SDLRT::ObjectBase> &currentObject,
	glm::dvec3 &color, double &intensity)
{
	return false;
}
