#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "funcionarios.h"
#include "produto.h"
#include "estoque.h"
#include "equipe.h"
#include "sobre.h"

// #include <windows.h>


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
            case '4':   modulo_estoque();
                        break;
//          case '5':   modulo_relatorio();
//                      break;
            case '6':   modulo_equipe();
                        break;
            case '7':   modulo_sobre();
                        break;


        } 	
    } while (opcao != '0');

    return 0;
}






char tela_principal(void){
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

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
    printf("║                          0- Encerrar Sistema                          ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: \n");
    scanf("%c", &op_prin);
    return op_prin;
}

// void tela_sobre_projeto(void){
//     char op_sobre;
//     system("clear || cls");
//     printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
//     printf("║                           SOBRE O PROJETO                             ║\n");
//     printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
//     printf("║   Este sistema auxilia a gestão de uma fábrica de redes de dormir.    ║\n");
//     printf("║   Funcionalidades:                                                    ║\n");
//     printf("║                                                                       ║\n");
//     printf("║   • Cadastro de clientes e funcionários                               ║\n");
//     printf("║   • Controle e monitoramento do estoque                               ║\n");
//     printf("║   • Gerenciamento do fluxo de produtos                                ║\n");
//     printf("║                                                                       ║\n");
//     printf("║                                                                       ║\n");
//     printf("║   Com isso, otimiza processos, organiza rotinas e apoia decisões.     ║\n");
//     printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione 0 para voltar à tela inicial: ");
//     scanf(" %c", &op_sobre);
// }



// void tela_final(void){
//     system("clear || cls");
//     printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
//     printf("║                      TELA FINAL E AGRADECIMENTOS                      ║\n");
//     printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
//     printf("║   AGRADECIMENTOS:                                                     ║\n");
//     printf("║      Agradecemos a você, usuário, por utilizar este sistema.          ║\n");
//     printf("║      Ele representa não apenas uma ferramenta prática, mas também     ║\n");
//     printf("║      o resultado de muito aprendizado e dedicação ao longo da         ║\n");
//     printf("║      disciplina.                                                      ║\n");
//     printf("║                                                                       ║\n");
//     printf("║      Nosso objetivo é continuar evoluindo este projeto, trazendo      ║\n");
//     printf("║      melhorias, novas funcionalidades e tornando-o cada vez mais      ║\n");
//     printf("║      útil para quem precisar utilizá-lo.                              ║\n");
//     printf("║                                                                       ║\n");
//     printf("║      A disciplina é fundamental para nosso crescimento acadêmico      ║\n");
//     printf("║      e pessoal, permitindo o contato com práticas de programação,     ║\n");
//     printf("║      trabalho em equipe e solução de problemas.                       ║\n");
//     printf("║                                                                       ║\n");
//     printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione ENTER para voltar à tela inicial...");
//     getchar();
// }


// void tela_de_clientes(void){
//     char op_cliente;
//     system("clear || cls");
//     printf("╔═════════════════════════════════════════════════╗\n");
//     printf("║               Módulo De Clientes                ║\n");
//     printf("╠═════════════════════════════════════════════════╣\n");
//     printf("║ 1 - Cadastrar Cliente                           ║\n");
//     printf("║ 2 - Exibir Clientes                             ║\n");
//     printf("║ 3 - Editar Cliente                              ║\n");
//     printf("║ 4 - Excluir Cliente                             ║\n");
//     printf("║                                                 ║\n");
//     printf("║ 0 - Voltar                                      ║\n");
//     printf("╚═════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione 0 para voltar à tela inicial: ");
//     scanf(" %c", &op_cliente);
// }

// void tela_de_funcionarios(void){
//     char op_funcionarios;
//     system("clear || cls");
//     printf("╔═════════════════════════════════════════════════╗\n");
//     printf("║              Módulo De Funcionários             ║\n");
//     printf("╠═════════════════════════════════════════════════╣\n");
//     printf("║ 1 - Cadastrar Funcionário                       ║\n");
//     printf("║ 2 - Exibir Funcionário                          ║\n");
//     printf("║ 3 - Editar Funcionário                          ║\n");
//     printf("║ 4 - Excluir Funcionário                         ║\n");
//     printf("║                                                 ║\n");
//     printf("║ 0 - Voltar                                      ║\n");
//     printf("╚═════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione 0 para voltar à tela inicial: ");
//     scanf(" %c", &op_funcionarios);
// }


// void tela_de_produtos(void){
//     char op_produtos;
//     system("clear || cls");
//     printf("╔═════════════════════════════════════════════════╗\n");
//     printf("║              Módulo De Produtos                 ║\n");
//     printf("╠═════════════════════════════════════════════════╣\n");
//     printf("║ 1 - Cadastrar Produto                           ║\n");
//     printf("║ 2 - exibir Produto                              ║\n");
//     printf("║ 3 - Editar Produto                              ║\n");
//     printf("║ 4 - Excluir Produto                             ║\n");
//     printf("║                                                 ║\n");
//     printf("║ 0 - Voltar                                      ║\n");
//     printf("╚═════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione 0 para voltar à tela inicial: ");
//     scanf(" %c", &op_produtos);
// }


// void tela_de_estoque(void){
//     char op_estoque;
//     system("clear || cls");
//     printf("╔═════════════════════════════════════════════════╗\n");
//     printf("║              Módulo De Estoque                  ║\n");
//     printf("╠═════════════════════════════════════════════════╣\n");
//     printf("║ 1 - Consultar Estoque                           ║\n");
//     printf("║ 2 - Registrar produto                           ║\n");
//     printf("║ 4 - Remover Produto                             ║\n");
//     printf("║                                                 ║\n");
//     printf("║ 0 - Voltar                                      ║\n");    
//     printf("╚═════════════════════════════════════════════════╝\n");
//     printf("\n");
//     printf("Pressione 0 para voltar à tela inicial: ");
//     scanf(" %c", &op_estoque);
// }