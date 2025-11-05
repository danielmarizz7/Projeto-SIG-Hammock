#include <stdio.h>
#include <stdlib.h>
#include "../include/relatorio.h"
#include "../include/utilidades.h"
#include "../include/clientes.h"
#include "../include/funcionarios.h"
#include "../include/produto.h"
#include "../include/pedidos.h"

FILE * arquivo;

void modulo_relatorio(void) {
    char opcao;

    do {
        opcao = tela_relatorio();
        switch(opcao) {
            case '1':   
                navegacao_relatorios_clientes();
                break;
            case '2':   
                navegacao_relatorios_funcionarios();
                break;
            case '3':   
                navegacao_relatorios_produtos();
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
                listar_clientes();
                break;
            case '2':   
                printf("Listagem de clientes inativos\n");
                getchar();
                break;           
        }
    } while (opcao != '0');
}

void navegacao_relatorios_funcionarios(void) {
    char opcao;

    do {
        opcao = tela_relatorio_funcionarios();
        switch(opcao) {
            case '1':   
                listar_funcionarios();
                break;
            case '2':   
                printf("Listagem de funcionarios inativos\n");
                getchar();
                break;           
        }
    } while (opcao != '0');
}

void navegacao_relatorios_produtos(void) {
    char opcao;

    do {
        opcao = tela_relatorio_produtos();
        switch(opcao) {
            case '1':   
                listar_produto();
                break;
            case '2':   
                printf("Listagem de produtos inativos\n");
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

char tela_relatorio_funcionarios(void){

    char op_func;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║            Relatório De Funcionários            ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║                                                 ║\n");
    printf("║ 1 - Listar funcionários ativos                  ║\n");
    printf("║ 2 - Listar funcionários inativos                ║\n");
    printf("║                                                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_func);
    limpar_buffer();
    return op_func;
}

char tela_relatorio_produtos(void){

    char op_produto;
    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║            Relatório De Produtos                ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║                                                 ║\n");
    printf("║ 1 - Listar produtos ativos                      ║\n");
    printf("║ 2 - Listar produtos inativos                    ║\n");
    printf("║                                                 ║\n");
    printf("╠═════════════════════════════════════════════════╣\n");
    printf("║ 0 - Voltar                                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op_produto);
    limpar_buffer();
    return op_produto;
}

void listar_clientes(void) {
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    int arquivo_vazio = True;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Listar Clientes                   ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    arquivo = fopen("database/clientes.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo == NULL) {
        arquivo = fopen("database/clientes.dat", "wb");
        fclose(arquivo);
        arquivo = fopen("database/clientes.dat", "rb");
    }

    while (fread(cli, sizeof(Cliente), 1, arquivo)){
        if (cli->status == True){
            printf("\n\n-------------------- Cliente %d --------------------", cli->id);
            printf("\nID do Cliente: %d", cli->id);
            printf("\nNome do Cliente: %s", cli->nome);
            printf("\nCPF do Cliente: %s", cli->cpf);
            printf("\nEmail do Cliente: %s", cli->email);
            printf("\nTelefone do Cliente: %s", cli->telefone);
            getchar();
            arquivo_vazio = False;
        }
    }
    fclose(arquivo);
    free(cli);
        
    if (arquivo_vazio == True) {
        printf("Não tem nenhum cliente cadastrado...");
        getchar();
    }

}

void listar_funcionarios(void) {
    Funcionarios* func;
    func = (Funcionarios*) malloc(sizeof(Funcionarios));
    int arquivo_vazio = True;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Listar Funcionários               ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    arquivo = fopen("database/funcionarios.dat", "rb");

    //testa se o arquivo existe, se não existe, cria o arquivo
    if (arquivo == NULL) {
        arquivo = fopen("database/funcionarios.dat", "wb");
        fclose(arquivo);
        arquivo = fopen("database/funcionarios.dat", "rb");
    }

    while (fread(func, sizeof(Funcionarios), 1, arquivo)){
        if (func->status == True){
            printf("\n\n------------------ Funcionário %d ------------------", func->id);
            printf("\nID do Funcionário: %d", func->id);
            printf("\nNome do Funcionário: %s", func->nome);
            printf("\nCPF do Funcionário: %s", func->cpf);
            printf("\nEmail do Funcionário: %s", func->email);
            printf("\nTelefone do Funcionário: %s", func->telefone);
            getchar();
            arquivo_vazio = False;
        }
    }
    fclose(arquivo);
    free(func);
  
    if (arquivo_vazio == True) {
        printf("Não tem nenhum funcionário cadastrado...");
        getchar();
    }
    
}

void listar_produto(void) {
    Produto* prod;
    prod = (Produto*) malloc(sizeof(Produto));
    int arquivo_vazio = True;

    system("clear || cls");
    printf("╔═════════════════════════════════════════════════╗\n");
    printf("║               Listar Produtos                   ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    arquivo = fopen("database/produtos.dat", "rb");

    if (arquivo == NULL) {
        arquivo = fopen("database/produtos.dat", "wb");
        fclose(arquivo);
        arquivo = fopen("database/produtos.dat", "rb");
    }

    while (fread(prod, sizeof(Produto), 1, arquivo)){
        if (prod->status == True){
            printf("\n\n------------------------ Produto %d ------------------------", prod->id);
            printf("\nID do Produto: %d", prod->id);
            printf("\nModelo do Produto: %s", prod->modelo_rede);
            printf("\nValor do Produto: %f", prod->valor_rede);
            printf("\nTipo do Produto: %s", prod->tipo_rede);
            printf("\nCor do Produto: %s", prod->cor_rede);
            getchar();
            arquivo_vazio = False;
        }
    }
    fclose(arquivo);
    free(prod);
            
    if (arquivo_vazio == True) {
        printf("Não tem nenhum produto cadastrado...");
        getchar();
    }
    
}