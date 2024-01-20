/*

    Estrutura de Dados I - Trabalho prático 1 N2 - PILHAS

    Aluno: Breno de Castro Monteiro Loureiro - 20201143015

*/

#define MAX 20

typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int topo_Pilha(Pilha* pi, int *v);
int insere_Pilha(Pilha* pi, int v);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int pilha_Vazia(Pilha* pi);
int pilha_Cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

void menuPrincipal();
void menuPilhaUnica();
void menuConcatena();
void menuPilhasDuplas_A_B();
void menuPilhasDuplas_B_A();
