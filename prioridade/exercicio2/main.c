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
    int qnt;
}tipoFila;

void CriarVazio(tipoFila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->qnt = 0;
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
    fila->qnt++;
}

    void balancear(tipoFila *fila1, tipoFila *fila2, Celula celula){
        if((abs(fila1->qnt - fila2->qnt)) > 2 ){
            if(fila1->qnt> fila2->qnt){
                adicionar(fila2,celula);
            }else{
                adicionar(fila1,celula);
            }
        }else{
            adicionar(fila1,celula);
        }
    }

    Celula remover(tipoFila *fila){
        Celula *celula = fila->primeiro;
        Celula *c = fila->primeiro;
        fila->primeiro = fila->primeiro->prox;
        fila->qnt --;
        free(celula);
        return *c;
}
    void balancearRemover(tipoFila *fila1, tipoFila *fila2){
        Celula *c = fila1->primeiro;
        remover(fila1);
         if((abs(fila1->qnt - fila2->qnt)) > 2 ){
                adicionar(fila1, remover(fila2));
         }
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

    tipoFila  caixa1, caixa2;
    CriarVazio(&caixa1);
    CriarVazio(&caixa2);
    Celula c;
    c.idade = 20;
    balancear(&caixa1,&caixa2,c);
    c.idade= 18;
    balancear(&caixa1,&caixa2,c);
    c.idade= 70;
    balancear(&caixa1,&caixa2,c);
    c.idade= 90;
    balancear(&caixa1,&caixa2,c);
    printf("caixa 1: \n%d\n", caixa1.qnt);
    printar(&caixa1);
    printf("caixa 2: \n%d\n", caixa2.qnt);
    printar(&caixa2);
    balancearRemover(&caixa2,&caixa1);
    printf("caixa 1: \n%d\n", caixa1.qnt);
    printar(&caixa1);
    printf("caixa 2: \n%d\n", caixa2.qnt);
    printar(&caixa2);

    return 0;
}
