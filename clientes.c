#include <stdio.h>
#include <stdlib.h>
#include <string.h> //usar o "strcmp"
#include <unistd.h>
#include "clientes.h"
#include <locale.h>
// #include <windows.h>

char nome[51];
char cpf[12];
char email[26];
char telefone[12];

FILE * arquivo; //Apontador do arquivo

void limpar_buffer(void) {
    int c;
    c = getchar();
    while ((c != '\n' && c != EOF)) {
        c = getchar();
    };
}

void modulo_clientes(void){
    char opcao;

    do {
        opcao = tela_de_clientes();
        switch(opcao){
            case '1':   cadastrar_clientes();
                        break;
            case '2':   exibir_clientes();
                        break;
            case '3':   alterar_cliente();
                        break;
            case '4':   excluir_cliente();
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
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente: ");
    scanf("%50s\n", nome);
    printf("Digite o CPF do cliente: ");
    scanf("%11s\n", cpf);
    printf("Digite o email do cliente: ");
    scanf("%25s\n", email);
    printf("Digite o telefone do cliente: ");
    scanf("%11s\n", telefone);

    limpar_buffer();
    printf("\n");
    printf("Cliente cadastrado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Telefone: %s\n", telefone);

    
    arquivo = fopen("clientes.csv", "at"); //Cria o arquivo
    if (arquivo == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
    }
    else
    {
        //Escreve coisas no arquivo
        fprintf(arquivo, "%s;", nome);
        fprintf(arquivo, "%s;", cpf);
        fprintf(arquivo, "%s;", email);
        fprintf(arquivo, "%s\n", telefone);
        fclose(arquivo);
        printf("\nCliente %s cadastrado com sucesso!", nome);
        printf("\nPressione ENTER para continuar.");
    }
    
    

    getchar();  // Apenas para pausar antes de sair
}






void exibir_clientes(void){
    char cpf_comparar[12];
    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja buscar: ");
    scanf(" %s", cpf_comparar);

    arquivo = fopen("clientes.csv", "rt");

    if (arquivo == NULL) {
        printf("\nO arquivo nao existe.");
        getchar();
    }

    while (!feof(arquivo)){
        fscanf(arquivo, "%[^;]", nome);
        fgetc(arquivo);
        fscanf(arquivo, "%[^;]", cpf);
        fgetc(arquivo);
        fscanf(arquivo, "%[^;]", email);
        fgetc(arquivo);
        fscanf(arquivo, "%[^;]", telefone);
        fgetc(arquivo);

        if (strcmp(cpf, cpf_comparar) == 0)
        {
            printf("\nNome do cliente: %s", nome);
            printf("\nCPF do cliente: %s", cpf);
            printf("\nEmail do cliente: %s", email);
            printf("\nTelefone do cliente: %s", telefone);

            fclose(arquivo);
            limpar_buffer();
            getchar();
            return;
            
        }
        
    }
    fclose(arquivo);
    
    printf("\nNenhum cliente com esse cpf foi encontrado.");
    limpar_buffer();
    getchar();
    
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void alterar_cliente(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja alterar: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}





void excluir_cliente(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Clientes                 ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja excluir: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}