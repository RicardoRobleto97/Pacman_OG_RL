#pragma once
#ifndef GHOSTS_H
#define GHOSTS_H

class Ghosts {

    int x, y;
public:

    void pintar();
    void borrar();
    void movercpu();
    void movercpu_2();

    void choque(class Pacman& C);
    Ghosts(int _x, int _y);

};
Ghosts::Ghosts(int _x, int _y) : x(_x), y(_y) {}


#endif // !GHOSTS_H
