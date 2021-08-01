/* Você vai trabalhar com a criação da AVL mínimas para dada altura h.
  Observe que a árvore está sendo impressa na representação tabular
  horizontal.
  a) Programe o procedimento CriaAVLM.
  b) Observe que a árvore obtida não é de busca. Acerte a sua criação
  (modificando o mínimo possível o procedimento CRIAAVLM) para acertar isso.
  c) Programe o procedimento Destroi() 
*/
  
#include <iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

typedef struct no* arv;  struct no{	int c;  arv ld,le;};
arv T;  int i, h, cont, RT[36][36];  

void CriaAVLM(int h, arv &p, int &cont){
    int i;
    if (h < 1){
		p = NULL;
	}	
    else{
        p = new(no);  
        p->c = ++cont;
        CriaAVLM(h-2,p->le, cont);
        CriaAVLM(h-1,p->ld, cont);
    }

}
void ImprTHoriz(arv p, int niv, int &maxniv, int &cont){;
    if (p != NULL){
        if (niv > maxniv)
        	maxniv = niv;
        ImprTHoriz(p->le, niv+1, maxniv, cont);
        if (cont <= 35)
			RT[niv][++cont] = p->c; 
        ImprTHoriz(p->ld, niv+1, maxniv, cont);
    }
}
void ImprimeArv(arv T){
    int cont, maxniv, k=0;
    for(int i=1; i<=35; i++) for (int j=1; j<=35; j++)
		RT[i][j] = -1;
    maxniv = 0;  cont=0;
	ImprTHoriz(T, 1, maxniv, cont);
	cout<<endl;
    for (int i=1; i<=maxniv; i++){
    	for(int j=1; j<=min(35,cont); j++)
			if (RT[i][j] == -1)
			    cout<<" . ";
			else{
				cout<<fixed<<setw(3)<<RT[i][j];
			}
		cout<<endl;
    }
}

void DestroiArv(arv p){
	if (p != NULL){
        DestroiArv(p->le);
        DestroiArv(p->ld);
        free(p);
	}
}
int main(){
    while(true){
        cout <<endl<<"h = "; cin >> h;
        cont = 0;
        CriaAVLM(h, T, cont);
		ImprimeArv(T);
        DestroiArv(T);
	}
	return 0;
}      

