#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>

void tela_de_produto(void);
void cadastrar_produto(void);
void exibir_produto(void);
void alterar_produto(void);
void excluir_produto(void);
 


int main(void){
    tela_de_produto();
    cadastrar_produto();
    exibir_produto();
    alterar_produto();
    excluir_produto();
    return 0;
}

void tela_de_produto(void){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);
    char op_produtos;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Módulo De Produtos                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Cadastrar Produto                           ║\n");
    printf("║ 2 - exibir Produto                              ║\n");
    printf("║ 3 - Editar Produto                              ║\n");
    printf("║ 4 - Excluir Produto                             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_produtos);
}

void cadastrar_produto(void){
    char id_produto[12];
    char nome_produto[55];
    char valor_produto[10];
    char cor_produto[15];
    char material_produto[30];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Cadastrar Produto                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o nome do produto: ");
    scanf(" %s", nome_produto);
    printf("Digite o ID do produto ");
    scanf(" %s", id_produto);
    printf("Digite um valor para o produto: ");
    scanf(" %s", valor_produto);
    printf("Digite a cor do produto: ");
    scanf(" %s", cor_produto);
    printf("Digite o material que o produto foi feito: ");
    scanf(" %s", material_produto);
    printf("Produto cadastrado com sucesso!\n");
    printf("nome: %s\n", nome_produto);
    printf("id: %s\n", id_produto);
    printf("valor: %s\n", valor_produto);
    printf("cor: %s\n", cor_produto);
    printf("material: %s\n", material_produto);
}

void exibir_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                 Pesquisar Produto               ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja buscar: ");
    scanf(" %s", id_produto);
    
  
}


void alterar_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Alterar Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja alterar: ");
    scanf(" %s", id_produto);
 
}

void excluir_produto(void){
    char id_produto[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                Excluir Produto                  ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja alterar: ");
    scanf(" %s", id_produto);
 
}