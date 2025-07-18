#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game() : window(nullptr), renderer(nullptr), running(false),
  windowWidth(1920), windowHeight(1080), isFullscreen(false),
  scaleX(1.0f), scaleY(1.0f),
  playerX(500.0f), playerY(300.0f),
  playerWidth(30.0f), playerHeight(30.0f),
  playerSpeed(200.0f),
  customerSpawnTimer(0.0f), customerSpawnInterval(5.0f), nextCustomerId(0) {
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
    UpdatePlayer();
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
        SetResolution(2560, 1440);
      }
      else if (keyEvent->keysym.sym == SDLK_w || keyEvent->keysym.sym == SDLK_UP) {
        if (!CheckCollision(playerX, playerY - playerSpeed *0.016f)) {
          playerY -= playerSpeed * 0.016f;
        }
      }
      else if (keyEvent->keysym.sym == SDLK_s || keyEvent->keysym.sym == SDLK_DOWN) {
        if (!CheckCollision(playerX, playerY + playerSpeed * 0.016f)) {
          playerY += playerSpeed * 0.016f;
        }
      }
      else if (keyEvent->keysym.sym == SDLK_a || keyEvent->keysym.sym == SDLK_LEFT) {
        if (!CheckCollision(playerX - playerSpeed * 0.016f, playerY)) {
          playerX -= playerSpeed * 0.016f;
        }
      }
      else if (keyEvent->keysym.sym == SDLK_d || keyEvent->keysym.sym == SDLK_RIGHT) {
        if (!CheckCollision(playerX + playerSpeed * 0.016f, playerY)) {
          playerX += playerSpeed * 0.016f;
        }
      }
    }
  }
}

void Game::Render() {
  // Safety check
  if (!window || !renderer) {
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

  // Draw table 3 (brown)
  SDL_Rect table3 = ScaleRect(1100, 400, 120, 120);
  SDL_RenderFillRect(renderer, &table3);

  // Draw table 4 (brown)
  SDL_Rect table4 = ScaleRect(1500, 400, 120, 120);
  SDL_RenderFillRect(renderer, &table4);

  // Draw serving area (green)
  SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
  SDL_Rect serving = ScaleRect(860, 250, 200, 100); 
  SDL_RenderFillRect(renderer, &serving);

  // Draw player (cyan)
  SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
  SDL_Rect player = ScaleRect((int)playerX, (int)playerY, (int)playerWidth, (int)playerHeight);
  SDL_RenderFillRect(renderer, &player);

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
  std::cout << "=== SetResolution called: " << width << "x" << height << std::endl;

  windowWidth = width;
  windowHeight = height;

  if (window && renderer) {
    std::cout << "Destroying existing window and renderer..." << std::endl;

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    std::cout << "Renderer destroyed." << std::endl;

    SDL_DestroyWindow(window);
    window = nullptr;
    std::cout << "Window destroyed." << std::endl;

    SDL_PumpEvents();
    SDL_Delay(100);

    std::cout << "Creating new window..." << std::endl;

    window = SDL_CreateWindow("Cooking Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
      std::cout << "Window could not be recreated. SDL_Error: " << SDL_GetError() << std::endl;
      running = false;
      return;
    }

    SDL_ShowWindow(window);
    SDL_RaiseWindow(window);

    std::cout << "Window created successfully." << std::endl;

    std::cout << "Creating new renderer..." << std::endl;

    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer = nullptr) {
      std::cout << "Renderer could not be recreated. SDL_Error: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(window);
      window = nullptr;
      running = false;
      return;
    }

    SDL_PumpEvents();

    std::cout << "Renderer created successfully." << std::endl;

    int actualW, actualH;
    SDL_GetWindowSize(window, &actualW, &actualH);
    std::cout << "Actual window size: " << actualW << "x" << actualH << std::endl;

    std::cout << "Window and renderer recreated successfully." << std::endl;
    std::cout << "New window width: " << width << "\nNew window height: " << height << std::endl;
  } else {
    std::cout << "WARNING: window or renderer was already null." << std::endl;
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
  rect.y = (int)(y * scaleY);
  rect.w = (int)(w * scaleX);
  rect.h = (int)(h * scaleY);
  return rect;
}

bool Game::CheckCollision(float newX, float newY) {
  if (newX < 0 || newY < 0 || newX + playerWidth > 1920 || newY + playerHeight > 1080) {
    return true;
  }

  if (newX + playerWidth > 100 && newX < 1820 && 
      newY + playerHeight > 50 && newY < 170) {
    return true;
  }

  // Table 1 collision
  if (newX + playerWidth > 300 && newX < 420 && 
      newY + playerHeight > 400 && newY < 520) {
    return true;
  }

  // Table 2 collision
  if (newX + playerWidth > 700 && newX < 820 && 
      newY + playerHeight > 400 && newY < 520) {
    return true;
  }

  // Table 3 collision
  if (newX + playerWidth > 1100 && newX < 1220 && 
      newY + playerHeight > 400 && newY < 520) {
    return true;
  }

  // Table 4 collision  
  if (newX + playerWidth > 1500 && newX < 1620 && 
      newY + playerHeight > 400 && newY < 520) {
    return true;
  }

  // No collision
  return false; 
}

void Game::UpdatePlayer() {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);

  float deltaTime = 0.016f;
  float moveDistance = playerSpeed * deltaTime;

  if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) {
    if (!CheckCollision(playerX, playerY - moveDistance)) {
      playerY -= moveDistance;
    }
  }
  if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) {
    if (!CheckCollision(playerX, playerY + moveDistance)) {
      playerY += moveDistance;
    }
  }
  if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) {
    if (!CheckCollision(playerX - moveDistance, playerY)) {
      playerX -= moveDistance;
    }
  }
  if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) {
    if (!CheckCollision(playerX + moveDistance, playerY)) {
      playerX += moveDistance;
    }
  }
}

void Game::UpdateCustomers(float deltaTime) {
  customerSpawnTimer += deltaTime;

  if (customerSpawnTimer >= customerSpawnInterval) {
    SpawnCustomer();
    customerSpawnTimer = 0.0f;
  }

  for (auto& customer : customers) {
    customer->Update(deltaTime);
  }

  customers.erase(std::remove_if(customers.begin(), customers.end(), [this](const std::unique_ptr<Customer>& customer) {
        if (customer->ShouldBeRemoved() {
            int table = customer->GetTargetTable();

            if (table >= 0 && table < 4) {
            tableOccupied[table] = false;
            }
              return true;
            }

            return false;
        }), customers.end());

}

