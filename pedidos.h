typedef struct pedido Pedido;

struct pedido {
    int id_pedido;
    int id_cliente;
    int id_produto;
    int id_funcionario;
    float preco;
    char data[26];
};

char tela_de_pedidos(void);
void cadastrar_pedidos(Pedido*);
void exibir_pedidos(Pedido*);
void alterar_pedido(Pedido*);
void excluir_pedido(Pedido*);
void modulo_pedidos(void);