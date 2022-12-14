//
// Created by brant on 12/12/2022.
//

#include "interface.h"

void GotoXY(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int GetTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}

/*void TextColor (int iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void TextBackground (int iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

void Borda(int x, int y, int largura, int altura, int tipo, int sombra){
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3" ,
                   "\xc9\xbb\xc8\xbc\xcd\xba"};
    int i, j;
    GotoXY(x, y); printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][1]);
    for(j = 0; j < altura; j++){
        GotoXY(x, y+j+1); printf("%c", C[tipo][5]);

        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][5]);
        if(sombra) printf("\xb2");
    }
    GotoXY(x, y+altura); printf("%c", C[tipo][2]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][3]);
    if(sombra){
        GotoXY(x+1, y+altura+1);
        for(i = 0; i < largura+2; i++) printf("\xb2");
    }
}

int Menu(char opcoes[][51], int x[], int y[], int opcao, int n){
    int i; int tecla;
    TextColoreback(BROWN, BLACK);
    for(i = 0; i < n; i++) {
        GotoXY(x[i], y[i]); printf("%s", opcoes[i]);
    }
    do {
        TextColoreback(YELLOW, BLACK);
        GotoXY(x[opcao], y[opcao]);
        printf("%s", opcoes[opcao]);
        tecla = GetTecla();
        TextColoreback(BROWN, BLACK);
        if(tecla == 13) return opcao;
        GotoXY(x[opcao], y[opcao]);
        printf("%s", opcoes[opcao]);
        if(tecla == TEC_BAIXO || tecla == TEC_DIR) opcao ++;
        if(tecla == TEC_CIMA || tecla == TEC_ESQ) opcao --;
        if(opcao < 0) opcao = n - 1;
        if(opcao >= n) opcao = 0;
    } while(tecla != 27);
    return -1;
}
