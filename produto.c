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

void cadastrar_produto(){
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));
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

    arquivo_produto = fopen("produtos.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_produto == NULL) {
        arquivo_produto = fopen("produtos.dat", "wb");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.dat", "rb");
    }

    prod->id = gerar_id(arquivo_produto, 1);

    fclose(arquivo_produto);
    prod->status = True;

    arquivo_produto = fopen("produtos.dat", "ab");
    if (arquivo_produto == NULL){
        printf("\nO arquivo não foi criado.");
        getchar();
    }
    else
    {
        //escreve o novo produto no arquivo
        fwrite(prod, sizeof(Produto), 1, arquivo_produto);
        fclose(arquivo_produto);
        free(prod);
        printf("\nProduto cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar.");
    }
    getchar();
}


void exibir_produto(void){
    int id_procurar = 0;
    Produto* prod;
    prod = (Produto*)malloc(sizeof(Produto));int id_procurar = 0;
    
    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do Produto que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_produto = fopen("produtos.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_produto == NULL) {
        arquivo_produto = fopen("produtos.dat", "wb");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.dat", "rb");
    }

    while (fread(prod, sizeof(Produto), 1, arquivo_produto)){
        if (prod->id == id_procurar && prod->status == True)
        {
            printf("\nID do Produto: %d", prod->id);
            printf("\nNome do Produto: %s", prod->modelo_rede);
            printf("\nCPF do Produto: %s", prod->valor_rede);
            printf("\nEmail do Produto: %s", prod->tipo_rede);
            printf("\nTelefone do Produto: %s", prod->cor_rede);

            fclose(arquivo_produto);
            free(prod);
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
    int id_procurar = 0;
    char opc_alterar;
    int prod_alterado = False;
    Produto* prod;
    prod = (Produto*) malloc(sizeof(Produto));


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

    arquivo_produto = fopen("produtos.dat", "rb");

    if (arquivo_produto == NULL) {
        arquivo_produto = fopen("produtos.dat", "wb");
        fclose(arquivo_produto);
        arquivo_produto = fopen("produtos.dat", "rb");
    }
    while (fread(prod, sizeof(Produto), 1, arquivo_produto) && prod_alterado == False){

        if (prod->id == id_procurar && prod->status == True){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo modelo: ");
                            scanf("%[^\n]", prod->modelo_rede);
                            prod_alterado = True;
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo valor: ");
                            scanf("%[^\n]", prod->valor_rede);
                            prod_alterado = True;
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo tipo: ");
                            scanf("%[^\n]", prod->tipo_rede);
                            prod_alterado = True;
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite a nova cor: ");
                            scanf("%[^\n]", prod->cor_rede);
                            prod_alterado = True;
                            limpar_buffer();
                            break;
                        default:
                            break;
            }
            fseek(arquivo_produto, (-1)*sizeof(Produto), SEEK_CUR);
            fwrite(prod, sizeof(Produto), 1, arquivo_produto);

            system("clear || cls");
            printf("\nProduto com o ID %d alterado com sucesso!", id_procurar);
            printf("\n\n------------------------ Produto Alterado ------------------------");
            printf("\nID do Produto: %d", prod->id);
            printf("\nModelo do Produto: %s", prod->modelo_rede);
            printf("\nValor do Produto: %s", prod->valor_rede);
            printf("\nTipo do Produto: %s", prod->tipo_rede);
            printf("\nCor do Produto: %s", prod->cor_rede);
            getchar();
        }
    }
    if (prod_alterado == False) {
        printf("\nFProduto com o ID %d não foi encontrado...", id_procurar);
        getchar();
    }
    fclose(arquivo_produto);
    free(prod);
}

