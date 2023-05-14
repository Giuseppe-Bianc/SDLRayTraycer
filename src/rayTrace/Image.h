#pragma once
#include "headers.h"

class Image
{
	public:
		// The constructor.
		Image() noexcept;
	
		// The destructor.
		~Image() noexcept;
	
		// Function to initialise.
		void Initialize(const std::size_t xSize, const std::size_t ySize, SDL_Renderer* pRenderer);
		void setPixel(const std::size_t x, const std::size_t y, const double red, const double green, const double blue) ;
		void setPixel(const std::size_t x, const std::size_t y);
		void Display();

		std::size_t GetXSize() const noexcept;
		std::size_t GetYSize() const noexcept;
private:
	std::size_t m_xSize;
	std::size_t m_ySize;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	ddvector m_rChannel;
	ddvector m_gChannel;
	ddvector m_bChannel;
	SDL_Color ConvertColor(const double red, const double green, const double blue) const noexcept;
	void InitTexture() noexcept;

};
















