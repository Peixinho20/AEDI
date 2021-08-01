/* Neste programa você trabalhará com o programa de ordenação por Seleção
1. Observe a criação do Vetor V. A primeira metade contem os números pares de 1 a n
   e a segunda metade, os ímpares, quando p n é par.
2. Observe que o programa imprime o total de comparações feitas.
3. Anote o total de comparações para os seguintes valores
   de n: 10, 100, 1.000, 10.000, 100.000, 1.000.000, 10.000.000 e 100.000.000.
4. Faça a regressão desses valores usando o site informado pelo professor.
5. Observe também o tempo de execução para cada situação. */
   
#include<iostream>
using namespace std;

int V[10000001], n; long long int comp;

void Imprime(string s, int V[], int n)
{   cout <<"Situacao "<<s<<" dos primeiros elementos:"<<" n = "<<n<<endl;
    for(int j=1; j<=min(n, 50); j++) 
		cout <<V[j]<<" ";
    cout<<endl<<endl;
}

long long int Selecao(int V[], int n){
    int i, m, j, t; long long int comp = 0;   
/*  para i <- 1 até n-1 inclusive:
        m <- i
        para j <- i+1 até n inclusive
            se (V[j] < V[m]):
			    m <- j
			comp++
        t <- V[i];  V[i] <- V[m];  V[m] <- t;
    retornar comp
*/
    for (i=1; i<= n-1; i++){
        m = i;
        for (j=i+1; j<=n; j++){
            if (V[j] < V[m]){
                m = j;   
            }
            comp = comp+1;
        }
        t = V[i];  V[i] = V[m];   V[m] = t;
    }
    return comp;
}

int main(){
    n=10;
    while(n <= 1000000){
	    cout<<endl<<"n = "<<n<<endl<<endl;
        for(int i=1; i<= n/2; i++) 
			V[i]=2*i;
        for(int i=1; i<= n/2; i++) 
			V[n/2+i]=2*i-1;
        Imprime("inicial", V, n);
        comp = Selecao(V, n);
        Imprime("final", V, n);
        cout<<"Total de comparacoes: "<<comp<<endl<<endl;
        n = n*10;
    }
    return 0;
}
