/* Neste programa trabalha-se com listas encadeadas simples, contendo apenas 3 elementos.
   1. Observe a declaração da lista em C/C++. Observe também sua impressão.
   2. Observe 3 algoritmos diferentes para criar uma lista com os números 1, 2 e 3.
      Os dois primeiros estão implementados. Implemente o terceiro.*/
#include<iostream>
using namespace std;

typedef struct no *pont;
struct no { int c;  pont prox; };
pont cab,p,q;

void ImprimeLista(pont cab){
    pont p;
    p = cab;
    while (p != NULL){
        cout<< p->c <<" ";
        p = p->prox;
    }
    cout<<endl;
}
void Crialista1(){
/*
    cab <- no();      
	cab.c <- 1;    
	p <- no();    
	p.c <- 2;  
	q <- no();  
	q.c <- 3;
    cab.prox <- p;   
	p.prox <- q;   
	q.prox <- nulo; 
*/
    cab = new(no);   
	cab->c = 1;   
	p = new(no);     
	p->c = 2;  
	q = new(no);  
	q->c = 3;
    cab->prox = p;   
	p->prox = q;  
	q->prox = NULL;
    ImprimeLista(cab);         
}
void Crialista2(){
/*
    cab <- no();    
	cab.c <- 1;    
	p <- no();    
	p.c <- 2;   
	cab.prox <- p;
    p <- no();      
	p.c <- 3;      
	cab.prox.prox <- p;       
	p.prox <- nulo;     
*/
    cab = new(no);  
	cab->c = 1;   
	p = new(no);  
	p->c = 2;     
	cab->prox = p;
    p = new(no);    
	p->c = 3;     
	cab->prox->prox = p;        
	p->prox = NULL;
    ImprimeLista(cab);       
}
void Crialista3(){
/*Algoritmo 3:
    cab <- no();   
	p <- cab;    
	p.c <- 1;   
	p.prox <- no();     
	p <- p.prox;
    p.c <- 2;      
	p.prox <- no();          
	p <- p.prox;        
	p.c <- 3;       
	p.prox <- nulo; 
*/  
     
}

int main(){
    Crialista1();
    Crialista2();
    Crialista3();
    cin.get();
}
