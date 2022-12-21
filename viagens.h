#ifndef SOFTBUS_VIAGENS_H
#define SOFTBUS_VIAGENS_H

struct viagens {
    int NumeroViagem;
    char LocalSaida[51];
    char LocalDestino[51];
    char DiaSaida[51];
    char HoraSaida[51];
    double Quilometragem;
    double Preco;
    int VetorOnibus[50];
};
typedef struct viagens Viagens;

void TelaViagens();
Viagens DigitarViagens(int Alterar, int Numero);
void ImprimirViagem(Viagens V, int y);
Viagens PesquisarViagens(int Alterar);
void AtivarViagens();
void AbrirArquivoViagens();
void SalvarNovaViagem(Viagens V);
void FecharArquivoViagens();

#endif //SOFTBUS_VIAGENS_H
