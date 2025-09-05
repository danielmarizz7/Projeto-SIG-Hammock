#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"
// #include <windows.h>


 


void modulo_estoque(void){
    char opcao;

    do {
        opcao = tela_de_estoque();
        switch(opcao){
            case '1':   consultar_estoque();
                        break;
            case '2':   registrar_estoque();
                        break;
            case '3':   remove_estoque();
                        break;

        }
    } while (opcao != '0');
}




char tela_de_estoque(void){

    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);
    
    char op_estoque;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Módulo De Estoque                  ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 1 - Consultar Estoque                           ║\n");
    printf("║ 2 - Registrar produto                           ║\n");
    printf("║ 3 - Remover Produto                             ║\n");
    printf("║                                                 ║\n");
    printf("║ 0 - Voltar                                      ║\n");    
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Pressione 0 para voltar à tela inicial: ");
    scanf(" %c", &op_estoque);
    return op_estoque;
}

    void consultar_estoque(void){
    char consultar_estoque[20];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║              Consultar o Estoque                ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Consultar por tipo de Material: \n");
    scanf(" %s", consultar_estoque);
    // mais informações seram adicionadas futuramente

}

    void registrar_estoque(void){
    char registrar_estoque[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║            Registrar Produto no estoque         ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja cadastrar no estoque: ");
    scanf(" %s", registrar_estoque);
    
  
}


    void remove_estoque(void){
    char remove_estoque[12];
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║            Remover produto do estoque           ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("Digite o ID do produto que deseja remover do estoque: ");
    scanf(" %s", remove_estoque);
    
  
}