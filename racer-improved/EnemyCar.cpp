#include "EnemyCar.h"

// Constructor
EnemyCar::EnemyCar(GameBoy& gb) : gb(&gb) {
    randomRespawn();
}

void EnemyCar::draw() {
    gb->drawPoint(x, y);
    gb->drawPoint(x, y - 1);
    gb->drawPoint(x - 1, y - 1);
    gb->drawPoint(x + 1, y - 1);
    gb->drawPoint(x, y - 2);
    gb->drawPoint(x - 1, y - 3);
    gb->drawPoint(x + 1, y - 3);
}

void EnemyCar::wipe() {
    gb->wipePoint(x, y);
    gb->wipePoint(x, y - 1);
    gb->wipePoint(x - 1, y - 1);
    gb->wipePoint(x + 1, y - 1);
    gb->wipePoint(x, y - 2);
    gb->wipePoint(x - 1, y - 3);
    gb->wipePoint(x + 1, y - 3);
}

void EnemyCar::randomRespawn() {
    x = (random(0, 10) % 10 > 5) ? 2 : 5; // Use rand() for standard C++
    y = 0;
}

void EnemyCar::move() {
    y++;
    if (y > 15) randomRespawn();
}

void EnemyCar::process() {
  wipe();
  move();
  draw();
}

// Setters and Getters
void EnemyCar::setGameBoy(GameBoy& gb) { this->gb = &gb; }
GameBoy& EnemyCar::getGameBoy() { return *gb; }

void EnemyCar::setX(int x) { this->x = x; }
int EnemyCar::getX() { return x; }

void EnemyCar::setY(int y) { this->y = y; }
int EnemyCar::getY() { return y; }
