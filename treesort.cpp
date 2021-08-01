
/*Você vai trabalhar com o método de ordenação Treesort.
A ideia é ler os n números, criar uma ABB e depois percorrê-la in-ordem.
1. Modifique a ordenação para ela ficar em ordem decrescente.
2. Rode o programa para n = 100, 1000, 10000, 100000, 1000000, 10000000, obtendo
   as comparações efetuadas.
   Obtenha a melhor regressão no site https://pt.planetcalc.com/5992/, coloque abaixo
   e comente:
   
Regressão linear
y=31.0174x−1520152.9657

Coeficiente de correlação linear
0.9998

Coeficiente de determinação
0.9995

Erro relativo médio, %
41979.8969 %  
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct no* arv;
struct no{ int c; arv le,ld;};
int i, j, n, cont, t, v, V[10000001], C[10];
arv T;

void PercIno(arv p, int &v){
    if(p!=NULL){
    	PercIno(p->ld, v);
		V[++v] = p->c;
        PercIno(p->le, v);
    }
}
void InsereABB(int k){
    arv p,f;
    p = f = T;
    while(p != NULL){
        f = p;
        if (k <= p->c)
			p = p->le;
        else            
			p = p->ld;
		cont++;   
    }
     p = new(no);   p->c = k;    p->le = p->ld =  NULL; 
     if(T == NULL)
	 	T = p;
     else if(k <= f->c)
	 	f->le = p;
     else                   
	 	f->ld = p;  
}
void Destroi(arv p){
    if (p != NULL){
        Destroi(p->le);
        Destroi(p->ld);
        free(p);   
    }
}
void TreeSort(int n){
	T = NULL;
    for(i = 1;i<=n;i++) 
		V[i] = (rand()*rand())%n;
    cout<<endl<<"Situacao inicial: ";    
	for(i = 1;i <= min(n,40); i++)   
		cout<<" "<<V[i];  
	cout<<endl;
	cont = 0;
    for(i = 1;i<=n;i++) 
		InsereABB(V[i]);
	v = 0;
	PercIno(T,v);
	cout<<endl<<"Situacao final: ";
	for(i = 1;i <= min(n,40); i++)   
		cout<<" "<<V[i];  
	cout<<endl<<cont<<" comparacoes"<<endl;
	C[t] = cont;
	Destroi(T);
}

int main(){
	srand (time(NULL));
	n = 100;  t = 1;
    while (t <= 6){
        cout<<endl<<" n = "<<n<<endl;
        TreeSort(n);
        n = n*10;  t++;
    }
    cout<<endl;
    for (n=100; n<=10000000; n = n*10){
        cout<<n<<" ";
    }
	cout<<endl;    
    for (t=1; t<=6; t++){
        cout<<C[t] <<" ";
    }
    cout<<endl;
    return 0;
}
