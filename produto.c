#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utilidades.h"
#include "produto.h"
#include <locale.h>



 


void modulo_produto(void){
    char opcao;

    do {
        opcao = tela_de_produto();
        switch(opcao){
            case '1':   cadastrar_produto();
                        break;
            case '2':   exibir_produto();
                        break;
            case '3':   alterar_produto();
                        break;
            case '4':   excluir_produto();
                        break;

        }
    } while (opcao != '0');
}


char tela_de_produto(void){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    char op_produtos;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Módulo De Produtos                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Produto                           ║\n");
    printf("║ 2 - exibir Produto                              ║\n");
    printf("║ 3 - Editar Produto                              ║\n");
    printf("║ 4 - Excluir Produto                             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Para voltar à tela inicial                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Selecione uma opção: ");
    scanf(" %c", &op_produtos);
    return op_produtos;
}

void cadastrar_produto(void){
    char nome_produto[55];
    char id_produto[4];
    char valor_produto[10];
    char cor_produto[15];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Cadastrar Produto                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do produto: ");
    fgets(nome_produto, sizeof(nome_produto), stdin);
    printf("Digite o ID do produto: ");
    fgets(id_produto, sizeof(id_produto), stdin);
    printf("Digite um valor para o produto: ");
    fgets(valor_produto, sizeof(valor_produto), stdin);
    printf("Digite a cor do produto: ");
    fgets(cor_produto, sizeof(cor_produto), stdin);
    printf("\n");
    printf("Produto cadastrado com sucesso!\n");
    printf("\n");
    printf("nome: %s\n", nome_produto);
    printf("id: %s\n", id_produto);
    printf("valor: %s\n", valor_produto);
    printf("cor: %s\n", cor_produto);
    getchar();
}

void exibir_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                 Pesquisar Produto               ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja buscar: ");
    scanf(" %s", id_produto);
    getchar();
    
}


void alterar_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja alterar: ");
    scanf(" %s", id_produto);
    getchar();
 
}

void excluir_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja Excluir: ");
    scanf(" %s", id_produto);
    getchar();
 
}