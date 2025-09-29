#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

void limpar_buffer(void) {
    int c;
    c = getchar();
    while ((c != '\n' && c != EOF)) {
        c = getchar();
    };
}

int gerar_id(FILE *arquivo) {
    char pular_linha[200];
    int id = 0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%20d", &id);
        fgetc(arquivo);

        fscanf(arquivo, "%[^\n]", pular_linha);
        fgetc(arquivo);
    }

    id += 1;
    return id;
}