#include<allegro.h>
#include "libTabuleiro.c"
#include "libJogada.c"
#include "libGrafico.c"
#include "libFuncoes.c"
#include "libValidar.c"

int tabuleiro[8][8];
int nClara=1;
int dClara=-1;
int nEscura=2;
int dEscura=-2;
int invalida = 5;
int vazia = 0;
int oponenteD, oponenteN;
int jogador = 1;
int pecaAtual;
int cap_User1, cap_User2;

/*
  Função principal, que faz as chamadas das demais funções.
*/
int main(){

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 560, 400, 0, 0);
    show_mouse(screen);
    casasInva();
    preecherCasas();
    jogada();
    displayUser_1();
    msgVencedor();
    return 0;
}

END_OF_MAIN()
