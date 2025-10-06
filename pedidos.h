typedef struct pedido Pedido;

struct pedido {
    int id_pedido;
    int id_cliente;
    int id_produto;
    int id_funcionario;
    float preco;
    char data[26];
};

void modulo_pedidos(void);
char tela_de_pedidos(void);
void cadastrar_pedidos(int, int, int, float, char[]);
void exibir_pedidos(int, int, int, float, char[]);
void alterar_pedido(void);
void excluir_pedido(void);