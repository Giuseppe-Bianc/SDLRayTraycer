/* ***********************************************************
	camera.hpp
	
	The camera class implementation - A class to handle the camera
	and compute camera geometry.
	
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

// camera.cpp

#include "Camera.h"
#include "Ray.h"
#include <math.h>

SDLRT::Camera::Camera() noexcept {
	// The default constructor.
	m_cameraPosition = {0.0, -10.0, 0.0};
	m_cameraLookAt = {0.0, 0.0, 0.0};
	m_cameraUp = {0.0, 0.0, 1.0};
	m_cameraLength = 1.0;
	m_cameraHorzSize = 1.0;
	m_cameraAspectRatio = 1.0;
}

void SDLRT::Camera::SetPosition(const glm::dvec3 &newPosition) noexcept
{
	m_cameraPosition = newPosition;
}

void SDLRT::Camera::SetLookAt(const glm::dvec3 &newLookAt) noexcept
{
	m_cameraLookAt = newLookAt;
}

void SDLRT::Camera::SetUp(const glm::dvec3 &upVector) noexcept
{
	m_cameraUp = upVector;
}

void SDLRT::Camera::SetLength(double newLength) noexcept
{
	m_cameraLength = newLength;
}

void SDLRT::Camera::SetHorzSize(double newHorzSize) noexcept
{
	m_cameraHorzSize = newHorzSize;
}

void SDLRT::Camera::SetAspect(double newAspect) noexcept
{
	m_cameraAspectRatio = newAspect;
}

// Method to return the position of the camera.
glm::dvec3 SDLRT::Camera::GetPosition() noexcept
{
	return m_cameraPosition;
}

// Method to return the LookAt of the camera.
glm::dvec3 SDLRT::Camera::GetLookAt() noexcept
{
	return m_cameraLookAt;
}

// Method to return the up vector of the camera.
glm::dvec3 SDLRT::Camera::GetUp() noexcept
{
	return m_cameraUp;
}

// Method to return the length of the camera.
double SDLRT::Camera::GetLength() noexcept
{
	return m_cameraLength;
}

// Method to return the horizontal size.
double SDLRT::Camera::GetHorzSize() noexcept
{
	return m_cameraHorzSize;
}

// Method to return the camera aspect ratio.
double SDLRT::Camera::GetAspect() noexcept
{
	return m_cameraAspectRatio;
}

// Method to return the U vector.
glm::dvec3 SDLRT::Camera::GetU() noexcept
{
	return m_projectionScreenU;
}

// Method to return the V vector.
glm::dvec3 SDLRT::Camera::GetV() noexcept
{
	return m_projectionScreenV;
}

// Method to return the projection screen centre.
glm::dvec3 SDLRT::Camera::GetScreenCentre() noexcept
{
	return m_projectionScreenCentre;
}

// Function to compute camera geometry.
void SDLRT::Camera::UpdateCameraGeometry()
{
	// First, compute the vector from the camera position to the LookAt position.
	m_alignmentVector = m_cameraLookAt - m_cameraPosition;
	m_alignmentVector = glm::normalize(m_alignmentVector);
	
	// Second, compute the U and V vectors.
	m_projectionScreenU = glm::cross(m_alignmentVector, m_cameraUp);
	m_projectionScreenU = glm::normalize(m_projectionScreenU);
	m_projectionScreenV = glm::cross(m_projectionScreenU, m_alignmentVector);
	m_projectionScreenV = glm::normalize(m_projectionScreenV);
	// Thirdly, compute the positon of the centre point of the screen.
	m_projectionScreenCentre = m_cameraPosition + (m_cameraLength * m_alignmentVector);
	
	// Modify the U and V vectors to match the size and aspect ratio.
	m_projectionScreenU = m_projectionScreenU * m_cameraHorzSize;
	m_projectionScreenV = m_projectionScreenV * (m_cameraHorzSize / m_cameraAspectRatio);
}

bool SDLRT::Camera::GenerateRay(double proScreenX, double proScreenY, Ray& cameraRay) {
	// Compute the location of the screen point in world coordinates.
	glm::dvec3 screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
	glm::dvec3  screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);

	// Use this point along with the camera position to compute the ray.
	cameraRay.m_point1 = m_cameraPosition;
	cameraRay.m_point2 = screenWorldCoordinate;
	cameraRay.m_lab =screenWorldCoordinate - m_cameraPosition;
	return true;
}

















