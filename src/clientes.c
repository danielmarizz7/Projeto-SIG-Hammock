#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar o "strcmp"
#include <unistd.h>
#include "../include/utilidades.h"
#include "../include/clientes.h"
#include <locale.h>

FILE * arquivo_cliente; //Apontador do arquivo

void modulo_clientes(void){
    char opcao;

    do {
        opcao = tela_de_clientes();
        switch(opcao){
            case '1':   cadastrar_clientes();
                        break;
            case '2':   exibir_clientes();
                        break;
            case '3':   listar_clientes();
                        break;
            case '4':   alterar_cliente();
                        break;
            case '5':   excluir_cliente();
                        break;
            case '6':   perma_excluir_cliente();
                        break;

        }
    } while (opcao != '0');
}


char tela_de_clientes(void){

    char op_cliente;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Módulo De Clientes                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Cliente                           ║\n");
    printf("║ 2 - Exibir Clientes                             ║\n");
    printf("║ 3 - Listar Cliente                              ║\n");
    printf("║ 4 - Editar Cliente                              ║\n");
    printf("║ 5 - Excluir Cliente                             ║\n");
    printf("║ 6 - Excluir Permanentemente Cliente             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_cliente);
    return op_cliente;
}



void cadastrar_clientes(void){
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    limpar_buffer();

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente: ");
    scanf("%[^\n]", cli->nome);
    limpar_buffer();

    printf("Digite o CPF do cliente: ");
    scanf("%[^\n]", cli->cpf);
    limpar_buffer();

    printf("Digite o email do cliente: ");
    scanf("%[^\n]", cli->email);
    limpar_buffer();

    printf("Digite o telefone do cliente: ");
    scanf("%[^\n]", cli->telefone);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "rb");
    }

    cli->id = gerar_id(arquivo_cliente, 1);

    fclose(arquivo_cliente);
    cli->status = True;
    
    arquivo_cliente = fopen("clientes.dat", "ab"); //Cria o arquivo
    if (arquivo_cliente == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
    }
    else
    {
        //Escreve o novo cliente no arquivo
        fwrite(cli, sizeof(Cliente), 1, arquivo_cliente);
        fclose(arquivo_cliente);
        free(cli);
        printf("\nCliente cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar.");
    }
    getchar();  // Apenas para pausar antes de sair
}






void exibir_clientes(void){
    int id_procurar = 0;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_cliente = fopen("clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "rb");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente)){
        if (cli->id == id_procurar && cli->status == True)
        {
            printf("\nID do Cliente: %d", cli->id);
            printf("\nNome do Cliente: %s", cli->nome);
            printf("\nCPF do Cliente: %s", cli->cpf);
            printf("\nEmail do Cliente: %s", cli->email);
            printf("\nTelefone do Cliente: %s", cli->telefone);

            fclose(arquivo_cliente);
            free(cli);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo_cliente);
    free(cli);
    limpar_buffer();
    printf("\nNenhum cliente com esse id foi encontrado.");
    getchar();
}

void listar_clientes(void) {
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    int arquivo_vazio = True;

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Listar Clientes                   ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    arquivo_cliente = fopen("clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "rb");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente) && cli->status == True)
    {
        printf("\n\n------------------------ Cliente %d ------------------------", cli->id);
        printf("\nID do Cliente: %d", cli->id);
        printf("\nNome do Cliente: %s", cli->nome);
        printf("\nCPF do Cliente: %s", cli->cpf);
        printf("\nEmail do Cliente: %s", cli->email);
        printf("\nTelefone do Cliente: %s", cli->telefone);
        getchar();
    }
    fclose(arquivo_cliente);
    free(cli);
        
    if (arquivo_vazio == True) {
        printf("Não tem nenhum cliente cadastrado...");
        getchar();
    }

}



void alterar_cliente(void){
    int id_procurar = 0;
    char opc_alterar;
    char opc_confirmar;
    int cli_alterado = False;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    printf("\nO que deseja alterar desse cliente? ");
    printf("\n1 - nome");
    printf("\n2 - cpf");
    printf("\n3 - email");
    printf("\n4 - telefone\n");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.dat", "r+b");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "r+b");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente) && cli_alterado == False){

        if (cli->id == id_procurar && cli->status == True){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo nome: ");
                            scanf("%[^\n]", cli->nome);
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo cpf: ");
                            scanf("%[^\n]", cli->cpf);
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo email: ");
                            scanf("%[^\n]", cli->email);
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite o novo telefone: ");
                            scanf("%[^\n]", cli->telefone);
                            limpar_buffer();
                            break;
                        default:
                            break;
            }
            system("clear || cls");
            printf("\nCliente com o ID %d alterado com sucesso!", id_procurar);
            printf("\n\n------------------------ Cliente Alterado ------------------------");
            printf("\nID do cliente: %d", cli->id);
            printf("\nNome do cliente: %s", cli->nome);
            printf("\nCPF do cliente: %s", cli->cpf);
            printf("\nEmail do cliente: %s", cli->email);
            printf("\nTelefone do cliente: %s", cli->telefone);
            getchar();
            
            printf("\nDeseja alterar algum outro campo? (s/n)\n");
            scanf("%c", &opc_confirmar);
            limpar_buffer();
            fseek(arquivo_cliente, (-1)*sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, arquivo_cliente);
            if (opc_confirmar == 's' || opc_confirmar == 'S'){
                system("clear || cls");
                printf("\nO que deseja alterar desse cliente? ");
                printf("\n1 - nome");
                printf("\n2 - cpf");
                printf("\n3 - email");
                printf("\n4 - telefone\n");
                scanf("%c", &opc_alterar);
                limpar_buffer();
                fseek(arquivo_cliente, (-1)*sizeof(Cliente), SEEK_CUR);     
            } else {
                cli_alterado = True;
            }
        }
    }
    if (cli_alterado == False) {
        printf("\nCliente com o ID %d não foi encontrado...", id_procurar);
        getchar();
    }
    fclose(arquivo_cliente);
    free(cli);
}

void excluir_cliente(void){
    int id_procurar = 0;
    int excluido = False;
    char opc_confirmar;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.dat", "r+b");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "r+b");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente) && (excluido == False)){
        if (cli->id == id_procurar && cli->status == True){
            system("clear || cls");
            printf("\n\n------------------------ Cliente ------------------------");
            printf("\nID do cliente: %d", cli->id);
            printf("\nNome do cliente: %s", cli->nome);
            printf("\nCPF do cliente: %s", cli->cpf);
            printf("\nEmail do cliente: %s", cli->email);
            printf("\nTelefone do cliente: %s", cli->telefone);
            printf("\n\nCliente de ID %d foi encontrado.\nTem certeza que deseja exclui-lo? (s/n)", id_procurar);
            scanf("%c", &opc_confirmar);
            limpar_buffer();

            if (opc_confirmar == 's' || opc_confirmar == 'S') {
                cli->status = 0;

                excluido = True;
                fseek(arquivo_cliente, (-1)*sizeof(Cliente), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, arquivo_cliente);
                printf("\nCliente com o ID %d excluido com sucesso!", id_procurar);   
            } else {
                printf("\nExclusão cancelada.");
                excluido = True;
            }
        }
                 
    }
    if (excluido == False) {
        printf("\nNão existe nenhum cliente com o ID %d cadastrado...", id_procurar);
    }
    fclose(arquivo_cliente);
    free(cli);
    getchar();
}


void perma_excluir_cliente(void) {
    int id_procurar = 0;
    int excluido = False;
    char opc_confirmar;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    FILE * arquivo_novo;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║        Excluir Permanentemente Clientes         ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja excluir permanentemente: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.dat", "rb");
    arquivo_novo = fopen("clientes_novo.dat", "wb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "rb");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente)){
        if (cli->id == id_procurar && cli->status == False){
            system("clear || cls");
            printf("\n\n------------------------ Cliente ------------------------");
            printf("\nID do cliente: %d", cli->id);
            printf("\nNome do cliente: %s", cli->nome);
            printf("\nCPF do cliente: %s", cli->cpf);
            printf("\nEmail do cliente: %s", cli->email);
            printf("\nTelefone do cliente: %s", cli->telefone);
            printf("\n\nCliente de ID %d foi encontrado.\nTem certeza que deseja exclui-lo permanentemente? (s/n)", id_procurar);
            scanf("%c", &opc_confirmar);
            limpar_buffer();

            if (opc_confirmar == 's' || opc_confirmar == 'S') {
                printf("\nCliente com o ID %d excluido com sucesso!", id_procurar);
                getchar();
                excluido = True;
            } else {
                fwrite(cli, sizeof(Cliente), 1, arquivo_novo);
                printf("\nExclusão cancelada.");
                getchar();
                excluido = True;
            }
        } else {
            fwrite(cli, sizeof(Cliente), 1, arquivo_novo);
        }
                 
    }
    if (excluido == False) {
        printf("\nNão existe nenhum cliente com o ID %d desativado...", id_procurar);
    }
    fclose(arquivo_cliente);
    fclose(arquivo_novo);
    free(cli);
    remove("clientes.dat");
    rename("clientes_novo.dat", "clientes.dat");
    getchar();
}