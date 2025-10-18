#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "../include/clientes.h"
#include "../include/produto.h"
#include "../include/funcionarios.h"
#include "../include/pedidos.h"

void limpar_buffer(void) {
    int c;
    c = getchar();
    while ((c != '\n' && c != EOF)) {
        c = getchar();
    };
}


int gerar_id(FILE *arquivo, int estrutura) {
    int id = 0;

    fseek(arquivo, 0, SEEK_END);

    if (estrutura == 1){
        Cliente* cli;
        cli = (Cliente*) malloc(sizeof(Cliente));

        fseek(arquivo, (-1)*sizeof(Cliente), SEEK_CUR);
        if (fread(cli, sizeof(Cliente), 1, arquivo)) {
            id = cli->id + 1;
        } else {
            id = 1;
        }
    }
    else if (estrutura == 2){
        Produto* prod;
        prod = (Produto*) malloc(sizeof(Produto));

        fseek(arquivo, (-1)*sizeof(Produto), SEEK_CUR);
        if (fread(prod, sizeof(Produto), 1, arquivo)) {
            id = prod->id + 1;
        } else {
            id = 1;
        }
    }
    else if (estrutura == 3){
        Funcionarios* func;
        func = (Funcionarios*) malloc(sizeof(Funcionarios));

        fseek(arquivo, (-1)*sizeof(Funcionarios), SEEK_CUR);
        if (fread(func, sizeof(Funcionarios), 1, arquivo)) {
            id = func->id + 1;
        } else {
            id = 1;
        }
    } else{
        Pedido* pedido;
        pedido = (Pedido*) malloc(sizeof(Pedido));

        fseek(arquivo, (-1)*sizeof(Pedido), SEEK_CUR);
        if(fread(pedido, sizeof(Pedido), 1, arquivo)) {
            id = pedido->id_pedido + 1;
        } else {
            id = 1;
        }
    }
    return id;
}