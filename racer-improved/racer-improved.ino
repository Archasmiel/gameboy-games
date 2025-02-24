#include <GameBoy.h>
#include "EnemyCar.h"
#include "PlayerCar.h"
#include "RoadLines.h"

GameBoy gb;
PlayerCar car(gb);
EnemyCar enemy(gb);
RoadLines road(gb);
  
void setup() {
  gb.begin(0);
  randomSeed(analogRead(0));
}

void loop() {
  enemy.process();
  road.process();
  car.process();
  if (car.checkCollision(enemy.getX(), enemy.getY())) {
    gb.testMatrix(10);
    gb.clearDisplay();
    return;
  }
  delay(car.getCarSpeed());
}
