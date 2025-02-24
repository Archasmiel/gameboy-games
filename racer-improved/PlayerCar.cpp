#include "PlayerCar.h"

// Constructors
PlayerCar::PlayerCar(GameBoy& gb, int x, int y) : gb(&gb), x(x), y(y), carSpeed(100) {}

PlayerCar::PlayerCar(GameBoy& gb) : PlayerCar(gb, 2, 12) {}

void PlayerCar::draw() {
    gb->drawPoint(x, y);
    gb->drawPoint(x, y + 1);
    gb->drawPoint(x - 1, y + 1);
    gb->drawPoint(x + 1, y + 1);
    gb->drawPoint(x, y + 2);
    gb->drawPoint(x - 1, y + 3);
    gb->drawPoint(x + 1, y + 3);
}

void PlayerCar::wipe() {
    gb->wipePoint(x, y);
    gb->wipePoint(x, y + 1);
    gb->wipePoint(x - 1, y + 1);
    gb->wipePoint(x + 1, y + 1);
    gb->wipePoint(x, y + 2);
    gb->wipePoint(x - 1, y + 3);
    gb->wipePoint(x + 1, y + 3);
}

void PlayerCar::move(bool isRight) {
    this->x = isRight ? 5 : 2;
}

void PlayerCar::checkMove() {
    if (gb->getKey() == 4) move(false);
    else if (gb->getKey() == 5) move(true);
}

bool PlayerCar::checkCollision(int enemy_x, int enemy_y) {
  if (this->x == enemy_x and enemy_y>=12) {
    return true;
  }
  return false;
}

void PlayerCar::process() {
  wipe();
  checkMove();
  draw();
}

// Setters and Getters
void PlayerCar::setGameBoy(GameBoy& gb) { this->gb = &gb; }
GameBoy& PlayerCar::getGameBoy() { return *gb; }

void PlayerCar::setX(int x) { this->x = x; }
int PlayerCar::getX() { return x; }

void PlayerCar::setY(int y) { this->y = y; }
int PlayerCar::getY() { return y; }

void PlayerCar::setCarSpeed(int carSpeed) { this->carSpeed = carSpeed; }
int PlayerCar::getCarSpeed() { return carSpeed; }
