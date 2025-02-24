#include "RoadLines.h"

// Constructor
RoadLines::RoadLines(GameBoy& gb) : gb(&gb), y(0) {}

void RoadLines::createLine(int y) {
    gb->drawPoint(0, y);
    gb->drawPoint(0, y + 1);
    gb->drawPoint(0, y + 2);

    gb->drawPoint(7, y);
    gb->drawPoint(7, y + 1);
    gb->drawPoint(7, y + 2);
}

void RoadLines::wipeLine(int y) {
    gb->wipePoint(0, y);
    gb->wipePoint(0, y + 1);
    gb->wipePoint(0, y + 2);

    gb->wipePoint(7, y);
    gb->wipePoint(7, y + 1);
    gb->wipePoint(7, y + 2);
}

void RoadLines::draw() {
    createLine(y);
    createLine(y + 5);
    createLine(y + 10);
    createLine(y + 15);
    createLine(y - 5);
    createLine(y - 10);
    createLine(y - 15);
}

void RoadLines::wipe() {
    wipeLine(y);
    wipeLine(y + 5);
    wipeLine(y + 10);
    wipeLine(y + 15);
    wipeLine(y - 5);
    wipeLine(y - 10);
    wipeLine(y - 15);
}

void RoadLines::move() {
    y++;
    if (y > 15) y = 0;
}

void RoadLines::process() {
  wipe();
  move();
  draw();
}

// Setters and Getters
void RoadLines::setGameBoy(GameBoy& gb) { this->gb = &gb; }
GameBoy& RoadLines::getGameBoy() { return *gb; }

void RoadLines::setY(int y) { this->y = y; }
int RoadLines::getY() { return y; }
