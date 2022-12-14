//
// Created by brant on 12/12/2022.
//

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
};
typedef struct viagens Viagens;

void TelaViagens();
void AtivarViagens();

#endif //SOFTBUS_VIAGENS_H
