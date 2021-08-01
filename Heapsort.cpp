/*Você vai trabalhar com o método de ordenação Heapsort.
  1. Implemente o Heapsort.
  2. Rode o  programa para n= 10, 100, 1000, 10000, 100000, 1000000, 10000000
     e obtenha a aproximação da complexidade do número de comparações
     pelo site planetcalc (https://pt.planetcalc.com/5992/), anotando abaixo:
     a) Resumo dado pelo programa:
		10 100 1000 10000 100000 1000000 10000000 
		10 173 1661 16847 168561 1684520 16846410 
     
     b) Melhor função do planetcalc
     
     
*/
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int i, n, comp, t, v, H[10000001], C[20];

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
void ImprimeVetor(int vez, int n){
    int i;
    if (vez == 1) 
		cout<<"Vetor inicial:"<<endl;
    else
    	cout<<"Vetor ordenado:"<<endl;
    cout<<endl<<"Primeiros: ";
    for(i=1; i<=min(n, 50); i++) cout<<H[i]<<" ";  cout<<endl;
    cout<<endl<<"Ultimos:   ";
    for(i=max(1, n-49); i<=n; i++) cout<<H[i]<<" ";  cout<<endl;
    cout<<endl;
}

int main(){
    srand(time(NULL));
    n = 1;
    for (v=1; v<=7; v++){
        n *= 10;
        for (i=1; i<=n; i++) H[i] = (rand()%n*rand()%n)%n;
        ImprimeVetor(1,n);
        comp = 0;
	
		for (i=n/2;i>=1;i--){
			DesceHeap(i,n,comp);
		}
		for (i=1;i>=n-1;i--){
			H[0]=H[1];
			H[1]=H[n-i+1];
			H[n-i+1]=H[0];	
			DesceHeap(1,n-i,comp);
		} 
        /* Heapsort:  */
        /*	para i <- n/2..1 incl.:
            	DesceHeap(i, n, comp)
         	para i <- 1..n-1 incl.:
            	Troca(1, n-i+1)
             	DesceHeap(1,n-i, comp)
        */

		C[v] = comp;
        ImprimeVetor(2,n);
        cout<<"n = "<<n<<" Total de comparacoes: "<< comp<<endl;
        cin.get();
    }
    cout<<"Resumo de comparacoes:"<<endl;
    for (i=10; i<=10000000; i = i*10) cout<<i<<" ";  cout<<endl;
    for (v=1; v<=7; v++) cout<<C[v]<<" ";  cout<<endl;
    return 0;
}
