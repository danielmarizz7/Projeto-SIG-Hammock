typedef struct  produto Produto;

struct produto{
    int id;
    char modelo_rede[31];
    char valor_rede[11];
    char tipo_rede[15]; 
    char cor_rede [26];
    int status;
};




char tela_de_produto(void);
void cadastrar_produto(void);
void exibir_produto(void);
void listar_produto(void);
void alterar_produto(void);
void excluir_produto(void);
void modulo_produto(void);