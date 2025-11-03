#include <stdio.h>
#include <stdlib.h>
#include "../include/relatorio.h"

char tela_relatorio(void);



void modulo_relatorio(void) {
    char opcao;

    opcao = tela_relatorio();
    switch(opcao) {
        case '0':   
            printf("Voltando ao menu inicial\n");
            break;
        default:
            printf("Esta funcionalidade ainda não está pronta.\n");
            printf("Pressione Enter para voltar a tela incial...");
            getchar();
    }
}

char tela_relatorio(void){
    char op_relat;
    system("clear || cls");
    printf("ESTE MÓDULO AINDA ESTÁ EM DESENVOLVIMENTO\n");
    printf("PORTANTO SÓ CONSTA COM A SUA TELA PRINCIPAL\n");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                  Relatorio Geral                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Relatório geral de clientes                 ║\n");
    printf("║ 2 - Relatório geral de Funcionários             ║\n");
    printf("║ 3 - Relatório geral de Produtos                 ║\n");
    printf("║ 4 - Relatório geral de Estoque                  ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_relat);
    getchar();
    return op_relat;
}

