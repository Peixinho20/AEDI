/*Você vai trabalhar   com   o  percurso em  nível  numa  árvore binária.
1. Observe que o procedimento CriaArv uma árvore completa contendo os números 1 a n.
2. Escreva o procedimento PercNiv, SEM MODIFICAR o restante do programa. Você deve
   imprimir o conteúdo dos nós visitados. Observe que os procedimentos para 
   tratamento da fila já estão programados.
3. Observe que a impressão não mostra os dados ordenados.
   Modifique a criação da árvore para que isso ocorra.
4. Crie uma árvore com 10.000.000 e responda abaixo se o procedimento foi rápido:

*/
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct no* arv; // define um endereço de arvore
typedef struct no{ int c;  arv le, ld; }no; // aponta para nós com essa estrutura
arv T,  Q[100000001];  int nc, n; //ponteiro externo; fila;

void EsvaziaFila(int &f, int &r){
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
		EsvaziaFila(f, r);
    else 
		f++;
    return p;
}

arv CriaArv(int n){
    arv p, s, T;  int i, f, r;
    EsvaziaFila(f, r); //f = 0, r = 0
    T = new(no);  T->c = 1;  T->le = T->ld = NULL; Enfila(Q, f, r, T);
    i=1;
    while (f != 0){ //enquanto fila nãos estiver vazia
        p=Q[f];
        if (i < n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL; //add filhos a direita do p
            p->le = s;  Enfila(Q, f, r, s);
        }
        if (i < n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL;
            p->ld = s;  Enfila(Q, f, r, s);
        }
        p = Desenfila(Q, f, r);
    }
    return T; // retorna o ponteiro para a raiz
}  
   
void PercNiv(arv T){
    arv p;   int f, r, v;
    EsvaziaFila(f, r);
    Enfila(Q, f, r, T);
    v = 0;
    while (f > 0){
		v++;
		p = Q[f];
		if (v = 100){
			printf("%d ", p -> c);
		}	
		Enfila(Q, f, r, p -> le);
		Enfila(Q, f, r, p -> ld);	
		p = Desenfila(Q, f, r);
	}
}
int main(){
    while (true){
        cout<<endl<<"Numero de nos: "; cin >> n;
        if (!n) break;
        T = CriaArv(n);
        PercNiv(T); // manda percorrer em niveis passando pela raiz
    }
}

