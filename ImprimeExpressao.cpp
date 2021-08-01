/*Voc� vai trabalhar com uma �rvore bin�ria que cont�m uma express�o aritm�tica.
   A �rvore j� est� criada.
1. Voc� deve implementar a fun��o ImprimeParentisada, para imprimir a express�o
	totalmente parentisada.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct no* Arv;
struct no{ char c; Arv le,ld;};
Arv T;  int n, toti;

void ImprimeParentisada(Arv p){
	if (p->le == NULL && p->ld == NULL){ //se p eh folha
		printf (" %c ",p->c);
	}	
	else{
		printf ("(");
		ImprimeParentisada(p->le);
		printf(" %c ",p->c);
		ImprimeParentisada(p->ld);
		printf (")");
	}
}
Arv CriaExpr(char tipono){
    int i,j;  char c;  Arv p;
    
    p = new(no); p->le = p->ld = NULL;
    if(tipono == 'F') p->c = (rand()%10) + '0';
    else{
        i = rand()%3 +1; toti++;
        if(i == 1)      p->c = '+';
        else if(i == 2) p->c = '-';
        else            p->c = '*';
        if(toti < n)    j = rand()%2;
        else            j = 0;
        if(!j)          c = 'F';
        else            c = 'I';
        p->le = CriaExpr(c);
        p->ld = CriaExpr(c);
    }
    return p; 
}

int main(){
    srand (time(NULL));
    while(true){
    	cout<<endl<<" n= ";  cin>>n;
        toti = 0;
        T = CriaExpr('I');
        ImprimeParentisada(T);
    }
    return 0;
}
