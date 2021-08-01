/* Ordenação por Contagem
Neste programa você vai implementar a Ordenação por Contagem, para ordenar
   umconjunto de dados onde cada elemento consiste de duas informações:
   a) o número de um candidato
   b) sua nota na prova de um concurso.
   A ordenação deve ser feita, primeiramente pela nota no concurso e, se
   dois candidatos têm a mesma nota, pelo número do candidato.
   Observe que cada dado é um registro do tipo Candidato com as informações:
       c = número do candidato
       t = nota obtida
a) Programe o procedimento Contagem
b) Responda às perguntas da folha de Exercício.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct Candidato {int c; int t;};
Candidato V1[100000001], V2[100000001];
int n, i; double r;

void Imprime(Candidato V[], int n)
{   int m;   
	if (n <= 500) m=n;  else m=500;
	cout <<"n = "<<n<<endl<<"Primeiros "<<m<<" elementos do vetor:"<<endl;
    for(int j=1; j<=m; j++) cout <<V[j].c<<" ("<<V[j].t<<")  ";
    cout<<endl<<endl;
}

void Contagem(Candidato V1[], Candidato V2[], int p){
    int i, j, VA[1001];

/*
	para j <-   1 até p incl.:   
		VA[j] <-   0
	
	para i <-  1 até n incl.:   
		VA[V1[i].t] <-   VA[V1[i].t]+1
	
	para j <-  2 até p incl.:  
		VA[j] <- VA[j] + VA[j-1] 
	
	para i <-  n..1 incl. passo -1:
		V2[VA[V1[i].t]]  <-   V1[i] 
		VA[V1[i].t] <- VA[V1[i].t] -1
		
	para i <-  1 até n incl.:
		V1[i]  <-  V2[i]		
		
*/

}

int main(){
    srand(time(NULL)); 
	n = 100;
	while (n <= 100000000){
	    for (i=1; i<=n; i++){
	        V1[i].c = i;
	        V1[i].t = rand()%1000+1;
	    }
	    Imprime(V1, n);
	    Contagem(V1, V2, 1000);
	    Imprime(V1, n);		 
        r = rand()%100+1;  r = 8.0 + r/100;  r = r*n;
		n = r;    
	}
    return 0;
}

