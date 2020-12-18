#pragma once
#ifndef PACMAN_H
#define PACMAN_H

class Pacman 
{
    int x, y;
    int vidas;
    int puntaje;
public:



    Pacman(int _x, int _y, int _vidas, int _puntaje) :x(_x), y(_y), vidas(_vidas),puntaje(_puntaje) {};
    int X() { return x; }
    int Y() { return y; }
    int yp1 = x;
    int xp1 = y;
   
    void COR() { vidas--; }
    //void Nivel() { lvl++; }
    void pintar();
    void pintarUP();
    void pintarDown();
    void pintarRight();
    void borrar();
    void borrarX();
    void mover();
    void pintar_vidas();
    void morir();

    bool verificarMovimiento();
    bool verificarPuntos();
    void Puntaje();
    void Pintar_Puntos();
};


#endif // !PACMAN_H
