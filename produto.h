typedef struct  produto Produto;

struct produto{
    int id;
    char modelo_rede[31];
    char valor_rede[11];
    char tipo_rede[15]; 
    char cor_rede [26];
};




char tela_de_produto(void);
void cadastrar_produto(Produto*);
void exibir_produto(Produto*);
void alterar_produto(Produto*);
void excluir_produto(Produto*);
void modulo_produto(void);