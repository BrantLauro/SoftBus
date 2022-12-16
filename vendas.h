#ifndef SOFTBUS_VENDAS_H
#define SOFTBUS_VENDAS_H

struct vendas {
    char Nome[51];
    char CPF[15];
    char Telefone[21];
    char Endereco[51];
};
typedef struct vendas Vendas;

#endif //SOFTBUS_VENDAS_H
