typedef struct cliente Cliente;

struct cliente {
    int id;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
    int status;
};

char tela_de_clientes(void);
void cadastrar_clientes(void);
void exibir_clientes(void);
void listar_clientes(void);
void alterar_cliente(void);
void excluir_cliente(void);
void modulo_clientes(void);
