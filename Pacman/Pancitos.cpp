//#include "Pancitos.h"
//#include "rlutil.h"
//
//
//using namespace std;
//
//
//
//
//void Pancitos::pintar() {
//
//
//    string arr[30][30];
//    int x, y;
//
//    for (x = 10; x < 30; x++) {
//
//        for (y = 5; y < 30; y++) {
//
//            if (x == 15 || x == 20) {
//
//                gotoxy(x, y); printf("%c", 35);
//                arr[x][y] = "#";
//
//            }
//            else if (x == 5 || x == 20) {
//                //arr[x][y] = "#";
//            }
//        }
//    }
//
//
//
//    gotoxy(30, 35); printf("%c", 250);
//    gotoxy(30, 36); printf("%c", 250);
//
//    gotoxy(30, 25); printf("%c", 250);
//    gotoxy(30, 26); printf("%c", 250);
//
//    gotoxy(30, 15); printf("%c", 250);
//    gotoxy(30, 16); printf("%c", 250);
//
//    gotoxy(30, 5); printf("%c", 250);
//    gotoxy(30, 6); printf("%c", 250);
//}
//void Pancitos::borrar() {
//
//    gotoxy(x, y); printf(" ");
//}
//void Pancitos::choque(class Pacman& C) {
//
//    if (x == C.X() && y == C.Y()) {
//        gotoxy(75, 12); printf("    CHoco ");
//        borrar();
//    }
//}