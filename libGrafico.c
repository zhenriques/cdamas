extern int invalida, nClara, dClara, nEscura, dEscura, vazia, oponenteN, oponenteD;
extern int tabuleiro[8][8], captUserPeca_1;

/*
  Função que recebe um inteiros e atualiza as mensagens laterais, para mostrar de quem é a vez de jogar
*/
int msg(int jgd) {

    clear(screen);//lipar a tela
    if(jgd == 1){
        textout_ex(screen,font,"Vez do Branco",410,10,makecol(255,255,255),-1); 
    }
    else{
        textout_ex(screen,font, "Vez do Azul",410,10,makecol(0,0,255),-1);
    }
    
    textout_ex(screen,font, "Andre Henriques",410,350,makecol(0,255,0),-1);
    textout_ex(screen,font, "hponto@hotmail.com",410,360,makecol(0,255,0),-1);
    textout_ex(screen,font, "LP2 - 4 Periodo",410,370,makecol(0,255,0),-1);
    textout_ex(screen,font, "CCO - FG",410,380,makecol(0,255,0),-1);
    
    return(0);
}

/*
  funcao sem parametros e sem retorno, funcao que monta todo o tabuleiro e é chamada a cada enquanto inicio de jogada.
  50 píxels são os tamanhos das imagens, que representa cada valor
*/
int displayUser_1(){

    int l, c;
    PALLETE pal;
    BITMAP *dClaraImg = load_bitmap("dClara.bmp", pal);
    BITMAP *dEscuraImg = load_bitmap("dEscura.bmp", pal);
    BITMAP *nClaraImg = load_bitmap("nClara.bmp", pal);
    BITMAP *nEscuraImg = load_bitmap("nEscura.bmp", pal);
    BITMAP *vaziaImg = load_bitmap("vazia.bmp", pal);
    BITMAP *invalidaImg = load_bitmap("invalida.bmp", pal);
    msg(jogador);
    for(l=0; l<8; l++){
       for(c=0; c<8; c++){
           switch(tabuleiro[l][c]){
               
               case -2:{//Dama escura
                   draw_sprite( screen, dEscuraImg, c*50, l*50 ); break;
               }
               case -1:{//Dama clara
                   draw_sprite( screen, dClaraImg, c*50, l*50 ); break;
               }
               case 1:{//Peão claro
                   draw_sprite( screen, nClaraImg, c*50, l*50 ); break;
               }
               case 2:{//peão escuro
                   draw_sprite( screen, nEscuraImg, c*50, l*50 ); break;
               }
               case 0:{//casa vazia
                   draw_sprite( screen, vaziaImg, c*50, l*50 ); break;
               }
               case 5:{//casa invalida
                   draw_sprite( screen, invalidaImg, c*50, l*50 ); break;
              }
          }
      }
   }
return(0);
}

/*
  funçao sem retorno e sem parametro tem como objetivo mostrar um mensagem de fim de jogo e quem é o vendcedor,
  pressionado Esc a funcao é tida como falsa e sai.
*/
int msgVencedor(){
    while(!key[KEY_ESC]) {
        if(cap_User1 == 12){
            textout_ex(screen,font, "Gamer Over!!!",200,200,makecol(255,0,0),-1);
            textout_ex(screen,font, "Peca BRANCA ganhou!!!",200,210,makecol(255,0,0),-1);
            textout_ex(screen,font, "Pressione ESC para sair",200,220,makecol(255,0,0),-1);
        }
        else{
            textout_ex(screen,font, "Gamer Over!!!",200,200,makecol(255,0,0),-1);
            textout_ex(screen,font, "Peca AZUL ganhou!!!",200,210,makecol(255,0,0),-1);
            textout_ex(screen,font, "Pressione ESC para sair",200,220,makecol(255,0,0),-1);
        }
    }
}
