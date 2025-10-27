#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
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

int validar_cpf(char *cpf) {
    if (cpf == NULL) {
        return 0;
    }

    int digitos[11];
    int len = 0;
    int soma = 0;

    // Extrai os números
    for (const char *p = cpf; *p != '\0' && len < 11; ++p) {
        if (isdigit((unsigned char)*p)) {
            digitos[len++] = *p - '0';
        }
    }

    // Checa se o CPF tem somente 11 digitos
    if (len != 11) {
        printf("\nO CPF tem que ter somente 11 digitos.");
        getchar();
        return 0;
    }

    // Calcula o primeiro dígito verificador
    for (int i = 0; i < 9; ++i) {
        soma += digitos[i] * (10 - i);
    }
    int resto = soma % 11;
    int dv1 = (resto < 2) ? 0 : 11 - resto;

    if (dv1 != digitos[9]) {
        printf("\nO primeiro dígito verificador não confere.");
        getchar();
        return 0;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; ++i) {
        soma += digitos[i] * (11 - i);
    }
    resto = soma % 11;
    int dv2 = (resto < 2) ? 0 : 11 - resto;

    if (dv2 != digitos[10]) {
        printf("\nO segundo dígito verificador não confere.");
        getchar();
        return 0;
    }

    return 1;

}

int validar_valor(char *valor) {
    if (valor == NULL || strlen(valor) == 0) {
        printf("\nDigite um preco para a rede.");
        getchar();
        return 0;
    }

    for (int i = 0; valor[i] != '\0'; i++) {
        if (!isdigit((unsigned char)valor[i])) {
            printf("\nDigite apenas numeros (0-9).");
            getchar();
            return 0;
        }
    }

    return 1;
}

int validar_email(char *email) {
    if (email == NULL) {
        return 0;
    }

    int tam = strlen(email);
    int antes_arroba = 0;
    int arroba = 0;
    int depois_arroba = 0;

    for (int i = 0; i < tam; i++) {
        if (email[i] == '@') {
            if (antes_arroba == 0) {
                printf("\nDeve haver texto antes do '@'");
                getchar();
                return 0;
            }
            else if (arroba == 1) {
                printf("\nDeve haver apenas um '@'");
                getchar();
                return 0;
            }
            else {
                arroba ++;
            }
        }
        else if (email[i] != '@') {
            if (arroba == 1) {
                depois_arroba ++;
            }
            else {
                antes_arroba ++;
            }
        }
    }
    if (arroba == 0) {
        printf("\nDeve haver um '@'");
        getchar();
        return 0;
    }
    if (depois_arroba == 0) {
        printf("\nDeve haver texto após '@'");
        getchar();
        return 0;
    }
    if (antes_arroba == 0) {
        printf("\nDeve haver texto antes do '@'");
        getchar();
        return 0;
    }
    return 1;
}