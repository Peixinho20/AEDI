inteiro contaGemeosPrimos(inteiro[] V):
    inteiro i, gemeos, n
    gemeos <- 0
    i <- 0 
    n <- |V| 
    enquanto (i < n):
        se (V[i] - V[i-1] = 2):
            se (V[i-1] - V[i-2] = 2):
                gemeos <- gemeos+1
            senao:
                gemeos <- gemeos+2 
        i <- i+1
    retornar gemeos
           


inteiro V[*] <- [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 53, 59, 61, 67, 71, 73]
inteiro total <- contaGemeosPrimos(V)
escrever(total)
