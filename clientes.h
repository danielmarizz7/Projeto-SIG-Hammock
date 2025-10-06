typedef struct cliente Cliente;

struct cliente {
    int id;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
};

void modulo_clientes(void);
char tela_de_clientes(void);
void cadastrar_clientes(char[], char[], char[], char[]);
void exibir_clientes(char[], char[], char[], char[]);
void alterar_cliente(void);
void excluir_cliente(void);
