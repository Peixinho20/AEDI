/*Este programa mostra a ordenação pelo Mergesort, exibindo os 40 primeiros
   elementos em duas situações: vetor já ordenado e vetor desordenado.
1. Implemente as funções Mergesort e Merge.
2. Observe que, ao final do programa há um resumo mostrando, para cada n
   o total de comparações efetuadas.
3. Rode o  programa para n= 100, 1000, 10000, 100000, 1000000, 10000000 e 
   100000000 e obtenha a aproximação da complexidade do número de comparações
   pelo site planetcalc (https://pt.planetcalc.com/5992/), anotando abaixo:
   
3. Comente o resultado do item 3.

Comparacoes efetuadas: 2665782272
Resumo:
100 1000 10000 100000 1000000 10000000 100000000 
672 9976 133616 1668928 19951424 233222784 2665782272 

Regressão linear
y=26.6955x − 6484560.9792

Coeficiente de correlação linear            
0.9999 

Coeficiente de determinação
0.9998

Erro relativo médio, %
147799.4586 %

*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int V[100000001], V1[50000001], V2[50000001],  i, n, v;
long long int comp, C[100];

void Merge(int V[], int e, int d){
int i, j, k, m;

	m=(e+d)/2;
	for(i=1;i<=m-e+1;i++){
		V1[i] = V[e+i-1];
		V2[i] = V[m+i];
	}
	V1[m-e+2] = max(V[m],V[d])+1;
	V2[d-m+1] = V1[m-e+2];
	i,j = 1,1;
	for(k=e;k<=d;k++){
		if(V1[i]<V2[j]){
			V[k] = V1[i];
			i++;
		}
		else{
			V[k] = V2[j];
			j++;
		}
	}
	comp = comp + d - e + 1;
}

void Mergesort(int V[], int e, int d){
    int m;

	if(d>e){
		m = ((e+d)/2);
        Mergesort(V, e, m);
        Mergesort(V, m+1, d);
        Merge(V, e, d);
	}
}
int main(){
	srand(time(NULL));
	n = 100;  v= 1;
    while(v <= 7){
        cout<<endl<<"n = "<<n;
        comp=0;
        for(i=1; i<=n; i++) V[i]= rand()%n;
        cout<<endl<<"Situacao inicial - primeiros 40 elementos:"<<endl;
        for(i=1; i<=40; i++) cout<<V[i]<<" ";  cout<<endl;
        Mergesort(V, 1, n);
        cout<<endl<<"Situacao final - primeiros 40 elementos:"<<endl;
        for(i=1; i<=40; i++) cout<<V[i]<<" ";  cout<<endl;
        cout<<endl<<"Comparacoes efetuadas: "<<comp<<endl;
        C[v] = comp;
        n = n*10;  v++;
    }
    cout<<"Resumo:"<<endl;
    for (i=100; i<=100000000; i = i*10) cout<<i<<" ";  cout<<endl;
    for (v=1; v<=7; v++) cout<<C[v]<<" ";  cout<<endl;
    return 0;
}

