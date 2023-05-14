#pragma once
#include "./rayTrace/headers.h"
#include "./rayTrace/Image.h"
#include "./rayTrace/Scene.h"
#include "./rayTrace/Camera.h"

class RayTrace
{
	public:
		RayTrace() noexcept;
		
		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event *event) noexcept;
		void OnLoop() noexcept;
		void OnRender() noexcept;
		void OnExit() noexcept;
		
		
	private:
		// An instance of the qbImage class to store the image.
		Image m_image;
		
		// An instance of the scene class.
		SDLRT::Scene m_scene;
		
		// SDL2 stuff.
		bool isRunning;
		SDL_Window *pWindow;
		SDL_Renderer *pRenderer;
		
		void PrintVector(const glm::dvec3 &inputVector);
};
