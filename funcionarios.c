#include <stdio.h>
#include <stdlib.h>

//ASSINATURAS 
void tela_de_funcionarios(void);


int main(void){
    tela_de_funcionarios();
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


