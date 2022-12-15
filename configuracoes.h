#ifndef SOFTBUS_CONFIGURACOES_H
#define SOFTBUS_CONFIGURACOES_H

struct configuracoes {
    double TaxaKm;
    double TaxaEmbarque;
    int TamanhoOnibus;
};
typedef struct configuracoes Configuracoes;

void AbrirArquivoConfiguracoes();
void SalvarNovaConfiguracao(Configuracoes Conf);
void FecharArquivoConfiguracoes();
void TelaConfiguracoes();
void ImprimirConfiguracoes(Configuracoes Conf);
Configuracoes DigitarConfiguracoes();
void AtivarConfiguracoes();

#endif //SOFTBUS_CONFIGURACOES_H
