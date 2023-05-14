#pragma once
#include "headers.h"
#include "Ray.h"

namespace SDLRT
{
	class Camera
	{
		public:
			// The default constructor.
			Camera() noexcept;
			
			// Functions to set camera parameters.
			void SetPosition	(const glm::dvec3 &newPosition) noexcept;
			void SetLookAt		(const glm::dvec3 &newLookAt) noexcept;
			void SetUp			(const glm::dvec3 &upVector) noexcept;
			void SetLength		(double newLength) noexcept;
			void SetHorzSize	(double newSize) noexcept;
			void SetAspect		(double newAspect) noexcept;
			
			// Functions to return camera parameters.
			glm::dvec3	GetPosition() noexcept;
			glm::dvec3	GetLookAt() noexcept;
			glm::dvec3	GetUp() noexcept;
			glm::dvec3	GetU() noexcept;
			glm::dvec3	GetV() noexcept;
			glm::dvec3	GetScreenCentre() noexcept;
			double	GetLength() noexcept;
			double	GetHorzSize() noexcept;
			double	GetAspect() noexcept;
			
			// Function to generate a ray.
			bool GenerateRay(double proScreenX, double proScreenY, SDLRT::Ray &cameraRay);
			
			// Function to update the camera geometry.
			void UpdateCameraGeometry();
			
		private:
			glm::dvec3 m_cameraPosition	{3};
			glm::dvec3 m_cameraLookAt		{3};
			glm::dvec3 m_cameraUp				{3};
			double m_cameraLength;
			double m_cameraHorzSize;
			double m_cameraAspectRatio;
			
			glm::dvec3 m_alignmentVector				{3};
			glm::dvec3 m_projectionScreenU			{3};
			glm::dvec3 m_projectionScreenV			{3};
			glm::dvec3 m_projectionScreenCentre	{3};
			
	};
}
