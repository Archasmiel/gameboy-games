#ifndef PLAYER_CAR_H
#define PLAYER_CAR_H

#include <GameBoy.h>
#include "EnemyCar.h"
class PlayerCar {
private:
    GameBoy* gb;
    int x, y;
    int carSpeed;

public:
    PlayerCar(GameBoy& gb, int x, int y);
    PlayerCar(GameBoy& gb);

    void draw();
    void wipe();
    void move(bool isRight);
    void checkMove();
    bool checkCollision(int enemy_x, int enemy_y);
    void process();

    void setGameBoy(GameBoy& gb);
    GameBoy& getGameBoy();

    void setX(int x);
    int getX();
    
    void setY(int y);
    int getY();
    
    void setCarSpeed(int carSpeed);
    int getCarSpeed();
};

#endif // PLAYER_CAR_H
