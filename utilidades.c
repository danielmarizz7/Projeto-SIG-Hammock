#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "clientes.h"

void limpar_buffer(void) {
    int c;
    c = getchar();
    while ((c != '\n' && c != EOF)) {
        c = getchar();
    };
}

int gerar_id(FILE *arquivo) {
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    int id = 0;

    while(fread(cli, sizeof(Cliente), 1, arquivo))
    {
        id = cli->id;
    }

    id += 1;
    return id;
}