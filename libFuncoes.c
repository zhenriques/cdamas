extern int vazia, nClara, dClara, nEscura, dEscura, invalida, oponenteN, oponenteD;
extern int tabuleiro[8][8], jogador;
extern int captUserPeca_1, captUserPeca_1;

/*
  Função que recebe um inteiro, definindo os oponentes(peça normal e peça coroada)
  de acordo com o jogador; sem retorno.
*/
int defineOponentes(int jgd){
    if(jgd == 1){
        oponenteN = nEscura;
        oponenteD = dEscura;
    }
    if(jgd == 2){
        oponenteN = nClara;
        oponenteD = dClara;
    }
    return(0);
}

/*
  Função generica que recebe dois parametros e retorna um inteiro; tem como objetivo retornar (1) caso a peça fez dama
  e (0) caso nao fez.
*/
int fezDama(int l, int jgd){
    
    if(jgd == 1){
        if(l == 0)
            return(1);
        else
            return(0);
    } 
    else
        if(l == 7)
            return(1);
        else
            return(0);

}

/*
  Função generica que recebe 4 parametros(inteiro)e retorna um inteiro(sempre 0); tem como objetivo coroar a peça
*/
int coroar(int ld, int cd,  int jgd){
    if(jgd == 1){
        tabuleiro[ld][cd] = dClara;
    }
    else
        tabuleiro[ld][cd] = dEscura;

    return(0);
}


/*
  Função que recebe em seus parametros cinco inteiros e deveolve um, para verificação de falso
  ou verdadeiro, tem como objetivo ver se a jogada foi pra capiturar o oponente
*/
int verRaptar(int l, int c, int ld, int cd, int jgd){
        defineOponentes(jgd);
        if((ld == l-2 && cd == c+2)&& (tabuleiro[l-1][c+1] == oponenteN || tabuleiro[l-1][c+1] == oponenteD)&& (tabuleiro[l-2][c+2] == vazia))
            return (1);
        else if((ld == l-2 && cd == c-2) && (tabuleiro[l-1][c-1] == oponenteN || tabuleiro[l-1][c-1] == oponenteD)&& (tabuleiro[l-2][c-2] == vazia))
            return (1);
        else if((ld == l+2 && cd == c+2) && (tabuleiro[l+1][c+1] == oponenteN || tabuleiro[l+1][c+1] == oponenteD)&& (tabuleiro[l+2][c+2] == vazia))
            return (1);
        else if((ld == l+2 && cd == c-2) && (tabuleiro[l+1][c-1] == oponenteN || tabuleiro[l+1][c-1] == oponenteD)&& (tabuleiro[l+2][c-2] == vazia))
            return (1);
 
        return(0);
}

/*
  funcao generia que recebe 5 inteiros e retorna 1 inteiro; que capitura a peça adversaria
*/
int raptar(int l , int c, int ld, int cd, int jgd){

    defineOponentes(jgd);
    
    if((tabuleiro[l-1][c+1] == oponenteN || tabuleiro[l-1][c+1] == oponenteD) && tabuleiro[l-2][c+2] == tabuleiro[ld][cd])
        tabuleiro[l-1][c+1] = vazia;
    else if((tabuleiro[l-1][c-1] == oponenteN || tabuleiro[l-1][c-1] == oponenteD) && tabuleiro[l-2][c-2] == tabuleiro[ld][cd])
        tabuleiro[l-1][c-1] = vazia;
    else if((tabuleiro[l+1][c+1] == oponenteN || tabuleiro[l+1][c+1] == oponenteD) && tabuleiro[l+2][c+2] == tabuleiro[ld][cd])
        tabuleiro[l+1][c+1] = vazia;
    else if((tabuleiro[l+1][c-1] == oponenteN || tabuleiro[l+1][c-1] == oponenteD) && tabuleiro[l+2][c-2] == tabuleiro[ld][cd])
        tabuleiro[l+1][c-1] = vazia;  
    
    tabuleiro[ld][cd] = tabuleiro[l][c];
    tabuleiro[l][c] = vazia;
    return(0);
}

/*
  função generica que recebe 3 inteiros e retorna 1 inteiro
  Retornos:
  .1 para mais posibilidade de capituras;
  .0 quando nao tem mais possibilidades.
*/
int capturarMais(int l, int c, int jgd){
    defineOponentes(jgd);
    if((tabuleiro[l-1][c+1] == oponenteN || tabuleiro[l-1][c+1] == oponenteD) && tabuleiro[l-2][c+2] == vazia){
        if((l-2>=0 && l-2<8) && (c+2>=0 && c+2<8))
            return(1);
    }
    else if((tabuleiro[l-1][c-1] == oponenteN || tabuleiro[l-1][c-1] == oponenteD) && tabuleiro[l-2][c-2] == vazia){
        if((l-2>=0 && l-2<8) && (c-2>=0 && c-2<8))
            return(1);
    }
    else if((tabuleiro[l+1][c+1] == oponenteN || tabuleiro[l+1][c+1] == oponenteD) && tabuleiro[l+2][c+2] == vazia){
        if((l+2>=0 && l+2<8) && (c+2>=0 && c+2<8))
            return(1);
    }
    else if((tabuleiro[l+1][c-1] == oponenteN || tabuleiro[l+1][c-1] == oponenteD) && tabuleiro[l+2][c-2] == vazia){
        if((l+2>=0 && l+2<8) && (c-2>=0 && c-2<8))
            return(1);
    }
   
    return(0);   
}
/*
  função que recebe um inteio, nao tem retorno, faz o incremento das peças capituradas dependendo do jogador
*/
int incrementoCap(int jgd){
    if(jgd == 1)
        cap_User1++;
    else
        cap_User2++;
}
