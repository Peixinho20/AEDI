/* Você vai trabalhar com a criação da ADPB para dado n.
   Após a geração da árvore ela será visualizada na representação
   tabular vertical. O programa só imprime corretamente até n = 35.
   A partir desse valor, imprime uma parte da árvore, apenas.
1.  Converta o procedimento CriaADPB.
2.  Acrescente a visualização da árvore na representação
   tabular horizontal.
3. */
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

typedef struct no* Arv;  struct no{	int c;  Arv ld,le;};
Arv T;  int i, j, n, niv;  
int V[10000001], RT[35][35];

void CriaADPB(int e, int d, Arv &p){
    int i;
/*  se e > d:
		p <- nulo
    senão:
        i <- (e+d)/2
        p <- no()
        p.c <-i
        CriaADPB(e,i-1,p.le)
        CriaADPB(i+1,d,p.ld)
*/

}

void PercIno(Arv p, int niv){ 
	int i;
    if (p != NULL){
        PercIno(p->ld, niv+1); 
        cout <<p->c<<endl;
        PercIno(p->le, niv+1);
    }
}
      
void DestroiArv(Arv p){	
    if (p != NULL){
        DestroiArv(p->le);  
		DestroiArv(p->ld);  
		free(p);
	}
}
void ImpRTHoriz(Arv p, int niv, int &maxniv, int &cont){;
    if (p != NULL){

    }
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
    while(true){
        cout <<"n = ";   cin >> n;
        CriaADPB(1, n, T);
        ImprimeArv(T);
        DestroiArv(T);
	}
	return 0;
}
         


