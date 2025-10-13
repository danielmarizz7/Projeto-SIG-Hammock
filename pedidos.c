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

    do {
        opcao = tela_de_pedidos();
        switch(opcao){
            case '1':   cadastrar_pedidos();
                        break;
            case '2':   exibir_pedidos();
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



void cadastrar_pedidos(void){
    limpar_buffer();
    Pedido* pedido;
    pedido = (Pedido*) malloc(sizeof(Pedido));

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

    arquivo_pedido = fopen("pedidos.dat", "rb");

    if (arquivo_pedido == NULL) {
        arquivo_pedido = fopen("pedidos.dat", "wb");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.dat", "rb");
    }

    pedido->id_pedido = gerar_id(arquivo_pedido, 4);

    fclose(arquivo_pedido);
    pedido->status = True;
    
    arquivo_pedido = fopen("pedidos.dat", "ab"); //Cria o arquivo
    if (arquivo_pedido == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
    }
    else
    {
        //Escreve o novo pedido no arquivo
        fwrite(pedido, sizeof(Pedido), 1, arquivo_pedido);
        fclose(arquivo_pedido);
        printf("\nPedido de numero %d cadastrado com sucesso!", pedido->id_pedido);
        printf("\nPressione ENTER para continuar.");
        free(pedido);
    }
    getchar();
}






void exibir_pedidos(void){
    int id_procurar = 0;
    Pedido* pedido;
    pedido = (Pedido*) malloc(sizeof(Pedido));

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_pedido = fopen("pedidos.dat", "rb");

    if (arquivo_pedido == NULL) {
        arquivo_pedido = fopen("pedidos.dat", "wb");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.dat", "rb");
    }

    while (fread(pedido, sizeof(Pedido), 1, arquivo_pedido)){
        if (pedido->id_pedido == id_procurar && pedido->status == True)
        {
            printf("\nID do Pedido: %d", pedido->id_pedido);
            printf("\nID do Cliente: %d", pedido->id_cliente);
            printf("\nID do Produto: %d", pedido->id_produto);
            printf("\nID do Funcionario: %d", pedido->id_funcionario);
            printf("\nPreco do Pedido: %f", pedido->preco);
            printf("\nData do Pedido: %s", pedido->data);

            fclose(arquivo_pedido);
            free(pedido);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo_pedido);
    free(pedido);
    limpar_buffer();
    printf("\nNenhum pedido com o ID %d foi encontrado.", id_procurar);
    getchar();
}





void alterar_pedido(void){
    int id_procurar = 0;
    char opc_alterar;
    char opc_confirmar;
    int pedido_alterado = False;
    Pedido* pedido;
    pedido = (Pedido*) malloc(sizeof(Pedido));

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

    arquivo_pedido = fopen("pedidos.dat", "r+b");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_pedido == NULL) {
        arquivo_pedido = fopen("pedidos.csv", "wb");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.csv", "r+b");
    }

    while (fread(pedido, sizeof(Pedido), 1, arquivo_pedido) && pedido_alterado == False){
        if (pedido->id_pedido == id_procurar && pedido->status == True){
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
            system("clear || cls");
            printf("\nPedido com o ID %d alterado com sucesso!", id_procurar);
            printf("\n\n------------------------ Pedido Alterado ------------------------");
            printf("\nID do pedido: %d", pedido->id_pedido);
            printf("\nID do cliente: %d", pedido->id_cliente);
            printf("\nID do produto: %d", pedido->id_produto);
            printf("\nID do funcionario: %d", pedido->id_funcionario);
            printf("\nPreco do pedido: %f", pedido->preco);
            printf("\nData do pedido: %s", pedido->data);
            getchar();

            printf("\nDeseja alterar algum outro campo? (s/n)\n");
            scanf("%c", &opc_confirmar);
            limpar_buffer();
            fseek(arquivo_pedido, (-1)*sizeof(Pedido), SEEK_CUR);
            fwrite(pedido, sizeof(Pedido), 1, arquivo_pedido);
            if (opc_confirmar == 's' || opc_confirmar == 'S'){
                system("clear || cls");
                printf("\nO que deseja alterar desse pedido? ");
                printf("\n1 - ID_cliente");
                printf("\n2 - ID_produto");
                printf("\n3 - ID_funcionario");
                printf("\n4 - Preco");    
                printf("\n5 - Data\n");
                scanf("%c", &opc_alterar);
                limpar_buffer();
                fseek(arquivo_pedido, (-1)*sizeof(Pedido), SEEK_CUR);     
            } else {
                pedido_alterado = True;
            }
        }   
    }
    if (pedido_alterado == False) {
        printf("\nPedido com o ID %d não foi encontrado...", id_procurar);
        getchar();
    }
    fclose(arquivo_pedido);
    free(pedido);
}





void excluir_pedido(void){
    int id_procurar = 0;
    Pedido* pedido;
    pedido = (Pedido*) malloc(sizeof(Pedido));
    int pedido_excluido = False;
    char opc_confirmar;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Pedidos                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do pedido que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_pedido = fopen("pedidos.dat", "r+b");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_pedido == NULL) {
        arquivo_pedido = fopen("pedidos.dat", "wb");
        fclose(arquivo_pedido);
        arquivo_pedido = fopen("pedidos.dat", "r+b");
    }

    while (fread(pedido, sizeof(Pedido), 1, arquivo_pedido) && pedido_excluido == False){
        if (pedido->id_pedido == id_procurar && pedido->status == True){
            system("clear || cls");
            printf("\n\n------------------------ Pedido ------------------------");
            printf("\nID do pedido: %d", pedido->id_pedido);
            printf("\nID do cliente: %d", pedido->id_cliente);
            printf("\nID do produto: %d", pedido->id_produto);
            printf("\nID do funcionario: %d", pedido->id_funcionario);
            printf("\nPreco do pedido: %f", pedido->preco);
            printf("\nData do pedido: %s", pedido->data);
            printf("\n\nPedido de ID %d foi encontrado.\nTem certeza que deseja exclui-lo? (s/n)", id_procurar);
            scanf("%c", &opc_confirmar);
            limpar_buffer();

            if (opc_confirmar == 's' || opc_confirmar == 'S') {
                pedido->status = False;
                pedido_excluido = True;
                fseek(arquivo_pedido, (-1)*sizeof(Pedido), SEEK_CUR);
                fwrite(pedido, sizeof(Pedido), 1, arquivo_pedido);
                printf("\nPedido com o ID %d excluido com sucesso!", id_procurar);   
            } else {
                printf("\nExclusão cancelada.");
                pedido_excluido = True;
            }
        }
        
    }
    if (pedido_excluido == False) {
        printf("\nNão existe nenhum pedido com o ID %d cadastrado...", id_procurar);
    }
    fclose(arquivo_pedido);
    free(pedido);
    getchar();
}