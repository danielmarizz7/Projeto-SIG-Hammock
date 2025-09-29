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
    char modelo_rede[31];
    char valor_rede[11];
    char tipo_rede[15]; 
    char cor_rede [26];

    do {
        opcao = tela_de_produto();
        switch(opcao){
            case '1':   cadastrar_produto(modelo_rede, valor_rede, tipo_rede, cor_rede);
                        break;
            case '2':   exibir_produto(modelo_rede, valor_rede, tipo_rede, cor_rede);
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

void cadastrar_produto(char modelo_rede[], char valor_rede[], char tipo_rede[], char cor_rede[]){
    int id_produto = 0;
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Cadastrar Produto                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");

    printf("Digite o modelo da rede: ");
    scanf("%[^\n]", modelo_rede);
    limpar_buffer();

    printf("Digite o valor da rede: ");
    scanf("%[^\n]", valor_rede);
    limpar_buffer();

    printf("Digite o tipo da rede: ");
    scanf("%[^\n]", tipo_rede);
    limpar_buffer();

    printf("Digite a cor da rede: ");
    scanf("%[^\n]", cor_rede);
    limpar_buffer();

    arquivo_produto = fopen("produtos.csv", "rt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_produto == NULL) {
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "wt");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "rt");
    }

    id_produto = gerar_id(arquivo_produto);

    fclose(arquivo_produto);

    arquivo_produto = fopen("produtos.csv", "at");
    if (arquivo_produto == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_produto);
    } else {
        fprintf(arquivo_produto, "%d;", id_produto);
        fprintf(arquivo_produto, "%s;", modelo_rede);
        fprintf(arquivo_produto, "%s;", valor_rede);
        fprintf(arquivo_produto, "%s;", tipo_rede);
        fprintf(arquivo_produto, "%s\n", cor_rede);
        fclose(arquivo_produto);
        printf("\nA rede de modelo %s foi cadastrada com sucesso!", modelo_rede);
        printf("\nPressione ENTER para continuar.");
    }
    getchar();  // Apenas para pausar antes de sair
}


void exibir_produto(char modelo_rede[], char valor_rede[], char tipo_rede[], char cor_rede[]){
    int id_procurar = 0;
    int id_produto = 0;

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do Produto que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_produto = fopen("produtos.csv", "rt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_produto == NULL) {
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "wt");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "rt");
    }

    while (!feof(arquivo_produto)){
        fscanf(arquivo_produto, "%d", &id_produto);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", modelo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", valor_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", tipo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^\n]", cor_rede);
        fgetc(arquivo_produto);

        if (id_produto == id_procurar)
        {
            printf("\nID do Produto: %d", id_produto);
            printf("\nmodelo do Produto: %s", modelo_rede);
            printf("\nValor do Produto: %s", valor_rede);
            printf("\nTipo do Produto: %s", tipo_rede);
            printf("\nCor do Produto: %s", cor_rede);

            fclose(arquivo_produto);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo_produto);
    
    limpar_buffer();
    printf("\nNenhuma rede com esse id foi encontrado.");
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