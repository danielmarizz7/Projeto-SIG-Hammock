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
    Pedido pedido;;

    do {
        opcao = tela_de_pedidos();
        switch(opcao){
            case '1':   cadastrar_pedidos(&pedido);
                        break;
            case '2':   exibir_pedidos(&pedido);
                        break;
            case '3':   alterar_pedido(&pedido);
                        break;
            case '4':   excluir_pedido(&pedido);
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



void cadastrar_pedidos(Pedido* pedido){
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Pedidos                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que fez o pedido: ");
    scanf("%d", &pedido->id_cliente);
    limpar_buffer();

    printf("Digite o ID do produto que faz parte do pedido: ");
    scanf("%d", &pedido->id_produto);
    limpar_buffer();

    printf("Digite o ID do funcionario que fez a venda: ");
    scanf("%d", &pedido->id_funcionario);
    limpar_buffer();

    printf("Digite o preco do pedido: ");
    scanf("%f", &pedido->preco);
    limpar_buffer();

    printf("Digite a data do pedido: ");
    scanf("%[^\n]", pedido->data);
    limpar_buffer();    

    arquivo_pedido = fopen("pedidos.csv", "rt");

    pedido->id_pedido = gerar_id(arquivo_pedido);

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
        fprintf(arquivo_pedido, "%d;", pedido->id_pedido);
        fprintf(arquivo_pedido, "%d;", pedido->id_cliente);
        fprintf(arquivo_pedido, "%d;", pedido->id_produto);
        fprintf(arquivo_pedido, "%d;", pedido->id_funcionario);
        fprintf(arquivo_pedido, "%f;", pedido->preco);
        fprintf(arquivo_pedido, "%s\n", pedido->data);
        fclose(arquivo_pedido);
        printf("\nPedido de numero %d cadastrado com sucesso!", pedido->id_pedido);
        printf("\nPressione ENTER para continuar.");
    }
    
    

    getchar();  // Apenas para pausar antes de sair
}






void exibir_pedidos(Pedido* pedido){
    int id_procurar = 0;

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
        fscanf(arquivo_pedido, "%d", &pedido->id_pedido);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_cliente);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_produto);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_funcionario);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%f", &pedido->preco);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%[^\n]", pedido->data);
        fgetc(arquivo_pedido);

        if (pedido->id_pedido == id_procurar)
        {
            printf("\nID do pedido: %d", pedido->id_pedido);
            printf("\nID do cliente: %d", pedido->id_cliente);
            printf("\nID do produto: %d", pedido->id_produto);
            printf("\nID do funcionario: %d", pedido->id_funcionario);
            printf("\nPreco do pedido: %f", pedido->preco);
            printf("\nData do pedido: %s", pedido->data);

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





void alterar_pedido(Pedido* pedido){
    int id_procurar = 0;
    char opc_alterar;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();
    // esta tela ainda vai receber atualizações ao longo do projeto

    printf("\nO que deseja alterar desse pedido? ");
    printf("\n1 - ID_cliente");
    printf("\n2 - ID_produto");
    printf("\n3 - ID_funcionario");
    printf("\n4 - Preco");    
    printf("\n5 - Data\n");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_pedido = fopen("pedidos.csv", "rt");

    arquivo_temporario = fopen("pedidos_temp.csv", "wt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_pedido == NULL) {
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.csv", "wt");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.csv", "rt");
    }

    while (fscanf(arquivo_pedido, "%d", &pedido->id_pedido) == 1){
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_cliente);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_produto);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_funcionario);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%f", &pedido->preco);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%[^\n]", pedido->data);
        fgetc(arquivo_pedido);

        if (pedido->id_pedido == id_procurar){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo ID do cliente: ");
                            scanf("%d", &pedido->id_cliente);
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo ID do produto: ");
                            scanf("%d", &pedido->id_produto);
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo ID do funcionario: ");
                            scanf("%d", &pedido->id_funcionario);
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite o novo preco: ");
                            scanf("%f", &pedido->preco);
                            limpar_buffer();
                            break;
                        case '5':
                            printf("\nDigite a nova data: ");
                            scanf("%[^\n]", pedido->data);
                            limpar_buffer();
                            break;                            
                        default:
                            break;
            }
        }
        fprintf(arquivo_temporario, "%d;", pedido->id_pedido);
        fprintf(arquivo_temporario, "%d;", pedido->id_cliente);
        fprintf(arquivo_temporario, "%d;", pedido->id_produto);
        fprintf(arquivo_temporario, "%d;", pedido->id_funcionario);
        fprintf(arquivo_temporario, "%f;", pedido->preco);
        fprintf(arquivo_temporario, "%s\n", pedido->data);              
    }
    fclose(arquivo_temporario);
    fclose(arquivo_pedido);
    remove("pedidos.csv");
    rename("pedidos_temp.csv", "pedidos.csv");
    printf("\nPedido com o ID %d alterado com sucesso!", id_procurar);
    getchar();
}





void excluir_pedido(Pedido* pedido){
    int id_procurar = 0;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_pedido = fopen("pedidos.csv", "rt");

    arquivo_temporario = fopen("pedidos_temp.csv", "wt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_pedido == NULL) {
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.csv", "wt");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.csv", "rt");
    }

    while (fscanf(arquivo_pedido, "%d", &pedido->id_pedido) == 1){
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_cliente);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_produto);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%d", &pedido->id_funcionario);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%f", &pedido->preco);
        fgetc(arquivo_pedido);
        fscanf(arquivo_pedido, "%[^\n]", pedido->data);
        fgetc(arquivo_pedido);

        if (pedido->id_pedido != id_procurar){
            fprintf(arquivo_temporario, "%d;", pedido->id_pedido);
            fprintf(arquivo_temporario, "%d;", pedido->id_cliente);
            fprintf(arquivo_temporario, "%d;", pedido->id_produto);
            fprintf(arquivo_temporario, "%d;", pedido->id_funcionario);
            fprintf(arquivo_temporario, "%f;", pedido->preco);
            fprintf(arquivo_temporario, "%s\n", pedido->data);
        }
                 
        
    }
    fclose(arquivo_temporario);
    fclose(arquivo_pedido);
    remove("pedidos.csv");
    rename("pedidos_temp.csv", "pedidos.csv");
    printf("\nPedido com o ID %d excluido com sucesso!", id_procurar);
    getchar();
}