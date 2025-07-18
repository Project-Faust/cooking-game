#define CUSTOMER_H

#include <SDL2/SDL.h>

enum class CustomerState {
  ENTERING,
  WALKING_TO_TABLE,
  SEATED,
  ORDERING,
  WAITING_FOR_FOOD,
  EATING,
  LEAVING,
  ANGRY 
};

class Customer {
  public:
    Customer(float startX, float startY, int targetTable);
    ~Customer();

    void update(float deltaTime);
    void render(SDL_Renderer* renderer, float scaleX, float scaleY);

    // Getters
    CustomerState GetState() const { return state; }
    int GetTargetTable() const { return targetTable };
    bool ShouldBeRemoved() const { return shouldRemove };
    float GetX() const { return x; };
    float GetY() const { return y; };

    // Actions
    void StartOrdering();
    void ReceiveFood();
    void SetAngry();

  private:
    float x, y;
    float targetX, targetY;
    float speed;
    float width, height;

    CustomerState state;
    int targetTable;
    float stateTimer;
    bool shouldRemove;

    // Timing constants
    static constantexpr float ORDERING_TIME = 3.0f;
    static constantexpr float WAITING_TIME = 15.0f;
    static constantexpr float EATING_TIME = 8.0f;

    void UpdateMovement(float deltaTime);
    void UpdateState(float deltaTime);
    SDL_Rect ScaleRect(int x, int y, int w, int h, float scaleX, float scaleY);
};
