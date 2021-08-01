/* Este programa faz busca e insercao numa AVL
  1. Leia e entenda o programa
  2. Rode o programa
  3. Crie uma entrada tal que seja obtida a AVL mínima (com o menor número de 
  	 nós possível) de altura 5 (nota B no exercício) ou altura 6 (nota A).
  	 Escreva a seguir a ordem de entrada que produz essa árvore.
  	 
  	 
*/
#include <iostream>
#include<math.h>
#define LINHAS 21
#define COLUNAS 121
using namespace std;

typedef struct no* arv;
struct no{ int chave; int bal; arv le, ld;};
arv T;
char ArvTela[LINHAS][COLUNAS]; int i,x,maxniv;
bool h;

int Power(int i,int j){
	int k,pot;
	pot=i; for(k=1;k<j;k++)pot=pot*i;
	return pot;
}

void Limpa_AVL(void){
	int i,j;
	for(i=1;i<LINHAS;i++)
		for(j=1;j<COLUNAS;j++)ArvTela[i][j]=' ';
}

void PreparaVisualizacao(arv p, int pos, int nivat){
	int i,k,j,pose,posd;
	if(p!= NULL){
		pose=pos-Power(2,5-nivat);  posd=pos+Power(2,5-nivat);
		PreparaVisualizacao(p->ld, posd, nivat+1);
		PreparaVisualizacao(p->le, pose, nivat+1);
        k = abs(p->chave);  j = 0; ArvTela[nivat][pos] = k%10 + '0'; k = k/10;
        while (k > 0){
             j++;  ArvTela[nivat][pos-j] = k%10 + '0';  k=k/10;
        }		
		if (p->le != NULL) for (i=pose;i<pos-j;i++) ArvTela[nivat][i]='-';
		if (p->ld != NULL) for (i=pos+1;i<=posd;i++) ArvTela[nivat][i]='-';
		if (nivat > maxniv) maxniv=nivat;
	}
}

void Imprime_AVL(void){
	int i,j;
	Limpa_AVL();
	PreparaVisualizacao(T, 35, 1);
	for(i=1; i<=maxniv; i++){
		cout<<endl;
		for (j=1; j<=70; j++) cout <<ArvTela[i][j];
	}
	cout<<endl;
}

void Balanceamento_Esquerda(arv &p, bool &h){
	arv pf,pn;
	pf=p->le;
	if (pf->bal == -1){
		cout<<endl<<"Rotacao Simples a Esquerda:"<<endl;
		p->le =pf->ld;  pf->ld=p;  p->bal=0;  p=pf;
	}
    else{
		cout<<endl<<"Rotacao Dupla a Esquerda:"<<endl;
		pn=pf->ld;  pf->ld=pn->le;  pn->le=pf;  p->le=pn->ld;  pn->ld=p;
		if (pn->bal == -1) 
			p->bal=1;
		else 
			p->bal=0;
		if (pn->bal == 1) 
			pf->bal=-1;
		else 
			pf->bal=0;
		p=pn;
	}
	p->bal=0;  
	h=false;  
	Imprime_AVL();
}

void Balanceamento_Direita(arv &p, bool &h){
	arv pf,pn;
	pf=p->ld;
	if(pf->bal == 1){
		cout <<endl<<"Rotacao Simples a direita:"<<endl;
		p->ld=pf->le;  pf->le=p;  p->bal=0;  p=pf;
	}
    else{
		cout<<endl<<"Rotacao Dupla a Direita:"<<endl;
		pn=pf->le;  pf->le=pn->ld;  pn->ld=pf;  p->ld=pn->le;  pn->le=p;
		if (pn->bal == 1) 
			p->bal=-1;
		else 
			p->bal=0;
		if (pn->bal == -1) 
			pf->bal=1;
		else 
			pf->bal=0;
		p=pn;
	}
	p->bal=0;  
	h=false;  
	Imprime_AVL();
}

void Insere_AVL (int x, arv &p, bool &h){
	if(p==NULL){
		p=new(no);  p->chave=x;  p->bal=0;  p->le=NULL;  p->ld=NULL;
		if (T == NULL)
			T=p;
		h=true;  
		Imprime_AVL();
	}
    else if(x<p->chave){
		Insere_AVL(x, p->le, h);
		if(h){
			switch (p->bal){
				case 1:  
					p->bal= 0;  
					h= false;  
					break;
				case 0:  
					p->bal= -1; 
					break;
				case -1: 
					Balanceamento_Esquerda(p, h); 
					break;
				default: 
					break;
			}
		}
	}
    else{
		Insere_AVL(x, p->ld, h);
		if(h){
			switch(p->bal){
				case 1:  
					Balanceamento_Direita(p, h);  
					break;
				case 0:  
					p->bal= 1;  
					break;
				case -1: 
					p->bal= 0;  
					h= false;  
					break;
				default: 
					break;
			}
		}
	}
}

int Busca_AVL (int x, arv p){
	if(p==NULL) 
		return 0;
	else if(x == p->chave) 
		return 1;
	else if(x < p->chave) return 
		Busca_AVL(x, p->le);
    else return 
		Busca_AVL (x, p->ld);
}

int main(){
	T=NULL;   i = 21;
    while(i--){
		cout <<"Numero: "; cin >> x;
        if (Busca_AVL(x, T)) 
			cout<<x<<" - chave duplicada"<<endl;
		else{
			cout<<x <<" - chave inserida"<<endl;
			Insere_AVL(x, T, h);
		}
	}
	cin.get();
	return 0;
}

