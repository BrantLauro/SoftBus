#include <stdio.h>
#include "interface.h"
#include "viagens.h"
#include "clientes.h"
#include "vendas.h"

char opcoes[][51] = {"Viagens",  "Clientes", "Vendas", "Fechar" };
int x[] = {18, 43, 68, 93};
int y[] = {24, 24, 24, 24};

void TelaPrincipal () {
    TextColoreback(BROWN, BLACK);
    Borda(0, 0, 118, 28, 1, 0);
    GotoXY(34, 1); printf("________       _____________ ________  ");
    GotoXY(34, 2); printf("__  ___/______ ___  __/__  /____  __ )____  __________");
    GotoXY(34, 3); printf("_____ \\ _  __ \\__  /_  _  __/__  __  |_  / / /__  ___/");
    GotoXY(34, 4); printf("____/ / / /_/ /_  __/  / /_  _  /_/ / / /_/ / _(__  ) ");
    GotoXY(34, 5); printf("/____/  \\____/ /_/     \\__/  /_____/  \\__,_/  /____/");
    Borda(13, 23, 15, 2, 0,0);
    Borda(38, 23, 15, 2, 0,0);
    Borda(63, 23, 15, 2, 0,0);
    Borda(88, 23, 15, 2, 0,0);
    GotoXY(28, 9); printf(" .-------------------------------------------------------------.");
    GotoXY(28, 10); printf("'------..-------------..----------..----------..----------..--.|");
    GotoXY(28, 11); printf("|       \\\\            ||          ||          ||          ||  ||");
    GotoXY(28, 12); printf("|        \\\\           ||          ||          ||          ||  ||");
    GotoXY(28, 13); printf("|    ..   ||  _    _  ||    _   _ || _    _   ||    _    _||  ||");
    GotoXY(28, 14); printf("|    ||   || //   //  ||   //  // ||//   //   ||   //   //|| /||");
    GotoXY(28, 15); printf("|_.------\"''----------''----------''----------''----------''--'|");
    GotoXY(28, 16); printf(" |)|      |       |       |       |    |      R&B|      ||==|  |");
    GotoXY(28, 17); printf(" | |      |  _-_  |       |       |    |  .-.    |      ||==| C|");
    GotoXY(28, 18); printf(" | |  __  |.'.-.' |   _   |   _   |    |.'.-.'.  |  __  | \"__=='");
    GotoXY(28, 19); printf(" '---------'|( )|'----------------------'|( )|'----------\"\"");
    GotoXY(28, 20); printf("             '-'                          '-'");
}

// Branch Polimento Iniciadaaaaaaaaa

int main() {
    int escolha = 0;
    do {
        TelaPrincipal();
        escolha = Menu(opcoes, x, y, escolha, 4);
        if(escolha == 0)
            AtivarViagens();
        if(escolha == 1)
            AtivarClientes();
        if(escolha == 2)
            AtivarVendas();
        if(escolha == 3)
            break;
    } while(escolha != -1);

    GotoXY(0, 30);
    return  0;
}
