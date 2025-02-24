#ifndef ENEMY_CAR_H
#define ENEMY_CAR_H

#include <GameBoy.h>

class EnemyCar {
private:
    GameBoy* gb;
    int x, y;

public:
    EnemyCar(GameBoy& gb); // Constructor

    void draw();
    void wipe();
    void randomRespawn();
    void move();
    void process();

    void setGameBoy(GameBoy& gb);
    GameBoy& getGameBoy();

    void setX(int x);
    int getX();
    
    void setY(int y);
    int getY();
};

#endif // ENEMY_CAR_H
