#include "Image.h"

// The default constructor.
Image::Image() noexcept : m_xSize(0), m_ySize(0), m_pRenderer(nullptr), m_pTexture(nullptr) {}

// The destructor.
Image::~Image() noexcept
{
	if (m_pTexture != nullptr) {
		SDL_DestroyTexture(m_pTexture);
		m_pTexture = nullptr;
	}
}

// Function to inialize.
void Image::Initialize(const std::size_t xSize, const std::size_t ySize, SDL_Renderer *pRenderer)
{
	// Resize the image arrays.
	m_rChannel.resize(xSize, std::vector<double>(ySize, 0.0));
	m_gChannel.resize(xSize, std::vector<double>(ySize, 0.0));
	m_bChannel.resize(xSize, std::vector<double>(ySize, 0.0));
	
	// Store the dimensions.
	m_xSize = xSize;
	m_ySize = ySize;
	
	// Store the pointer to the renderer.
	m_pRenderer = pRenderer;
	
	// Initialise the texture.
	InitTexture();
}

// Function to set pixels.
void Image::setPixel(const std::size_t x, const std::size_t y, const double red, const double green, const double blue)
{
	m_rChannel.at(x).at(y) = red;
	m_gChannel.at(x).at(y) = green;
	m_bChannel.at(x).at(y) = blue;
}

void Image::setPixel(const std::size_t x, const std::size_t y){
	m_rChannel.at(x).at(y) = 0.0;
	m_gChannel.at(x).at(y) = 0.0;
	m_bChannel.at(x).at(y) = 0.0;
}


// Function to return the dimensions of the image.
std::size_t Image::GetXSize() const noexcept {
	return m_xSize;
}
std::size_t Image::GetYSize() const noexcept {
	return m_ySize;
}

// Function to generate the display.
void Image::Display() {
	long long int framebuffersize = CAST_ULLI(m_xSize) * CAST_ULLI(m_ySize);
	std::vector<SDL_Color> framebuffer(framebuffersize);
	for (size_t x = 0; x < m_xSize; ++x) {
		for (size_t y = 0; y < m_ySize; ++y) {
			framebuffer.at((y * m_xSize) + x) = ConvertColor(m_rChannel.at(x).at(y), m_gChannel.at(x).at(y), m_bChannel.at(x).at(y));
		}
	}
	SDL_UpdateTexture(m_pTexture, nullptr, framebuffer.data(), CAST_I(m_xSize) * sizeof(SDL_Color));
	SDL_Rect srcRect{ 0, 0, CAST_I(m_xSize),CAST_I(m_ySize) };
	SDL_Rect bounds{ srcRect };
	SDL_RenderCopy(m_pRenderer, m_pTexture, &srcRect, &bounds);
}

// Function to initialize the texture.
void Image::InitTexture() noexcept {
	if (m_pTexture != nullptr)
		SDL_DestroyTexture(m_pTexture);
	SDL_Surface* tempSurface = SDL_CreateRGBSurfaceWithFormat(0, CAST_I(m_xSize), CAST_I(m_ySize), 32, SDL_PIXELFORMAT_RGBA32);
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}

SDL_Color Image::ConvertColor(const double red, const double green, const double blue) const noexcept {
	return SDL_COLOR(CAST_U8(red), CAST_U8(green), CAST_U8(blue), CAST_U8(255));
}























