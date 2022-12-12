#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "viagens.h"
#include "clientes.h"
#include "configuracoes.h"
#include "vendas.h"

char opcoes[][51] = {"Cadastrar Viagem", "Pesquisar Viagem", "Realizar Venda",
                     "Cadastrar Cliente", "Excluir Cliente", "Configuracoes"};
int x[] = {22, 52, 83, 21, 53, 84};
int y[] = {13, 13, 13, 18, 18, 18};

void TelaPrincipal () {
    TextBackground(BLACK);
    TextColor(WHITE);
    Borda(0, 0, 118, 28, 1, 0);
    GotoXY(30, 1); printf("________       _____________ ________  ");
    GotoXY(30, 2); printf("__  ___/______ ___  __/__  /____  __ )____  __________");
    GotoXY(30, 3); printf("_____ \\ _  __ \\__  /_  _  __/__  __  |_  / / /__  ___/");
    GotoXY(30, 4); printf("____/ / / /_/ /_  __/  / /_  _  /_/ / / /_/ / _(__  ) ");
    GotoXY(30, 5); printf("/____/  \\____/ /_/     \\__/  /_____/  \\__,_/  /____/");
    Borda(19, 12, 20, 2, 0,0);
    Borda(49, 12, 20, 2, 0,0);
    Borda(79, 12, 20, 2, 0,0);
    Borda(19, 17, 20, 2, 0,0);
    Borda(49, 17, 20, 2, 0,0);
    Borda(79, 17, 20, 2, 0,0);
}

int main() {
    int escolha = 0;
    do {
        TelaPrincipal();
        escolha = Menu(opcoes, x, y, escolha, 6);
        GotoXY(3, 10);
        if(escolha == 0){;
        }
        if(escolha == 1) {
        }
        if(escolha == 2) {
        }
        if(escolha == 3) {
        }
        if(escolha == 4) {
        }
        if(escolha == 5){
        }
    } while(escolha != -1);

    GotoXY(0, 25);
    return  0;
}

