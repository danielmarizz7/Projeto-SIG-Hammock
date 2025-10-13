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
    Funcionarios* func;
    func = (Funcionarios*) malloc(sizeof(Funcionarios));
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
    
    arquivo_funcionario = fopen("funcionarios.dat", "rb");
    
    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_funcionario == NULL) {
        arquivo_funcionario = fopen("funcionarios.dat", "wb");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.dat", "rb");
    }


    func->id = gerar_id(arquivo_funcionario, 3);

    fclose(arquivo_funcionario);
    func->status = True;

    arquivo_funcionario = fopen("funcionarios.dat", "ab"); //Cria o arquivo
    if (arquivo_funcionario == NULL){
        printf("\nO arquivo não foi criado.");
        getchar();
    }
    else
    {
        //escreve o novo funcionário no arquivo
        fwrite(func, sizeof(Funcionarios), 1, arquivo_funcionario);
        fclose(arquivo_funcionario);
        free(func);
        printf("\nFuncionário cadastrado com sucesso!");
        printf("\nPressione ENTER para continuar.");
    }
    getchar();
}

void exibir_funcionarios(void){
    int id_procurar = 0;
    Funcionarios* func;
    func = (Funcionarios*)malloc(sizeof(Funcionarios));
    

    system("clear || cls");
    limpar_buffer();
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Pesquisar Funcionários            ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o id do Funcionário que deseja buscar: ");
    scanf(" %d", &id_procurar);

    arquivo_funcionario = fopen("funcionarios.dat", "rb");

    if (arquivo_funcionario == NULL) {
        arquivo_funcionario = fopen("funcionarios.dat", "wb");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.dat", "rb");
    }

    while (fread(func, sizeof(Funcionarios), 1, arquivo_funcionario)){
        if (func->id == id_procurar && func->status == True)
        {
            printf("\nID do Funcionário: %d", func->id);
            printf("\nNome do Funcionário: %s", func->nome);
            printf("\nCPF do Funcionário: %s", func->cpf);
            printf("\nEmail do Funcionário: %s", func->email);
            printf("\nTelefone do Funcionário: %s", func->telefone);

            fclose(arquivo_funcionario);
            free(func);
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
    int id_procurar = 0;
    char opc_alterar;
    int func_alterado = False;
    Funcionarios* func;
    func = (Funcionarios*) malloc(sizeof(Funcionarios));

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Funcionários             ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do Funcionário que deseja alterar: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();
    printf("\nO que deseja alterar desse Funcionário ?");
    printf("\n1 - nome");
    printf("\n2 - cpf");
    printf("\n3 - email");
    printf("\n4 - telefone\n");
    scanf("%c", &opc_alterar);
    limpar_buffer();

    arquivo_funcionario = fopen("funcionarios.dat", "rb");


    if (arquivo_funcionario == NULL) {
        arquivo_funcionario = fopen("funcionarios.dat", "wb");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.dat", "rb");
    }

    while (fread(func, sizeof(Funcionarios), 1, arquivo_funcionario) && func_alterado == False){

        if (func->id == id_procurar && func->status == True){
            switch (opc_alterar)
                        {
                        case '1':
                            printf("\nDigite o novo nome: ");
                            scanf("%[^\n]", func->nome);
                            func_alterado = True;
                            limpar_buffer();
                            break;
                        case  '2':
                            printf("\nDigite o novo cpf: ");
                            scanf("%[^\n]", func->cpf);
                            func_alterado = True;
                            limpar_buffer();
                            break;
                        case  '3':
                            printf("\nDigite o novo email: ");
                            scanf("%[^\n]", func->email);
                            func_alterado = True;
                            limpar_buffer();
                            break;
                        case  '4':
                            printf("\nDigite o novo telefone: ");
                            scanf("%[^\n]", func->telefone);
                            func_alterado = True;
                            limpar_buffer();
                            break;
                        default:
                            break;
            }
            fseek(arquivo_funcionario, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(func, sizeof(Funcionarios), 1, arquivo_funcionario);

            system("clear || cls");
            printf("\nFuncionário com o ID %d alterado com sucesso!", id_procurar);
            printf("\n\n------------------------ Funcionário Alterado ------------------------");
            printf("\nID do Funcionário: %d", func->id);
            printf("\nNome do Funcionário: %s", func->nome);
            printf("\nCPF do Funcionário: %s", func->cpf);
            printf("\nEmail do Funcionário: %s", func->email);
            printf("\nTelefone do Funcionário: %s", func->telefone);
            getchar();
        }
    }
    if (func_alterado == False) {
        printf("\nFuncionário com o ID %d não foi encontrado...", id_procurar);
        getchar();
    }
    fclose(arquivo_funcionario);
    free(func);
}


void excluir_funcionarios(void){
    int id_procurar = 0;
    int excluido = False;
    Funcionarios* func;
    func = (Funcionarios*) malloc(sizeof(Funcionarios));

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Excluir Funcionários               ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do Funcionário que deseja excluir: ");
    scanf(" %d", &id_procurar);
    limpar_buffer();

    arquivo_funcionario = fopen("funcionarios.dat", "r+b");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo_funcionario == NULL) {
        arquivo_funcionario = fopen("funcionarios.dat", "wb");
        fclose(arquivo_funcionario);
        arquivo_funcionario = fopen("funcionarios.dat", "r+b");
    }

    while (fread(func, sizeof(Funcionarios), 1, arquivo_funcionario) && (excluido == False)){
        if (func->id == id_procurar && func->status == True){
            func->status = False;

            excluido = True;
            fseek(arquivo_funcionario, (-1)*sizeof(Funcionarios), SEEK_CUR);
            fwrite(func, sizeof(Funcionarios), 1, arquivo_funcionario);
            printf("\nFuncionário com o ID %d excluido com sucesso!", id_procurar);
        }
                 
        
    }
    if (excluido == False) {
        printf("\nNão existe nenhum Funcionário com o ID %d cadastrado...", id_procurar);
    }
    fclose(arquivo_funcionario);
    free(func);
    getchar();
}

