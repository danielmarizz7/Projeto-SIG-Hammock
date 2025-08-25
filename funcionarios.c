#include <stdio.h>
#include <stdlib.h>

//ASSINATURAS 
void tela_de_funcionarios(void);
void cadastrar_funcionarios(void);
void exibir_funcionarios(void);
 


int main(void){
    tela_de_funcionarios();
    cadastrar_funcionarios();
    exibir_funcionarios();
    return 0;
}

void tela_de_funcionarios(void){
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
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_funcionario);
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
    scanf(" %s", nome);
    printf("Digite o CPF do funcionario: ");
    scanf(" %s", cpf);
    printf("Digite o email do funcionario: ");
    scanf(" %s", email);
    printf("Digite o telefone do funcionario: ");
    scanf(" %s", telefone);
    printf("funcionario cadastrado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Telefone: %s\n", telefone);
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



