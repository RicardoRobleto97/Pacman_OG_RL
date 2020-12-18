#pragma once
#ifndef GHOSTS_H
#define GHOSTS_H
//#include "Pacman.h"
class Ghosts {

    int x, y;
public:

    void pintar();
    void borrar();
    void movercpu();
    void movercpu_2();
    bool verificarMovimiento();

    void choque(class Pacman& C);
    Ghosts(int _x, int _y);

};
Ghosts::Ghosts(int _x, int _y) : x(_x), y(_y) {}


#endif // !GHOSTS_H
