/* ***********************************************************
	CApp.cpp
	
	The application class implementation.
	
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
	
**********************************************************/

// CApp.cpp

#include "RayTracer.h"

// The constructor (default)
RayTrace::RayTrace() noexcept : isRunning(true), pWindow(nullptr), pRenderer(nullptr) {}

bool RayTrace::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << errorMessage << SDL_GetError << std::endl;
		return false;
	}
	
	pWindow = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	
	if (pWindow != nullptr)
	{
		pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == nullptr) {
			std::cout << createRendererErrorMessage << SDL_GetError() << std::endl;
			OnExit();
			return false;
		}
		
		// Intialize the qbImage instance.
		m_image.Initialize(screenWidth, screenHeight, pRenderer);
		
		// Set the background color to white.
		SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
		SDL_RenderClear(pRenderer);
		
		// Render the scene.
		m_scene.Render(m_image);
		
		// Display the image.
		m_image.Display();
		
		// Show the result.
		SDL_RenderPresent(pRenderer);
		
	}
	else {
		OnExit();
		return false;
	}
	
	return true;
}

int RayTrace::OnExecute()
{
	SDL_Event event{};
	
	if (OnInit() == false)
	{
		return -1;
	}
	
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}
		
		OnLoop();
		OnRender();
	}
	
	OnExit();
	return 0;
}

void RayTrace::OnEvent(SDL_Event *event) noexcept {

	switch (event->type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void RayTrace::OnLoop() noexcept {}

void RayTrace::OnRender() noexcept {}

void RayTrace::OnExit() noexcept
{
	// Tidy up SDL2 stuff.
	if (pRenderer != nullptr) {
		SDL_DestroyRenderer(pRenderer);
		pRenderer = nullptr;
	}
	if (pWindow != nullptr) {
		SDL_DestroyWindow(pWindow);
		pWindow = nullptr;
	}
	SDL_Quit();
}

// PRIVATE FUNCTIONS.
void RayTrace::PrintVector(const glm::dvec3 &vec) {
	PRINT(6, "Vector: (" << vec.x << ", " << vec.y << ", " << vec.z << ")");
}



























