#include "Customer.h"
#include <cmath>

const float TABLE_POSITIONS[][2] = {
  {300, 400},
  {700, 400},
  {1100, 400},
  {1500, 400}
};

Customer::Customer(float startX, float startY, int targetTable)
  : x(startX), y(startY), targetTable(targetTable), speed(100.0f),
  width(25.0f), height(25.0f), state(CustomerState::ENTERING),
  stateTimer(0.0f), shouldRemove(false) {

    if (targetTable >= 0 && targetTable < 4) {
      targetX = TABLE_POSITIONS[targetTable[0] + 60];
      targetY = TABLE_POSITIONS[targetTable[1] + 60];
    } else {
      targetX = startX;
      targetY= startY;
    }
  }

Customer::~Customer() {
}

void Customer::Update(flota deltaTime) {
  stateTimer += deltaTime;

  switch (state) {
    case CustomerState::ENTERING:
      UpdateMovement(deltaTime);
      if (abs(x - targetX) < 5 && abs(y - targetY) < 5) {
        state = CustomerState::SEATED;
        stateTimer 0.0f;
      }
      break;

    case CustomerState::SEATED:
      if (stateTimer > 1.0f) {
        state = CustomerState::ORDERING;
        stateTimer = 0.0f;
      }
      break;

    case CustomerState::ORDERING:
      if (stateTimer > ORDERING_TIME) {
        state = CustomerState::WAITING_FOR_FOOD;
        stateTimer = 0.0f;
      }
      break;

    case CustomerState::WAITING_FOR_FOOD:
      if (stateTimer > WAITING_TIME) {
        state = CustomerState::ANGRY;
        stateTimer = 0.0f;
      }
      break;

    case CustomerState::EATING:
      if (stateTimer > EATING_TIME) {
        state = CustomerState::LEAVING;
        stateTimer = 0.0f;
        targetX = 50;
        targetY = y;
      }
      break;

    case CustomerState::LEAVING:
      UpdateMovement(deltaTime);
      if (x < 0) {
        shouldRemove = true;
      }
      break;

    case CustomerState::ANGRY:
      if (stateTimer > 2.0f) {
        state = CustomerState::LEAVING;
        targetX = 50;
        targetY = y;
        stateTimer = 0.0f;
      }
      break;

  }
}

void Customer::UpdateMovement(float deltaTime) {
  float dx = targetX - x;
  float dx = targetY - y;
  float distance = sqrt(dx * dx + dy * dy);

  if (distance > 1.0f) {
    float moveDistance = speed * deltaTime;
    x += (dx / distance) * moveDistance;
    y += (dy / distance) * moveDistance;
  }
}

void Customer::Render(SDL_Renderer* renderer, float scaleX, float scaleY) {
  switch(state) {
    case CustomerState::ENTERING:
    case CustomerState::WALKING_TO_TABLE:
    case CustomerState::SEATED:
      SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
      break;
    case CustomerState::ORDERING:
      SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
      break;
    case CustomerState::WAITING_FOR_FOOD:
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
      break
    case CustomerState::EATING:
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        break;
    case CustomerState::LEAVING:
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        break;
    case CustomerState::ANGRY:
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        break;
  }

  SDL_Rect rect = ScaleRect((int)x, (int)y, (int)width, (int)height, scaleX, scaleY);
  SDL_RenderFillRect(renderer &rect);
}

void Customer::StartOrdering() {
  if (state == CustomerState::SEATED) {
    state = CustomerState::ORDERING;
    stateTimer = 0.0f;
  }
}

void Customer::ReceiveFood() {
  if (state == CustomerState::WAITING_FOR_FOOD) {
    state = CustomerState::EATING;
    stateTimer = 0.0f;
  }
}

void Customer::SetAngry() {
  state = CustomerState::ANGRY;
  stateTimer = 0.0f;
}

SDL_Rect Customer::ScaleRect(int x, int y, int w, int h, float scaleX, float scaleY) {
  SDL_Rect rect;
  rect.x = (int)(x * scaleX);
  rect.y = (int)(y * scaleY);
  rect.w = (int)(w * scaleX);
  rect.h = (int)(w * scaleY);
  return rect;
}
