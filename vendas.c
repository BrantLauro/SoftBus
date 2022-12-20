#include <stdio.h>
#include "vendas.h"
#include "interface.h"

FILE *fpVendas;

void AbrirArquivoVendas() {
    fpVendas = fopen("vendas.txt","rb+");
    if(fpVendas == NULL){
        fpVendas = fopen("vendas.txt","wb+");
        if(fpVendas == NULL){
            GotoXY(0, 30);
            printf("[ERROR] O programa nao conseguiu abrir o arquivo.");
            exit(1);
        }
    }
}

void SalvarNovoVendas(Vendas C) {
    fseek(fpVendas, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&C, sizeof(Vendas), 1, fpVendas);//Grava
    fflush(fpVendas);
}

void FecharArquivoVendas() {
    fclose(fpVendas);
}

void TelaVendas() {
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(17, 8); printf("        Nome: ");
    GotoXY(17, 11); printf("         CPF: ");
    GotoXY(17, 14); printf("    Telefone: ");
    GotoXY(17, 17); printf("    Endereco: ");
    Borda(32, 7, 60, 2, 0, 0);
    Borda(32, 10, 60, 2, 0, 0);
    Borda(32, 13, 60, 2, 0, 0);
    Borda(32, 16, 60, 2, 0, 0);
}

void ImprimirVendas(Vendas V) {
    GotoXY(34, 8); printf("%s\n", V.Nome);
    GotoXY(34, 11); printf("%s\n", V.CPF);
    GotoXY(34, 14); printf("%s\n", V.Telefone);
    GotoXY(34, 17); printf("%s\n", V.Endereco);
}

Vendas PesquisarVendas() {
    char Nome[51]; Vendas V;
    GotoXY(34,8);
    scanf(" %[^\n]", Nome);
    fseek(fpVendas, 0, SEEK_SET);
    while(fread(&V, sizeof(Vendas), 1, fpVendas)) {
        if(strcmp(V.Nome, Nome) == 0)
            return V;
    }
    strcpy(V.Nome, "");
    return V;
}
/*
int CarregarVendas(char Dados[][51]) {
    int n = 0;
    Vendas V;

    fseek(fpVendas, 0, SEEK_SET);

    while(fread(&V, sizeof(Vendas), 1, fpVendas)){
        strcpy(Dados[n], V.Nome);
        n++;
    }
    return n;
}*/

Vendas DigitarVendas() {
    Vendas V;
    GotoXY(34,8); scanf(" %[^\n]", V.Nome);
    GotoXY(34, 11); scanf(" %[^\n]", V.CPF);
    GotoXY(34, 14); scanf(" %[^\n]", V.Telefone);
    GotoXY(34, 17); scanf(" %[^\n]", V.Endereco);
    return V;
}

void AtivarVendas() {
    Vendas V;
    int Escolha = 0;
    char Opcoes[][51] = {"Novo", "Pesquisar", "Alterar", "Sair"};
    char OpcoesConfirma[][51] = {"Confirma", "Cancelar"};
    AbrirArquivoVendas();
    int x[] = {29, 46,67, 89};
    int y[] = {24, 24, 24, 24};
    int xConfirma[] = {47, 67};
    do {
        TelaVendas();
        Borda(25, 23, 10, 2, 0, 0);
        Borda(45, 23, 10, 2, 0, 0);
        Borda(65, 23, 10, 2, 0, 0);
        Borda(85, 23, 10, 2, 0, 0);
        Escolha = Menu(Opcoes, x, y, Escolha, 4);
        if(Escolha == 0) {
            TelaVendas();
            V = DigitarVendas();
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
            if(Escolha == 0)
                SalvarNovoVendas(V);
            else
                Escolha = 0;
        }
        if(Escolha == 1) {
            TelaVendas();
            V = PesquisarVendas();
            if(strlen(V.Nome) > 0)
                ImprimirVendas(V);
            else {
                Borda(49, 10, 25, 4, 1, 0);
                GotoXY(52, 12);
                printf("VENDA NAO FINALIZADA");
            }
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
        }
    } while(Escolha != 3);
    FecharArquivoVendas();
}
