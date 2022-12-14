//
// Created by brant on 12/12/2022.
//

#include "viagens.h"
#include "interface.h"

void TelaViagens() {
    Borda(4, 1, 111, 26, 1, 0);
    GotoXY(16, 6);
    printf("       Numero: ");
    Borda(32, 5, 60, 2, 0, 0);
    GotoXY(16, 9);
    printf("        Saida: ");
    Borda(32, 8, 60, 2, 0, 0);
    GotoXY(16, 12);
    printf("      Destino: ");
    Borda(32, 11, 60, 2, 0, 0);
    GotoXY(16, 15);
    printf("          Dia: ");
    Borda(32, 14, 60, 2, 0, 0);
    GotoXY(16, 18);
    printf("         Hora: ");
    Borda(32, 17, 60, 2, 0, 0);
    GotoXY(16, 21);
    printf("Quilometragem: ");
    Borda(32, 20, 60, 2, 0, 0);

}

void AtivarViagens() {
    int escolha = 0;
    Viagens V;
    char opcoes[][51] = {"Novo","Sair"};
    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    //AbrirArquivoPaciente();
    int x[] = {55, 69};
    int y[] = {24, 24};
    int xConfirma[] = {30, 42};
    do {
        TelaViagens();
        Borda(51, 23, 10, 2, 0, 0);
        Borda(65, 23, 10, 2, 0, 0);
        escolha = Menu(opcoes, x, y, escolha, 4);
        if(escolha == 0){
            TelaViagens();
            //V = DigitarViagens();
            Borda(28, 18, 10, 2, 0, 0);
            Borda(40, 18, 10, 2, 0, 0);
            escolha = Menu(opcoesConfirma, xConfirma, y, escolha, 2);
            if(escolha == 0){
                //SalvarNovoPaciente(P);
            } else
                escolha = 0;
        }
    } while(escolha != 1);
    //FecharArquivoPaciente();
}
