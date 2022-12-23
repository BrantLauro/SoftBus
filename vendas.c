#include <stdio.h>
#include "vendas.h"
#include "viagens.h"
#include "clientes.h"
#include "interface.h"
#include "configuracoes.h"

FILE *fpVendas;
FILE *fpClientesV;
FILE *fpViagensV;
FILE *fpConfiguracoesVen;

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

void SalvarNovaVenda(Vendas C) {
    fseek(fpVendas, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&C, sizeof(Vendas), 1, fpVendas);//Grava
    fflush(fpVendas);
}

void FecharArquivoVendas() {
    fclose(fpVendas);
}

void TelaVendas() {
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(20, 4);
    printf("     Nome: ");
    Borda(32, 3, 60, 2, 0, 0);
    GotoXY(20, 7);
    printf("     CPF: ");
    Borda(32, 6, 60, 2, 0, 0);
    GotoXY(20, 10);
    printf("Telefone: ");
    Borda(32, 9, 60, 2, 0, 0);
    GotoXY(20, 13);
    printf("Endereco: ");
    Borda(32, 12, 60, 2, 0, 0);
    GotoXY(20, 16);
    printf("  Onibus: ");
    Borda(32, 15, 60, 2, 0, 0);
    GotoXY(20, 19);
    printf("Poltrona: ");
    Borda(32, 18, 60, 2, 0, 0);
}

void TelaPesquisaVendas() {
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(16, 4);
    printf("Nome:");
    Borda(32, 3, 60, 2, 0, 0);
    Borda(6, 6, 105, 20, 0, 0);
}

void ImprimirVendas(Vendas V, int y) {
    Viagens Vi;
    Borda(8, (y - 1), 101, 2, 0, 0);
    GotoXY(12, y); printf("CPF: %s", V.CPF);
    fpViagensV = fopen("Viagens.txt", "rb");
    fseek(fpViagensV, 0, SEEK_SET);
    while(fread(&Vi, sizeof(Viagens), 1, fpViagensV)){
        if(V.Onibus == Vi.NumeroViagem)break;
    }
    GotoXY(36, y); printf("Destino: %s", Vi.LocalDestino);
    GotoXY(77, y); printf("Onibus: %d | %d", V.Onibus, V.Poltrona);
    GotoXY(92, y); printf("Preco = R$%.2lf", V.Valor);
}

Vendas PesquisarVendas(int Alterar) {
    int NumeroVendas, Encontrado = 0, yImprimir = 8, count = 0; char Nome[51]; Vendas V;
    fseek(fpVendas, 0, SEEK_SET);
    GotoXY(34,4);
    scanf(" %[^\n]", Nome);
    while(fread(&V, sizeof(Vendas), 1, fpVendas)) {
        if(strcmp(V.Nome, Nome) == 0){
            ImprimirVendas(V, yImprimir);
            Encontrado = 1;
            yImprimir += 3;
            count++;
        }
        if(count >= 5) yImprimir = 8;
    }
    if(Encontrado == 0)
        strcpy(V.Nome, "");
    return V;
}

Vendas DigitarVenda() {
    Vendas V; Clientes C; Viagens Vi; Configuracoes Conf; int Cliente = 0, OnibusExiste = 0, PoltronaLivre = 0;
    GotoXY(34,4); scanf(" %[^\n]", V.Nome);
    fpClientesV = fopen("clientes.txt", "rb");
    fseek(fpClientesV, 0, SEEK_SET);
    while(fread(&C, sizeof(Clientes), 1, fpClientesV)) {
        if(strcmp(V.Nome, C.Nome) == 0) {
            Cliente = 1;
            strcpy(V.CPF, C.CPF);
            strcpy(V.Telefone, C.Telefone);
            strcpy(V.Endereco, C.Endereco);
        }
    }
    fclose(fpClientesV);
    if(Cliente == 1) {
        GotoXY(34, 7); printf("%s", V.CPF);
        GotoXY(34, 10); printf("%s", V.Telefone);
        GotoXY(34, 13); printf("%s", V.Endereco);

    } else {
        GotoXY(34, 7); scanf(" %[^\n]", V.CPF);
        GotoXY(34, 10); scanf(" %[^\n]", V.Telefone);
        GotoXY(34, 13); scanf(" %[^\n]", V.Endereco);
    }
    while(OnibusExiste != 1) {
        GotoXY(34, 16); scanf("%d", &V.Onibus);
        fpViagensV = fopen("viagens.txt", "rb+");
        fseek(fpViagensV, 0, SEEK_SET);
        while(fread(&Vi, sizeof(Viagens), 1, fpViagensV)) {
            if(Vi.NumeroViagem == V.Onibus) {
                OnibusExiste = 1;
                if(Cliente == 1)
                    V.Valor = Vi.Preco - (Vi.Preco * 0.05);
                else
                    V.Valor = Vi.Preco;
            }
        }
        if(OnibusExiste == 0) {
            GotoXY(34, 16); printf("VIAGEM NAO CADASTRADA");
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
            Borda(32, 15, 60, 2, 0, 0);
            GotoXY(35, 23);
            printf("                                                             ");
            GotoXY(35, 24);
            printf("                                                             ");
            GotoXY(35, 25);
            printf("                                                             ");
        }
    }
    while(PoltronaLivre != 1) {
        GotoXY(34, 19); scanf("%d", &V.Poltrona);
        fpConfiguracoesVen = fopen("configuracoes.txt", "rb");
        fseek(fpConfiguracoesVen, 0, SEEK_SET);
        fread(&Conf, sizeof(Configuracoes), 1, fpConfiguracoesVen);
        if ((Vi.VetorOnibus[V.Poltrona] != 1) && (V.Poltrona < Conf.TamanhoOnibus)) {
            Vi.VetorOnibus[V.Poltrona] = 1;
            PoltronaLivre = 1;
            fseek(fpViagensV, -sizeof(Vi.VetorOnibus), SEEK_CUR);
            fwrite(&Vi.VetorOnibus, sizeof(Vi.VetorOnibus), 1, fpViagensV);
            fflush(fpViagensV);
        } else {
            GotoXY(34, 19);
            printf("POLTRONA OCUPADA");
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
            Borda(32, 18, 60, 2, 0, 0);
            GotoXY(35, 23);
            printf("                                                             ");
            GotoXY(35, 24);
            printf("                                                             ");
            GotoXY(35, 25);
            printf("                                                             ");
        }
    }
    GotoXY(53, 22); printf("Preco = R$%.2lf", V.Valor);
    fclose(fpViagensV);
    return V;
}

void AtivarVendas() {
    Vendas V;
    int Escolha = 0, EscolhaConfirma = 0;
    char Opcoes[][51] = {"Novo", "Pesquisar", "Sair"};
    char OpcoesConfirma[][51] = {"Dinheiro", "Cartao", "Pix", "Cancelar"};
    AbrirArquivoVendas();
    int x[] = {39, 57, 79};
    int y[] = {24, 24, 24, 24};
    int xConfirma[] = {27, 48,69, 87};
    do {
        TelaVendas();
        Borda(35, 23, 10, 2, 0, 0);
        Borda(55, 23, 10, 2, 0, 0);
        Borda(75, 23, 10, 2, 0, 0);
        Escolha = Menu(Opcoes, x, y, Escolha, 3);
        if(Escolha == 0) {
            TelaVendas();
            V = DigitarVenda();
            Borda(25, 23, 10, 2, 0, 0);
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            Borda(85, 23, 10, 2, 0, 0);
            EscolhaConfirma = Menu(OpcoesConfirma, xConfirma, y, EscolhaConfirma, 4);
            if(EscolhaConfirma != 3)
                SalvarNovaVenda(V);
            else
                Escolha = 0;
        }
        if(Escolha == 1) {
            TelaPesquisaVendas();
            V = PesquisarVendas(0);
            if(strlen(V.Nome) <= 0) {
                Borda(41, 13, 34, 4, 1, 0);
                GotoXY(43, 15);
                printf("NAO HA VENDAS COM ESSE CLIENTE");
            }
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
        }
    } while(Escolha != 2);
    FecharArquivoVendas();
}
