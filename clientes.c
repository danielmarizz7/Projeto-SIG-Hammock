#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar o "strcmp"
#include <unistd.h>
#include "utilidades.h"
#include "clientes.h"
#include <locale.h>
// #include <windows.h>

FILE * arquivo_cliente; //Apontador do arquivo

void modulo_clientes(void){
    char opcao;
    Cliente cli;

    do {
        opcao = tela_de_clientes();
        switch(opcao){
            case '1':   cadastrar_clientes();
                        break;
            case '2':   exibir_clientes();
                        break;
            case '3':   alterar_cliente(&cli);
                        break;
            case '4':   excluir_cliente(&cli);
                        break;
            case '5':
                listar_clientes();
                break;
        }
    } while (opcao != '0');
}


char tela_de_clientes(void){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    char op_cliente;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Módulo De Clientes                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Cliente                           ║\n");
    printf("║ 2 - Exibir Clientes                             ║\n");
    printf("║ 3 - Editar Cliente                              ║\n");
    printf("║ 4 - Excluir Cliente                             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_cliente);
    return op_cliente;
}



void cadastrar_clientes(void){
    Cliente* cli; //criando um apontador de Cliente
    //colocando na variável "cli" uma alocação de memória de "Cliente", com base no tamanho do struct de cliente
    //.dat
    //criar o campo status. "status" vai servir como um modo de "desativar" e "ativar" o cliente em questão. Usar True e False
    // #define True 1
    // #define False 0
    // Refazer função de gerar ID
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

    //RB -> Read Binary
    arquivo_cliente = fopen("clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rb");
    }

    cli->id = gerar_id(arquivo_cliente);
    //cli->id = 1;
    fclose(arquivo_cliente);
    
    arquivo_cliente = fopen("clientes.dat", "ab"); //Cria o arquivo
    if (arquivo_cliente == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
        fclose(arquivo_cliente);
    }
    else
    {
        //Escreve coisas no arquivo
        fwrite(cli, sizeof(Cliente), 1, arquivo_cliente);
        fclose(arquivo_cliente);
        free(cli);
        printf("\nCliente cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar.");
    }
    getchar();  // Apenas para pausar antes de sair
}






void exibir_clientes(){
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    int id_procurar = 0;

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
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rb");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo_cliente)){

        if (cli->id == id_procurar)
        {
            printf("\nID do cliente: %d", cli->id);
            printf("\nNome do cliente: %s", cli->nome);
            printf("\nCPF do cliente: %s", cli->cpf);
            printf("\nEmail do cliente: %s", cli->email);
            printf("\nTelefone do cliente: %s", cli->telefone);

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
    
    // esta tela ainda vai receber atualizações ao longo do projeto
}

void listar_clientes(void) {
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Lista de Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");

    arquivo_cliente = fopen("clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "wb");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.dat", "rb");
    }
    
    while(fread(cli, sizeof(Cliente), 1, arquivo_cliente)){
        printf("\nID do cliente: %d", cli->id);
        printf("\nNome do cliente: %s", cli->nome);
        printf("\nCPF do cliente: %s", cli->cpf);
        printf("\nEmail do cliente: %s", cli->email);
        printf("\nTelefone do cliente: %s\n", cli->telefone);
    }

    fclose(arquivo_cliente);
    free(cli);
    getchar();
}





void alterar_cliente(Cliente* cli){
    int id_procurar = 0;
    char opc_alterar;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();
    // esta tela ainda vai receber atualizações ao longo do projeto

    printf("\nO que deseja alterar desse cliente? ");
    printf("\n1 - nome");
    printf("\n2 - cpf");
    printf("\n3 - email");
    printf("\n4 - telefone\n");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.csv", "rt");

    arquivo_temporario = fopen("clientes_temp.csv", "wt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "wt");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rt");
    }

    while (fscanf(arquivo_cliente, "%d", &cli->id) == 1){
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->nome);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->cpf);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->email);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^\n]", cli->telefone);
        fgetc(arquivo_cliente);

        if (cli->id == id_procurar){
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
        }
        fprintf(arquivo_temporario, "%d;", cli->id);
        fprintf(arquivo_temporario, "%s;", cli->nome);
        fprintf(arquivo_temporario, "%s;", cli->cpf);
        fprintf(arquivo_temporario, "%s;", cli->email);
        fprintf(arquivo_temporario, "%s\n", cli->telefone);              
    }
    fclose(arquivo_temporario);
    fclose(arquivo_cliente);
    remove("clientes.csv");
    rename("clientes_temp.csv", "clientes.csv");
    printf("\nCliente com o ID %d alterado com sucesso!", id_procurar);
    getchar();
}

void excluir_cliente(Cliente* cli){
    int id_procurar = 0;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_cliente = fopen("clientes.csv", "rt");

    arquivo_temporario = fopen("clientes_temp.csv", "wt");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_cliente == NULL) {
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "wt");
        fclose(arquivo_cliente);
        arquivo_cliente = fopen("clientes.csv", "rt");
    }

    while (fscanf(arquivo_cliente, "%d", &cli->id) == 1){
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->nome);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->cpf);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^;]", cli->email);
        fgetc(arquivo_cliente);
        fscanf(arquivo_cliente, "%[^\n]", cli->telefone);
        fgetc(arquivo_cliente);

        if (cli->id != id_procurar){
            fprintf(arquivo_temporario, "%d;", cli->id);
            fprintf(arquivo_temporario, "%s;", cli->nome);
            fprintf(arquivo_temporario, "%s;", cli->cpf);
            fprintf(arquivo_temporario, "%s;", cli->email);
            fprintf(arquivo_temporario, "%s\n", cli->telefone);
        }
                 
        
    }
    fclose(arquivo_temporario);
    fclose(arquivo_cliente);
    remove("clientes.csv");
    rename("clientes_temp.csv", "clientes.csv");
    printf("\nCliente com o ID %d excluido com sucesso!", id_procurar);
    getchar();
}