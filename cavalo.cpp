/*
#Dados: pontos (p, q), (x,y)

T[*,*] ← -1  
EsvaziaFila(Q,f,r)   
Enfila(Q, f, r , p, q, 0)
enquanto f ≠ 0
    (a, b, d) ← primeiro elemento da fila
Enfila(Q, f, r, a-2, b-1, d+1)    
Enfila(Q, f, r, a-2, b+1, d+1)
Enfila(Q, f, r, a-1, b-2, d+1)    
Enfila(Q, f, r, a-1, b+2, d+1)
Enfila(Q, f, r, a+1, b-2, d+1)    
Enfila(Q, f, r, a+1, b+2, d+1)
     Enfila(Q, f, r, a+2, b-1, d+1)    
Enfila(Q, f, r, a+2, b+1, d+1)
    (a, b, d) ←  Desenfila(Q, f, r)

escrever (T[x,y])
*/

#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

int T, n, a, b, d, f, r, p, q, x, y;
char L[101][101];
struct {int x,y,d,p;} Q[10000], CM[200];

void ImprimeL(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
			cout<<L[i][j];  cout<<endl;
			} 
    }

}

memset(matriz, -1, sizeof(matriz));
EsvaziaFila(Q,f,r);

void Enfila (int x1, int y1, int d1, int p1){
    if ((x1 >= 1) && (x1 <= n) && (y1 >= 1) && (y1 <= n) && (L[x1][y1] == 'I' || L[x1][y1] == '.'  || L[x1][y1]=='S')){
        if (L[x1][y1]=='S') 
			q=r+1;
		L[x1][y1] = '-';
        Q[++r].x = x1;   Q[r].y = y1;   Q[r].d = d1;  Q[r].p = p1;
        if (f == 0)
			f = 1;
    }
}
