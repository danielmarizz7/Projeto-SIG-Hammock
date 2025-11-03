#include <stdio.h>
#include <stdlib.h>
#include "include/clientes.h"
#include "include/funcionarios.h"
#include "include/produto.h"
#include "include/pedidos.h"
#include "include/relatorio.h"
#include "include/equipe.h"
#include "include/sobre.h"
#include "include/final.h"
#include "include/utilidades.h"

char tela_principal(void);


int main(void) {
    char opcao;

    do {
        opcao = tela_principal();
        switch(opcao) {
            case '1':   modulo_clientes();
                        break;
            case '2':   modulo_funcionarios();
                        break;
            case '3':   modulo_produto();
                        break;
            case '4':   modulo_pedidos();
                        break;
            case '5':   modulo_relatorio();
                        break;
            case '6':   modulo_equipe();
                        break;
            case '7':   modulo_sobre();
                        break;
            case '8':   modulo_final();
                        break;


        } 	
    } while (opcao != '0');

    return 0;
}

char tela_principal(void){


    char op_prin;
    system("clear || cls");
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ ######  ####  ######           ##     ##    ###    ##     ## ##     ##  #######   ######  ##    ## ║\n");
    printf("║##    ##  ##  ##    ##          ##     ##   ## ##   ###   ### ###   ### ##     ## ##    ## ##   ##  ║\n");
    printf("║##        ##  ##                ##     ##  ##   ##  #### #### #### #### ##     ## ##       ##  ##   ║\n");
    printf("║ ######   ##  ##   #### ####### ######### ##     ## ## ### ## ## ### ## ##     ## ##       #####    ║\n");
    printf("║      ##  ##  ##    ##          ##     ## ######### ##     ## ##     ## ##     ## ##       ##  ##   ║\n");
    printf("║##    ##  ##  ##    ##          ##     ## ##     ## ##     ## ##     ## ##     ## ##    ## ##   ##  ║\n");
    printf("║ ######  ####  ######           ##     ## ##     ## ##     ## ##     ##  #######   ######  ##    ## ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                                                    ║\n");
    printf("║                                         1- Módulo Clientes                                         ║\n");
    printf("║                                         2- Módulo Funcionários                                     ║\n");
    printf("║                                         3- Módulo Produtos                                         ║\n");
    printf("║                                         4- Módulo Pedidos                                          ║\n");
    printf("║                                         5- Relatórios                                              ║\n");
    printf("║                                         6- Equipe                                                  ║\n");
    printf("║                                         7- Sobre                                                   ║\n");
    printf("║                                         8- Final e Agradecimentos                                  ║\n");
    printf("║                                                                                                    ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                         0- Encerrar Sistema                                        ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_prin);                                                                         
    return op_prin;
}
