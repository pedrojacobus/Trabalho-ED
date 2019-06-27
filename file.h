#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#endif // TESTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
#define MAXRT 10



struct TEXT
{
    char text[MAX];
    char hashtag[MAX][30];
    char mencoes[MAX][30];

}
;typedef struct TEXT TEXTO;
struct aux
{
    int i;
    int flag;
};
typedef struct aux AUX;


struct SINFO
{
    char linhainteira[MAX];
    TEXTO texto;
    char arroba[MAX];
    int NumRT;
    int NumFav;
    int flag;
};
typedef struct SINFO TipoInfo;

struct tipoponteiro
{
    AUX auxiliar;
    TipoInfo info;
    struct tipoponteiro *prox;
};
typedef struct tipoponteiro TipoPtNo;


void imprime(TipoPtNo* ptLista);
TipoPtNo* Insere(TipoPtNo* ptLista, TipoInfo dados);
//void abre_operacoes(char *op, int *n)
TipoPtNo *achahashtag(TipoPtNo *ptLista, char string[]);
TipoPtNo *achamencao(TipoPtNo *ptLista, char str[]);
void crescente(TipoPtNo* ptLista, int lim);

TipoPtNo* inicializa(void);
TipoPtNo* remover(TipoPtNo* ptLista, int dado);

TipoPtNo* ax (TipoPtNo *ptLista);







typedef struct TPtPilha TipoPilha;


TipoPilha* InicializaPilha (void);
int PilhaVazia (TipoPilha *Topo);
void ImprimirPilha (TipoPilha *Topo);
TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado);
int PopPilha (TipoPilha **Topo, TipoInfo *Dado);
TipoInfo ConsultaPilha (TipoPilha *Topo);
TipoPilha* DestroiPilha (TipoPilha *Topo);
