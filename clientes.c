#include <stdio.h>
#include "clientes.h"
#include "interface.h"

FILE *fpClientes;

void AbrirArquivoClientes() {
    fpClientes = fopen("clientes.txt","rb+");
    if(fpClientes == NULL){
        fpClientes = fopen("clientes.txt","wb+");
        if(fpClientes == NULL){
            GotoXY(0, 30);
            printf("[ERROR] O programa nao conseguiu abrir o arquivo.");
            exit(1);
        }
    }
}

void SalvarNovoCliente(Clientes C) {
    fseek(fpClientes, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&C, sizeof(Clientes), 1, fpClientes);//Grava
    fflush(fpClientes);
}

void FecharArquivoClientes() {
    fclose(fpClientes);
}

void TelaClientes() {
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

void ImprimirCliente(Clientes C) {
    GotoXY(34, 8); printf("%s", C.Nome);
    GotoXY(34, 11); printf("%s", C.CPF);
    GotoXY(34, 14); printf("%s", C.Telefone);
    GotoXY(34, 17); printf("%s", C.Endereco);
}

Clientes PesquisarClientes(int Alterar) {
    char Nome[51]; Clientes C;
    GotoXY(34,8);
    scanf(" %[^\n]", Nome);
    fseek(fpClientes, 0, SEEK_SET);
    while(fread(&C, sizeof(Clientes), 1, fpClientes)) {
        if(strcmp(C.Nome, Nome) == 0) {
            if (Alterar == 1)Borda(32, 7, 60, 2, 0, 0);
            return C;
        }
    }
    strcpy(C.Nome, "");
    return C;
}

Clientes DigitarClientes() {
    Clientes C;
    GotoXY(34,8); scanf(" %[^\n]", C.Nome);
    GotoXY(34, 11); scanf(" %[^\n]", C.CPF);
    GotoXY(34, 14); scanf(" %[^\n]", C.Telefone);
    GotoXY(34, 17); scanf(" %[^\n]", C.Endereco);
    return C;
}

void AtivarClientes() {
    Clientes C;
    int Escolha = 0;
    char Opcoes[][51] = {"Novo", "Pesquisar", "Alterar", "Sair"};
    char OpcoesConfirma[][51] = {"Confirma", "Cancelar"};
    AbrirArquivoClientes();
    int x[] = {29, 46,67, 89};
    int y[] = {24, 24, 24, 24};
    int xConfirma[] = {47, 67};
    do {
        TelaClientes();
        Borda(25, 23, 10, 2, 0, 0);
        Borda(45, 23, 10, 2, 0, 0);
        Borda(65, 23, 10, 2, 0, 0);
        Borda(85, 23, 10, 2, 0, 0);
        Escolha = Menu(Opcoes, x, y, Escolha, 4);
        if(Escolha == 0) {
            TelaClientes();
            C = DigitarClientes();
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
            if(Escolha == 0) {
                SalvarNovoCliente(C);
            } else
                Escolha = 0;
        }
        if(Escolha == 1) {
            TelaClientes();
            C = PesquisarClientes(0);
            if(strlen(C.Nome) > 0)
                ImprimirCliente(C);
            else {
                Borda(49, 10, 25, 4, 1, 0);
                GotoXY(52, 12);
                printf("CLIENTE NAO CADASTRADO");
            }
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
        }
        if(Escolha == 2) {
            TelaClientes();
            C = PesquisarClientes(1);
            if(strlen(C.Nome) > 0) {
                fseek(fpClientes, -sizeof(Clientes), SEEK_CUR);
                C = DigitarClientes();
                GotoXY(53, 22);
                Borda(45, 23, 10, 2, 0, 0);
                Borda(65, 23, 10, 2, 0, 0);
                Escolha = 0;
                Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
                if (Escolha == 0) {
                    fwrite(&C, sizeof(Clientes), 1, fpClientes);
                    fflush(fpClientes);
                } else
                    Escolha = 2;
            } else {
                Borda(49, 10, 25, 4, 1, 0);
                GotoXY(52, 12);
                printf("CLIENTE NAO CADASTRADO");
                Borda(35, 23, 46, 2, 0, 0);
                GotoXY(36, 24);
                system("PAUSE");
            }
        }
    } while(Escolha != 3);
    FecharArquivoClientes();
}
