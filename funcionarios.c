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
    Funcionarios func;

    do {
        opcao = tela_de_funcionarios();
        switch(opcao) {
            case '1':   cadastrar_funcionarios(&func);
                        break;
            case '2': 	exibir_funcionarios(&func);
                        break;
            case '3': 	alterar_funcionarios(&func);
                        break;
            case '4': 	excluir_funcionarios(&func);
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

void cadastrar_funcionarios(Funcionarios* func){
    limpar_buffer();
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Cadastrar Funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do funcionario: ");
    scanf("%[^\n]", func->nome);
    limpar_buffer();

    printf("Digite o CPF do funcionario: ");
    scanf("%[^\n]", func->cpf);
    limpar_buffer();

    printf("Digite o email do funcionario: ");
    scanf("%[^\n]", func->email);
    limpar_buffer();

    printf("Digite o telefone do funcionario: ");
    scanf("%[^\n]", func->telefone);
    limpar_buffer();
    
    arquivo_funcionario = fopen("funcionarios.csv", "rt");

    if (arquivo_funcionario == NULL) {
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "wt");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "rt");
    }


    func->id = gerar_id(arquivo_funcionario);

    fclose(arquivo_funcionario);

    arquivo_funcionario = fopen("funcionarios.csv", "at");
    if (arquivo_funcionario == NULL){
        printf("\nO arquivo não foi criado.");
        getchar();
        fclose(arquivo_funcionario);
    }
    else
    {
        fprintf(arquivo_funcionario, "%d;", func->id);
        fprintf(arquivo_funcionario, "%s;", func->nome);
        fprintf(arquivo_funcionario, "%s;", func->cpf);
        fprintf(arquivo_funcionario, "%s;", func->email);
        fprintf(arquivo_funcionario, "%s\n", func->telefone);
        fclose(arquivo_funcionario);
        printf("\nFuncionário %s cadastrado com sucesso!", func->nome);
        printf("\nPressione ENTER para continuar.");
    }

    getchar();
}

void exibir_funcionarios(Funcionarios* func){
    int id_procurar = 0;
    

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

    while (fscanf(arquivo_funcionario, "%d", &func->id) == 1){
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->nome);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->cpf);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->email);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^\n]", func->telefone);
        fgetc(arquivo_funcionario);

        if (func->id == id_procurar)
        {
            printf("\nID do funcionário: %d", func->id);
            printf("\nNome do funcionário: %s", func->nome);
            printf("\nCPF do funcionário: %s", func->cpf);
            printf("\nEmail do funcionário: %s", func->email);
            printf("\nTelefone do funcionário: %s", func->telefone);

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


void alterar_funcionarios(Funcionarios* func){
    int id_procurar = 0;
    char opc_alterar;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do Funcionário que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();
    printf("\nO que deseja alterar desse Funcionário ?");
    printf("\n1 - nome");
    printf("\n2 - cpf");
    printf("\n3 - email");
    printf("\n4 - telefone\n");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_funcionario = fopen("funcionarios.csv", "rt");

    arquivo_temporario = fopen("funcionarios_tem_csv", "wt");

    if (arquivo_funcionario == NULL){
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "wt");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "rt");
    }

    while (fscanf(arquivo_funcionario, "%d", &func->id) == 1){
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->nome);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->cpf);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->email);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^\n]", func->telefone);
        fgetc(arquivo_funcionario);

        if (func->id == id_procurar){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo nome: ");
                            scanf("%[^\n]", func->nome);
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo cpf: ");
                            scanf("%[^\n]", func->cpf);
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo email: ");
                            scanf("%[^\n]", func->email);
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite o novo telefone: ");
                            scanf("%[^\n]", func->telefone);
                            limpar_buffer();
                            break;
                        default:
                            break;
                        }

        }
        fprintf(arquivo_temporario, "%d;", func->id);
        fprintf(arquivo_temporario, "%s;", func->nome);
        fprintf(arquivo_temporario, "%s;", func->cpf);
        fprintf(arquivo_temporario, "%s;", func->email);
        fprintf(arquivo_temporario, "%s\n", func->telefone);   
    }
    fclose(arquivo_temporario);
    fclose(arquivo_funcionario);
    remove("funcionarios.csv");
    rename("funcionarios_temp.csv", "funcionarios.csv");
    printf("\nFuncionário com o ID %d alterado com sucesso!", id_procurar);
    getchar();
}


void excluir_funcionarios(Funcionarios* func){
    int id_procurar = 0;
    FILE * arquivo_temporario;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o CPF do funcionário que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_funcionario = fopen("funcionarios.csv", "rt");

    arquivo_temporario = fopen("funcionarios_temp.csv", "wt");

    if(arquivo_funcionario == NULL){
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.csv", "wt");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios_temp.csv", "rt");
    }
    
    while (fscanf(arquivo_funcionario, "%d", &func->id) == 1){
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->nome);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->cpf);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^;]", func->email);
        fgetc(arquivo_funcionario);
        fscanf(arquivo_funcionario, "%[^\n]", func->telefone);
        fgetc(arquivo_funcionario);

        if (func->id != id_procurar){
            fprintf(arquivo_temporario, "%d;", func->id);
            fprintf(arquivo_temporario, "%s;", func->nome);
            fprintf(arquivo_temporario, "%s;", func->cpf);
            fprintf(arquivo_temporario, "%s;", func->email);
            fprintf(arquivo_temporario, "%s\n", func->telefone);
        }

        }
        fclose(arquivo_temporario);
        fclose(arquivo_funcionario);
        remove("funcionarios.csv");
        rename("funcionarios_temp.csv", "funcionarios.csv");
        printf("\nFuncionário com o ID %d excluido com sucesso!", id_procurar);
        getchar();
}
