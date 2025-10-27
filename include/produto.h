typedef struct  produto Produto;

struct produto{
    int id;
    char modelo_rede[31];
    float valor_rede;
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
void restaurar_produto(void);
void perma_excluir_produto(void);
void modulo_produto(void);
int verificar_id_produto(int);
float verificar_valor_produto(int);