#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utilidades.h"
#include "funcionarios.h"
#include <locale.h>


FILE * arquivo_funcionario; //Apontador para o arquivo

void modulo_funcionarios(void) {
    char opcao;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
    
    do {
        opcao = tela_de_funcionarios();
        switch(opcao) {
            case '1':   cadastrar_funcionarios(nome, cpf, email, telefone);
                        break;
            case '2': 	exibir_funcionarios(nome, cpf, email, telefone);
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

void cadastrar_funcionarios(char nome[], char cpf[], char email[], char telefone[]){
    int id_funcionario = 0;
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Cadastrar Funcionarios             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do funcionario: ");
    scanf("%[^\n]", nome);
    limpar_buffer();

    printf("Digite o CPF do funcionario: ");
    scanf("%[^\n]", cpf);
    limpar_buffer();

    printf("Digite o email do funcionario: ");
    scanf("%[^\n]", email);
    limpar_buffer();

    printf("Digite o telefone do funcionario: ");
    scanf("%[^\n]", telefone);
    limpar_buffer();
    
    arquivo_funcionario = fopen("funcionarios.csv", "rt");

    if (arquivo_funcionario == NULL) {
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "wt");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "rt");
    }
    id_funcionario = gerar_id(arquivo_funcionario);

    fclose(arquivo_funcionario);

    arquivo_funcionario = fopen("funcionarios.csv", "at");
    if (arquivo_funcionario == NULL){
        printf("\nO arquivo não foi criado.");
        getchar();
        fclose(arquivo_funcionario);
    }
    else
    {
        fprintf(arquivo_funcionario, "%d;", id_funcionario);
        fprintf(arquivo_funcionario, "%s;", nome);
        fprintf(arquivo_funcionario, "%s;", cpf);
        fprintf(arquivo_funcionario, "%s;", email);
        fprintf(arquivo_funcionario, "%s\n", telefone);
        fclose(arquivo_funcionario);
        printf("\nFuncionário %s cadastrado com sucesso!", nome);
        printf("\nPressione ENTER para continuar.");
    }

    getchar();
}

void exibir_funcionarios(char nome[], char cpf[], char email[], char telefone[]){
    int id_procurar = 0;
    int id_funcionario = 0;

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pesquisar Funcionários            ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o id do Funcionário que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_funcionario = fopen("funcionarios.csv", "rt");

    if (arquivo_funcionario == NULL) {
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "wt");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "rt");
    }

    while (!feof(arquivo_funcionario)){
        fscanf(arquivo_funcionario, "%d", &id_funcionario);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", nome);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", cpf);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", email);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^\n]", telefone);
        fgetc(arquivo_funcionario);

        if (id_funcionario == id_procurar)
        {
            printf("\nID do funcionário: %d", id_funcionario);
            printf("\nNome do funcionário: %s", nome);
            printf("\nCPF do funcionário: %s", cpf);
            printf("\nEmail do funcionário: %s", email);
            printf("\nTelefone do funcionário: %s", telefone);

            fclose(arquivo_funcionario);
            limpar_buffer();
            getchar();
            return;
        }
    }
    fclose(arquivo_funcionario);
    
    limpar_buffer();
    printf("\nNenhum funcionário com esse id foi encontrado.");
    getchar();
    
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