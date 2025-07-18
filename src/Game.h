#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Customer.h"
#include <vector>
#include <memory>

class Game {
  public:
    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Cleanup();

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    void HandleEvents();
    void Render();

    int windowWidth;
    int windowHeight;
    bool isFullscreen;
    float scaleX, scaleY;

    void SetResolution(int width, int height);
    void UpdateScale();
    SDL_Rect ScaleRect(int x, int y, int w, int h);

    float playerX, playerY;
    float playerWidth, playerHeight;
    float playerSpeed;

    bool CheckCollision(float newX, float newY);
    void UpdatePlayer();
};

#endif // GAME_H
