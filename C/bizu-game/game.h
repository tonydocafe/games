#ifndef GAME_H
#define GAME_H

typedef struct{
    int x;
    int y;
}Coord;

typedef struct {
    Coord* c;
    int tamanho;
    int direcao;

    // Animação
    int frame_velocidade;     
    int frame_contador;       
    int alterna_imagem;       

    // Salto
    int velocidade_salto;
    int gravidade;
    int altura_maxima;
    int altura_atual;
    int direcao_anterior;
    int saltando;
    bool subindo;
    int w;
    int s;
    int a;
    int d;
    int chute_contador;
    int chute_duracao;
    bool andando_para_direita;
    bool andando_para_esquerda;
    bool parado;
    int tomo; 
    bool recuando;
    int recuo_restante;
} player;




typedef struct {
    Coord* c;
    int tamanho;
    int direcao;

    int frame_velocidade;   
    int frame_contador;    
    int alterna_imagem;
    int velocidade_salto;
    int gravidade;
    int altura_maxima;
    int altura_atual;
    int direcao_anterior;
    int saltando;
    bool subindo;
    int w;
    int s;
    int a;
    int d;
    int chute_contador;
    int chute_duracao;
    bool andando_para_direita;
    bool andando_para_esquerda;
    bool parado;
    bool recuando;
    int recuo_restante;
    bool tomo;
    int cooldown_ataque;
    int life;


} player2;


player* cria_player();
player2* cria_player3();

int movi (player *objeto, int direcao);

void desen(player* objeto);
void desen4(player2* objeto2);

void mudareta(player *objeto);

player2* cria_player2();

int movi2 (player2 *objeto2, int direcao2);

void desen2(player2* objeto2);

void mudareta2(player* objeto, player2 *objeto2);

void atacar(player* objeto,player2* objeto2 );
void mudareta3(player* objeto, player2 *objeto2);
int movi3(player2* objeto2, int direcao);
void limita_bordas(Coord* c);

#endif
