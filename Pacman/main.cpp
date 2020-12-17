
//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
#include <list>
//#include <stdbool.h>
#include <iostream>
//#include <cstdlib>
#include "Pacman.h"
#include "Pancitos.h"
#include "rlutil.h"
#include "Ghosts.h"

#include <array>
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
bool game_over;


using namespace std;

int lvl = 1;

int xvi;
int time;
int MurosX[200];
int MurosY[200];
int MurosXP[200];
int MurosYP[200];
//int Puntaje=0;
//int Muros[30][30];
HANDLE C = GetStdHandle(STD_OUTPUT_HANDLE);
//void gotoxy(int x, int y) {
//
//    HANDLE hCon;
//    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD dwPos;
//    dwPos.X = x;
//    dwPos.Y = y;
//    SetConsoleCursorPosition(hCon, dwPos);
//
//}

void OcultarCursor() {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = false;

    SetConsoleCursorInfo(hCon, &cci);
}
void pintar_limites() {
   
    //SetConsoleTextAttribute(C, FOREGROUND_RED | FOREGROUND_INTENSITY);

    rlutil::setColor(rlutil::YELLOW);
    //limites horizontales
    for (int x = 11; x < 75; x++) {
        gotoxy(x, 3); printf("%c", 205);
        gotoxy(x, 45); printf("%c", 205);
      //  rlutil::ANSI_YELLOW;
    }
   
    //limites laterales
    for (int x = 3; x < 45; x++) {
        gotoxy(10, x); printf("%c", 186);
        gotoxy(75, x); printf("%c", 186);

    }
    gotoxy(10, 45); printf("%c", 200);
    gotoxy(75, 45); printf("%c", 188);
}
void Pintar_Puntos() {
    int m =0 ;
    //Puntos Lateral Izquierdo
    MurosXP[20] = 14; MurosYP[20] = 10;
    MurosXP[21] = 14; MurosYP[21] = 11;
    MurosXP[22] = 14; MurosYP[22] = 12;
    MurosXP[23] = 14; MurosYP[23] = 13;
    MurosXP[24] = 14; MurosYP[24] = 14;
    MurosXP[25] = 14; MurosYP[25] = 15;
    MurosXP[26] = 14; MurosYP[26] = 16;
    MurosXP[27] = 14; MurosYP[27] = 17;

    gotoxy(14, 10); printf("%c", 46);
    gotoxy(14, 11); printf("%c", 46);

    gotoxy(14, 12); printf("%c", 46);
    gotoxy(14, 13); printf("%c", 46);

    gotoxy(14, 14); printf("%c", 46);
    gotoxy(14, 15); printf("%c", 46);

    gotoxy(14, 16); printf("%c", 46);
    gotoxy(14, 17); printf("%c", 46);


    MurosXP[0] = 14; MurosYP[0] = 30;
    MurosXP[1] = 14; MurosYP[1] = 31;
    MurosXP[2] = 14; MurosYP[2] = 32;
    MurosXP[3] = 14; MurosYP[3] = 33;
    MurosXP[4] = 14; MurosYP[4] = 34;
    MurosXP[5] = 14; MurosYP[5] = 35;
    MurosXP[6] = 14; MurosYP[6] = 36;
    MurosXP[7] = 14; MurosYP[7] = 37;

    gotoxy(14, 30); printf("%c", 46);
    gotoxy(14, 31); printf("%c", 46);

    gotoxy(14, 32); printf("%c", 46);
    gotoxy(14, 33); printf("%c", 46);

    gotoxy(14, 34); printf("%c", 46);
    gotoxy(14, 35); printf("%c", 46);

    gotoxy(14, 36); printf("%c", 46);
    gotoxy(14, 37); printf("%c", 46);

    MurosXP[10] = 14; MurosYP[10] = 20;
    MurosXP[11] = 14; MurosYP[11] = 21;
    MurosXP[12] = 14; MurosYP[12] = 22;
    MurosXP[13] = 14; MurosYP[13] = 23;
    MurosXP[14] = 14; MurosYP[14] = 24;
    MurosXP[15] = 14; MurosYP[15] = 25;
    MurosXP[16] = 14; MurosYP[16] = 26;
    MurosXP[17] = 14; MurosYP[17] = 27;

    gotoxy(14, 20); printf("%c", 46);
    gotoxy(14, 21); printf("%c", 46);

    gotoxy(14, 22); printf("%c", 46);
    gotoxy(14, 23); printf("%c", 46);

    gotoxy(14, 24); printf("%c", 46);
    gotoxy(14, 25); printf("%c", 46);

    gotoxy(14, 26); printf("%c", 46);
    gotoxy(14, 27); printf("%c", 46);
    
    //Puntos Derecho Izquierdo

    MurosXP[10] = 14; MurosYP[10] = 20;
    MurosXP[11] = 14; MurosYP[11] = 21;
    MurosXP[12] = 14; MurosYP[12] = 22;
    MurosXP[13] = 14; MurosYP[13] = 23;
    MurosXP[14] = 14; MurosYP[14] = 24;
    MurosXP[15] = 14; MurosYP[15] = 25;
    MurosXP[16] = 14; MurosYP[16] = 26;
    MurosXP[17] = 14; MurosYP[17] = 27;

    gotoxy(64, 10); printf("%c", 46);
    gotoxy(64, 11); printf("%c", 46);

    gotoxy(64, 12); printf("%c", 46);
    gotoxy(64, 13); printf("%c", 46);

    gotoxy(64, 14); printf("%c", 46);
    gotoxy(64, 15); printf("%c", 46);

    gotoxy(64, 16); printf("%c", 46);
    gotoxy(64, 17); printf("%c", 46);

 /*   for (int i = 0; i < 200; i++)
    {   
        MurosXP[i];
        MurosYP[i];
        if (MurosXP[i] = m && MurosYP[i] = m) {

            gotoxy(i, i); printf(" ");
        }
    }*/
}
void Pintar_Muros() {

   

   
    //Pared lateral
    MurosX[0] = 30; MurosY[0] = 40;
    MurosX[1] = 31; MurosY[1] = 40;
    MurosX[2] = 32; MurosY[2] = 40;
    MurosX[3] = 33; MurosY[3] = 40;
    MurosX[4] = 34; MurosY[4] = 40;
    MurosX[5] = 35; MurosY[5] = 40;
    MurosX[6] = 36; MurosY[6] = 40;
    MurosX[7] = 37; MurosY[7] = 40;

   

    gotoxy(30, 40); printf("%c", 35);
    gotoxy(31, 40); printf("%c", 220);

    gotoxy(32, 40); printf("%c", 220);
    gotoxy(33, 40); printf("%c", 220);

    gotoxy(34, 40); printf("%c", 220);
    gotoxy(35, 40); printf("%c", 220);

    gotoxy(36, 40); printf("%c", 220);
    gotoxy(37, 40); printf("%c", 220);

    MurosX[100] = 23; MurosY[100] = 40;
    MurosX[101] = 24; MurosY[1] = 40;
    MurosX[102] = 25; MurosY[2] = 40;
    MurosX[103] = 26; MurosY[3] = 40;
    MurosX[104] = 27; MurosY[4] = 40;
    MurosX[105] = 28; MurosY[5] = 40;
    MurosX[106] = 29; MurosY[6] = 40;
    //MurosX[7] = ; MurosY[7] = 40;


    gotoxy(23, 40); printf("%c", 220);
    gotoxy(24, 40); printf("%c", 220);
    gotoxy(25, 40); printf("%c", 220);
    gotoxy(26, 40); printf("%c", 220);
    gotoxy(27, 40); printf("%c", 220);
    gotoxy(28, 40); printf("%c", 220);
    gotoxy(29, 40); printf("%c", 220);
    //gotoxy(29, 40); printf("%c", 220);




   /* MurosXY[0][0] = 20, 30;
    MurosXY[1][1] = 20, 31;
    MurosXY[2][2] = 20, 32;
    MurosXY[3][3] = 20, 33;*/
    //Muros Verticales
    MurosX[10] = 20; MurosY[10] = 30;
    MurosX[11] = 20; MurosY[11] = 31;
    MurosX[12] = 20; MurosY[12] = 32;
    MurosX[13] = 20; MurosY[13] = 33;
    MurosX[14] = 20; MurosY[14] = 34;
    MurosX[15] = 20; MurosY[15] = 35;
    MurosX[16] = 20; MurosY[16] = 36;
    MurosX[17] = 20; MurosY[17] = 37;

    gotoxy(20, 30); printf("%c", 35);
    gotoxy(20, 31); printf("%c", 219);

    gotoxy(20, 32); printf("%c", 219);
    gotoxy(20, 33); printf("%c", 219);

    gotoxy(20, 34); printf("%c", 219);
    gotoxy(20, 35); printf("%c", 219);

    gotoxy(20, 36); printf("%c", 219);
    gotoxy(20, 37); printf("%c", 219);



    gotoxy(60, 30); printf("%c", 35);
    gotoxy(60, 31); printf("%c", 219);

    gotoxy(60, 32); printf("%c", 219);
    gotoxy(60, 33); printf("%c", 219);

    gotoxy(60, 34); printf("%c", 219);
    gotoxy(60, 35); printf("%c", 219);

    gotoxy(60, 36); printf("%c", 219);
    gotoxy(60, 37); printf("%c", 219);

    MurosX[20] = 20; MurosY[10] = 20;
    MurosX[21] = 20; MurosY[21] = 21;
    MurosX[22] = 20; MurosY[22] = 22;
    MurosX[23] = 20; MurosY[23] = 23;
    MurosX[24] = 20; MurosY[24] = 24;
    MurosX[25] = 20; MurosY[25] = 25;
    MurosX[26] = 20; MurosY[26] = 26;
    MurosX[27] = 20; MurosY[27] = 27;

    gotoxy(20, 20); printf("%c", 219);
    gotoxy(20, 21); printf("%c", 219);

    gotoxy(20, 22); printf("%c", 219);
    gotoxy(20, 23); printf("%c", 219);

    gotoxy(20, 24); printf("%c", 219);
    gotoxy(20, 25); printf("%c", 219);

    gotoxy(20, 26); printf("%c", 219);
    gotoxy(20, 27); printf("%c", 219);



    MurosX[30] = 20; MurosY[30] = 10;
    MurosX[31] = 20; MurosY[31] = 11;
    MurosX[32] = 20; MurosY[32] = 12;
    MurosX[33] = 20; MurosY[33] = 13;
    MurosX[34] = 20; MurosY[34] = 14;
    MurosX[35] = 20; MurosY[35] = 15;
    MurosX[36] = 20; MurosY[36] = 16;
    //MurosX[37] = 20; MurosY[37] = 17;

    gotoxy(20, 10); printf("%c", 35);
    gotoxy(20, 11); printf("%c", 219);

    gotoxy(20, 12); printf("%c", 219);
    gotoxy(20, 13); printf("%c", 219);

    gotoxy(20, 14); printf("%c", 219);
    gotoxy(20, 15); printf("%c", 219);

    gotoxy(20, 16); printf("%c", 219);



    gotoxy(60, 10); printf("%c", 35);
    gotoxy(60, 11); printf("%c", 219);

    gotoxy(60, 12); printf("%c", 219);
    gotoxy(60, 13); printf("%c", 219);

    gotoxy(60, 14); printf("%c", 219);
    gotoxy(60, 15); printf("%c", 219);

    gotoxy(60, 16); printf("%c", 219);



    //Pared Lateral
    gotoxy(23, 7); printf("%c", 220);
    gotoxy(24, 7); printf("%c", 220);
    gotoxy(25, 7); printf("%c", 220);
    gotoxy(25, 7); printf("%c", 220);
    gotoxy(26, 7); printf("%c", 220);
    gotoxy(27, 7); printf("%c", 220);
    gotoxy(28, 7); printf("%c", 220);
    gotoxy(29, 7); printf("%c", 220);
    gotoxy(30, 7); printf("%c", 220);
    gotoxy(31, 7); printf("%c", 220);

    gotoxy(32, 7); printf("%c", 220);
    gotoxy(33, 7); printf("%c", 220);

    gotoxy(34, 7); printf("%c", 220);
    gotoxy(35, 7); printf("%c", 220);

    gotoxy(36, 7); printf("%c", 220);
    gotoxy(37, 7); printf("%c", 220);
    gotoxy(38, 7); printf("%c", 220);
    gotoxy(39, 7); printf("%c", 220);
    gotoxy(40, 7); printf("%c", 220);
    gotoxy(41, 7); printf("%c", 220);
    gotoxy(42, 7); printf("%c", 220);
    gotoxy(43, 7); printf("%c", 220);
    gotoxy(44, 7); printf("%c", 220);
    gotoxy(45, 7); printf("%c", 220);
    gotoxy(46, 7); printf("%c", 220);
    gotoxy(47, 7); printf("%c", 220);
    gotoxy(48, 7); printf("%c", 220);
    gotoxy(49, 7); printf("%c", 220);
    gotoxy(50, 7); printf("%c", 220);
    gotoxy(51, 7); printf("%c", 220);
    gotoxy(52, 7); printf("%c", 220);
    gotoxy(53, 7); printf("%c", 220);
    gotoxy(54, 7); printf("%c", 220);
    gotoxy(55, 7); printf("%c", 220);
    gotoxy(56, 7); printf("%c", 220);
    gotoxy(57, 7); printf("%c", 220);
    gotoxy(58, 7); printf("%c", 220);
    gotoxy(59, 7); printf("%c", 220);



    //gotoxy(20, 17); printf("%c", 219);
    //int Muros[5][5];

    //int muros_size = (sizeof(Muros) / sizeof(Muros[0][0]));

    //for (int x = 12; x < muros_size - 1; x++) {

    //    for (int y = 4; y < muros_size - 1; y++) {
    //        if (x == 12 || x == 23) {

    //            gotoxy(x, y); printf("%c", 35);

    //        }
    //        else if (y == 4 || y == 23) {
    //            gotoxy(x, y); printf("%c", 35);
    //        }
    //        else {
    //            gotoxy(x, y); printf("%c", 46);

    //        }
    //    }
    //}
    //return true;
}
bool Pacman::verificarMovimiento() {
    for (int i = 0; i < 200; i++) {
        if (x+2 == MurosX[i] && y == MurosY[i]) {
            borrar();
            x -= 2;
            return false;

        }
        else if (x - 2 == MurosX[i] && y == MurosY[i]) {
            borrar();
            x += +2;

            return false;
        }
        else if (x == MurosX[i] && y+1 == MurosY[i]) {
            borrar();

            y--;
            return false;

        }
        else if (x == MurosX[i] && y - 1 == MurosY[i]) {
            borrar();

            y++;
            return false;

        }
    }
    return true;
}
bool Pacman::verificarPuntos() {
    for (int i = 0; i < 200; i++) {
        if (x + 2 == MurosXP[i] && y == MurosYP[i]) {
         
            //x -= 2;
            return true;
           
        }
        else if (x - 2 == MurosXP[i] && y == MurosYP[i]) {
            
            //x += +2;

            return true;
        }
        else if (x == MurosXP[i] && y + 1 == MurosYP[i]) {
            

            //y--;
            return true;
            MurosXP[i] = 0;
            MurosYP[i] = 0;
            gotoxy(x, y); printf(" ");
        }
        else if (x == MurosXP[i] && y - 1 == MurosYP[i]) {
            
            
            //y++;
            return true;
          
        }
    }
    return false;

}
void Pacman::pintar() {

    gotoxy(x, y); printf("%c", 62);
    //gotoxy(x, y + 1); printf("  %c%c ", 219, 219);
    //gotoxy(x, y + 1); printf("@-%c-@", 219);

    //gotoxy(x, y+2); printf("%c%c %c%c", 30, 190, 190,30);

}
void Pacman::pintarUP() {
    //::setColor(rlutil::YELLOW);

    gotoxy(x, y); printf("%c", 86);
}
void Pacman::pintarDown() {

    gotoxy(x, y); printf("%c", 94);

}
void Pacman::pintarRight() {

    gotoxy(x, y); printf("%c", 60);

}
void Pacman::borrar() {
    gotoxy(x, y); printf(" ");

   // gotoxy(x, y + 1); printf("         ");
   //gotoxy(x, y + 2); printf("         ");
}
void Pacman::borrarX() {
   // gotoxy(x, y); printf(" ");
    gotoxy(x, y); printf("         ");
     //gotoxy(x, y + 2); printf("         ");
}

void Pacman::mover() {

   /// *Puntaje;
    if (_kbhit()) {

        char tecla = _getch();
        //gotoxy(x, y); printf(" ");
       /* if (x!=MurosX[0]=30) {
            x;
            y;
            gotoxy(75, 12); printf("  Toco Muro");
        }*/
        if (tecla == IZQUIERDA && x>12 && verificarMovimiento()) {
            borrar();
            
            x-=2; 
            pintar();
            if (verificarPuntos() && MurosXP[!0] && MurosYP[!0]) {

                puntaje++;
            }
        }
        if (tecla == DERECHA && x < 73 && verificarMovimiento()) {
            borrar();
            x+=+2;
            pintarRight();
            if (verificarPuntos() && MurosXP[!0] && MurosYP[!0]) {

                puntaje++;
            }
        }
        if (tecla == ARRIBA && y>4 && verificarMovimiento()) {
            borrar();

            y--;
            pintarUP();
            if (verificarPuntos()&& MurosXP[!0] && MurosYP[!0]) {

                puntaje++;
            }
        }
        
       
        if (tecla == ABAJO && y<44 && verificarMovimiento()) {
            borrar();
            y++;
            pintarDown();
            if (verificarPuntos()) {

                puntaje++;
            }

        }if (tecla == 'x')COR();
       // pintar();
          //if(tecla=='c')
        pintar_vidas();
        //gotoxy(x, y); printf(">");
        //pintar();
      

    }

}
void Pacman::pintar_vidas() {

    gotoxy(80, 10); printf("Vidas%d  ", vidas);
    gotoxy(90, 10); printf("      ");
    for (int i = 0; i < vidas; i++)
    {
        gotoxy(80 + i, 15); printf("%c", 43);
    }
   
}
//void Pancitos::Puntaje_Colors() {
//
//    gotoxy(100, 20); printf("Puntaje%d : ", puntos);
//
//}
void Pacman::Puntaje() {
    gotoxy(100, 20); printf("Puntaje%d : ", puntaje);


}
void Pacman::morir() {


    if (vidas == 0) {
        borrar();
        gotoxy(x, y);     printf(" *");
        Sleep(150);
        borrar();
        gotoxy(x, y);     printf("* x *");
  
        Beep(523, 500);
        vidas = 3;
        pintar_vidas();
        pintar();

        borrarX();

    }

}
void Pancitos::pintar() {

   
    string arr[30][30];
    int x, y;

    for (x = 10; x < 30; x++) {

        for (y = 5; y < 30; y++) {

            if(x==15||x==20){

                gotoxy(x, y); printf("%c", 35);
                arr[x][y] = "#";

            }
            else if (x == 5 || x == 20) {


                //arr[x][y] = "#";
            }
        }
    }


   
}
void Pancitos::borrar() {

    gotoxy(x, y); printf("  ");
}
void Pancitos::choque(class Pacman& C) {

    if (x == C.X()&& y==C.Y()) {
        gotoxy(75, 12); printf("    CHoco ");
        borrar();
    }
}
void Pancitos::puntos(int x, int y, class Pacman& P) {
   // Puntos = 0;
    gotoxy(x, y); printf("%c", 46);
    if (x == P.X() && y == P.Y()) {
        //Puntos += 5;
        gotoxy(75, 12); printf("   Puntos ++%d ",Puntos);

        
        Puntaje_Colors();
        borrar();
    }

    //gotoxy(100, 20); printf("Puntaje%d : ", Puntos);
}
void Ghosts::borrar() {

    gotoxy(x, y); printf(" ");

}
void Ghosts::pintar() {

    gotoxy(x, y); printf("%c", 77);
}

void Ghosts::movercpu() {
    time = 0;

     xvi = (rand() % 70) + 6;
    //SetConsoleTextAttribute(C, FOREGROUND_RED | FOREGROUND_INTENSITY);
    time++;
    if (time > 10) {
        time = 0;

    }
    if (xvi > 30 && xvi < 40 && x < 73) {
        borrar();

        x++;

        pintar();
    }
    if (xvi > 20 && xvi < 30 && x < 12) {
        borrar();

        x--;

        pintar();
    }
    if (xvi > 10 && xvi < 19 && y<44) {
        borrar();
        y++;
        pintar();
    }
    if (xvi > 10 && xvi < 19 && y < 4) {
        borrar();
        y--;
        pintar();
    }

   
  
}
void Ghosts::movercpu_2() {
    int distance;
    int pos = 0;
    distance = pos;

    int cpumove;

    bool cpulive = true;
    //SetConsoleTextAttribute(C, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

   /* distance += rand() % 10;
    pos = pos + (distance - pos);*/

    while (cpulive) {

        distance += rand() % 20;
        pos = pos + (distance - pos);

        for (int i = 0; i < pos; i++) {


            if (y < 44 && x < 73) {

                borrar();
                x++;

                pintar();

                pos--;
                if (pos > 10) {
                    borrar();
                    y++;

                    pintar();
                    break;
                }

            }
            else {
                borrar();
                x--;

                pintar();

               // pos--;
                break;
               
                if (x > 13) {
                    borrar();
                    y--;

                    pintar();

                    break;
                }
            }
           

           
        }
        break;
    }


    //int Timer;
    //Timer+= Timer->GetTimeElapsed();
    //int Random = (rand() % 4);
}

int main() {



    OcultarCursor();
    //int x = 10, y = 10;
   // rlutil::hidecursor();
    Pacman A(40,10,3,0);

    Pancitos B(30,38,0);
    Ghosts G(20, 5);
    Ghosts H(40, 20);
    A.pintar();
    A.pintar_vidas();

    G.pintar();
    //gotoxy(x, y); printf(">");
    //rlutil::setBackgroundColor(rlutil::BLUE);

    game_over = false;
    while (!game_over)
    {
        A.Puntaje();
        Pintar_Puntos();

        rlutil::hidecursor();
        //B.pintar();
        B.choque(A);
        pintar_limites();
        A.mover();
        A.morir();
        Pintar_Muros();
        B.puntos(30,30,A);
        G.movercpu_2();
        H.movercpu();
        Sleep(5);
    }

    return 0;

}