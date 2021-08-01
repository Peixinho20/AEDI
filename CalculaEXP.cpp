/*Você vai trabalhar com uma árvore binária que contém uma expressão 
	aritmética. A árvore já está criada e impressa na representação
	tabular vertical.
2. Converter os procedimentos ImprExpressao e CalcExpressao.
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct no* Arv;
struct no{ char c; Arv le,ld;};
Arv T;  int n, tam;
char RT[36][36];

Arv CriaExpressao(char tipono, int toti, int &n){
    int i,j;  char c;  Arv p;
    
    n++;
	p = new(no); 
	p->le = p->ld = NULL;
    if(tipono == 'F') 
		p->c = (rand()%10) + '0';
    else{
        i = rand()%3 +1; toti++;
        if(i == 1)      
			p->c = '+';
        else if(i == 2) 
			p->c = '-';
        else            
			p->c = '*';
        if(toti < tam)    
			j = rand()%2;
        else            
			j = 0;
        if(!j)          
			c = 'F';
        else            
			c = 'I';
        p->le = CriaExpressao(c, toti, n);
        p->ld = CriaExpressao(c, toti, n);
    }
    return p; 
}

void ImpRTVert(Arv p, int niv, int &maxniv, int &cont){;
    if (p != NULL){
        if (niv > maxniv)
        	maxniv = niv;
        ImpRTVert(p->ld, niv+1, maxniv, cont);
        if (cont <= 35)
			RT[niv][++cont] = p->c;   
        ImpRTVert(p->le, niv+1, maxniv, cont);
    }
}
void ImprimeArv(Arv T){
    int cont, maxniv;
    for(int i=1; i<=35; i++) for (int j=1; j<=35; j++)
		RT[i][j] = '.';
    maxniv = 0;  cont=0;
	ImpRTVert(T, 1, maxniv, cont);
    for (int j=1; j<=min(35,n); j++) {
    	for(int i=1; i<=maxniv; i++)
			cout<<" "<<RT[i][j]<<" ";
		cout<<endl;
    }
} 

int Resultado (int a, int b, char op){
    if (op=='+') return a+b;
    else if (op =='-') return a-b;
    else if (op=='*') return a*b;
}

int CalcExpressao(Arv p){
    int ve, vd; 
    if(p->ld == NULL && p->le == NULL){
		return p->c='0';
	}
	else{
		return Resultado(CalcExpressao(p->le),CalcExpressao(p->ld),p->c);
	}
}

string ImprExpressao(Arv p){
	if (p->le = p->ld = NULL){
		return string(1, p->c);
	}
	else{
		return "(" + ImprExpressao(p->le)+ string(1,p->c)+ImprExpressao(p->ld)+")";  
	}	
}

int main(){
    srand (time(NULL));
    tam=10;
    while(true){
    	n = 0;
        T = CriaExpressao('I', rand()%tam, n);
        ImprimeArv(T);
        cout <<ImprExpressao(T)+" = "<< CalcExpressao(T) <<endl;
        cin.get();
    }
    return 0;
}
