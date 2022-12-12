cmake_minimum_required(VERSION 3.24)
project(SoftBus C)

set(CMAKE_C_STANDARD 99)

add_executable(SoftBus main.c interface.c interface.h viagens.c viagens.h
        configuracoes.c configuracoes.h clientes.c clientes.h vendas.c vendas.h)
