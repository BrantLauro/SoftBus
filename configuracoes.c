#include "configuracoes.h"
#include "interface.h"

FILE *fpConfiguracoes;
int MODO;

void AbrirArquivoConfiguracoes() {
    fpConfiguracoes = fopen("configuracoes.txt","rb+");
    MODO = 1;
    if(fpConfiguracoes == NULL) {
        fpConfiguracoes = fopen("configuracoes.txt","wb+");
        MODO = 0;
        if(fpConfiguracoes == NULL) {
            GotoXY(0, 30);
            printf("[ERROR] O programa nao conseguiu abrir o arquivo.");
            exit(1);
        }
    }
}

void SalvarNovaConfiguracao(Configuracoes Conf) {
    fseek(fpConfiguracoes, 0, SEEK_SET);
    fwrite(&Conf, sizeof(Configuracoes), 1, fpConfiguracoes);
    fflush(fpConfiguracoes);
}

void FecharArquivoConfiguracoes() {
    fclose(fpConfiguracoes);
}

void TelaConfiguracoes() {
    Borda(20, 5, 80, 16, 1, 0);
    GotoXY(37, 8);
    printf("       Taxa KM: ");
    Borda(55, 7, 20, 2, 0, 0);
    GotoXY(57, 8); printf("R$");
    GotoXY(37, 11);
    printf(" Taxa Embarque: ");
    Borda(55, 10, 20, 2, 0, 0);
    GotoXY(57, 11); printf("R$");
    GotoXY(37, 14);
    printf("Tamanho onibus: ");
    Borda(55, 13, 20, 2, 0, 0);
}

void ImprimirConfiguracoes(Configuracoes Conf) {
    if(MODO != 0) {
        GotoXY(60, 8); printf("%.2lf", Conf.TaxaKm);
        GotoXY(60, 11); printf("%.2lf", Conf.TaxaEmbarque);
        GotoXY(57, 14); printf("%d", Conf.TamanhoOnibus);
    }
}

Configuracoes DigitarConfiguracoes() {
    Configuracoes Conf;
    GotoXY(60, 8); scanf("%lf", &Conf.TaxaKm);
    GotoXY(60, 11); scanf("%lf", &Conf.TaxaEmbarque);
    GotoXY(57, 14); scanf("%d", &Conf.TamanhoOnibus);
    return Conf;
}

void AtivarConfiguracoes() {
    int Escolha = 0; Configuracoes Conf;
    char Opcoes[][51] = {"Alterar", "Sair"};
    char OpcoesConfirma[][51] = {"Confirma", "Cancelar"};
    AbrirArquivoConfiguracoes();
    int x[] = {47, 69};
    int y[] = {18, 18};
    int xConfirma[] = {47, 67};
    fseek(fpConfiguracoes, 0, SEEK_SET);
    fread(&Conf, sizeof(Configuracoes), 1, fpConfiguracoes);
    do {
        TelaConfiguracoes();
        ImprimirConfiguracoes(Conf);
        Borda(45, 17, 10, 2, 0, 0);
        Borda(65, 17, 10, 2, 0, 0);
        Escolha = Menu(Opcoes, x, y, Escolha, 2);
        if(Escolha == 0){
            TelaConfiguracoes();
            Conf = DigitarConfiguracoes();
            Borda(45, 17, 10, 2, 0, 0);
            Borda(65, 17, 10, 2, 0, 0);
            Escolha = Menu(OpcoesConfirma, xConfirma, y, Escolha, 2);
            if(Escolha == 0){
                SalvarNovaConfiguracao(Conf);
                MODO = 1;
            } else {
                Escolha = 0;
                MODO = 0;
            }
        }
    } while(Escolha != 1);
    FecharArquivoConfiguracoes();
}
