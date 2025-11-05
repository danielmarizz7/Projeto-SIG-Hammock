#include <stdio.h>
#include <stdlib.h>
#include "../include/relatorio.h"
#include "../include/utilidades.h"

char tela_relatorio(void);



void modulo_relatorio(void) {
    char opcao;

    do {
        opcao = tela_relatorio();
        switch(opcao) {
            case '1':   
                navegacao_relatorios_clientes();
                break;
            case '2':   
                printf("Relatorio Funcionarios\n");
                break;
            case '3':   
                printf("Relatorio Produtos\n");
                break;
            case '4':   
                printf("Relatorio Pedidos\n");
                break;              
        }
    } while (opcao != '0');
}

void navegacao_relatorios_clientes(void) {
    char opcao;

    do {
        opcao = tela_relatorio_clientes();
        switch(opcao) {
            case '1':   
                printf("Listagem de clientes ativos\n");
                getchar();
                break;
            case '2':   
                printf("Listagem de clientes inativos\n");
                getchar();
                break;           
        }
    } while (opcao != '0');
}

char tela_relatorio(void){
    char op_relat;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                  Relatorio Geral                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Relatório geral de Clientes                 ║\n");
    printf("║ 2 - Relatório geral de Funcionários             ║\n");
    printf("║ 3 - Relatório geral de Produtos                 ║\n");
    printf("║ 4 - Relatório geral de Pedidos                  ║\n");
    printf("║                                                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_relat);
    limpar_buffer();
    return op_relat;
}

char tela_relatorio_clientes(void){

    char op_cliente;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Relatório De Clientes             ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║                                                 ║\n");
    printf("║ 1 - Listar clientes ativos                      ║\n");
    printf("║ 2 - Listar clientes inativos                    ║\n");
    printf("║                                                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_cliente);
    limpar_buffer();
    return op_cliente;
}