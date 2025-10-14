#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <locale.h>
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
    long int arquivo_tam, registro_tam, numero_registros;

    fseek(arquivo, 0, SEEK_END);
    arquivo_tam = ftell(arquivo);

    if (estrutura == 1){
        registro_tam = sizeof(Cliente);
    }
    else if (estrutura == 2){
        registro_tam = sizeof(Produto);
    }
    else if (estrutura == 3){
        registro_tam = sizeof(Funcionarios);
    } else{
        registro_tam = sizeof(Pedido);
    }
    
    numero_registros = arquivo_tam/registro_tam;

    id = numero_registros + 1;
    return id;
}

int validar_nome(const char* nome) {
    int tam;
    tam = strlen(nome);
    if (tam > 51)
    {
        system("clear || cls");
        printf("\nO nome digitado está muito grande.\nPor favor digite um nome com menos de 51 caracteres.");
        getchar();
        return 0;
    }
    else
    {
        return 1;
    }
    
    
}

int validar_cpf()


//const char * input(const char * mensagem, const char * var) {

//}