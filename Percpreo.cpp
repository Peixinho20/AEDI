/*Você vai trabalhar com o percurso  pré-ordem  numa  árvore binária,
  versão não recursiva, usando uma pilha.
a)  Escreva, APENAS, o procedimento Percpre. Observe que oas operações
  PUSH e POP já estão implementadas, de forma simplificada.
  NÃO MODIFIQUE o restante do programa 
b) Crie  árvores para n = 10.000.000 e 100.000.000 eresponda a seguir se 
	o programa rodou rápido:
   
    
*/
#include<iostream>
using namespace std;

typedef struct no* arv;
struct no{ int c;  arv le, ld; };
arv T,  Q[100000001], S[100000001]; int n, f, r;

void EsvaziaPil(int &topo){
    topo=0;
}
void PUSH(arv S[], int &topo, arv p){
    if (p != NULL) 
	 	S[++topo]=p;
}
arv POP(arv S[], int &topo){
    arv p;
    p = S[topo--];
    return p;
}          
void EsvaziaFil(int &f, int &r){
    f = r = 0;
}
void Enfila(arv Q[], int &f, int &r, arv p){
    if (p != NULL){
        Q[++r] = p;
        if (f==0) 
			f = 1;
    }
}
arv Desenfila(arv Q[], int &f, int &r){
    arv p;
    p = Q[f];
    if (f == r) 
		EsvaziaFil(f, r);
    else 
		f++;
    return p;
}
arv CriaArv(int n){
    arv p, s, T;  int i, f, r;
    EsvaziaFil(f, r);
    T = new(no);  T->c = 1;  T->le = T->ld = NULL; Enfila(Q, f, r, T);
    i=1;
    while (f != 0){
        p=Q[f];
        if (i < n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL;
            p->ld = s;  Enfila(Q, f, r, s);
        }
        if (i < n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL;
            p->le = s;  Enfila(Q, f, r, s);
        }
        p = Desenfila(Q, f, r);
    }
    return T;
}  
void PercPre(arv T){
    arv  p;  int topo, v;
    EsvaziaPil(topo);
    PUSH(S, topo, T);
    v = 0;
    while (topo != 0){
		v++;
		p = POP(S, topo);
		if (v = 100){
			printf("%d",p -> c);
		}
		PUSH(S, topo, p -> ld);
		PUSH(S, topo, p -> le);
}
int main(){
    while (true){
        cout<<endl<<"Numero de nos: "; cin >> n;      
        if (!n) break;
        T = CriaArv(n);
        PercPre(T);
    }
}






