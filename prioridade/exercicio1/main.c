#include <stdio.h>
#include <stdlib.h>
/*1) A partir do código de fila, faça as alterações necessárias para que a fila se transforme em uma fila de prioridade por idade.
(Obs: Faça a implementação deixando a fila já ordenada com as pessoas com mais de 60 anos no início).
*/
typedef struct Celula{
    int idade;
    struct Celula *prox;
}Celula;

typedef struct{
    Celula *primeiro;
    Celula *ultimo;
}tipoFila;

void CriarVazio(tipoFila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}
int verificarVazio(tipoFila *fila){
    return fila->primeiro == NULL;
}



void adicionar (tipoFila *fila, Celula celula){
    Celula *c = (Celula*) malloc(sizeof(Celula));
    Celula *c2 = fila->primeiro;
    *c = celula;
    c->prox = NULL;
    if(verificarVazio(fila)){
        fila->primeiro = c;
        fila->ultimo = c;
    }else{
        if(c->idade > 60){
                if(fila->primeiro->idade <=60){
                    c->prox = fila->primeiro;
                    fila->primeiro = c;
                }else{
                    while(c2->prox->idade >60){
                        c2 = c2->prox;
                    }
                    c->prox =c2->prox;
                    c2->prox = c;
                }
        }else{
            fila->ultimo->prox = c;
            fila->ultimo = c;
        }
    }
}
void remover(tipoFila *fila){
    Celula *celula = fila->primeiro;
    fila->primeiro = fila->primeiro->prox;
    free(celula);
}
void printar(tipoFila *fila){
    Celula *celula = fila->primeiro;
    while(celula !=NULL){
        printf("Idade:%d\n",celula->idade);
        celula = celula->prox;
    }
}

int main()
{
    tipoFila fila;
    CriarVazio(&fila);
    Celula c;
    c.idade = 20;
    adicionar(&fila,c);
    c.idade= 18;
    adicionar(&fila,c);
    c.idade= 70;
    adicionar(&fila,c);
    c.idade= 90;
    adicionar(&fila,c);
    printar(&fila);

    return 0;
}
