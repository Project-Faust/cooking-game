#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game() : window(nullptr), renderer(nullptr), running(false), windowWidth(1920), windowHeight(1080), isFullscreen(false),
scaleX(1.0f), scaleY(1.0f) {
}

Game::~Game() {
	Cleanup();
}

bool Game::Initialize() {
	std::cout << "Cooking Game Engine Starting..." << std::endl;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	std::cout << "SDL initialized successfully!" << std::endl;

	// Create window
	window = SDL_CreateWindow("Cooking Game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	std::cout << "Window created successfully!" << std::endl;

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	std::cout << "Renderer created successfully!" << std::endl;

	running = true;
	return true;
}

void Game::Run() {
	SDL_Event event;

	while (running) {
		HandleEvents();
		Render();
		SDL_Delay(16);
	}
}

void Game::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent* keyEvent = &event.key;
			if (keyEvent->keysym.sym == SDLK_F1) {
				SetResolution(1280, 720);
			}	
			else if (keyEvent->keysym.sym == SDLK_F2) {
				SetResolution(1920, 1080);
			}
			else if (keyEvent->keysym.sym == SDLK_F3) {
				SetResolution(2560, 1400);
			}
		}
	}
}

void Game::Render() {
	// Safety check
	if (!window || !renderer) {
		std::cout << "Error: window or renderer is null!" << std::endl;
		running = false;
		return;
	}

	// Clear screen (black background)
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw kitchen counter (grey)
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
	SDL_Rect kitchen = ScaleRect(100, 50, 1720, 120); 
	SDL_RenderFillRect(renderer, &kitchen);

	// Draw table 1 (brown)
	SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
	SDL_Rect table1 = ScaleRect(300, 400, 120 ,120);
	SDL_RenderFillRect(renderer, &table1);

	// Draw table 2 (brown)
	SDL_Rect table2 = ScaleRect(700, 400, 120, 120); 
	SDL_RenderFillRect(renderer, &table2);

	// Draw serving area (green)
	SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
	SDL_Rect serving = ScaleRect(860, 250, 200, 100); 
	SDL_RenderFillRect(renderer, &serving);

	// Present the frame
	SDL_RenderPresent(renderer);
}

void Game::Cleanup() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}
	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
	SDL_Quit();
}

void Game::SetResolution(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	UpdateScale();

	if (window) {
		SDL_SetWindowSize(window, windowWidth, windowHeight);
		SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		std::cout << "Resolution changed to " << width << "x" << height << std::endl;
	}
}

void Game::UpdateScale() {
	const float referenceWidth = 1920.0f;
	const float referenceHeight = 1080.0f;

	scaleX = (float)windowWidth / referenceWidth;
	scaleY = (float)windowHeight / referenceHeight;

	std::cout << "Scale factors: x=" << scaleX << ", y=" << scaleY << std::endl;
}

SDL_Rect Game::ScaleRect(int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = (int)(x * scaleX);
	rect.y = (int)(x * scaleY);
	rect.w = (int)(w * scaleX);
	rect.h = (int)(h * scaleY);
	return rect;
}
