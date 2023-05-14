#pragma once
#include "headers.h"
#include "Image.h"
#include "Camera.h"
#include "ObjectSphere.h"
#include "PointLight.h"

namespace SDLRT
{
	class Scene
	{
		public:
			// The default constructor.
			Scene();
			
			// Function to perform the rendering.
			bool Render(Image &outputImage);
			
		// Private functions.
		private:
		
		// Private members.
		private:
			// The camera that we will use.
			SDLRT::Camera m_camera{};
			
			// The list of objects in the scene.
			std::vector<std::shared_ptr<SDLRT::ObjectBase>> m_objectList{};
	
			// The list of lights in the scene.
			std::vector<std::shared_ptr<SDLRT::LightBase>> m_lightList{};
	};
}