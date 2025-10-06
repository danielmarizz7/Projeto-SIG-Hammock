typedef struct cliente Cliente;

struct cliente {
    int id;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
};

char tela_de_clientes(void);
void cadastrar_clientes(Cliente*);
void exibir_clientes(Cliente*);
void alterar_cliente(Cliente*);
void excluir_cliente(Cliente*);
void modulo_clientes(void);
