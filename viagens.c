#include "viagens.h"
#include "interface.h"

FILE *fpViagens;

void AbrirArquivoViagens() {
    fpViagens = fopen("viagens.txt","rb+");
    if(fpViagens == NULL) {
        fpViagens = fopen("viagens.txt","wb+");
        if(fpViagens == NULL) {
            GotoXY(0, 30);
            printf("[ERROR] O programa nao conseguiu abrir o arquivo.");
            exit(1);
        }
    }
}

void SalvarNovaViagem(Viagens V) {
    fseek(fpViagens, 0, SEEK_END);
    fwrite(&V, sizeof(Viagens), 1, fpViagens);
    fflush(fpViagens);
}

void FecharArquivoViagens() {
    fclose(fpViagens);
}

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

Viagens DigitarViagens() {
    Viagens V;
    GotoXY(34, 4); scanf("%d", &V.NumeroViagem);
    GotoXY(34, 7); scanf(" %[^\n]", V.LocalSaida);
    GotoXY(34, 10); scanf(" %[^\n]", V.LocalDestino);
    GotoXY(34, 13); scanf(" %[^\n]", V.DiaSaida);
    GotoXY(34, 16); scanf(" %[^\n]", V.HoraSaida);
    GotoXY(34, 19); scanf("%lf", &V.Quilometragem);
    V.Preco = (V.Quilometragem * 1.5) + 2;
    return V;
}

void AtivarViagens() {
    int escolha = 0; Viagens V;
    char opcoes[][51] = {"Novo","Sair"};
    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    AbrirArquivoViagens();
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
            V = DigitarViagens();
            GotoXY(53, 21); printf("Preco = R$%.2lf", V.Preco);
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            escolha = Menu(opcoesConfirma, xConfirma, y, escolha, 2);
            if(escolha == 0){
                SalvarNovaViagem(V);
            } else
                escolha = 0;
        }
    } while(escolha != 1);
    FecharArquivoViagens();
}
