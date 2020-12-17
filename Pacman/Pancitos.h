#pragma once
#ifndef PANCITOS_H
#define PANCITOS_H
#include "Pacman.h"

class Pancitos {
    int x, y;
    int Puntos;
public:
    
    void pintar();
    void borrar();
    void movercpu();
    void infinto();
    void choque(class Pacman& C);
    void puntos(int x, int y, class Pacman& P);
    Pancitos(int _x, int _y, int _puntos);
    void Puntaje_Colors() { Puntos += 5; }

};
Pancitos::Pancitos(int _x, int _y, int _puntos) : x(_x), y(_y),Puntos(_puntos) {}

#endif // !PANCITOS_H