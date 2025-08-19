#include <stdio.h>
#include <stdlib.h>

void tela_principal(void);
void tela_sobre_projeto(void);
void tela_de_equipe(void);


int main(void){
    tela_principal();
    tela_sobre_projeto();
    tela_de_equipe();
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

void tela_sobre_projeto(void){
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
}

void tela_de_equipe (void){
    char op_equipe;
    system("clear || cls");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           SOBRE O PROJETO                             ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║   Este projeto foi desenvolvido pelos alunos:                         ║\n");
    printf("║      Daniel Mariz                                                     ║\n");
    printf("║       GitHub: danielmarrizz7                                          ║\n");
    printf("║      Gabriel Victor                                                   ║\n");
    printf("║       GitHub: GabrielVictor7                                          ║\n");
    printf("║      xxxxxxxxxxxxxx                                                   ║\n");
    printf("║       GitHub: xxxxxxxx                                                ║\n");
    printf("║                                                                       ║\n");
    printf("║   Com a supervisão do Gerente                                         ║\n");
    printf("║      Flavius Gorgonio                                                 ║\n");
    printf("║       Github: FlaviusGorgonio                                         ║\n");
    printf("║                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_equipe);
}