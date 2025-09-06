#include <stdio.h>
#include <stdlib.h>



// void modulo_relatorio(void);
//     char opcao;

//     do {
//         opcao = tela_de_rel();
//         switch(opcao){
//             case '1':   cadastrar_clientes();
//                         break;
//             case '2':   exibir_clientes();
//                         break;
//             case '3':   alterar_cliente();
//                         break;
//             case '4':   excluir_cliente();
//                         break;

//         }
//     } while (opcao != '0');
// }

char tela_relatorio(void){
    char op_relat;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║                  Relatorio Geral                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Relatório geral de clientes                 ║\n");
    printf("║ 2 - Relatório geral de Funcionários             ║\n");
    printf("║ 3 - Relatório geral de Produtos                 ║\n");
    printf("║ 4 - Relatório geral de Estoque                  ║\n"); //ESSE CAMPO RECEBERÁ AS INFORMAÇÕES DA TELA DE "CONSULTAR ESTOQUE" E PASSARÁ INFORMAÇÕES PARA O CAMPO DE RELATÓRIO
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", op_relat);
    getchar();

    //IDEIAS DE RELATÓRIO COM FILTROS :BUSCA POR SEXO
    //
}

