#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utilidades.h"
#include "produto.h"
#include <locale.h>


FILE * arquivo_produto;


void modulo_produto(void){

    char opcao;
    char nome[31];
    char valor_produto[11];
    char tipo_produto[15]; 
    char cor_produto [26];

    do {
        opcao = tela_de_produto();
        switch(opcao){
            case '1':   cadastrar_produto(nome, valor_produto, tipo_produto, cor_produto);
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

void cadastrar_produto(char nome[], char valor_produto[], char tipo_produto[], char cor_produto[]){
    int id_produto = 0;
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Cadastrar Produto                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");

    printf("Digite o nome do Produto: ");
    scanf("%[^\n]", nome);
    limpar_buffer();

    printf("Digite o Valor: ");
    scanf("%[^\n]", valor_produto);
    limpar_buffer();

    printf("Digite o Tipo: ");
    scanf("%[^\n]", tipo_produto);
    limpar_buffer();

    printf("Digite a Cor: ");
    scanf("%[^\n]", cor_produto);
    limpar_buffer();

    arquivo_produto = fopen("produtos.csv", "rt");

    id_produto = gerar_id(arquivo_produto);

    fclose(arquivo_produto);

    arquivo_produto = fopen("produtos.csv", "at");
    if (arquivo_produto == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_produto);
    } else {
        fprintf(arquivo_produto, "%d;", id_produto);
        fprintf(arquivo_produto, "%s;", nome);
        fprintf(arquivo_produto, "%s;", valor_produto);
        fprintf(arquivo_produto, "%s;", tipo_produto);
        fprintf(arquivo_produto, "%s\n", cor_produto);
        fclose(arquivo_produto);
        printf("\n%s cadastrado com sucesso!", nome);
        printf("\nPressione ENTER para continuar.");
    }
    getchar();  // Apenas para pausar antes de sair
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