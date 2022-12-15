#include "viagens.h"
#include "interface.h"
#include "configuracoes.h"

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

void ImprimirViagem(Viagens V) {
    GotoXY(34, 4); printf("%d\n", V.NumeroViagem);
    GotoXY(34, 7); printf("%s\n", V.LocalSaida);
    GotoXY(34, 10); printf("%s\n", V.LocalDestino);
    GotoXY(34, 13); printf("%s\n", V.DiaSaida);
    GotoXY(34, 16); printf("%s\n", V.HoraSaida);
    GotoXY(34, 19); printf("%.2lf\n", V.Quilometragem);
    GotoXY(53, 22); printf("Preco = R$%.2lf", V.Preco);
}

Viagens PesquisarViagens() {
    int NumeroViagem; Viagens V;
    GotoXY(34,4);
    scanf("%d", &NumeroViagem);
    fseek(fpViagens, 0, SEEK_SET);
    while(fread(&V, sizeof(Viagens), 1, fpViagens)) {
        if(V.NumeroViagem == NumeroViagem)
            return V;
    }
    V.NumeroViagem = 0;
    return V;
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
    int Escolha = 0; Viagens V;
    char Opcoes[][51] = {"Novo", "Configuracoes", "Pesquisar", "Alterar", "Sair"};
    char OpcoesConfirma[][51] = {"Confirma", "Cancelar"};
    AbrirArquivoViagens();
    int x[] = {19, 34,56, 77, 98};
    int y[] = {24, 24, 24, 24, 24};
    int xConfirma[] = {47, 67};
    do {
        TelaViagens();
        Borda(12, 23, 15, 2, 0, 0);
        Borda(32, 23, 15, 2, 0, 0);
        Borda(52, 23, 15, 2, 0, 0);
        Borda(72, 23, 15, 2, 0, 0);
        Borda(92, 23, 15, 2, 0, 0);
        Escolha = Menu(Opcoes, x, y, Escolha, 5);
        if(Escolha == 0){
            TelaViagens();
            V = DigitarViagens();
            GotoXY(53, 22); printf("Preco = R$%.2lf", V.Preco);
            Borda(45, 23, 10, 2, 0, 0);
            Borda(65, 23, 10, 2, 0, 0);
            Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
            if(Escolha == 0){
                SalvarNovaViagem(V);
            } else
                Escolha = 0;
        }
        if(Escolha == 1) {
            AtivarConfiguracoes();
        }
        if(Escolha == 2) {
            TelaViagens();
            V = PesquisarViagens();
            if(V.NumeroViagem != 0)
                ImprimirViagem(V);
            else {
                Borda(49, 10, 25, 4, 1, 0);
                GotoXY(52, 12);
                printf("VIAGEM NAO CADASTRADA");
            }
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
        }
        if(Escolha == 3) {
            //V = PesquisarViagens();
            //AlterarViagem(V);
        }
    } while(Escolha != 4);
    FecharArquivoViagens();
}
