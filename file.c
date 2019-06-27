#include "teste.h"

TipoPtNo* inicializa(void)
{
    return NULL;
}


void imprime(TipoPtNo* ptLista)
{
    int i=0,j=1,k=1,n[MAX],p[MAX];
    TipoPtNo* ptaux;
    if (ptLista == NULL)
        puts("lista vazia");
    else
        for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox)
        {
            i++;
            printf("\t\t\nLinha Inteira [%d]: %sUser:%s\nTexto:%s\nNumero de RT:%d\nNumero de FAV:%d\n", i,ptaux->info.linhainteira,ptaux->info.arroba,  ptaux->info.texto.text, ptaux->info.NumRT, ptaux->info.NumFav);
            n[j]=strlen(ptaux->info.texto.hashtag[j]);
            p[k]=strlen(ptaux->info.texto.mencoes[k]);
      while (n[j]!=0)
           {
            printf("Hashtag [%d]: %s\n" ,j,ptaux->info.texto.hashtag[j]);
            j++;
            n[j]=strlen(ptaux->info.texto.hashtag[j]);
            }

            while (p[k]!=0)
           {
            printf("Mencao  [%d]: %s\n" ,k,ptaux->info.texto.mencoes[k]);
            k++;
            p[k]=strlen(ptaux->info.texto.mencoes[k]);
            }


            j=1;
            k=1;
            printf("\n\n");
        }
}

TipoPtNo* Insere(TipoPtNo* ptLista, TipoInfo dados)
{
    TipoPtNo *novo;
    novo=malloc(sizeof(TipoPtNo));
    strcpy(novo->info.linhainteira,dados.linhainteira);

    strcpy(novo->info.arroba,dados.arroba);
    novo->info.NumFav=dados.NumFav;
    novo->info.NumRT=dados.NumRT;

    strcpy(novo->info.texto.text,dados.texto.text);

    novo->prox=ptLista;
    ptLista=novo;

    return ptLista;
}

void abre_operacoes(char *op, int *n)
{
    FILE *arq2;
    arq2=fopen("consultas-100.csv", "r");
    char buffer[MAX];

        while(fgets(buffer, MAX, arq2)!=NULL)
        {
            strcpy(op, strtok(buffer,";"));
            *n=atoi(strtok(NULL, "  "));
            printf("\n\tOperacao: %s \n\t n:%d", *op,*n);
            }

    }

TipoPtNo *achahashtag(TipoPtNo *ptLista, char string[])
{

	char str[MAX] = "@ufrgsnoticias;Só gente feliz. #UFRGSPortasAbertas #UFRGS85anos #gez #piupiu; #popo;3;45";
	char *palavra;
	char delimiter[]= {" ,.&*%\?!;/-'@\"$=><()][}{:\n\t"};

	int j = 1;

	//printf("\n\nFrase Hashtag: %s: ", string);

	palavra = strtok(string, delimiter);

	while(palavra!=NULL) {
		if(strchr(palavra, '#') != NULL)
            {
			strcpy(ptLista->info.texto.hashtag[j] , palavra);
			//printf( "\nHashtag Posicao [ %d ] : %s", j, ptLista->info.texto.hashtag[j]);
			j++;
		}

		palavra = strtok(NULL, delimiter);
	}

	return ptLista;
}


TipoPtNo *achamencao(TipoPtNo *ptLista, char str[])
{

char *palavra2;
	char delimiter[]= {" ,.&*%\?!;/-'\"$=><()][}{:\n\t"};

	int j = 1;

	//printf("\n\nFrase Mencao: %s: ", str);

	palavra2 = strtok(str, delimiter);

	while(palavra2!=NULL) {
		if(strchr(palavra2, '@') != NULL)
            {
			strcpy(ptLista->info.texto.mencoes[j] , palavra2);
			//printf( "\nMencao  [ %d ] : %s", j, ptLista->info.texto.mencoes[j]);
			j++;
		}

		palavra2 = strtok(NULL, delimiter);
	}

	return ptLista;
}

void crescente(TipoPtNo* ptListaBackup, int lim)
{
    TipoPtNo *ptaux, *ant,*aux2;
    TipoPilha *p;

    p=InicializaPilha();
    int i=0,a;
    int visitado[MAX];
   ptaux=ptListaBackup;
   while(ptaux!=NULL)
   {

       ptaux=ptaux->prox;
       ptaux->info.flag=0;

   }

    ptaux=ptListaBackup;



while(lim!=0)
{
    while (ptaux->prox  !=NULL)
    {

        ant = ptaux;
        ptaux = ptaux->prox;
        if (ptaux->info.NumRT < ant->info.NumRT )
        {
           aux2->prox=ptaux->prox;
            ptaux = ant;
            ptaux->prox=aux2->prox;
            }
    }
lim--;
    p=PushPilha(p, ptaux->info);
    remover(ptListaBackup, ptaux->auxiliar.i);
    ptaux=ptListaBackup;
}
    ImprimirPilha(p);

}





/*
while(ptaux2!=NULL)
    {

        novo->info.NumRT=ptaux2->info.NumRT;
        while (ptaux  !=NULL && (novo->info.NumRT)>ptaux->info.NumRT)
    {
        ant = ptaux;
        ptaux = ptaux->prox;
    }

    novo->prox=ptaux;
    if (ant)
        ant->prox=novo;
    else

        ptListaCrescente=novo;

ptaux2=ptaux2->prox;*/









TipoPtNo* ax (TipoPtNo *ptLista)
{

    int i=1;
    while(ptLista!=NULL)
    {
    ptLista->auxiliar.i=i;
        i++;
        ptLista=ptLista->prox;
    }
        return ptLista;

}









TipoPtNo* remover(TipoPtNo* ptLista, int dado)
{
TipoPtNo *ant = NULL; //ponteiro auxiliar para a posição anterior
TipoPtNo *ptaux = ptLista; //ponteiro auxiliar para percorrer a lista
/*procura o elemento na lista*/
while (ptaux !=NULL && (ptaux->auxiliar.i==dado))
{
ant = ptaux;
ptaux = ptaux->prox;
}
if (ptaux == NULL) /*verifica se achou*/
return ptLista; /*retorna a lista original*/
if (ant == NULL) /*vai remover o primeiro elemento*/
ptLista = ptaux->prox;
else /*vai remover do meio ou do final*/
ant->prox = ptaux->prox;
free(ptaux); /*libera a memória alocada*/
return ptLista;
}








































































struct TPtPilha
{
    TipoInfo info;
    struct TPtPilha *elo;
};


TipoPilha* InicializaPilha (void)
{
    return NULL;
}

int PilhaVazia (TipoPilha *Topo)
{
    if (Topo==NULL)
        return 1;
    else
        return 0;
}

void ImprimirPilha (TipoPilha *Topo)
{
    TipoPilha *ptaux;

    if (Topo != NULL)
    {
        puts("---Imprimindo pilha---");
        for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
            printf("\t\t\nLinha Inteira : %s@:%s\nTexto:%s\nNumero de RT:%d\nNumero de FAV:%d\n",ptaux->info.linhainteira,ptaux->info.arroba,  ptaux->info.texto.text, ptaux->info.NumRT, ptaux->info.NumFav);
        puts("-------Fim pilha------");
    }
    else
        puts("Pilha vazia");

}


TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)
{
    TipoPilha *novo; //novo elemento
    TipoPilha *ptaux = Topo; //ponteiro auxiliar para percorrer a lista

    /*aloca um novo nodo */
    novo = (TipoPilha*) malloc(sizeof(TipoPilha));
    novo->elo = NULL;

    /*insere a informação no novo nodo*/
    novo->info = Dado;

    /*encaeia o elemento*/
    novo->elo = Topo;
    Topo = novo;
    return Topo;
}


/*int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //retorna 1 se exclui e zero se não exclui
{
   TipoPilha* ptaux;

   if (PilhaVazia(*Topo))
     return 0;   //não tem nada na pilha
   else
   {
        *Dado = (*Topo)->dado;     // devolve o valor do topo
        ptaux = *Topo;          //guarda o endereço do topo
        *Topo = (*Topo)->elo;     //o próximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        ptaux=NULL;
        return 1;
   }
}
*/

/*TipoInfo ConsultaPilha (TipoPilha *Topo)
{
 if (Topo==NULL)
   return 0;
 else
   return Topo->dado;

}

TipoPilha* DestroiPilha (TipoPilha *Topo)
{
        TipoPilha *ptaux;
        while (Topo != NULL)
        {
          ptaux = Topo;          //guarda o endereço do topo
          Topo = Topo->elo;     //o próximo passa a ser o topo
          free(ptaux);           //libera o que estava no topo
        }
        return NULL;
}
*/

