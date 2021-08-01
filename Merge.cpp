 /* Neste programa você vai trabalhar com a operação de Merge em dois vetores já
   ordenados, representando dois conjuntos. Você deve obter V3 = V1-V2, ou seja,
   o conjunto diferença entre V1 e V2. A geração e a impressão dos dados já estão
   programados. O valor máximo da entrada é 1000.
   b) Implemente a operação de diferença.
   c) Acerte a "pegadinha" na impressão de V3.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int V1[1001],V2[1001],V3[1001], i, n, m, k;

int Difer(int V1[], int n, int V2[], int m, int V3[]){
	int i, j, k;
	
	i=1; j=1; k=0;
	while(i <= n and j <= m){
	    if (V1[i] < V2[j]){
	        k++; V3[k] = V1[i]; i++;
	    } 
	    else if (V1[i] == V2[j]){
	        i++;
	        j++;
	    }   
	    else{
	        j++;
	    }
	}
	while (i<=n){ 
	    k++;  V3[k] = V1[i];  i++;
	 }   
	
/*
    i <- 1;  j <- 1;  k <- 0;
    enquanto (i <= n E j <= m)):
        se (V1[i] < V2[j]):
            k<- k+1;  V3[k] <- V1[i];  i <- i+1;
        senão se (V1[i] == V2[j]):
            i <- i+1;  j <- j+1;
        senão:
			j <- j+1;
    enquanto (i <= n):
        k<- k+1;  V3[k] <- V1[i];  i <- i+1;
*/ 
     
}

void Imprime(string mens, int V[], int t){
   int i;
    cout<<mens;
    for(i = 1; i<=t; i++)
		cout<<V[i]<<" "; 
	cout<<endl<<endl;
}

int main(){
    srand(time(NULL));
    n = 8;  m = 16;
    while (m < 100){
        cout<<endl<<endl<<"n, m = "<<n<<" "<<m<<endl<<endl;
    	V1[1] = rand()%10;  
		for(i = 1; i <= n; i++) 
			V1[i] = V1[i-1]+rand()%4+1;
    	V2[1] = rand()%10;  
		for(i = 1; i <= m; i++) V2[i] = V2[i-1]+rand()%4+1;
            Imprime("V1: ", V1, n);  
    		Imprime("V2: ", V2, m);
            k = Difer(V1, n, V2, m,  V3);
            Imprime("V3: ", V3, n+m);
            n = n*2; m = m*2;
    }
    return 0;
}
