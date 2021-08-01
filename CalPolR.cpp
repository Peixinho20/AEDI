/*Neste programa você vai trabalhar com o cálculo de uma uma Expressão escrita
na notação Polonesa Reversa.
a) O programa gera uma expressão em notação polonesa reversa aleatória.
   Observe que o string gerado tem um branco na primeira posição, os operandos
   contêm apenas 1 dígito, os operadores são apenas +, - e * e não há
   brancos no meio do string.
b) Para facilitar o algoritmo seguinte, já foi criada a função Resultado.
c) Você deve escrever a função CalcPolRev, cujo algoritmo está mostrado.
d) Uma dica para transformar o caracter s[i] no dígito inteiro d é fazer
   d = s[i] - '0';
e) As funções esvazia pilha, Push() e POP() devem ser implementadas de forma muito
    simplificada. Isto é, não precisa criar funções para isso.
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const string  tchar = " +-*0123456789"; 
int j, n;  string E;

string GeraExpPolRev(int n){
    int i, nopn, nopr, tg;  string s = " ";
    nopn = 0;  nopr = 0;
    for (i=1; i<=n; i++){
        if (nopn == (n+1)/2)       tg = 1;
        else if (nopn <= (nopr+1)) tg = 2;
        else                       tg = rand()%2+1;
        if (tg == 1) {s = s + tchar[rand()%3+1];  nopr++;}
        else         {s = s + tchar[rand()%10+4]; nopn++;}   
    }
    cout<<"Expressao gerada ocupando as posicoes 1 a "<<s.length()+2<<" : "<<s<<endl;
	return s;  
}

int Resultado(int op1,int op2,char opr){
	if(opr == '+') return op1+op2;
	else if(opr == '-') return op1-op2;
	else if(opr == '*') return op1*op2;	
}

int CalcPolRev(string E){
int i,topo, op1, op2, S[101];
topo = 0;
for (i=1; i<=E.length()+2;i++){
	if (E[i]>='0' && E[i]<='9'){
		S[++topo]=E[i]-'0';
	}
	else{
		op2 = S[topo--];
		op1 = S[topo--];
		S[++topo] = Resultado(op1,op2,E[i]);
	}
}
return S[1];
}
		
/*	Esvazia pilha #topo = 0
	para i <-1..E.length()-1 incl.:
		se E[i] é operando: #se esse caracter está entre 0 e 9 
            PUSH(S, topo, valor(E[i]))  #d = E[i]-'0' conversao de string para número
		senão: 
            op2 <- POP(S, topo)
			op1 <- POP(S, topo)
			PUSH (S, topo, Resultado(op1,op2,E[i]))
    retornar S[1] 
*/



int main(){
    srand(time(NULL)); 
    while(true){
		n = 2*(rand()%10)+1;
        E = GeraExpPolRev(n);
		cout <<"Resultado: " << CalcPolRev(E) << endl;
		cin.get();
	}
	return 0;	
}




