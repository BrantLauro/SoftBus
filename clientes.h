//
// Created by brant on 12/12/2022.
//

#ifndef SOFTBUS_CLIENTES_H
#define SOFTBUS_CLIENTES_H

struct clientes {
    char Nome[51];
    char CPF[15];
    char Telefone[21];
    char Endereco[51];
    int Preferencial;
};
typedef struct clientes Clientes;

void TelaClientes();
Clientes DigitarClientes();
void AtivarClientes();
void AbrirArquivoClientes();
void SalvarNovoCliente(Clientes C);
void FecharArquivoClientes();

#endif //SOFTBUS_CLIENTES_H
