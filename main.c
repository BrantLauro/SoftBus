#include <stdio.h>
#include "interface.h"
#include "viagens.h"
#include "clientes.h"
#include "configuracoes.h"
#include "vendas.h"

char opcoes[][51] = {"Cadastrar Viagem", "Pesquisar Viagem", "Realizar Venda",
                     "Cadastrar Cliente", "Excluir Cliente", "Configuracoes"};
int x[] = {21, 51, 82, 20, 52, 83};
int y[] = {13, 13, 13, 18, 18, 18};

void TelaPrincipal () {
    TextBackground(BLACK);
    TextColor(WHITE);
    Borda(0, 0, 118, 28, 1, 0);
    GotoXY(34, 1); printf("________       _____________ ________  ");
    GotoXY(34, 2); printf("__  ___/______ ___  __/__  /____  __ )____  __________");
    GotoXY(34, 3); printf("_____ \\ _  __ \\__  /_  _  __/__  __  |_  / / /__  ___/");
    GotoXY(34, 4); printf("____/ / / /_/ /_  __/  / /_  _  /_/ / / /_/ / _(__  ) ");
    GotoXY(34, 5); printf("/____/  \\____/ /_/     \\__/  /_____/  \\__,_/  /____/");
    Borda(18, 12, 20, 2, 0,0);
    Borda(48, 12, 20, 2, 0,0);
    Borda(78, 12, 20, 2, 0,0);
    Borda(18, 17, 20, 2, 0,0);
    Borda(48, 17, 20, 2, 0,0);
    Borda(78, 17, 20, 2, 0,0);
}

int main() {
    int escolha = 0;
    do {
        TelaPrincipal();
        escolha = Menu(opcoes, x, y, escolha, 6);
        Borda(150, 12, 20, 2, 0,0);
        Borda(150, 15, 20, 2, 0,0);
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

