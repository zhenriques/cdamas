extern int vazia, nClara, dClara, nEscura, dEscura, invalida, oponenteN, oponenteD, tabuleiro[8][8], jogador;

/*
  Função que tem como objetivo retornar um inteiro, se o jogador fizer  referencia a uma casa em 
  branco a funcao retornará 1(como verdadeiro), caso contrario, retornará 0
*/
int semPeca(int l, int c){
    if((tabuleiro[l][c] == vazia) || (tabuleiro[l][c] == invalida))
        return (1);
    else
        return (0);
}

/*
  Função que verifica a se a peça que está sendo referenciada é a do oponente, retorna 1 para 
  verdadeiro e 0(zero) para falso.
*/
int verPecaOponente(int l, int c, int jgd){
    if((jgd == 1 && (tabuleiro[l][c] == dEscura || tabuleiro[l][c] == nEscura)) || (jgd == 2 && (tabuleiro[l][c] == dClara || tabuleiro[l][c] == nClara)))
        return (1);
    else
        return (0);
}

/*
  Função generica que recebe 3 parametros inteiros e tem um retorno também inteiro.
  verificações:
  .se a casa é invalida(casa de cor branca), nunca usada;
  .se a casa está ocupada pelo seu oponente ou dama ou peão;
  .Se está ocupada pela peça do seu time.
*/
int jgPCsInv(int ld, int cd, int jgd){//nome da funcao: "jogar para casa invalida"
     defineOponentes(jgd);
     if(tabuleiro[ld][cd] == invalida)
        return(1);
    else if(tabuleiro[ld][cd] == oponenteN || tabuleiro[ld][cd] == oponenteD)
        return(2);
    else if((tabuleiro[ld][cd] != oponenteN || tabuleiro[ld][cd] != oponenteD) && tabuleiro[ld][cd]!= vazia)
        return(3);
    else
        return(0);
}

/*
  Função que faz uma verificação se a casa destino em coparação a localizacao atual avançou apenas
  uma casa na diagonal, recebe 5 inteiros e retorna 1 inteiro.
  se for uma peça normal(Peão).
*/
int verAvanUmaN(int l, int ld, int c, int cd, int jgd){
    if(jgd == 1){//verifica jogador 1
        if(ld == l-1 &&(cd == c+1 || cd == c-1))
            return(1);
        else
            return (0);
    }
    else{//jogador 2
        if(jgd == 2){
            if(ld == l+1 &&(cd == c+1 || cd == c-1))
                return (1);
            else
                return (0);
        }
    
    }
}

/*
  Função que faz uma verificação se a casa destino em coparação a localizacao atual avançou apenas
  uma casa na diagonal, recebe 4 inteiros e retorna 1 inteiro.
  Se for uma peça coroada(Dama).
*/
int verAvanUmaD(int l, int ld, int c, int cd){
    if(ld == l-1 &&(cd == c+1 || cd == c-1))
        return(1);
    else if(ld == l+1 &&(cd == c+1 || cd == c-1))
        return(1);

    return(0);
    
}

/*
  Função que recebe e retorna um inteiro.
  Verifica se exista uma possibilidade de raptar a peça do oponente.
*/
int evitaSopro(int jgd){
    int l, c;
    defineOponentes(jgd);
    for(l=0; l<8; l++){
        for(c=0; c<8; c++){
            if(tabuleiro[l][c] == jgd || tabuleiro[l][c] == jgd*-1){//jgd ou é 1 ou 2, logo (jgd*-1) == -1 ou -2
                if((tabuleiro[l-1][c+1] == oponenteN || tabuleiro[l-1][c+1] == oponenteD)  &&  tabuleiro[l-2][c+2] == vazia){
                    if((l-2>=0 && l-2<8) && (c+2>=0 && c+2<8))//se está dentro do tabuleiro
                        return (1);
                }
                else if((tabuleiro[l-1][c-1] == oponenteN || tabuleiro[l-1][c-1] == oponenteD) &&  tabuleiro[l-2][c-2] == vazia){
                    if((l-2>=0 && l-2<8) && (c-2>=0 && c-2<8))
                        return (1);

                }
                else if((tabuleiro[l+1][c+1] == oponenteN || tabuleiro[l+1][c+1] == oponenteD) && tabuleiro[l+2][c+2] == vazia){
                    if((l+2>=0 && l+2<8) && (c+2>=0 && c+2<8))
                        return (1);

                }
                else if((tabuleiro[l+1][c-1] == oponenteN || tabuleiro[l+1][c-1] == oponenteD) && tabuleiro[l+2][c-2]== vazia){
                    if((l+2>=0 && l+2<8) && (c-2>=0 && c-2<8))
                        return (1);
                }
            }
        }
    }
    return (0);
}
