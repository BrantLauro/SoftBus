//
// Created by brant on 12/12/2022.
//

#ifndef SOFTBUS_INTERFACE_H
#define SOFTBUS_INTERFACE_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081


enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

int GetTecla();
void GotoXY(int x, int y);
void TextColor (int iColor);
void TextBackground (int iColor);
void Borda(int x, int y, int largura, int altura, int tipo, int sombra);
int Menu(char opcoes[][51], int x[], int y[], int opcao, int n);


#endif //SOFTBUS_INTERFACE_H
