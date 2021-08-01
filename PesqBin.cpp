/*Neste programa você vai trabalhar com a Pesquisa Binária em um vetor ordenado.
a) Observe a geração dos dados e o algoritmo de Pesquisa Binária.
b) Implemente a Pesquisa por faixa no vetor, usando a Pesquisa Binária.
   Note que queremos apenas o número de elementos encontrados.
   Veja a observação que está descrita no Procedimento BF().
   Observe que o retorno já foi programado.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int i, n, a, b, V[10000001];

int PB(int V[], int k)
{	int c, f, i;
  	c = 1;  f = n;
   	while (c <= f){
        i = (c+f)/ 2;
        if (V[i]==k)
            break;
        else if (k < V[i])
			f = i-1;
        else 
			c = i+1;
    }
    
    return i;
}

int BF(int V[], int a, int b){
    int i, ia, ib;
/*
   Programa no espaço a seguir a busca por faixa.
   A idéia é encontrar a posição do vetor mais próxima a a e também a mais
   próxima a b.  Mas ao obter o retorno de cada busca, você deve acertar o
   valor recebido para que o índice se refira ao elemento buscado.
*/
	




/* Esta parte do programa confere o número de elementos encontrados.
   O aluno não deve modificar nada a partir deste ponto.
*/
    cout<<"Conferencia dos elementos da faixa: ";
    for (i=1; i<=n; i++)
       if (V[i] >=a && V[i] <=b)
           cout<<V[i]<<"  ";
    cout<<endl;
    
    return ib-ia+1; 
}
void Imprime(int V[]){
    int m;
    m = min(10, n);
    cout<<endl<<"Primeiros "<<m<<" elementos: ";
    for(int i=1; i<=m; i++) 
		cout<<V[i]<<" "; 
	cout<<endl<<endl;
}
int main(){
    srand(time(NULL));
    n = 10;
    while(n <= 1000000){
        V[1] = 1; 
		for(i = 2; i<=n; i++) 
			V[i] = V[i-1]+ rand()%4+1;
        Imprime(V);  
        cout<<"Faixa a b = "; 
		cin >> a>>b;
        cout<<endl<<"Entre a = "<<a<<" e b = "<<b<<" existem "<<BF(V, a,b)<<" elementos."<<endl<<endl;
        n = n*10;
    }
}
