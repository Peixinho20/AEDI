/* Você vai trabalhar com os percursos recursivos numa  árvore binária.
1. Entenda o programa apresentado. 
2. Escreva os procedimentos Percpre, Percino, Percpos
3. Desenhe uma possível árvore binária correspondente aos percursos
   apresentados, para n=10.
*/
#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

typedef struct no* arv;  struct no{	int c;  arv ld,le;}; 
arv T;  int i, j, nc, n, f, r;  arv Q[100001];

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

void PercPre(arv p){
	if (p != NULL){
		printf(" %d ",p->c);
		PercPre(p->le);
		PercPre(p->ld);
	}
   /*  se p != nulo:
           escreve(p.c,' ')
           PercPre(p.le)
           PercPre(p.ld)
  */
}
void PercIno(arv p){
	if (p != NULL){
		PercIno(p->le);
		printf(" %d ",p->c);
		PercIno(p->ld);
	}
   /*  se p != nulo:
           PercIno(p.le)
           escreve(p.c,' ')
           PercIno(p.ld)
  */
}
void PercPos(arv p){
	if (p != NULL){
		PercPos(p->le);
		PercPos(p->ld);
		printf(" %d ",p->c);
	}
   /*  se p != nulo:
           PercPos(p.le)
           PercPos(p.ld)
           escreve(p.c,' ')           
  */
}

int main(){
    srand(time(NULL));
	nc=15;
    while(nc--){
        cout<<endl<<"Numero de nos: "; cin >> n;
        CriaArv();
        cout<<endl<<endl<<"Percurso em Pre-ordem"<<endl; PercPre(T);
        cout<<endl<<endl<<"Percurso em In-Ordem"<<endl;  PercIno(T);
        cout<<endl<<endl<<"Percurso em Pos-ordem"<<endl; PercPos(T);        
        DestroiArv(T);
	}
	return 0;
}
         


