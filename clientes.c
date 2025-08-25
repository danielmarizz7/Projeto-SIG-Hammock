#include <stdio.h>
#include <stdlib.h>

//assinaturas do módulo clientes
void tela_de_clientes(void);
void cadastrar_clientes(void);
void exibir_clientes(void);
void alterar_cliente(void);



int main(void){
    tela_de_clientes();
    cadastrar_clientes();
    exibir_clientes();
    alterar_cliente();
    return 0;
}


void tela_de_clientes(void){
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
}

void cadastrar_clientes(void){
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Cadastrar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente: ");
    scanf(" %s", nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %s", cpf);
    printf("Digite o email do cliente: ");
    scanf(" %s", email);
    printf("Digite o telefone do cliente: ");
    scanf(" %s", telefone);
    printf("Cliente cadastrado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Telefone: %s\n", telefone);
}

void exibir_clientes(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pesquisar Clientes                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja buscar: ");
    scanf(" %s", cpf);
    
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