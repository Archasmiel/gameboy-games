#ifndef ROADLINES_H
#define ROADLINES_H

#include <GameBoy.h>

class RoadLines {
private:
    GameBoy* gb;
    int y;

public:
    RoadLines(GameBoy& gb);

    void createLine(int y);
    void wipeLine(int y);
    void draw();
    void wipe();
    void move();
    void process();

    void setGameBoy(GameBoy& gb);
    GameBoy& getGameBoy();

    void setY(int y);
    int getY();
};

#endif // ROADLINES_H
