#include <stdio.h>
#include <stdlib.h>

void tela_principal(void);

int main(void){
    tela_principal();
    return 0;
}

void tela_principal(void){
    char op_prin;
    system("clear || cls");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              SIG-Hammock                              ║\n");
    printf("║        Sistema de Gestão Para uma Fábricas de Redes Para Dormir       ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                       ║\n");
    printf("║                          1- Módulo Clientes                           ║\n");
    printf("║                          2- Módulo Funcionários                       ║\n");
    printf("║                          3- Módulo Produtos                           ║\n");
    printf("║                          4- Módulo Estoque                            ║\n");
    printf("║                          5- Módulo Relatório                          ║\n");
    printf("║                          6- Equipe                                    ║\n");
    printf("║                          7- Sobre                                     ║\n");
    printf("║                          0- Encerrar Sistema                          ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: \n");
    scanf("%c", &op_prin);
    getchar();
}

