#include "viagens.h"
#include "interface.h"
#include "configuracoes.h"

FILE *fpViagens;
FILE *fpConfiguracoesV;

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

void TelaPesquisa() {
    Borda(3, 1, 111, 26, 1, 0);
    GotoXY(16, 4);
    printf("Destino:");
    Borda(32, 3, 60, 2, 0, 0);
    Borda(6, 6, 105, 20, 0, 0);
}

void ImprimirViagem(Viagens V, int y) {
    Borda(8, (y - 1), 101, 2, 0, 0);
    GotoXY(15, y); printf("Num: %d", V.NumeroViagem);
    GotoXY(30, y); printf("Saida: %s", V.LocalSaida);
    GotoXY(69, y); printf("Data: D %d | H %d ", V.DiaSaida, V.HoraSaida);
    GotoXY(90, y); printf("Preco: R$%.2lf", V.Preco);
}

Viagens PesquisarViagens(int Alterar) {
    int NumeroViagem, Encontrado = 0, yImprimir = 8, count = 0; char Destino[51]; Viagens V;
    fseek(fpViagens, 0, SEEK_SET);
    GotoXY(34,4);
    if(Alterar == 0) {
        scanf(" %[^\n]", Destino);
        while (fread(&V, sizeof(Viagens), 1, fpViagens)) {
            if (strcmp(Destino, V.LocalDestino) == 0) {
                ImprimirViagem(V, yImprimir);
                Encontrado = 1;
                yImprimir += 3;
                count++;
            }
            if(count >= 5) yImprimir = 8;
        }
        if (Encontrado == 0)
            strcpy(V.LocalDestino, "");
        return V;
    } else if(Alterar == 1) {
        scanf("%d", &NumeroViagem);
        while (fread(&V, sizeof(Viagens), 1, fpViagens)) {
            if (V.NumeroViagem == NumeroViagem) {
                Borda(32, 3, 60, 2, 0, 0);
                return V;
            }
        }
        V.NumeroViagem = 0;
        return V;
    }
}

Viagens DigitarViagens(int Alterar, int Numero) {
    Viagens V; Configuracoes C;
    fpConfiguracoesV = fopen("configuracoes.txt","rb+");
    fseek(fpConfiguracoesV, 0, SEEK_SET);
    fread(&C, sizeof(Configuracoes), 1, fpConfiguracoesV);
    if(Alterar == 0) {
        V.NumeroViagem = ++C.SequenciaViagens;
        fseek(fpConfiguracoesV, -sizeof(C.SequenciaViagens), SEEK_CUR);
        fwrite(&C.SequenciaViagens, sizeof(C.SequenciaViagens), 1, fpConfiguracoesV);
        fclose(fpConfiguracoesV);
    } else V.NumeroViagem = Numero;
    GotoXY(34, 4); printf("%d", V.NumeroViagem);
    GotoXY(34, 7); scanf(" %[^\n]", V.LocalSaida);
    GotoXY(34, 10); scanf(" %[^\n]", V.LocalDestino);
    V.DiaSaida = 0; V.HoraSaida = -1;
    while(V.DiaSaida < 1 || V.DiaSaida > 31){
        Borda(32, 12, 60, 2, 0, 0);
        GotoXY(34, 13); scanf(" %d", &V.DiaSaida);
    }
    while(V.HoraSaida < 0 || V.HoraSaida > 24) {
        Borda(32, 15, 60, 2, 0, 0);
        GotoXY(34, 16); scanf(" %d", &V.HoraSaida);
    }
    GotoXY(34, 19); scanf("%lf", &V.Quilometragem);
    V.Preco = (V.Quilometragem * C.TaxaKm) + C.TaxaEmbarque;
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
            V = DigitarViagens(0, -1);
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
            TelaPesquisa();
            V = PesquisarViagens(0);
            if(strlen(V.LocalDestino) <= 0) {
                Borda(41, 13, 34, 4, 1, 0);
                GotoXY(43, 15);
                printf("NAO HA VIAGENS PARA ESSE DESTINO");
            }
            Borda(35, 23, 46, 2, 0, 0);
            GotoXY(36, 24);
            system("PAUSE");
        }
        if(Escolha == 3) {
            TelaViagens();
            V = PesquisarViagens(1);
            if(V.NumeroViagem != 0) {
                fseek(fpViagens, -sizeof(Viagens), SEEK_CUR);
                V = DigitarViagens(1, V.NumeroViagem);
                GotoXY(53, 22); printf("Preco = R$%.2lf", V.Preco);
                Borda(45, 23, 10, 2, 0, 0);
                Borda(65, 23, 10, 2, 0, 0);
                Escolha = 0;
                Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
                if(Escolha == 0) {
                    fwrite(&V, sizeof(Viagens), 1, fpViagens);
                    fflush(fpViagens);
                } else
                    Escolha = 3;
            } else {
                Borda(49, 10, 25, 4, 1, 0);
                GotoXY(52, 12);
                printf("VIAGEM NAO CADASTRADA");
                Borda(35, 23, 46, 2, 0, 0);
                GotoXY(36, 24);
                system("PAUSE");
            }
        }
    } while(Escolha != 4);
    FecharArquivoViagens();
}
