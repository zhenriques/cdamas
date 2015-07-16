extern int vazia, nClara, dClara, nEscura, dEscura, invalida, oponenteN, oponenteD;
extern int tabuleiro[8][8], jogador, pecaAtual, cap_User1, cap_User2;

//vaiavais globais para esse arquivo
int l, ld, c, cd, x, y;

/*
  Função que nao tem retorno nem recebe parametros, o objetivo dessa rotina é 
  pegar as coordenadas da paça que quero mover.
*/
void mouseDe(){
     x = -1;
     do{
         if(mouse_b & 2){
             x = mouse_x;
             y = mouse_y;
         }
    }while( x == -1);
    //coluna
    if(x>=0 && x<50)
        c = 0;
    if(x>=50 && x<100)
        c = 1;
    if(x>=100 && x<150)
        c = 2;
    if(x>=150 && x<200)
        c = 3;
    if(x>=200 && x<250)
        c = 4;
    if(x>=250 && x<300)
        c = 5;
    if(x>=300 && x<350)
        c = 6;
    if(x>=350 && x<400)
        c = 7;

    //linha
    if(y>=0 && y<50)
        l = 0;
    if(y>=50 && y<100)
        l = 1;
    if(y>=100 && y<150)
        l = 2;
    if(y>=150 && y<200)
        l = 3;
    if(y>=200 && y<250)
        l = 4;
    if(y>=250 && y<300)
        l = 5;
    if(y>=300 && y<350)
        l = 6;
    if(y>=350 && y<400)
        l = 7;
}

/*
  Função que nao tem retorno nem recebe parametros, o objetivo dessa rotina é 
  pegar as coordenadas da casa destino.
*/
void mousePara(){
    x = -1;
    do{
        if(mouse_b & 1){
            x = mouse_x;
            y = mouse_y;
        }
    }while(x==-1);
    //coluna
    if(x>=0 && x<50)
        cd = 0;
    if(x>=50 && x<100)
        cd = 1;
    if(x>=100 && x<150)
        cd = 2;
    if(x>=150 && x<200)
        cd = 3;
    if(x>=200 && x<250)
        cd = 4;
    if(x>=250 && x<300)
        cd = 5;
    if(x>=300 && x<350)
        cd = 6;
    if(x>=350 && x<400)
        cd = 7;

    //linha
    if(y>=0 && y<50)
        ld = 0;
    if(y>=50 && y<100)
        ld = 1;
    if(y>=100 && y<150)
        ld = 2;
    if(y>=150 && y<200)
        ld = 3;
    if(y>=200 && y<250)
        ld = 4;
    if(y>=250 && y<300)
        ld = 5;
    if(y>=300 && y<350)
        ld = 6;
    if(y>=350 && y<400)
        ld = 7;

}

/*
  Função sem retorno, e sem parametros; é a rotina principal no que se refera a jogadas, contém chamdas às funções
  e validações, dentro existem dois (do...while) o primeiro é controlado pela variavel
  fimJogo(inteiro) e o segundo DO é controlado pela variavel fimJogada(inteiro).
*/
void jogada(){
    int fimJogo , fimJogada;
    fimJogo = fimJogada = 0;
    

    while(fimJogo !=12){
        
        do{
            displayUser_1();

            mouseDe();
            
            if(semPeca(l, c) == 1){
                allegro_message("Casa vazia");
            }
            else if (verPecaOponente(l, c, jogador) == 1){
                allegro_message("Peca do oponente");
                
            }
        }while(semPeca(l, c) == 1 || verPecaOponente(l, c, jogador) == 1);
        
        
        pecaAtual = tabuleiro[l][c];

        //mover as pecas
        do{
            mousePara();

            if(jgPCsInv(ld, cd, jogador)== 1){
                allegro_message("Casa invalida, nao pode ser jogado para essa casa");
            }
            else if(jgPCsInv(ld, cd, jogador)== 2){
                allegro_message("Casa ocupada pelo seu oponente");
            }
            else if(jgPCsInv(ld, cd, jogador)== 3){
                allegro_message("Casa preechida pelo seu time, issa fara com que a jogada reinicie");
                jogada();
            }
            else{
                if(tabuleiro[l][c] == nClara || tabuleiro[l][c] == nEscura){//se é peça simples
                    if(verAvanUmaN(l, ld, c, cd, jogador) == 1){
                        if(evitaSopro(jogador) == 1){//se fez sopro
                            allegro_message("Nao eh permitido sopro");
                        }
                        else{ //caso nao fez sopro e é peça simples(Normal)
                            if(jogador == 1){
                                if(fezDama(ld, jogador) == 1){
                                    coroar(ld, cd, jogador);
                                }
                                else
                                    tabuleiro[ld][cd] = pecaAtual;
    
                               tabuleiro[l][c] = vazia;
                               jogador = 2;
                               fimJogada = 1;
                               
                            }
                            else if(jogador == 2){
                                if(fezDama(ld, jogador) == 1){
                                    coroar(ld, cd, jogador);
                                }
                                else
                                    tabuleiro[ld][cd] = pecaAtual;

                                tabuleiro[l][c] = vazia;
                                jogador = 1;
                                fimJogada = 1;
                            }
                        }
                    }
                    else{//Peça normal avacou mais de uma casa
                        if(verRaptar(l, c, ld, cd, jogador)==1){//ver se a jogada é uma captura, se voltar 1 é!
                            raptar(l, c, ld, cd, jogador);
                            incrementoCap(jogador);
                            
                            //não foi criado uma função para verificar, nem dava pra fazer com a que já existe(fazDama(parametros))
                            if(capturarMais(ld, cd, jogador) == 0)
                                if(jogador == 1 && ld == 0){
                                    tabuleiro[ld][cd] = dClara;
                                }
                                else if(jogador == 2 && ld == 7){
                                    tabuleiro[ld][cd] = dEscura;
                                }
                               
                            if(capturarMais(ld, cd, jogador) == 1){
                                allegro_message("voce tem outra jogada com a mesma peca");
                                jogada();
                            }
                            else
                                if(jogador == 1){
                                    jogador = 2;
                                    fimJogada = 1;
                                }
                                else if(jogador == 2){
                                    jogador = 1;
                                    fimJogada = 1;
                                }
                        }
                        else{
                            if(evitaSopro(jogador) == 1){
                                allegro_message("Nao eh permitido sopro");
                            }
                            else{
                                allegro_message("Desculpe, mas vc nao pode ir para essa casa!");
                            }                       
                        }
                    }
                }
                else if(verAvanUmaD(l, ld, c, cd, jogador) == 1){//se  é coroada
                        if(evitaSopro(jogador) == 1){
                            allegro_message("Nao existe sopro e ainda por cima uma Dama");
                        }
                        else{
                            if(jogador == 1){
                               tabuleiro[ld][cd] = pecaAtual;
                               tabuleiro[l][c] = vazia;
                               jogador = 2;
                               fimJogada = 1;
                            }
                            else if(jogador == 2){
                                tabuleiro[ld][cd] = pecaAtual;
                                tabuleiro[l][c] = vazia;
                                jogador = 1;
                                fimJogada = 1;
                            }
                        
                        }
                }
                else{//a DAMA anvaçou mais de uma
                    if(verRaptar(l, c, ld, cd, jogador)==1){//ver se a jogada é uma captura, se voltar 1 é!
                            raptar(l, c, ld, cd, jogador);
                            incrementoCap(jogador);
                            
                           if(capturarMais(ld, cd, jogador) == 1){
                                allegro_message("voce tem outra jogada com a mesma peca");
                                jogada(); 
                            }
                            else
                                if(jogador == 1){
                                    jogador = 2;
                                    fimJogada = 1;
                                }
                                else if(jogador == 2){
                                    jogador = 1;
                                    fimJogada = 1;
                                }
                        }
                        else{
                            if(evitaSopro(jogador) == 1){
                                allegro_message("Nao eh permitido sopro");
                            }
                            else{
                                allegro_message("Desculpe, mas vc nao pode ir para essa casa");
                            }                       
                        }
                }
            }
        }while(fimJogada != 1);
        
        /*atualiza fimJogo dependendo do conteudo de cap_User1 ou cap_User2 que são globais, ou seja, a maior será 
        atribuida a fimJogo*/
        if(cap_User1 > cap_User2)
            fimJogo = cap_User1;
        else
            fimJogo = cap_User2;
    }
}
