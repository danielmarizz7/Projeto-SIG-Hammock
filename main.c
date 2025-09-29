#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "funcionarios.h"
#include "produto.h"
#include "relatorio.h"
#include "equipe.h"
#include "sobre.h"
#include "final.h"
#include "utilidades.h"


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
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              SIG-Hammock                              ║\n");
    printf("║        Sistema de Gestão Para uma Fábricas de Redes Para Dormir       ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                       ║\n");
    printf("║                          1- Módulo Clientes                           ║\n");
    printf("║                          2- Módulo Funcionários                       ║\n");
    printf("║                          3- Módulo Produtos                           ║\n");
    printf("║                          4- Módulo Estoque                            ║\n");
    printf("║                          5- Relatórios                                ║\n");
    printf("║                          6- Equipe                                    ║\n");
    printf("║                          7- Sobre                                     ║\n");
    printf("║                          8- Final e Agradecimentos                    ║\n");
    printf("║                          0- Encerrar Sistema                          ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_prin);
    return op_prin;
}
