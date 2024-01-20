/*

    Estrutura de Dados I - Trabalho prático 1 N2 - PILHAS

    Aluno: Breno de Castro Monteiro Loureiro - 20201143015

*/

#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstaticaSequencial.h"


//---------------------------------------------------------------------------
struct pilha{
    int qtd;
    int vet[MAX];
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void libera_Pilha(Pilha* pi){
    free(pi);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int topo_Pilha(Pilha* pi, int *v){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *v = pi->vet[pi->qtd-1];
    return *v;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int insere_Pilha(Pilha* pi, int v){
    if(pi == NULL)
        return 0;
    if(pi->qtd == MAX)
        return 0;
    pi->vet[pi->qtd] = v;
    pi->qtd++;
    return 1;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int pilha_Cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int pilha_Vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i=pi->qtd-1; i >=0; i--){
        printf("\n| Vetor [%d]: %d",i, pi->vet[i]);
        printf("\n|");
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void menuPrincipal(){

    int menu1;

    do{
    printf("\n _______________________________________________________________");
    printf("\n|                                                               |");
    printf("\n|                        MENU PRINCIPAL                         |");
    printf("\n|_______________________________________________________________|");
    printf("\n|                                                               |");
    printf("\n|                   O que você deseja fazer ?                   |");
    printf("\n|_______________________________________________________________|");
    printf("\n|                                                               |");
    printf("\n|  1- Criar uma pilha                                           |");
    printf("\n|  2- Concatenação de pilhas                                    |");
    printf("\n|  0- Encerrar o programa                                       |");
    printf("\n|_______________________________________________________________|");
    printf("\n");

    scanf("%d", &menu1);
    getchar();

    system("cls");

    switch(menu1){
        case 0:
            printf("\n ____________________________________________________________________");
            printf("\n|                                                                    |");
            printf("\n| Programa encerrado, pressione qualquer tecla para fechar a janela  |");
            printf("\n|____________________________________________________________________|");
            printf("\n");
            exit(0);
            break;
        case 1:
            menuPilhaUnica();
            break;
        case 2:
            menuConcatena();
            break;
        default:
            printf("\nEscolha inválida, digite uma opção válida\n\n");
            break;
    }
    }while(menu1);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void menuPilhaUnica(){

    int menu2, v[0];

    Pilha* pi = cria_Pilha();
    printf("\n Pilha criada com sucesso\n");

    do{
    printf("\n ______________________________________________________________");
    printf("\n|                                                              |");
    printf("\n|                          MENU PILHA                          |");
    printf("\n|______________________________________________________________|");
    printf("\n|                                                              |");
    printf("\n|            O que você deseja fazer com a pilha ?             |");
    printf("\n|______________________________________________________________|");
    printf("\n|                                                              |");
    printf("\n|  1- Checar o seu tamanho                                     |");
    printf("\n|  2- Adicionar um valor no topo                               |");
    printf("\n|  3- Deletar o valor do topo                                  |");
    printf("\n|  4- Verificar o valor no topo da pilha                       |");
    printf("\n|  5- Verificar se a pilha está vazia                          |");
    printf("\n|  6- Verificar se a pilha está cheia                          |");
    printf("\n|  7- Imprimir pilha                                           |");
    printf("\n|  0- Deletar pilha e voltar ao menu principal                 |");
    printf("\n|______________________________________________________________|");
    printf("\n");

    scanf("%d", &menu2);
    getchar();

    switch(menu2){
        case 0:
            libera_Pilha(pi);
            system("cls");
            printf("\n A pilha foi deletada, voltamos ao menu principal\n");
            menuPrincipal();
            break;
        case 1:
            system("cls");
            printf("\nQuantidade de valores: %d\n\nPosicões restantes: %d\n\n", tamanho_Pilha(pi), (MAX - tamanho_Pilha(pi)));
            break;
        case 2:
            if(tamanho_Pilha(pi) < MAX){
            system("cls");
            printf("\nDigite o valor a ser adicionado:\n");
            scanf("%d", &v[0]);
            getchar();
            insere_Pilha(pi, v[0]);
            printf("\nO valor %d foi inserido na pilha com sucesso\n\n", v[0]);
            }else{
                system("cls");
                printf("\nA pilha está cheia, não é possivel inserir um novo valor\n\n");
            }
            break;
        case 3:
            system("cls");
            if(pilha_Vazia(pi) == 1){
                printf("\n\nNão existe valor para ser deletado\n\n.");
            }else{
                remove_Pilha(pi);
                printf("\n\nValor deletado com sucesso\n\n.");
            }
            break;
        case 4:
            system("cls");
            if(topo_Pilha(pi, v) == 0){
                printf("\n\nPilha sem valores\n\n");
                break;
            }else{
                printf("\nValor do topo: %d\n\n", topo_Pilha(pi , v));
            }
            break;
        case 5:
            system("cls");
            if(pilha_Vazia(pi) == 1){
                printf("\nA pilha está vazia\n\n");
            }else{
                printf("\nA pilha não está vazia. Escolha a opção '1' no MENU PILHA para mais detalhes\n\n");
            }
            break;
        case 6:
            system("cls");
            if(tamanho_Pilha(pi) < MAX){
                printf("\nA pilha não está cheia\n\n");
            }else{
                printf("\nA pilha está cheia\n\n");
            }
            break;
        case 7:
            system("cls");
            if(tamanho_Pilha(pi) == 0){
                printf("\nNão há valores na pilha\n\n");
            }else{
                printf("\n _______________________");
                printf("\n|                       ");
                printf("\n|         Pilha         ");
                printf("\n|");

                imprime_Pilha(pi);
                printf("\n|_______________________");
            }
            break;
        default:
            system("cls");
            printf("\nEscolha inválida, digite uma opção válida\n\n");
            break;
    }
    }while(menu2);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void menuConcatena(){

    int menu2;

    do{
    printf("\n _____________________________________________________________");
    printf("\n|                                                             |");
    printf("\n|                      MENU CONCATENAÇÃO                      |");
    printf("\n|_____________________________________________________________|");
    printf("\n|                                                             |");
    printf("\n|                  O que você deseja fazer ?                  |");
    printf("\n|_____________________________________________________________|");
    printf("\n|                                                             |");
    printf("\n|  1- Concatenar pilha 'A' e pilha 'B'                        |");
    printf("\n|  2- Concatenar pilha 'B' e pilha 'A'                        |");
    printf("\n|  0- Voltar ao menu principal                                |");
    printf("\n|_____________________________________________________________|");
    printf("\n");


    scanf("%d", &menu2);
    getchar();

    system("cls");

    switch(menu2){
        case 0:
            system("cls");
            printf("\nVoltamos ao menu principal\n\n");
            menuPrincipal();
            break;
        case 1:
            menuPilhasDuplas_A_B();
            break;
        case 2:
            menuPilhasDuplas_B_A();
            break;
        default:
            printf("\nEscolha inválida, digite uma opção válida\n\n");
            break;
    }
    }while(menu2);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void menuPilhasDuplas_A_B(){

    int v1[7] = {11,12,13,14,15,16,17};
    int v2[8] = {51,52,53,54,55,56,57,58};
    int i;

    Pilha* pi1 = cria_Pilha();
    Pilha* pi2 = cria_Pilha();
    Pilha* pi3 = cria_Pilha();

    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha 'A' criada com sucesso");


    for(i = 0; i < 7; i++){
        insere_Pilha(pi1,v1[i]);
    }

    imprime_Pilha(pi1);

    printf("\n| Tamanho final: %d", tamanho_Pilha(pi1));
    printf("\n|_____________________________________________________________");


    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha 'B' criada com sucesso");


    for(i = 0; i < 8; i++){
        insere_Pilha(pi2,v2[i]);
    }

    imprime_Pilha(pi2);

    printf("\n| Tamanho final: %d", tamanho_Pilha(pi2));
    printf("\n|_____________________________________________________________");

    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha concatenada de 'A' recebendo 'B'");

    int vA[7];
    int vB[8];

    for(int i = 0; i < 7; i++){
        vA[i] = topo_Pilha(pi1, v1);
        remove_Pilha(pi1);
    }

    for(int i = 0; i < 8; i++){
        vB[i] = topo_Pilha(pi2, v2);
        remove_Pilha(pi2);
    }

    for(int i = (7-1); i >= 0; i--){
        insere_Pilha(pi3, vA[i]);
    }

    for(int i = (8-1); i >= 0; i--){
        insere_Pilha(pi3, vB[i]);
    }

    imprime_Pilha(pi3);

    printf("\n| Tamanho da pilha concatenada 'A'_'B': %d", tamanho_Pilha(pi3));
    printf("\n|_____________________________________________________________");

    libera_Pilha(pi1);
    libera_Pilha(pi2);
    libera_Pilha(pi3);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void menuPilhasDuplas_B_A(){

    int v1[7] = {71,72,73,74,75,76,77};
    int v2[8] = {101,102,103,104,105,106,108,109};
    int i;

    Pilha* pi1 = cria_Pilha();
    Pilha* pi2 = cria_Pilha();
    Pilha* pi3 = cria_Pilha();

    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha 'A' criada com sucesso");


    for(i = 0; i < 7; i++){
        insere_Pilha(pi1,v1[i]);
    }

    imprime_Pilha(pi1);

    printf("\n| Tamanho final: %d", tamanho_Pilha(pi1));
    printf("\n|_____________________________________________________________");


    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha 'B' criada com sucesso");


    for(i = 0; i < 8; i++){
        insere_Pilha(pi2,v2[i]);
    }

    imprime_Pilha(pi2);

    printf("\n| Tamanho final: %d", tamanho_Pilha(pi2));
    printf("\n|_____________________________________________________________");

    printf("\n _____________________________________________________________");
    printf("\n|                                                             ");
    printf("\n|                Pilha concatenada de 'B' recebendo 'A'");

    int vA[7];
    int vB[8];

    for(int i = 0; i < 7; i++){
        vA[i] = topo_Pilha(pi1, v1);
        remove_Pilha(pi1);
    }

    for(int i = 0; i < 8; i++){
        vB[i] = topo_Pilha(pi2, v2);
        remove_Pilha(pi2);
    }

    for(int i = (8-1); i >= 0; i--){
        insere_Pilha(pi3, vB[i]);
    }

    for(int i = (7-1); i >= 0; i--){
        insere_Pilha(pi3, vA[i]);
    }

    imprime_Pilha(pi3);

    printf("\n| Tamanho da pilha concatenada 'B'_'A': %d", tamanho_Pilha(pi3));
    printf("\n|_____________________________________________________________");

    libera_Pilha(pi1);
    libera_Pilha(pi2);
    libera_Pilha(pi3);
}
//---------------------------------------------------------------------------
