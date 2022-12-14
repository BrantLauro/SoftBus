//
// Created by brant on 12/12/2022.
//

#include "viagens.h"
#include "interface.h"

void TelaViagens() {
    Borda(4, 1, 111, 26, 1, 0);
    GotoXY(16, 6);
    printf("Numero: ");
    Borda(26, 5, 35, 2, 0, 0);
    GotoXY(16, 9);
    printf("Saida: ");
    Borda(26, 8, 35, 2, 0, 0);
    GotoXY(16, 12);
    printf("Destino: ");
    Borda(26, 11, 35, 2, 0, 0);
    GotoXY(16, 15);
    printf("Dia: ");
    Borda(26, 14, 35, 2, 0, 0);
    GotoXY(16, 18);
    printf("Hora: ");
    Borda(26, 17, 35, 2, 0, 0);
    GotoXY(16, 20);
    printf("Quilometragem: ");
    Borda(26, 17, 35, 2, 0, 0);

}

void AtivarViagens() {
    int escolha = 0;
    Viagens V;
    char opcoes[][51] = {"Novo","Sair"};
    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    //AbrirArquivoPaciente();
    int x[] = {50, 59};
    int y[] = {20, 20};
    int xConfirma[] = {30, 42};
    do {
        TelaViagens();
        Borda(51, 20, 10, 2, 0, 0);
        Borda(59, 20, 10, 2, 0, 0);
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
