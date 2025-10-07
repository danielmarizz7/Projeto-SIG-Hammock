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

//fseek() -> joga o ponteiro para o final do arquivo
//ftell() -> mostra em qual posição do arquivo eu estou
// Usa o fsize() para pegar o tamanho do struct em questão
// divide o numero total de bytes pego em ftell() pelo numero obtido por fsize().
// Assim, dá para saber quantos registros tem no arquivo.
//modificar o gerar_id
