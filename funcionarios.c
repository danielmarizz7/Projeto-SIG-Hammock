#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"




void modulo_funcionarios(void) {
    char opcao;

    do {
        opcao = tela_de_funcionarios();
        switch(opcao) {
            case '1':   cadastrar_funcionarios();
                        break;
            case '2': 	exibir_funcionarios();
                        break;
            case '3': 	alterar_funcionarios();
                        break;
            case '4': 	excluir_funcionarios();
                        break;
        } 		
    } while (opcao != '0');
}

char tela_de_funcionarios(void){

    char op_funcionario;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Módulo De Funcionarios            ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Funcionario                       ║\n");
    printf("║ 2 - Exibir Funcionarios                         ║\n");
    printf("║ 3 - Editar Funcionario                          ║\n");
    printf("║ 4 - Excluir Funcionario                         ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolhar uma Opção desejada: ");
    scanf(" %c", &op_funcionario);
    return op_funcionario;
}

void cadastrar_funcionarios(void){
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Cadastrar Funcionarios             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do funcionario: ");
    scanf("%s50",nome);
    getchar();
    printf("Digite o CPF do funcionario: ");
    scanf("%s11", cpf);
    getchar();
    printf("Digite o email do funcionario: ");
    scanf("%s25", email);
    getchar();
    printf("Digite o telefone do funcionario: ");
    scanf("%s11", telefone);
    getchar();
    printf("\n");
    printf("Funcionário cadastrado com sucesso!\n");
    printf("\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Telefone: %s\n", telefone);
    getchar();
}

void exibir_funcionarios(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pesquisar Funcionários            ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do Funcionário que deseja buscar: ");
    scanf(" %s", cpf);
    
    // esta tela ainda vai receber atualizações ao longo do projeto
}


void alterar_funcionarios(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do Funcionário que deseja alterar: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}

void excluir_funcionarios(void){
    char cpf[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do funcionário que deseja excluir: ");
    scanf(" %s", cpf);
    // esta tela ainda vai receber atualizações ao longo do projeto
}