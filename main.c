#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
#include "teste.h"
#define MAXRT 10






int main()
{
    TipoPtNo *Lista;
    TipoPtNo *ListaCrescente;
    ListaCrescente=inicializa();
    TipoInfo dados;
    Lista=inicializa();

  { //funcao para abrir o arquivo de operacoes (BUG NA PRIMEIRA OPERACAO, TA LENDO LIXO
        char op[MAX], carac[2]="g", HTopg[20];
        int n,l;
        FILE *arq2;
        arq2=fopen("consultas-100.csv", "r");
        if (arq2==NULL)
            puts("\tERRO NA ABERTURA DO ARQUIVO DE OPERACOES");
        char buffer[MAX];
while(fgets(buffer, MAX, arq2)!=NULL)
        {

 strcpy(op, strtok(buffer,";"));
            l=strlen(op);

            //printf("\nl=%d\n" ,l);
            while(l!=1)
            {

                l=l-1;
            }
            if (l==1)
            {


            if(strcmp(carac, op) == 0) //verificacao se a operacao chamda eh a g, caso especifico em que nao retorna um int mas sim um char
            {

                strcpy(HTopg, strtok(NULL, "  ") );
                //printf("Operacao:%s hashtag: %s",op, HTopg);
            }
            else
            {

                n=atoi(strtok(NULL, "  "));
                //printf("Operacao:%s n:%d", op,n);
            }
             }
            //printf("\n");
        }
  }





        //essa parte aqui eh pra abrir o arquivo texto
        char tudo[MAX], teste[MAX], teste2[MAX];
        FILE *arq;
        arq=fopen("base-100.csv", "r");
        if (arq==NULL)
            printf("\n\n\t\t ERRO NA ABERTURA \n\n");
        int nRT,nFAV,i=0;
        char arroba[MAX], texto[MAX];
        while(fgets(tudo, MAX, arq)!=NULL)
        {


            strcpy(dados.linhainteira, tudo);
            strcpy(arroba, strtok(tudo,";")); //separa o @ que fez o tweet
            strcpy(dados.arroba,arroba);
            strcpy(texto, strtok(NULL,";"));
            strcpy(dados.texto.text,texto); //aqui separa todo o texto (parte depois do @) e armazena na structure texto, pq depois tem que achar as hashtags e as mencoes
            nRT= atoi(strtok(NULL,";")); //atoi converte tipo char pra tipo int
            dados.NumRT=nRT;
            nFAV=atoi(strtok(NULL, " ;"));
            dados.NumFav=nFAV;
            //aqui a gente coloca as insercoes de outras ED'S, exemplo ListaDuplamenteEncadeada=Insere...
            Lista=Insere(Lista,dados);


            strcpy(teste,dados.texto.text);
            strcpy(teste2,dados.texto.text);
            //aqui tambem teria que fazer pras outras ED's
            Lista=achamencao(Lista, teste);
            Lista=achahashtag(Lista,teste2);
}
        imprime(Lista);







        ;
        return 0;
    }
