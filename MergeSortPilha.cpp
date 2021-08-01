/*Este programa mostra a ordenação pelo Mergesort, exibindo os 40 primeiros
   elementos de um vetor gerado aleatoriamente, usando pilha, ao invés de
   recursão.
1. Implemente a contagem do número de comparações.
2. Obtenha o tamanho máximo da pilha durante a ordenação
3. Rode o  programa para n= 1000, 10000, 100000, 1000000, 10000000 e 
   100000000. Responda a seguir se os resultados são semelhantes ou não
   à versão recursiva:
   
   
4. Descomente a instrução comentada em MergeSortPil e rode o programa para 
   um valor pequeno de n, para entender como funciona o algoritmo.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

struct no{char op; int e;  int d;};
no S[200];
int V[100000001], V1[50000001], V2[50000001], i, n, topo, maxpil;
long long int comp;

void Merge(int V[], int e, int d){
int i, j, k, m;
	m = (e+d)/2;
    for (i=1; i<= m-e+1; i++){
        V1[i]=V[e+i-1];  
		V2[i]=V[m+i];
    }
    V1[m-e+2] = V2[d-m+1] = max(V[m],V[d])+1;
    i=1;  j=1;
    for (k=e; k<=d; k++){
        if (V1[i]<V2[j]) {
			V[k]=V1[i++];
			comp++;        	
		}

        else 
			V[k]=V2[j++];
    }
}

void MergeSortPil(int V[], int c, int n){
    no noa, nob;   int m;
    topo = 0;   maxpil = 0;
	noa = {'O', c, n};
    S[++topo] = noa;  
    while(topo > 0){
        noa = S[topo--];   
		cout<<"Saindo da pilha: "<<noa.op<<" "<<noa.e<<" "<<noa.d<<endl;
		
        m = (noa.e +noa.d)/2;
		if (noa.op == 'M'){
			maxpil++;
			Merge(V, noa.e, noa.d);
		}

		else if (noa.d > noa.e){	
		    nob = {'M', noa.e, noa.d};   S[++topo] = nob;
		    nob = {'O', m+1, noa.d};     S[++topo] = nob;
		    nob = {'O', noa.e, m};       S[++topo] = nob;		
		}  
    }
}
int main(){
    while(true){
        cout<<"n = ";  cin>>n;   
		comp=0;  
		maxpil=0;
        for(i=1; i<=n; i++) 
			V[i]= rand()%n;
        cout<<endl<<"Situacao inicial - primeiros "<<min(n, 40)<<" elementos:"<<endl;
        for(i=1; i<=min(n,40); i++) 
			cout<<V[i]<<" ";  
		cout<<endl;
        MergeSortPil(V, 1, n);
        cout<<endl<<"Situacao final - primeiros "<<min(n, 40)<<" elementos:"<<endl;
        for(i=1; i<=min(n,40); i++) 
			cout<<V[i]<<" ";  
		cout<<endl;
        cout<<endl<<"Comparacoes efetuadas: "<<comp<<" Tamanho maximo da pilha: "<<maxpil<<endl;        
    }
    return 0;
}
