#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar o "strcmp"
#include <unistd.h>
#include "utilidades.h"
#include "pedidos.h"
#include <locale.h>
// #include <windows.h>

FILE * arquivo_pedido; //Apontador do arquivo

void modulo_pedidos(void){
    char opcao;
    int id_cliente = 0;
    int id_produto = 0;
    int id_funcionario = 0;
    float preco = 0;
    char data[26];

    do {
        opcao = tela_de_pedidos();
        switch(opcao){
            case '1':   cadastrar_pedidos(id_cliente, id_produto, id_funcionario, preco, data);
                        break;
            case '2':   exibir_pedidos(id_cliente, id_produto, id_funcionario, preco, data);
                        break;
            case '3':   alterar_pedido();
                        break;
            case '4':   excluir_pedido();
                        break;

        }
    } while (opcao != '0');
}



char tela_de_pedidos(void){

    char op_pedido;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Módulo De Pedidos                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Pedido                            ║\n");
    printf("║ 2 - Exibir Pedido                               ║\n");
    printf("║ 3 - Editar Pedido                               ║\n");
    printf("║ 4 - Excluir Pedido                              ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_pedido);
    return op_pedido;
}



void cadastrar_pedidos(int id_cliente, int id_produto, int id_funcionario, float preco, char data[]){
    int id_pedido = 0;
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Pedidos                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que fez o pedido: ");
    scanf("%d", &id_cliente);
    limpar_buffer();

    printf("Digite o ID do produto que faz parte do pedido: ");
    scanf("%d", &id_produto);
    limpar_buffer();

    printf("Digite o ID do funcionario que fez a venda: ");
    scanf("%d", &id_funcionario);
    limpar_buffer();

    printf("Digite o preco do pedido: ");
    scanf("%f", &preco);
    limpar_buffer();

    printf("Digite a data do pedido: ");
    scanf("%[^\n]", data);
    limpar_buffer();    

    arquivo_pedido = fopen("pedidos.csv", "rt");

    id_pedido = gerar_id(arquivo_pedido);

    fclose(arquivo_pedido);
    
    arquivo_pedido = fopen("pedidos.csv", "at"); //Cria o arquivo
    if (arquivo_pedido == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_pedido);
    }
    else
    {
        //Escreve coisas no arquivo
        fprintf(arquivo_pedido, "%d;", id_pedido);
        fprintf(arquivo_pedido, "%d;", id_cliente);
        fprintf(arquivo_pedido, "%d;", id_produto);
        fprintf(arquivo_pedido, "%d;", id_funcionario);
        fprintf(arquivo_pedido, "%f;", preco);
        fprintf(arquivo_pedido, "%s\n", data);
        fclose(arquivo_pedido);
        printf("\nPedido de numero %d cadastrado com sucesso!", id_pedido);
        printf("\nPressione ENTER para continuar.");
    }
    
    

    getchar();  // Apenas para pausar antes de sair
}






void exibir_pedidos(int id_cliente, int id_produto, int id_funcionario, float preco, char data[]){
    int id_procurar = 0;
    int id_pedido = 0;

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_pedido = fopen("pedidos.csv", "rt");

    if (arquivo_pedido == NULL) {
        printf("\nO arquivo nao existe.");
        getchar();
    }

    while (!feof(arquivo_pedido)){
        fscanf(arquivo_pedido, "%d", &id_pedido);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &id_cliente);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &id_produto);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &id_funcionario);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%f", &preco);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%[^\n]", data);
        fgetc(arquivo_pedido);

        if (id_pedido == id_procurar)
        {
            printf("\nID do pedido: %d", id_pedido);
            printf("\nID do cliente: %d", id_cliente);
            printf("\nID do produto: %d", id_produto);
            printf("\nID do funcionario: %d", id_funcionario);
            printf("\nPreco do pedido: %f", preco);
            printf("\nData do pedido: %s", data);

            fclose(arquivo_pedido);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo_pedido);
    
    limpar_buffer();
    printf("\nNenhum pedido com esse id foi encontrado.");
    getchar();
    
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void alterar_pedido(void){
    char id[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja alterar: ");
    scanf(" %s", id);
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void excluir_pedido(void){
    char id[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja excluir: ");
    scanf(" %s", id);
    // esta tela ainda vai receber atualizações ao longo do projeto
}