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
    Produto prod;
    
    do {
        opcao = tela_de_produto();
        switch(opcao){
            case '1':   cadastrar_produto(&prod);
                        break;
            case '2':   exibir_produto(&prod);
                        break;
            case '3':   alterar_produto(&prod);
                        break;
            case '4':   excluir_produto(&prod);
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
    printf("║ 2 - Exibir Produto                              ║\n");
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

void cadastrar_produto(Produto* prod){
    int id = 0;

    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Cadastrar Produto                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");

    printf("Digite o modelo da rede: ");
    scanf("%[^\n]", prod->modelo_rede);
    limpar_buffer();

    printf("Digite o valor da rede: ");
    scanf("%[^\n]", prod->valor_rede);
    limpar_buffer();

    printf("Digite o tipo da rede: ");
    scanf("%[^\n]", prod->tipo_rede);
    limpar_buffer();

    printf("Digite a cor da rede: ");
    scanf("%[^\n]", prod->cor_rede);
    limpar_buffer();

    arquivo_produto = fopen("produtos.csv", "rt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_produto == NULL) {
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "wt");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "rt");
    }

    prod->id = gerar_id(arquivo_produto);

    fclose(arquivo_produto);

    arquivo_produto = fopen("produtos.csv", "at");
    if (arquivo_produto == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_produto);
    } else {
        fprintf(arquivo_produto, "%d;", id);
        fprintf(arquivo_produto, "%s;", prod->modelo_rede);
        fprintf(arquivo_produto, "%s;", prod->valor_rede);
        fprintf(arquivo_produto, "%s;", prod->tipo_rede);
        fprintf(arquivo_produto, "%s\n", prod->cor_rede);
        fclose(arquivo_produto);
        printf("\nA rede de modelo %s foi cadastrada com sucesso!", prod->modelo_rede);
        printf("\nPressione ENTER para continuar.");
    }
    getchar();  // Apenas para pausar antes de sair
}


void exibir_produto(Produto* prod){
    int id_procurar = 0;
    
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
        fscanf(arquivo_produto, "%d", &prod->id);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->modelo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->valor_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->tipo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^\n]", prod->cor_rede);
        fgetc(arquivo_produto);

        if (prod->id == id_procurar)
        {
            printf("\nID do Produto: %d", prod->id);
            printf("\nmodelo do Produto: %s", prod->valor_rede);
            printf("\nTipo do Produto: %s", prod->tipo_rede);
            printf("\nCor do Produto: %s", prod->cor_rede);

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



void alterar_produto(Produto* prod){
   
    int id_procurar = 0;
    char opc_alterar;
    FILE * arquivo_temporario;



    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();
    printf("\nO que deseja alterar desse Prodtuo ?");
    printf("\n1 - modelo");
    printf("\n2 - valor");
    printf("\n3 - tipo");
    printf("\n4 - cor");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_produto = fopen("produtos.csv", "rt");

    arquivo_temporario = fopen("produtos_temp.csv", "wt");

    if (arquivo_produto == NULL){
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "wt");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "rt");
    }
    while (fscanf(arquivo_produto, "%d", &prod->id) == 1){
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->modelo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->valor_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->tipo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^\n]", prod->cor_rede);
        fgetc(arquivo_produto);

        if (prod->id == id_procurar){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo novo modelo: ");
                            scanf("%[^\n]", prod->modelo_rede);
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo valor: ");
                            scanf("%[^\n]", prod->valor_rede);
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo tipo: ");
                            scanf("%[^\n]", prod->tipo_rede);
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite a nova cor: ");
                            scanf("%[^\n]", prod->cor_rede);
                            limpar_buffer();
                            break;
                        default:
                            break;
                        }
        }
        fprintf(arquivo_temporario, "%d;", prod->id);
        fprintf(arquivo_temporario, "%s;", prod->modelo_rede);
        fprintf(arquivo_temporario, "%s;", prod->valor_rede);
        fprintf(arquivo_temporario, "%s;", prod->tipo_rede);
        fprintf(arquivo_temporario, "%s\n", prod->cor_rede);   
    }
    fclose(arquivo_temporario);
    fclose(arquivo_produto);
    remove("produtos.csv");
    rename("produtos_temp.csv", "funcionarios.csv");
    printf("\nProduto com o ID %d alterado com sucesso!", id_procurar);
    getchar();
 
}

void excluir_produto(Produto* prod){
    int id_procurar = 0;
    FILE * arquivo_temporario;


    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja Excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_produto = fopen("produtos.csv", "rt");

    arquivo_temporario = fopen("produtos_temp.csv", "wt");


    if(arquivo_produto == NULL){
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.csv", "wt");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos_temp.csv", "rt");  
    }
    while (fscanf(arquivo_produto, "%d", &prod->id) == 1){
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->modelo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->valor_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^;]", prod->tipo_rede);
        fgetc(arquivo_produto);
        fscanf(arquivo_produto, "%[^\n]", prod->cor_rede);
        fgetc(arquivo_produto);

        if (prod->id != id_procurar){
            fprintf(arquivo_temporario, "%d;", prod->id);
            fprintf(arquivo_temporario, "%s;", prod->modelo_rede);
            fprintf(arquivo_temporario, "%s;", prod->valor_rede);
            fprintf(arquivo_temporario, "%s;", prod->tipo_rede);
            fprintf(arquivo_temporario, "%s\n", prod->cor_rede);
        }

        }
        fclose(arquivo_temporario);
        fclose(arquivo_produto);
        remove("produtos.csv");
        rename("produtos_temp.csv", "funcionarios.csv");
        printf("\nProdutos com o ID %d excluido com sucesso!", id_procurar);
        getchar();
}