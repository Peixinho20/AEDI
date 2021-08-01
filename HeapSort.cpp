/*Você vai trabalhar com a criação de um Heap usando SobeHeap e DesceHeap.
  1. Observe que a impressão do Heap está sendo feita com uma adaptação da
     recursão usada para mostrar a representação tabular horizontal de 
     árvores binárias.
  2. Implemente a criação do Heap usando SobeHeap, depois DesceHeap.
  3. Rode o  programa para n= 10, 100, 1000, 10000, 100000, 1000000, 10000000
     e obtenha a aproximação da complexidade do número de comparações
     pelo site planetcalc (https://pt.planetcalc.com/5992/), anotando abaixo:
     a) Resumo dado pelo programa:
		
		Resumo de comparacoes para Sobeheap:
			10 100 1000 10000 100000 1000000 10000000 
			28 579 8986 123630 1568945 18951444 223222808 
		
		Resumo de comparacoes para DesceHeap:
			10 100 1000 10000 100000 1000000 10000000 
			14 190 1982 19982 199978 1999974 19999970 
     
     b) Melhor função do planetcalc para SobeHeap
			Regressão potencial
				y=2.7731x^1.1420
			Coeficiente de correlação
				0.9691
			Coeficiente de determinação
				0.9391
			Erro relativo médio, %
				16.5648 %
		  
     c) Melhor função do planetcalc para DesceHeap
		
			Regressão linear
				y=2.0000x−16.2478
			Coeficiente de correlação linear
				1.0000
			Coeficiente de determinação
				1.0000
			Erro relativo médio, %
				10.9410 %
   
*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctime>
using namespace std;

int i, n, comp, v, H[10000001], RT[36][36], CS[20],CD[20];

void SobeHeap(int k, int &comp){
    int t;
    t = H[k];  H[0] = t;
    while (H[k/2] < t) {
        H[k] = H[k/2];  k = k/2;
        comp++;
    }
    comp++;
    H[k] = t;
}
void DesceHeap(int k, int m, int &comp){
    int t, j;
    t = H[k];
    while (k <= m/2) {
        j = 2*k;
        if (j < m) {
            if (H[j+1] > H[j]) j++;
            comp++;
        }
        if (t >= H[j]) break;
        H[k] = H[j];  k = j;
        comp++;
    }
    H[k] = t;
}

void ImprTHoriz(int p, int niv, int &maxniv, int &cont, int n){;
    if (p <= n){
        if (niv > maxniv)
        	maxniv = niv;
        ImprTHoriz(2*p, niv+1, maxniv, cont, n);
        if (cont <= 35)
			RT[niv][++cont] = H[p]; 
        ImprTHoriz(2*p+1, niv+1, maxniv, cont, n);
    }
}
void ImprimeHeap(int H[], int n){
    int cont, maxniv, k=0;
    for(int i=1; i<=35; i++) for (int j=1; j<=35; j++)
		RT[i][j] = -1;
    maxniv = 0;  cont=0;
	ImprTHoriz(1, 1, maxniv, cont, n);
	cout<<endl;
    for (int i=1; i<=maxniv; i++) {
    	for(int j=1; j<=min(35,cont); j++)
			if (RT[i][j] == -1)
			    cout<<" . ";
			else{
				cout<<fixed<<setw(3)<<RT[i][j];
			}
		cout<<endl;
    }
}


int main(){
    n = 1;
    for (v=1; v<=7; v++){
        n *= 10;
        for(i=1; i<=n; i++) H[i] = i;
        cout<<endl<<"n = "<<n<<" Heap inicial: "<<endl;
        ImprimeHeap(H, n);
        comp = 0;
        
		for (i=2; i<=n; i++){
			SobeHeap(i, comp);
			}	

        /* Criação do Heap, usando SobeHeap */
        /*	para i <- 2..n incl. :
            	SobeHeap(i, comp)
        */


        CS[v] = comp;
        cout<<endl<<"  Heap criado com SobeHeap. Comparacoes: "<< comp<<endl;
        ImprimeHeap(H, n);

        for(i=1; i<=n; i++) H[i] = i;
        comp = 0;

		for (i=n/2; i>=1; i--){
			DesceHeap(i,n,comp);
			}
        /* Criação do Heap, usando DesceHeap */
        /*	para i <- n/2 ..1 incl.:
            	DesceHeap(i,n, comp)
         */


		CD[v] = comp;         
        cout<<endl<<"  Heap criado com DesceHeap. Comparacoes: "<< comp<<endl;
        ImprimeHeap(H, n);
        cin.get();
    }
    cout<<"Resumo de comparacoes para Sobeheap:"<<endl;
    for (i=10; i<=10000000; i = i*10) cout<<i<<" ";  cout<<endl;
    for (v=1; v<=7; v++) cout<<CS[v]<<" ";  cout<<endl;
    cout<<"Resumo de comparacoes para DesceHeap:"<<endl;
    for (i=10; i<=10000000; i = i*10) cout<<i<<" ";  cout<<endl;
    for (v=1; v<=7; v++) cout<<CD[v]<<" ";  cout<<endl;
    return 0;
}
