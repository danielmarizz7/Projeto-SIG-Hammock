#include <stdio.h>
#include <stdlib.h>

//ASSINATURAS 
void tela_de_funcionarios(void);
void cadastrar_funcionarios(void);
void exibir_funcionarios(void);
void alterar_funcionarios(void);
void excluir_funcionarios(void);
 


int main(void){
    tela_de_funcionarios();
    cadastrar_funcionarios();
    exibir_funcionarios();
    alterar_funcionarios();
    excluir_funcionarios();
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
    fgets(nome, sizeof(nome), stdin);
    printf("Digite o CPF do funcionario: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o email do funcionario: ");
    fgets(email, sizeof(email), stdin);
    printf("Digite o telefone do funcionario: ");
    fgets(telefone, sizeof(telefone), stdin);
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