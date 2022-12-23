#ifndef SOFTBUS_VENDAS_H
#define SOFTBUS_VENDAS_H

struct vendas {
    char Nome[51];
    char CPF[15];
    char Telefone[21];
    char Endereco[51];
    int Onibus;
    int Poltrona;
    double Valor;
};
typedef struct vendas Vendas;

void AbrirArquivoVendas();
void SalvarNovaVenda(Vendas C);
void FecharArquivoVendas();
void TelaVendas();
void TelaPesquisaVendas();
void ImprimirVendas(Vendas V, int y);
Vendas PesquisarVendas(int Alterar);
Vendas DigitarVenda();
void AtivarVendas();

#endif //SOFTBUS_VENDAS_H
