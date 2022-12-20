#ifndef SOFTBUS_CLIENTES_H
#define SOFTBUS_CLIENTES_H

struct clientes {
    char Nome[51];
    char CPF[15];
    char Telefone[21];
    char Endereco[51];
};
typedef struct clientes Clientes;

void TelaClientes();
Clientes DigitarClientes();
void ImprimirCliente(Clientes C);
Clientes PesquisarClientes(int Alterar);
void AtivarClientes();
void AbrirArquivoClientes();
void SalvarNovoCliente(Clientes C);
void FecharArquivoClientes();

#endif //SOFTBUS_CLIENTES_H
