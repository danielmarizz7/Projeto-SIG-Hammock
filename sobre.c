#include <stdio.h>
#include <stdlib.h>

char tela_sobre_projeto(void);

void modulo_sobre(void) {
    char opcao;
    do {
        opcao = tela_sobre_projeto();
        switch(opcao) {
            case '0':   
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                getchar();
        }
    } while (opcao != '0');
}

char tela_sobre_projeto(void) {
    char op_sobre;
    system("clear || cls");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           SOBRE O PROJETO                             ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║   Este sistema auxilia a gestão de uma fábrica de redes de dormir.    ║\n");
    printf("║   Funcionalidades:                                                    ║\n");
    printf("║                                                                       ║\n");
    printf("║   • Cadastro de clientes e funcionários                               ║\n");
    printf("║   • Controle e monitoramento do estoque                               ║\n");
    printf("║   • Gerenciamento do fluxo de produtos                                ║\n");
    printf("║                                                                       ║\n");
    printf("║                                                                       ║\n");
    printf("║   Com isso, otimiza processos, organiza rotinas e apoia decisões.     ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_sobre);
    getchar();
    return op_sobre;
}
