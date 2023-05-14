#pragma once

#define GLM_FORCE_SILENT_WARNINGS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_WIN32
#define GLM_FORCE_SIZE_T_LENGTH
#define GLM_FORCE_PURE
#define GLM_FORCE_INLINE
#define GLM_FORCE_EXPLICIT_CTOR
#define GLM_FORCE_CXX17
#define GLM_FORCE_UNRESTRICTED_GENTYPE
#define GLM_FORCE_PRECISION_HIGHP_DOUBLE
#define GLM_FORCE_PRECISION_HIGHP_INT
#define GLM_FORCE_PRECISION_HIGHP_FLOAT
//#define GLM_FORCE_MESSAGES
#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/random.hpp>
#include <string_view>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

using ddvector = std::vector<std::vector<double>>;

static constexpr double MAX_COLOR = 255.0;
static constexpr double NO_COLOR = 0.0;
static constexpr double EPSILON = 1e-22;
// Dimensioni della finestra
static constexpr unsigned int screenWidth = 1280;
static constexpr unsigned int screenHeight = 720;
//static constexpr unsigned long long int framebuffersize = static_cast<long long int>(screenWidth) * static_cast<long long int>(screenHeight);
static constexpr unsigned int MaxColorValue = 255;
static constexpr unsigned int DelayMilliseconds = 1;
static constexpr std::string_view windowTitle = "Ray Tracer";
static constexpr std::string_view errorMessage = "Errore durante l'inizializzazione di SDL: ";
static constexpr std::string_view createWindowErrorMessage = "Errore durante la creazione della finestra: ";
static constexpr std::string_view createRendererErrorMessage = "Errore durante la creazione dell' render: ";

#define CAST_U8(x) static_cast<Uint8>((x))
#define CAST_I(x) static_cast<int>((x))
#define CAST_ULLI(x) static_cast<long long int>((x))
#define CAST_D(x) static_cast<double>((x))
#define PRINT(p, ...)  std::cout << std::fixed << std::setprecision(p) << __VA_ARGS__ << std::endl;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define SDL_COLOR(r, g, b, a) { CAST_U8(r), CAST_U8(g), CAST_U8(b), CAST_U8(a) }
#else
#define SDL_COLOR(r, g, b, a) { CAST_U8(b), CAST_U8(g), CAST_U8(r), CAST_U8(a) }
#endif
