#include <stdio.h>
#include "clientes.h"
#include "interface.h"

FILE *fpClientes;

void TelaClientes(){
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(17, 6); printf("        Nome: ");
    GotoXY(17, 9); printf("         CPF: ");
    GotoXY(17, 12); printf("    Telefone: ");
    GotoXY(17, 15); printf("    Endereco: ");
    GotoXY(17, 18); printf("Preferencial: ");
    Borda(32, 5, 60, 2, 0, 0);
    Borda(32, 8, 60, 2, 0, 0);
    Borda(32, 11, 60, 2, 0, 0);
    Borda(32, 14, 60, 2, 0, 0);
    Borda(32, 17, 60, 2, 0, 0);
}

/*void ImprimirClientes(Clientes C){
    Borda(14, 3, 52, 18, 1, 1);
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
    gotoxy(17, 6);
    printf("     Nome:");
    gotoxy(27, 6);
    printf("%s\n", C.Nome);
    gotoxy(17, 9);
    printf("    Cpf:");
    gotoxy(27, 9);
    printf("%s\n", C.CPF);
    gotoxy(17, 12);
    printf("Telefone:");
    gotoxy(27, 12);
    printf("%s\n", C.Telefone);
    gotoxy(17, 15);
    printf("Endereco:");
    gotoxy(27, 15);
    printf("%s\n", C.Endereco);
    gotoxy(27, 15);
    printf("%s\n", C.Endereco);
}*/

void AbrirArquivoClientes(){
    fpClientes = fopen("C:\\Users\\brant\\OneDrive\\Documentos\\projetos\\SoftBus\\arquivos\\clientes.txt",
                       "rb+");

    if(fpClientes == NULL){
        fpClientes = fopen("C:\\Users\\brant\\OneDrive\\Documentos\\projetos\\SoftBus\\arquivos\\clientes.txt",
                           "wb+");
        if(fpClientes == NULL){
            GotoXY(0, 30);
            printf("[ERROR] O programa nao conseguiu abrir o arquivo.");
            exit(1);
        }
    }
}

void SalvarNovoCliente(Clientes C){
    fseek(fpClientes, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&C, sizeof(Clientes), 1, fpClientes);//Grava
    fflush(fpClientes);
}

void FecharArquivoClientes(){
    fclose(fpClientes);
}

/*
Clientes PesquisarClientes(){
    char CPF[51]; Clientes C;
    GotoXY(27,6);
    scanf(" %[^\n]", CPF);
    fseek(fpClientes, 0, SEEK_SET);
    while(fread(&C, sizeof(Clientes), 1, fpClientes)){
        if(strcmp(C.CPF, CPF) == 0){
            return C;
        }
    }
    strcpy(C.CPF, "");
    return C;
}

int CarregarPaciente(char Dados[][51]){
    int n = 0;
    Clientes C;

    fseek(fpClientes, 0, SEEK_SET);

    while(fread(&C, sizeof(Clientes), 1, fpClientes)){
        strcpy(Dados[n], C.Nome);
        n++;
    }
    return n;
}*/

Clientes DigitarClientes(){
    Clientes C;

    GotoXY(34,6);
    scanf(" %[^\n]", C.Nome);

    GotoXY(34, 9);
    scanf(" %[^\n]", C.CPF);

    GotoXY(34, 12);
    scanf(" %[^\n]", C.Telefone);

    GotoXY(34, 15);
    scanf(" %[^\n]", C.Endereco);

    GotoXY(34, 18);
    scanf("%d", C.Preferencial);

    return C;
}

void AtivarClientes(){
    Clientes C;
    int Escolha = 0;
    char opcoes[][51] = {"Novo","Sair"};
    int x[] = {49, 69};
    int y[] = {23, 23};

    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    int x1[] = {47, 67};
    int y1[] = {23, 23};

    AbrirArquivoClientes();
    do{
        TelaClientes();
        Borda(45, 22, 10, 2, 0, 0);
        Borda(65, 22, 10, 2, 0, 0);
        Escolha = Menu(opcoes, x, y, Escolha, 2);
        if(Escolha == 0)
        {
            TelaClientes();
            C = DigitarClientes();
            Borda(45, 22, 10, 2, 0, 0);
            Borda(65, 22, 10, 2, 0, 0);
            Escolha = Menu(opcoesConfirma, x1, y1, Escolha, 2);
            if(Escolha == 0) {
                SalvarNovoCliente(C);
            } else
                Escolha = 0;
        }
        /*if(Escolha == 1)
        {
            TelaClientes();
            P = PesquisarClientes();
            if(strlen(P.CPF) > 0)
            {
                //ImprimirClientes(C);
            }
            else {
                Borda(27, 18, 26, 2, 0, 0);
                GotoXY(30, 19);
                printf("PACIENTE NAO CADASTRO");
            }
            GotoXY(0, 25);
            system("Pause");
        }*/
    }while(Escolha != 1);
    FecharArquivoClientes();
}
