
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

using namespace std;

int lvl = 1;
int pos = 1;
char tecla;
int sal = 1;
int xvi;
int time;
int MurosX[250];
int MurosY[250];
int MurosXP[200];
int MurosYP[200];
//int Puntaje=0;
//int Muros[30][30];


bool game_over=false;
HANDLE C = GetStdHandle(STD_OUTPUT_HANDLE);

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
void Pacman::Pintar_Puntos() {
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
    
    //Puntos Lateral Derechoo

    MurosXP[30] = 64; MurosYP[30] = 10;
    MurosXP[31] = 64; MurosYP[31] = 11;
    MurosXP[32] = 64; MurosYP[32] = 12;
    MurosXP[33] = 64; MurosYP[33] = 13;
    MurosXP[34] = 64; MurosYP[34] = 14;
    MurosXP[35] = 64; MurosYP[35] = 15;
    MurosXP[36] = 64; MurosYP[36] = 16;
    MurosXP[37] = 64; MurosYP[37] = 17;

    gotoxy(64, 10); printf("%c", 46);
    gotoxy(64, 11); printf("%c", 46);

    gotoxy(64, 12); printf("%c", 46);
    gotoxy(64, 13); printf("%c", 46);

    gotoxy(64, 14); printf("%c", 46);
    gotoxy(64, 15); printf("%c", 46);

    gotoxy(64, 16); printf("%c", 46);
    gotoxy(64, 17); printf("%c", 46);

    MurosXP[40] = 64; MurosYP[40] = 20;
    MurosXP[41] = 64; MurosYP[41] = 21;
    MurosXP[42] = 64; MurosYP[42] = 22;
    MurosXP[43] = 64; MurosYP[43] = 23;
    MurosXP[44] = 64; MurosYP[44] = 24;
    MurosXP[45] = 64; MurosYP[45] = 25;
    MurosXP[46] = 64; MurosYP[46] = 26;
    MurosXP[47] = 64; MurosYP[47] = 27;


    gotoxy(64, 20); printf("%c", 46);
    gotoxy(64, 21); printf("%c", 46);

    gotoxy(64, 22); printf("%c", 46);
    gotoxy(64, 23); printf("%c", 46);

    gotoxy(64, 24); printf("%c", 46);
    gotoxy(64, 25); printf("%c", 46);

    gotoxy(64, 26); printf("%c", 46);
    gotoxy(64, 27); printf("%c", 46);

    MurosXP[50] = 64; MurosYP[50] = 30;
    MurosXP[51] = 64; MurosYP[51] = 31;
    MurosXP[52] = 64; MurosYP[52] = 32;
    MurosXP[53] = 64; MurosYP[53] = 33;
    MurosXP[54] = 64; MurosYP[54] = 34;
    MurosXP[55] = 64; MurosYP[55] = 35;
    MurosXP[56] = 64; MurosYP[56] = 36;
    MurosXP[57] = 64; MurosYP[57] = 37;
    gotoxy(64, 30); printf("%c", 46);
    gotoxy(64, 31); printf("%c", 46);

    gotoxy(64, 32); printf("%c", 46);
    gotoxy(64, 33); printf("%c", 46);

    gotoxy(64, 34); printf("%c", 46);
    gotoxy(64, 35); printf("%c", 46);

    gotoxy(64, 36); printf("%c", 46);
    gotoxy(64, 37); printf("%c", 46);

    gotoxy(44, 17); printf("*");

    //Puntos Lteral Derecho Inferior
    MurosXP[60] = 54; MurosYP[60] = 10;
    MurosXP[61] = 54; MurosYP[61] = 11;
    MurosXP[62] = 54; MurosYP[62] = 12;
    MurosXP[63] = 54; MurosYP[63] = 13;
    MurosXP[64] = 54; MurosYP[64] = 14;
    MurosXP[65] = 54; MurosYP[65] = 15;
    MurosXP[66] = 54; MurosYP[66] = 16;
    MurosXP[67] = 54; MurosYP[67] = 17;
    gotoxy(54, 10); printf("%c", 46);
    gotoxy(54, 11); printf("%c", 46);

    gotoxy(54, 12); printf("%c", 46);
    gotoxy(54, 13); printf("%c", 46);

    gotoxy(54, 14); printf("%c", 46);
    gotoxy(54, 15); printf("%c", 46);

    gotoxy(54, 16); printf("%c", 46);
    gotoxy(54, 17); printf("%c", 46);

    MurosXP[70] = 54; MurosYP[70] = 20;
    MurosXP[71] = 54; MurosYP[71] = 21;
    MurosXP[72] = 54; MurosYP[72] = 22;
    MurosXP[73] = 54; MurosYP[73] = 23;
    MurosXP[74] = 54; MurosYP[74] = 24;
    MurosXP[75] = 54; MurosYP[75] = 25;
    MurosXP[76] = 54; MurosYP[76] = 26;
    MurosXP[77] = 54; MurosYP[77] = 27;

    gotoxy(54, 20); printf("%c", 46);
    gotoxy(54, 21); printf("%c", 46);

    gotoxy(54, 22); printf("%c", 46);
    gotoxy(54, 23); printf("%c", 46);

    gotoxy(54, 24); printf("%c", 46);
    gotoxy(54, 25); printf("%c", 46);

    gotoxy(54, 26); printf("%c", 46);
    gotoxy(54, 27); printf("%c", 46);
    MurosXP[80] = 54; MurosYP[80] = 30;
    MurosXP[81] = 54; MurosYP[81] = 31;
    MurosXP[82] = 54; MurosYP[82] = 32;
    MurosXP[83] = 54; MurosYP[83] = 33;
    MurosXP[84] = 54; MurosYP[84] = 34;
    MurosXP[85] = 54; MurosYP[85] = 35;
    MurosXP[86] = 54; MurosYP[86] = 36;
    MurosXP[87] = 54; MurosYP[87] = 37;

    gotoxy(54, 30); printf("%c", 46);
    gotoxy(54, 31); printf("%c", 46);

    gotoxy(54, 32); printf("%c", 46);
    gotoxy(54, 33); printf("%c", 46);

    gotoxy(54, 34); printf("%c", 46);
    gotoxy(54, 35); printf("%c", 46);

    gotoxy(54, 36); printf("%c", 46);
    gotoxy(54, 37); printf("%c", 46);

    MurosXP[90] = 24; MurosYP[90] = 10;
    MurosXP[91] = 24; MurosYP[91] = 11;
    MurosXP[92] = 24; MurosYP[92] = 12;
    MurosXP[93] = 24; MurosYP[93] = 13;
    MurosXP[94] = 24; MurosYP[94] = 14;
    MurosXP[95] = 24; MurosYP[95] = 15;
    MurosXP[96] = 24; MurosYP[96] = 16;
    MurosXP[97] = 24; MurosYP[97] = 17;

    gotoxy(24, 10); printf("%c", 46);
    gotoxy(24, 11); printf("%c", 46);

    gotoxy(24, 12); printf("%c", 46);
    gotoxy(24, 13); printf("%c", 46);

    gotoxy(24, 14); printf("%c", 46);
    gotoxy(24, 15); printf("%c", 46);

    gotoxy(24, 16); printf("%c", 46);
    gotoxy(24, 17); printf("%c", 46);

    MurosXP[100] = 24; MurosYP[100] = 20;
    MurosXP[101] = 24; MurosYP[101] = 21;
    MurosXP[102] = 24; MurosYP[102] = 22;
    MurosXP[103] = 24; MurosYP[103] = 23;
    MurosXP[104] = 24; MurosYP[104] = 24;
    MurosXP[105] = 24; MurosYP[105] = 25;
    MurosXP[106] = 24; MurosYP[106] = 26;
    MurosXP[107] = 24; MurosYP[107] = 27;

    gotoxy(24, 20); printf("%c", 46);
    gotoxy(24, 21); printf("%c", 46);

    gotoxy(24, 22); printf("%c", 46);
    gotoxy(24, 23); printf("%c", 46);

    gotoxy(24, 24); printf("%c", 46);
    gotoxy(24, 25); printf("%c", 46);

    gotoxy(24, 26); printf("%c", 46);
    gotoxy(24, 27); printf("%c", 46);

    MurosXP[110] = 24; MurosYP[110] = 30;
    MurosXP[111] = 24; MurosYP[111] = 31;
    MurosXP[112] = 24; MurosYP[112] = 32;
    MurosXP[113] = 24; MurosYP[113] = 33;
    MurosXP[114] = 24; MurosYP[114] = 34;
    MurosXP[115] = 24; MurosYP[115] = 35;
    MurosXP[116] = 24; MurosYP[116] = 36;
    MurosXP[117] = 24; MurosYP[117] = 37;

    gotoxy(24, 30); printf("%c", 46);
    gotoxy(24, 31); printf("%c", 46);

    gotoxy(24, 32); printf("%c", 46);
    gotoxy(24, 33); printf("%c", 46);

    gotoxy(24, 34); printf("%c", 46);
    gotoxy(24, 35); printf("%c", 46);

    gotoxy(24, 36); printf("%c", 46);
    gotoxy(24, 37); printf("%c", 46);
    //Puntos  Superior Lateral
    MurosXP[118] = 23; MurosYP[118] = 5;
    MurosXP[119] = 24; MurosYP[119] = 5;
    MurosXP[120] = 25; MurosYP[120] = 5;
    MurosXP[121] = 26; MurosYP[121] = 5;
    MurosXP[122] = 27; MurosYP[122] = 5;
    MurosXP[123] = 28; MurosYP[123] = 5;
    MurosXP[124] = 29; MurosYP[124] = 5;
    MurosXP[125] = 30; MurosYP[125] = 5;
    MurosXP[126] = 31; MurosYP[126] = 5;
    MurosXP[127] = 32; MurosYP[127] = 5;
    MurosXP[128] = 33; MurosYP[128] = 5;
    MurosXP[129] = 34; MurosYP[129] = 5;
    MurosXP[130] = 35; MurosYP[130] = 5;
    MurosXP[131] = 40; MurosYP[131] = 5;
    MurosXP[132] = 41; MurosYP[132] = 5;
    MurosXP[133] = 42; MurosYP[133] = 5;
    MurosXP[134] = 43; MurosYP[134] = 5;
    MurosXP[135] = 44; MurosYP[135] = 5;
    MurosXP[136] = 45; MurosYP[136] = 5;
    MurosXP[137] = 46; MurosYP[137] = 5;
    MurosXP[138] = 47; MurosYP[138] = 5;
    MurosXP[139] = 48; MurosYP[139] = 5;
    MurosXP[140] = 49; MurosYP[140] = 5;
    MurosXP[141] = 50; MurosYP[141] = 5;
    MurosXP[142] = 51; MurosYP[142] = 5;
    MurosXP[143] = 42; MurosYP[143] = 5;

    gotoxy(23, 5); printf("%c", 250);
    gotoxy(24, 5); printf("%c", 250);
    gotoxy(25, 5); printf("%c", 250);
    gotoxy(26, 5); printf("%c", 250);
    gotoxy(27, 5); printf("%c", 250);
    gotoxy(28, 5); printf("%c", 250);
    gotoxy(29, 5); printf("%c", 250);
    gotoxy(30, 5); printf("%c", 250);
    gotoxy(31, 5); printf("%c", 250);
    gotoxy(32, 5); printf("%c", 250);
    gotoxy(33, 5); printf("%c", 250);
    gotoxy(34, 5); printf("%c", 250);
    gotoxy(35, 5); printf("%c", 250);

    gotoxy(40, 5); printf("%c", 250);
    gotoxy(41, 5); printf("%c", 250);
    gotoxy(42, 5); printf("%c", 250);
    gotoxy(43, 5); printf("%c", 250);
    gotoxy(44, 5); printf("%c", 250);
    gotoxy(45, 5); printf("%c", 250);
    gotoxy(46, 5); printf("%c", 250);
    gotoxy(47, 5); printf("%c", 250);
    gotoxy(48, 5); printf("%c", 250);
    gotoxy(49, 5); printf("%c", 250);
    gotoxy(50, 5); printf("%c", 250);
    gotoxy(51, 5); printf("%c", 250);
    gotoxy(52, 5); printf("%c", 250);


    MurosXP[150] = 35; MurosYP[150] = 10;
    MurosXP[151] = 36; MurosYP[151] = 10;
    MurosXP[152] = 37; MurosYP[152] = 10;
    MurosXP[153] = 38; MurosYP[153] = 10;
    MurosXP[154] = 39; MurosYP[154] = 10;
    MurosXP[155] = 40; MurosYP[155] = 10;
    MurosXP[156] = 41; MurosYP[156] = 10;
    MurosXP[157] = 42; MurosYP[157] = 10;

    MurosXP[160] = 35; MurosYP[160] = 37;
    MurosXP[161] = 36; MurosYP[161] = 37;
    MurosXP[162] = 37; MurosYP[162] = 37;
    MurosXP[163] = 38; MurosYP[163] = 37;
    MurosXP[164] = 39; MurosYP[164] = 37;
    MurosXP[165] = 40; MurosYP[165] = 37;
    MurosXP[166] = 41; MurosYP[166] = 37;
    MurosXP[167] = 42; MurosYP[167] = 37;


    gotoxy(35, 10); printf("%c", 250);
    gotoxy(36, 10); printf("%c", 250);
    gotoxy(37, 10); printf("%c", 250);
    gotoxy(38, 10); printf("%c", 250);


    gotoxy(39, 10); printf("%c", 250);
    gotoxy(40, 10); printf("%c", 250);
    gotoxy(41, 10); printf("%c", 250);
    gotoxy(42, 10); printf("%c", 250);

    gotoxy(35, 37); printf("%c", 250);
    gotoxy(36, 37); printf("%c", 250);
    gotoxy(37, 37); printf("%c", 250);
    gotoxy(38, 37); printf("%c", 250);

    gotoxy(39, 37); printf("%c", 250);
    gotoxy(40, 37); printf("%c", 250);
    gotoxy(41, 37); printf("%c", 250);
    gotoxy(42, 37); printf("%c", 250);
}
void Pintar_Muros() {

   

   
    //Pared lateral Superior de Abajo
    MurosX[0] = 30; MurosY[0] = 40;
    MurosX[1] = 31; MurosY[1] = 40;
    MurosX[2] = 32; MurosY[2] = 40;
    MurosX[3] = 33; MurosY[3] = 40;
    MurosX[4] = 34; MurosY[4] = 40;
    MurosX[5] = 35; MurosY[5] = 40;
    MurosX[6] = 36; MurosY[6] = 40;
    MurosX[7] = 37; MurosY[7] = 40;



    gotoxy(23, 40); printf("%c", 35);
    gotoxy(24, 40); printf("%c", 220);
    gotoxy(25, 40); printf("%c", 220);
    gotoxy(26, 40); printf("%c", 220);
    gotoxy(27, 40); printf("%c", 220);
    gotoxy(28, 40); printf("%c", 220);
    gotoxy(29, 40); printf("%c", 220);

    gotoxy(30, 40); printf("%c", 35);
    gotoxy(31, 40); printf("%c", 220);

    gotoxy(32, 40); printf("%c", 220);
    gotoxy(33, 40); printf("%c", 220);

    gotoxy(34, 40); printf("%c", 220);
    gotoxy(35, 40); printf("%c", 220);

    gotoxy(36, 40); printf("%c", 220);
    gotoxy(37, 40); printf("%c", 220);
    gotoxy(38, 40); printf("%c", 220);
    gotoxy(39, 40); printf("%c", 220);
    gotoxy(40, 40); printf("%c", 220);
    gotoxy(41, 40); printf("%c", 220);
    gotoxy(42, 40); printf("%c", 220);
    gotoxy(43, 40); printf("%c", 220);
    gotoxy(44, 40); printf("%c", 220);
    gotoxy(45, 40); printf("%c", 220);
    gotoxy(46, 40); printf("%c", 220);
    gotoxy(47, 40); printf("%c", 220);
    gotoxy(48, 40); printf("%c", 220);
    gotoxy(49, 40); printf("%c", 220);
    gotoxy(50, 40); printf("%c", 220);
    gotoxy(51, 40); printf("%c", 220);
    gotoxy(52, 40); printf("%c", 220);
    gotoxy(53, 40); printf("%c", 220);
    gotoxy(54, 40); printf("%c", 220);
    gotoxy(55, 40); printf("%c", 220);
    gotoxy(56, 40); printf("%c", 220);
    //gotoxy(57, 40); printf("%c", 220);


    MurosX[100] = 23; MurosY[100] = 40;
    MurosX[101] = 24; MurosY[101] = 40;
    MurosX[102] = 25; MurosY[102] = 40;
    MurosX[103] = 26; MurosY[103] = 40;
    MurosX[104] = 27; MurosY[104] = 40;
    MurosX[105] = 28; MurosY[105] = 40;
    MurosX[106] = 29; MurosY[106] = 40;
    MurosX[107] = 30; MurosY[107] = 40;
    MurosX[108] = 31; MurosY[108] = 40;
    MurosX[109] = 32; MurosY[109] = 40;
    MurosX[110] = 33; MurosY[110] = 40;
    MurosX[111] = 34; MurosY[111] = 40;
    MurosX[112] = 35; MurosY[112] = 40;
    MurosX[113] = 36; MurosY[113] = 40;
    MurosX[114] = 37; MurosY[114] = 40;
    MurosX[115] = 38; MurosY[115] = 40;
    MurosX[116] = 39; MurosY[116] = 40;
    MurosX[117] = 40; MurosY[117] = 40;
    MurosX[118] = 41; MurosY[118] = 40;
    MurosX[119] = 42; MurosY[119] = 40;
    MurosX[120] = 43; MurosY[120] = 40;
    MurosX[121] = 44; MurosY[121] = 40;
    MurosX[122] = 45; MurosY[122] = 40;
    MurosX[123] = 46; MurosY[123] = 40;
    MurosX[124] = 47; MurosY[124] = 40;
    MurosX[125] = 48; MurosY[125] = 40;
    MurosX[126] = 49; MurosY[126] = 40;
    MurosX[127] = 50; MurosY[127] = 40;
    MurosX[128] = 51; MurosY[128] = 40;
    MurosX[129] = 52; MurosY[129] = 40;
    MurosX[130] = 53; MurosY[130] = 40;
    MurosX[131] = 54; MurosY[131] = 40;
    MurosX[132] = 55; MurosY[132] = 40;


    //Muros Verticales Superior Izquierda
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

    //Muros Verticales Superior Derecha
   // MurosX[40] = 60; MurosY[40] = 30;
    MurosX[41] = 60; MurosY[41] = 31;
    MurosX[42] = 60; MurosY[42] = 32;
    MurosX[43] = 60; MurosY[43] = 33;
    MurosX[44] = 60; MurosY[44] = 34;
    MurosX[45] = 60; MurosY[45] = 35;
    MurosX[46] = 60; MurosY[46] = 36;

   // gotoxy(60, 30); printf("%c", 35);
    gotoxy(60, 31); printf("%c", 35);

    gotoxy(60, 32); printf("%c", 219);
    gotoxy(60, 33); printf("%c", 219);

    gotoxy(60, 34); printf("%c", 219);
    gotoxy(60, 35); printf("%c", 219);

    gotoxy(60, 36); printf("%c", 219);
    gotoxy(60, 37); printf("%c", 219);

    MurosX[50] = 60; MurosY[50] = 20;
    MurosX[51] = 60; MurosY[51] = 21;
    MurosX[52] = 60; MurosY[52] = 22;
    MurosX[53] = 60; MurosY[53] = 23;
    MurosX[54] = 60; MurosY[54] = 24;
    MurosX[55] = 60; MurosY[55] = 25;
    MurosX[56] = 60; MurosY[56] = 26;
    MurosX[57] = 60; MurosY[57] = 27;
    MurosX[58] = 60; MurosY[58] = 10;
    MurosX[59] = 60; MurosY[59] = 11;
    MurosX[60] = 60; MurosY[60] = 12;
    MurosX[61] = 60; MurosY[61] = 13;
    MurosX[62] = 60; MurosY[62] = 14;
    MurosX[63] = 60; MurosY[63] = 15;
    MurosX[64] = 60; MurosY[64] = 16;


    gotoxy(60, 20); printf("%c", 35);
    gotoxy(60, 21); printf("%c", 219);

    gotoxy(60, 22); printf("%c", 219);
    gotoxy(60, 23); printf("%c", 219);

    gotoxy(60, 24); printf("%c", 219);
    gotoxy(60, 25); printf("%c", 219);

    gotoxy(60, 26); printf("%c", 219);
    gotoxy(60, 27); printf("%c", 219);

    gotoxy(60, 10); printf("%c", 35);
    gotoxy(60, 11); printf("%c", 219);

    gotoxy(60, 12); printf("%c", 219);
    gotoxy(60, 13); printf("%c", 219);

    gotoxy(60, 14); printf("%c", 219);
    gotoxy(60, 15); printf("%c", 219);

    gotoxy(60, 16); printf("%c", 219);



    //Pared Lateral Superior Derecha

    MurosX[140] = 23; MurosY[140] = 7;
    MurosX[141] = 24; MurosY[141] = 7;
    MurosX[142] = 25; MurosY[142] = 7;
    MurosX[143] = 26; MurosY[143] = 7;
    MurosX[144] = 27; MurosY[144] = 7;
    MurosX[145] = 28; MurosY[145] = 7;
    MurosX[146] = 29; MurosY[146] = 7;
    MurosX[147] = 30; MurosY[147] = 7;
    MurosX[148] = 31; MurosY[148] = 7;
    MurosX[149] = 32; MurosY[149] = 7;
    MurosX[150] = 33; MurosY[150] = 7;
    MurosX[151] = 34; MurosY[151] = 7;
    MurosX[152] = 35; MurosY[152] = 7;
    MurosX[153] = 36; MurosY[153] = 7;
    MurosX[154] = 37; MurosY[154] = 7;
    MurosX[155] = 38; MurosY[155] = 7;
    MurosX[156] = 39; MurosY[156] = 7;
    MurosX[157] = 40; MurosY[157] = 7;
    MurosX[158] = 41; MurosY[158] = 7;
    MurosX[159] = 42; MurosY[159] = 7;
    MurosX[160] = 43; MurosY[160] = 7;
    MurosX[161] = 44; MurosY[161] = 7;
    MurosX[162] = 45; MurosY[162] = 7;
    MurosX[163] = 46; MurosY[163] = 7;
    MurosX[164] = 47; MurosY[164] = 7;
    MurosX[165] = 48; MurosY[165] = 7;
    MurosX[166] = 49; MurosY[166] = 7;
    MurosX[167] = 50; MurosY[167] = 7;
    MurosX[168] = 51; MurosY[168] = 7;
    MurosX[169] = 52; MurosY[169] = 7;
    MurosX[170] = 53; MurosY[170] = 7;
    MurosX[171] = 54; MurosY[171] = 7;
    MurosX[172] = 55; MurosY[172] = 7;
    MurosX[173] = 56; MurosY[173] = 7;
    MurosX[174] = 57; MurosY[174] = 7;

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

    //Cruz
    MurosX[175] = 40; MurosY[175] = 15;
    MurosX[176] = 40; MurosY[176] = 16;
    MurosX[177] = 40; MurosY[177] = 17;
    MurosX[178] = 40; MurosY[178] = 18;
    MurosX[179] = 40; MurosY[179] = 19;
    MurosX[179] = 40; MurosY[179] = 20;
    MurosX[180] = 40; MurosY[180] = 21;
    MurosX[181] = 40; MurosY[181] = 22;
    MurosX[182] = 40; MurosY[182] = 23;
    MurosX[183] = 40; MurosY[183] = 24;
    MurosX[184] = 40; MurosY[184] = 25;
    MurosX[185] = 40; MurosY[185] = 26;
    MurosX[186] = 40; MurosY[186] = 27;
    MurosX[187] = 40; MurosY[187] = 28;
    MurosX[189] = 40; MurosY[189] = 29;
    MurosX[190] = 40; MurosY[190] = 30;

    gotoxy(40, 15); printf("%c", 219);
    gotoxy(40, 16); printf("%c", 219);
    gotoxy(40, 17); printf("%c", 219);
    gotoxy(40, 18); printf("%c", 219);
    gotoxy(40, 19); printf("%c", 219);


    gotoxy(40, 20); printf("%c", 219);
    gotoxy(40, 20); printf("%c", 219);
    gotoxy(40, 21); printf("%c", 219);
    gotoxy(40, 22); printf("%c", 219);
    gotoxy(40, 23); printf("%c", 219);
    gotoxy(40, 24); printf("%c", 219);
    gotoxy(40, 25); printf("%c", 219);
    gotoxy(40, 26); printf("%c", 219);
    gotoxy(40, 27); printf("%c", 219);
    gotoxy(40, 28); printf("%c", 219);
    gotoxy(40, 29); printf("%c", 219);
    gotoxy(40, 30); printf("%c", 219);


    MurosX[191] = 41; MurosY[191] = 23;
    MurosX[192] = 42; MurosY[192] = 23;
    MurosX[193] = 43; MurosY[193] = 23;
    MurosX[194] = 44; MurosY[194] = 23;
    MurosX[195] = 45; MurosY[195] = 23;
    MurosX[196] = 46; MurosY[196] = 23;
    MurosX[197] = 47; MurosY[197] = 23;
    MurosX[198] = 48; MurosY[198] = 23;

    gotoxy(41, 23); printf("%c", 219);
    gotoxy(42, 23); printf("%c", 219);
    gotoxy(43, 23); printf("%c", 219);
    gotoxy(44, 23); printf("%c", 219);
    gotoxy(45, 23); printf("%c", 219);
    gotoxy(46, 23); printf("%c", 219);
    gotoxy(47, 23); printf("%c", 219);
    gotoxy(48, 23); printf("%c", 219);
    
    MurosX[199] = 39; MurosY[199] = 23;
    MurosX[200] = 38; MurosY[200] = 23;
    MurosX[201] = 37; MurosY[201] = 23;
    MurosX[202] = 36; MurosY[202] = 23;
    MurosX[203] = 35; MurosY[203] = 23;
    MurosX[204] = 34; MurosY[204] = 23;
    MurosX[205] = 33; MurosY[205] = 23;
    MurosX[206] = 32; MurosY[206] = 23;

    gotoxy(39, 23); printf("%c", 219);
    gotoxy(38, 23); printf("%c", 219);
    gotoxy(37, 23); printf("%c", 219);
    gotoxy(36, 23); printf("%c", 219);
    gotoxy(35, 23); printf("%c", 219);
    gotoxy(34, 23); printf("%c", 219);
    gotoxy(33, 23); printf("%c", 219);
    gotoxy(32, 23); printf("%c", 219);
}
bool Pacman::verificarMovimiento() {
    for (int i = 0; i < 250; i++) {
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
            gotoxy(x, y); printf(" ");
            MurosXP[i] = 0;
            MurosYP[i] = 0;
            pintar();
            return true;
           
        }
        else if (x - 2 == MurosXP[i] && y == MurosYP[i]) {
            
            //x += +2;
            gotoxy(x, y); printf(" ");
            MurosXP[i] = 0;
            MurosYP[i] = 0;
            gotoxy(x, y); printf("<");

            return true;
        }
        else if (x == MurosXP[i] && y + 1 == MurosYP[i]) {
            

            //y--;
            gotoxy(x, y); printf(" ");
            MurosXP[i] = 0;
            MurosYP[i] = 0;
            //pintar();
            gotoxy(x, y); printf("^");
            return true;
            

        }
        else if (x == MurosXP[i] && y - 1 == MurosYP[i]) {
            
            gotoxy(x, y); printf(" ");
            MurosXP[i] = 0;
            MurosYP[i] = 0;
            //pintar();
            //y++;
            gotoxy(x, y); printf("V");
            return true;
          
        }
    }
    return false;

}
void Pacman::pintar() {

    gotoxy(x, y); printf("%c", 62);

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

void Pacman::Puntaje() {
    gotoxy(80, 20); printf("Puntaje: %d", puntaje);


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
        game_over = true;
    }

}

void Ghosts::borrar() {

    gotoxy(x, y); printf(" ");

}
void Ghosts::pintar() {

    gotoxy(x, y); printf("%c", 77);
}
 bool Ghosts::verificarMovimiento() {
     for (int i = 0; i < 250; i++) {
         if (x + 2 == MurosX[i] && y == MurosY[i]) {
             borrar();
             x --;
             return false;

         }
         else if (x - 2 == MurosX[i] && y == MurosY[i]) {
             borrar();
             x ++;

             return false;
         }
         else if (x == MurosX[i] && y + 1 == MurosY[i]) {
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
void Ghosts::movercpu() {
 
    
    SetConsoleTextAttribute(C, FOREGROUND_RED | FOREGROUND_INTENSITY);
    time++;
    if (time > 5) {
        time = 0;
        xvi = (rand() % 70) + 6;
    }
    if (xvi > 30 && xvi < 40 && x < 73 && verificarMovimiento()) {
        borrar();

        x++;

        pintar();
    }
    if (xvi > 20 && xvi < 30 && x < 12 && verificarMovimiento()) {
        borrar();

        x--;

        pintar();
    }
    if (xvi > 10 && xvi < 19 && y<44 && verificarMovimiento()) {
        borrar();
        y++;
        pintar();
    }
    if (xvi > 10 && xvi < 19 && y < 4 && verificarMovimiento()) {
        borrar();
        y--;
        pintar();
    }

   
  
}
void Ghosts::movercpu_2() {

    SetConsoleTextAttribute(C, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

      time++;
    if (time > 5) {
        time = 0;
        xvi = (rand() % 70) + 6;
    }
    if (xvi > 30 && xvi < 40 && x < 73 && verificarMovimiento()) {
        borrar();

        x++;

        pintar();
    }
    if (xvi > 20 && xvi < 30 && x < 12 && verificarMovimiento()) {
        borrar();

        x--;

        pintar();
    }
    if (xvi > 10 && xvi < 19 && y<4 &&y<44 && verificarMovimiento()) {
        borrar();
        y--;
        pintar();
    }
    if (xvi > 41 && xvi < 51 && y < 4 && verificarMovimiento()) {
        borrar();
        y++;
        pintar();
    }
   // int distance;
   // int pos = 0;
   // distance = pos;

   // int cpumove;

   // bool cpulive = true;
   // SetConsoleTextAttribute(C, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

   ///* distance += rand() % 10;
   // pos = pos + (distance - pos);*/

   // while (cpulive) {

   //     distance += rand() % 20;
   //     pos = pos + (distance - pos);

   //     for (int i = 0; i < pos; i++) {


   //         if (y < 44 && x < 73 && x>13&& verificarMovimiento()){

   //             borrar();
   //             x++;

   //             pintar();

   //             pos--;
   //             if (pos > 10) {
   //                 borrar();
   //                 y++;

   //                 pintar();
   //                 break;
   //             }

   //         }
   //         else {
   //             borrar();
   //             x--;

   //             pintar();

   //            // pos--;
   //             break;
   //            
   //             if (x > 13) {
   //                 borrar();
   //                 y--;

   //                 pintar();

   //                 break;
   //             }
   //         }
   //        

   //        
   //     }
   //     break;
   // }


}
void Ghosts::choque(class Pacman& C) {

    if (x == C.X() && y == C.Y()) {
        

        C.COR();
        Beep(523, 500);
        C.pintar();
        C.pintar_vidas();
    }
}
void Menu() {

  
        gotoxy(60, 20); printf("Pacman: >");
        gotoxy(60, 22); printf("GHOSTS: M");

    gotoxy(40, 20); printf(" Play");
    gotoxy(40, 22); printf(" SALIR");
    gotoxy(40, 24); printf(">");
    sal = 1;

    do {
        tecla = _getch();
        if (tecla == 'w') {
            gotoxy(39, 20); printf(">");
            gotoxy(39, 22); printf(" ");
            pos = 2;
        }
        else {
            if (tecla == 's') {
                gotoxy(39, 20); printf(" ");
                gotoxy(39, 22); printf(">");
                pos = 2;
            }
        }
        if (tecla == ' ') {
            if (pos == 2) {
                sal = 2;
                //vidas = 5;
            }
            else {
                if (pos == 2) {
                    sal = 5;
                }
            }
        }
    } while (sal == 1);
    rlutil::cls(); 
}
void Game() {

   // bool game_over;
    Pacman A(40, 10, 3, 0);
    game_over = false;
    Ghosts G(44, 17);
    Ghosts H(44, 27);
    Ghosts O(34, 17);
    Ghosts S(34, 27);

    A.pintar();
    A.pintar_vidas();
    A.Pintar_Puntos();
    G.pintar();
    while (!game_over)
    {
        A.Puntaje();


        rlutil::hidecursor();
        
        pintar_limites();
        A.mover();
        A.morir();
        Pintar_Muros();
        
        G.movercpu_2(); G.choque(A);
        H.movercpu(); H.choque(A);
        O.movercpu(); O.choque(A);
        S.movercpu(); S.choque(A);

        Sleep(5);
        if (game_over == true) {
            rlutil::cls();
            //system("CLS");
            gotoxy(50, 24); printf("****GAME OVER!***");



            Beep(587, 500);
            Beep(659, 500);
            Beep(698, 500);
            Beep(784, 500);
           // gotoxy(50, 25); printf("Presiona Y si quieres regresar");
            //run_again = _getch();

        }
    }


}
int main() {


    while (sal != 5) {
        rlutil::cls();

        Menu();

        while (sal == 2) {
            Game();

        }
    }

   

}