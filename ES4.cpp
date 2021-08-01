#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int V[10000001], n, s, ne, nc, N[100];
long long int C1[100], C2[100];  float r;

void Imprime(int V[], int n)
{   int m;   
	if (n <= 100) m=n;  else m=100;
	cout <<"n = "<<n<<endl<<"Primeiros "<<m<<" elementos do vetor:"<<endl;
    for(int j=1; j<=m; j++) cout <<V[j]<<" ";
    cout<<endl<<endl;
}

void Algoritmo1(int V[], int n, int s, int nc)
{    int i, j, d;
/*	d <- 0;
	para i<-1 até n-1 inclusive:
        para j<- i+1 até n inclusive:
        	C1[nc]++;
         	se (V[i]+V[j] == s):
			 	d <- d+1;
*/
	d = 0;
	for (i=1; i<=n-1 ;i++){
		for (j=i+1; j<=n; j++){
			C1[nc]++;
			if (V[i]+V[j] == s){
				d++;
			}
		}
	}
    cout<<"O Algoritmo1 encontrou "<<d<<" duplas"<<endl<<endl;
    
}
void Algoritmo2(int V[], int n, int s, int nc)
{    int i, j, d=0;
/*  d <- 0;   i <-1;   j <- n;
    enquanto (i < j):
        C2[nc]++;
        se (V[i]+V[j] == s): 
			d <- d+1;   i <- i+1;   j <- j-1;
		senão se (V[i]+V[j] > s):
			j <- j-1
		senão 
			i <- i+1
*/
	
	d=0;
	i=1;
	j=n;
	while (i<j){
		C2 [nc]++;
		if (V[i]+V[j] == s){
			d++;
			i++;
			j--;
		}
		if (V[i]+V[j] > s){
			j--;
		}
		else{
			i++;
		}
	}
    cout<<"O Algoritmo2 encontrou "<<d<<" duplas"<<endl;
}
int main(){  
	srand(time(NULL)); 
	for (int i=1; i<100; i++){
        N[i]=C1[i]=C2[i]=0;
	}
	n = 100;  nc = 0;
	while (n <= 1000000){
		N[++nc] = n;   s=n;  
   		V[1] = 2; for(int i=2; i<=n; i++) V[i]=V[i-1]+ rand()%7+1;
   		Imprime(V, n);
    	Algoritmo2(V, n, s, nc);
    	Algoritmo1(V, n, s, nc);
        r = rand()%100+1;  r = 8.0 + r/100;  r = r*n;
		n = r;    
	}
	cout<<"Dados para analise do Algoritmo 1:"<<endl;
	for (int i=1; i<=nc; i++)
		cout<<N[i]<<" ";
    cout<<endl;
	for (int i=1; i<=nc; i++)
		cout<<C1[i]<<" ";
	cout<<endl<<endl;
	cout<<"Dados para analise do Algoritmo 2: "<<endl;
	for (int i=1; i<=nc; i++)
		cout<<N[i]<<" ";
    cout<<endl;
	for (int i=1; i<=nc; i++)
		cout<<C2[i]<<" ";
	cout<<endl;
    cin.get();
    return 0;
}
