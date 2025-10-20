typedef struct funcionarios Funcionarios;

struct funcionarios {
    int id;
    char nome[51];
    char cpf[12];
    char email[26];
    char telefone[12];
    int status;
};



char tela_de_funcionarios(void);
void cadastrar_funcionarios(void);
void exibir_funcionarios(void);
void listar_funcionarios(void);
void alterar_funcionarios(void);
void excluir_funcionarios(void);
void restaurar_funcionarios(void);
void perma_excluir_funcionario(void);
void modulo_funcionarios(void);