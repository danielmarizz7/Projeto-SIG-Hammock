typedef struct funcionarios Funcionarios;

struct funcionarios {
    int id;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
};




void modulo_funcionarios(void);
char tela_de_funcionarios(Funcionarios*);
void cadastrar_funcionarios(Funcionarios*);
void exibir_funcionarios(Funcionarios*);
void alterar_funcionarios(Funcionarios*);
void excluir_funcionarios(void);