//
// Created by brant on 12/12/2022.
//

#include "viagens.h"
#include "interface.h"

void TelaViagens() {
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(16, 4);
    printf("       Numero: ");
    Borda(32, 3, 60, 2, 0, 0);
    GotoXY(16, 7);
    printf("        Saida: ");
    Borda(32, 6, 60, 2, 0, 0);
    GotoXY(16, 10);
    printf("      Destino: ");
    Borda(32, 9, 60, 2, 0, 0);
    GotoXY(16, 13);
    printf("          Dia: ");
    Borda(32, 12, 60, 2, 0, 0);
    GotoXY(16, 16);
    printf("         Hora: ");
    Borda(32, 15, 60, 2, 0, 0);
    GotoXY(16, 19);
    printf("Quilometragem: ");
    Borda(32, 18, 60, 2, 0, 0);
}

void AtivarViagens() {
    int escolha = 0;
    Viagens V;
    char opcoes[][51] = {"Novo","Sair"};
    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    //AbrirArquivoPaciente();
    int x[] = {49, 69};
    int y[] = {24, 24};
    int xConfirma[] = {47, 67};
    do {
        TelaViagens();
        Borda(45, 23, 10, 2, 0, 0);
        Borda(65, 23, 10, 2, 0, 0);
        escolha = Menu(opcoes, x, y, escolha, 2);
        if(escolha == 0){
            TelaViagens();
            //V = DigitarViagens();
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            escolha = Menu(opcoesConfirma, xConfirma, y, escolha, 2);
            if(escolha == 0){
                //SalvarNovoPaciente(P);
            } else
                escolha = 0;
        }
    } while(escolha != 1);
    //FecharArquivoPaciente();
}
