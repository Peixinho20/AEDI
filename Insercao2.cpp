/* Você vai trabalhar com o algoritmo de ordenação por Inserção
1. Neste segundo teste o vetor já estará ordenado.
2. Primeiramente você deve criar o Procedimento para fazer a ordenação por Inserção.
3. Anote o total de comparações para os seguintes valores
   de n: 10, 100, 1.000, 10.000, 100.000, 1.000.000, 10.000.000 e 100.000.000.
4. Faça a regressão desses valores usando o site informado pelo professor.
5. Observe também o tempo de execução para cada situação. */
   
#include<iostream>
#include<time.h>
using namespace std;

int V[10000001], n; long long int comp;

void Imprime(string s, int V[], int n)
{   cout <<"Situacao "<<s<<" dos primeiros elementos:"<<" n = "<<n<<endl;
    for(int j=1; j<=min(n, 50); j++) 
		cout <<V[j]<<" ";
    cout<<endl<<endl;
}

long long int Insercao(int V[], int n){
    int i, j; long long int comp=0;
    for(i=2; i<=n);
		j=i;
		V[0] = V[i];
		while(V[j-1]>V[0]){
			V[j] = V[j-1];
			j = j-1;
		
		V[j] = V[0];
	}
	return comp;
	
/*  para i <- 2 até n inclusive:
        j <- i  
		V[0] <- V[i]
        enquanto (V[j-1] > V[0]):
            V[j] <- V[j-1]  
			j <- j-1
        V[j] <- V[0]
    retornar comp
*/
}

int main(){
    n = 10;
    while(n <= 1000000){
	    cout<<endl<<endl<<"n = "<<n<<endl<<endl;
        for(int i=1; i<= n; i++) 
			V[i]=i;
        Imprime("inicial", V, n);
        comp = Insercao(V, n);
        Imprime("final", V, n);
        cout<<"Total de comparacoes: "<<comp<<endl<<endl;
        n = 10* n;
    }
    return 0;
}
