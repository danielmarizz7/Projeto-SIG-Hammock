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
        printf("\nO CPF não pode estar vazio.");
        getchar();
        return 0;
    }

    int digitos[11];
    int len = 0;
    int soma = 0;

    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cpf[i]) &&
            cpf[i] != '.' && cpf[i] != '-') {
            printf("\nCPF contém caracteres inválidos (somente números, '.' e '-').");
            getchar();
            return 0;
        }
    }


    // Extrai os números
    for (const char *p = cpf; *p != '\0'; ++p) {
        if (isdigit((unsigned char)*p)
    ) {
            if (len >= 11) {
                printf("\nO CPF contém mais de 11 dígitos numéricos.");
                getchar();
                return 0;
            }
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
        if (!isdigit((unsigned char)valor[i]) && valor[i] != '.') {
            printf("\nDigite apenas numeros (0-9) ou '.' para decimais.");
            getchar();
            return 0;
        }
    }

    return 1;
}

int validar_nome(char *nome) {
    int len = strlen(nome);
    int contem_letra = 0;

    if (len == 0) {
        printf("\nO nome não pode estar vazio.");
        getchar();
        return 0;
    }

    if (len > 50) {
        printf("\nO número de caracteres do nome não pode ser maior que 50.");
        getchar();
        return 0;  
    }

    for (int i = 0; i < len; i++) {
        if (nome[i] >= 0) { // Verifica o código do caractere para saber se é especial, ex: Ç, ã, â, ê
            if (!isalpha(nome[i]) && nome[i] != ' ') {
                printf("\nO nome deve conter apenas letras e espaços.");
                getchar();
                return 0;
            }
        }
        if (nome[i] != ' ') {
            contem_letra ++;
        }
    }
    if (contem_letra == 0) {
            printf("\nO nome não deve conter apenas espaços.");
            getchar();
            return 0;  
    }
    return 1;
}
int validar_telefone(char *telefone) {
    int len = strlen(telefone);
    if (telefone == NULL) {
        printf("\nO telefone não pode estar vazio.");
        getchar();
        return 0;
    }

    if (len > 11) {
        printf("\nO telefone não pode ter mais de 11 digitos.");
        getchar();
        return 0;
    }

    int digitos[15];
    len = 0;

    // Extrai apenas os números
    for (const char *p = telefone; *p != '\0'; ++p) {
        if (isdigit((unsigned char)*p)) {
            digitos[len++] = *p - '0';
        }
    }

    // Verifica quantidade de dígitos
    if (len < 10 || len > 11) {
        printf("\nO telefone deve conter 10 ou 11 dígitos (DDD + número).");
        getchar();
        return 0;
    }

    // Se tiver 11 dígitos, o 3º deve ser 9 (celular no Brasil)
    if (len == 11 && digitos[2] != 9) {
        printf("\nNúmeros de celular com 11 dígitos devem ter '9' após o DDD.");
        getchar();
        return 0;
    }

    return 1;
}

int validar_email(char *email) {
    if (email == NULL) {
        printf("\nO email não deve estar vazio");
        getchar();
        return 0;
    }

    int tam = strlen(email);
    int antes_arroba = 0;
    int arroba = 0;
    int depois_arroba = 0;
    int ponto = 0;
    int antes_ponto = 0;

    if (tam > 50) {
        printf("\nO número de caracteres do email não pode ser maior que 50");
        getchar();
        return 0;  
    }

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
        if (email[i] == '.') {
            if (antes_ponto == 0) {
                printf("\nDeve haver texto antes do '.'");
                getchar();
                return 0;
            }
            if (arroba == 1) {
                ponto ++;
            }
        }
        else if (email[i] != '@' && email[i] != '.') {
            if (arroba == 1) {
                depois_arroba ++;
            }
            else {
                antes_arroba ++;
                antes_ponto ++;
            }
        }
    }
    if (arroba == 0) {
        printf("\nDeve haver um '@'");
        getchar();
        return 0;
    }
    if (ponto == 0) {
        printf("\nDeve haver um '.' depois do '@'");
        getchar();
        return 0;    
    }
    if (depois_arroba == 0) {
        printf("\nDeve haver texto após '@' (diferente de um '.')");
        getchar();
        return 0;
    }
    if (email[tam - 1] == '.') {
        printf("\nO email não pode terminar com '.'\n");
        getchar();
        return 0;
    }

    return 1;
}

int validar_modelo_rede(char *modelo_rede) {
    int len = strlen(modelo_rede);
    int contem_letra = 0;

    if (len == 0) {
        printf("\nO modelo da rede não pode estar vazio.");
        getchar();
        return 0;
    }

    if (len > 30) {
        printf("\nO modelo da rede não pode ultrapassar 30 caracteres.");
        getchar();
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (modelo_rede[i] != ' ') {
            contem_letra ++;
        }
    }
    if (contem_letra == 0) {
        printf("\nO modelo da rede não deve conter apenas espaços.");
        getchar();
        return 0;
    }

    // Verifica caracteres inválidos
    for (int i = 0; i < len; i++) {
        char c = modelo_rede[i];
        if (!(isalnum((unsigned char)c) || c == ' ' || c == '-' || c == '.')) {
            printf("\nO modelo da rede contém caracteres inválidos (use apenas letras, números, espaço, '-' ou '.').");
            getchar();
            return 0;
        }
    }

    return 1;
}
