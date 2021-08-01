/*Você vai trabalhar com árvores binárias de busca, reconhecendo
   se dada árvore é estritamente binária ou não.
1. Converta o procedimento EstrBin.
2. Obtenha, experimentalmente, a probabilidade de ser gerada
   uma árvore estritamente binária. Escreva abaixo essa probabilidade:
   
   Dica: quando for contar os casos positivos em 1000 tentativas, 
   iniba o comando cin.get()
3. Modifique o programa para só gerar n ímpar e coloque a nova
   probabilidade abaixo:
   
   
*/
#include <iostream>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;

typedef struct no* arv;  struct no{	int c;  arv ld,le;}; 
arv T, Q[1000001];  
int i, j, nc, n, RT[51][51], f, r; 

void EsvaziaFil(void){
	f = r = 0;
}

void Enfila(arv p){
    if (p != NULL){
        Q[++r]= p;
        if (f == 0) f = 1;
	}
}

arv Desenfila(void){
    arv p;
    p = Q[f];
    if (f == r) EsvaziaFil();
    else f++;
    return p;
}

void CriaArv(void){
	arv p,v;  int i;
    EsvaziaFil();
    T = new(no);
    i = 1; T->c = i; T->le = T->ld = NULL; Enfila(T);	 
    while (f != 0){
        p = Q[f];
        
        if (i < n && rand()%2==1){
			i++;  v =new(no);  
			v->c = i; v->le = v->ld = NULL; p->le = v; Enfila(v);
        }
        if (i < n && rand()%2==1){
            i++;  v = new(no);  
			v->c = i; v->le = v->ld = NULL; p->ld = v; Enfila(v);
        }
        p = Desenfila();
    }
}

void DestroiArv(arv p){	
    if (p != NULL){
        DestroiArv(p->le);
        DestroiArv(p->ld);
        free(p);
	}
}


bool EstrBin(arv p){
/*  se p é nulo:
		retornar V
	senão:
		se ((p é folha) ou (p.le != nulo e p.ld != nulo):
			retornar (EstrBin(p.le) e EstrBin(p.ld);
		senão:
			retornar F;
*/  
}
void ImpRTVert(arv p, int niv, int &maxniv, int &cont){;
    if (p != NULL){
        if (niv > maxniv)
        	maxniv = niv;
        ImpRTVert(p->ld, niv+1, maxniv, cont);
        if (cont <= 35)
			RT[niv][++cont] = p->c;   
        ImpRTVert(p->le, niv+1, maxniv, cont);
    }
}
void ImprimeArv(arv T){
    int cont, maxniv;
    for(int i=1; i<=35; i++) for (int j=1; j<=35; j++)
		RT[i][j] = -1;
    maxniv = 0;  cont=0;
	ImpRTVert(T, 1, maxniv, cont);
    for (int j=1; j<=min(35,n); j++) {
    	for(int i=1; i<=maxniv; i++)
    		if (RT[i][j] == -1)
    			cout<<" . ";
    		else
				cout<<fixed<<setw(3)<<RT[i][j];
		cout<<endl;
    }
}

int main(){
    srand(time(NULL));
	nc=1000;
    while(nc--){
        n = rand()%20+1;
        CriaArv();
        ImprimeArv(T);
		if (EstrBin(T))
			cout<<"Arvore eh estritamente binaria"<<endl;
		else
			cout<<"Arvore nao eh estritamente binaria"<<endl;		      
        DestroiArv(T);
        cin.get();
	}
	return 0;
}
         


