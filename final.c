#include <stdio.h>
#include <stdlib.h>

char tela_final(void);


void modulo_final(void) {
    char opcao;
    do {
        opcao = tela_final();
        switch(opcao) {
            case '0':   
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                getchar();
        }
    } while (opcao != '0');
}



char tela_final(void){
    char op_final;
    system("clear || cls");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                      TELA FINAL E AGRADECIMENTOS                      ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║   AGRADECIMENTOS:                                                     ║\n");
    printf("║      Agradecemos a você, usuário, por utilizar este sistema.          ║\n");
    printf("║      Ele representa não apenas uma ferramenta prática, mas também     ║\n");
    printf("║      o resultado de muito aprendizado e dedicação ao longo da         ║\n");
    printf("║      disciplina.                                                      ║\n");
    printf("║                                                                       ║\n");
    printf("║      Nosso objetivo é continuar evoluindo este projeto, trazendo      ║\n");
    printf("║      melhorias, novas funcionalidades e tornando-o cada vez mais      ║\n");
    printf("║      útil para quem precisar utilizá-lo.                              ║\n");
    printf("║                                                                       ║\n");
    printf("║      A disciplina é fundamental para nosso crescimento acadêmico      ║\n");
    printf("║      e pessoal, permitindo o contato com práticas de programação,     ║\n");
    printf("║      trabalho em equipe e solução de problemas.                       ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial...");
    getchar();
    return op_final;
}


