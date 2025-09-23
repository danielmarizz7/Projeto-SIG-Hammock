#include <stdio.h>
#include <stdlib.h>
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
    getchar();
    printf("Digite o CPF do cliente: ");
    scanf("%11s\n", cpf);
    getchar();
    printf("Digite o email do cliente: ");
    scanf("%25s\n", email);
    getchar();
    printf("Digite o telefone do cliente: ");
    scanf("%11s\n", telefone);
    getchar();
    printf("\n");
    printf("Cliente cadastrado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Telefone: %s\n", telefone);

    
    arquivo = fopen("clientes.txt", "at"); //Cria o arquivo
    if (arquivo == NULL) {
        printf("\nO arquivo nao foi criado.");
        getchar();
    }
    else
    {
        //Escreve coisas no arquivo
        fprintf(arquivo, "%s\n", nome);
        fprintf(arquivo, "%s\n", cpf);
        fprintf(arquivo, "%s\n", email);
        fprintf(arquivo, "%s\n", telefone);
        fclose(arquivo);
    }
    
    

    getchar();  // Apenas para pausar antes de sair
}






void exibir_clientes(void){
    char cpf[12];
    char linha[256];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pequisar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja buscar: ");
    scanf(" %s", cpf);

    arquivo = fopen("clientes.txt", "rt");

    while (fscanf(arquivo,"%[^\n]",linha) == 1) {
        printf("%s\n",linha);
        fgetc(arquivo); 
    }
    limpar_buffer();
    getchar();
    fclose(arquivo);
    
    
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