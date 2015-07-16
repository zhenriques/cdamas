extern int vazia, nClara, nEscura, invalida;
extern int tabuleiro[8][8];

/*
  Função que preeche as casas invalidas, nao tem retorno nem recebe valor
*/
void casasInva(){
    int l, c;
    for(l=0; l<8; l++)
        for(c=0; c<8; c++)
            if((l%2 == 0 && c%2 == 0) || (l%2 !=0 && c%2 != 0))
                tabuleiro[l][c] = invalida;
}

/*
 Função nao retorna valor, nem recebe valor, objetivo da funcao é preecher as casas com 
 valores das pecas, será chamada só no inicio do jogo.
*/
void preecherCasas(){
    int l, c;
    
    //preeche as casas com pecas escuras
    for(l=0; l<3; l++)
        for(c=0; c<8; c++)
            if((l%2 == 0 && c%2 !=0) || (l%2 != 0 && c%2 == 0))
                tabuleiro[l][c] = nEscura;
    

    //preeche as casas com pecas claras
    for(l=5; l<8; l++)
        for(c=0; c<8; c++)
            if((l%2 !=0 && c%2 == 0) || (l%2 == 0 && c%2 !=0))
                tabuleiro[l][c] = nClara;
}
