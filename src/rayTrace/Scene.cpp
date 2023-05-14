#include "Scene.h"


// The constructor.
SDLRT::Scene::Scene() {
	// Configure the camera.
	m_camera.SetHorzSize(0.25);
	m_camera.SetAspect(16.0 / 9.0);
	m_camera.UpdateCameraGeometry();
	
	// Construct a test sphere.
	m_objectList.push_back(std::make_shared<SDLRT::ObjSphere> (SDLRT::ObjSphere()));
	
	// Construct a test light.
	m_lightList.push_back(std::make_shared<SDLRT::PointLight> (SDLRT::PointLight()));
	m_lightList.at(0) -> m_location = {5.0, -10.0, 5.0};
	m_lightList.at(0) -> m_color = {255.0, 255.0, 255.0};
}

// Function to perform the rendering.
bool SDLRT::Scene::Render(Image &outputImage)
{
	// Get the dimensions of the output image.
	std::size_t xSize = outputImage.GetXSize();
	std::size_t ySize = outputImage.GetYSize();
	
	// Loop over each pixel in our image.
	SDLRT::Ray cameraRay{};
	glm::dvec3 intPoint{};
	glm::dvec3 localNormal{};
	glm::dvec3 localColor{};
	double xFact = 1.0 / (CAST_D(xSize) / 2.0);
	double yFact = 1.0 / (CAST_D(ySize) / 2.0);
	double minDist = 1e6;
	double maxDist = 0.0;
	for (int x=0; x<xSize; ++x)
	{
		for (int y=0; y<ySize; ++y)
		{
			// Normalize the x and y coordinates.
			double normX = (CAST_D(x) * xFact) - 1.0;
			double normY = (CAST_D(y) * yFact) - 1.0;
			
			// Generate the ray for this pixel.
			m_camera.GenerateRay(normX, normY, cameraRay);
			
			// Test for intersections with all objects in the scene.
			for (auto currentObject : m_objectList)
			{
				bool validInt = currentObject -> TestIntersection(cameraRay, intPoint, localNormal, localColor);
				
				// If we have a valid intersection, change pixel color to red.
				if (validInt)
				{
					// Compute intensity of illumination.
					double intensity;
					glm::dvec3 color {3};
					bool validIllum = false;
					for (auto currentLight : m_lightList)
					{
						validIllum = currentLight->ComputeIllumination(intPoint, localNormal, m_objectList, currentObject, color, intensity);
					}
				
					// Compute the distance between the camera and the point of intersection.
					double dist = glm::length(intPoint - cameraRay.m_point1);
					if (dist > maxDist)
						maxDist = dist;
					
					if (dist < minDist)
						minDist = dist;
				
					//outputImage.SetPixel(x, y, 255.0 - ((dist - 9.0) / 0.94605) * 255.0, 0.0, 0.0);
					if (validIllum)
					{
						outputImage.setPixel(x, y, 255.0 * intensity, 0.0, 0.0);
					}
					else
					{
						outputImage.setPixel(x, y, 0.0, 0.0, 0.0);
					}
				}
				else
				{
					outputImage.setPixel(x, y, 0.0, 0.0, 0.0);
				}				
			}
		}
	}
	PRINT(12, "Minimum distance: " << minDist << "\nMaximum distance : " << maxDist)
	return true;
}
