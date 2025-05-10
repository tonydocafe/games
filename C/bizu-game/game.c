#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include <jogo.h>



player* cria_player() {
    player* objeto = (player*)malloc(sizeof(player));
    objeto->tamanho = 1;
    objeto->c = (Coord*)malloc(3600 * sizeof(Coord));  
    objeto->c[0].x = 90;
    objeto->c[0].y = 400;
    objeto->direcao = BAIXO;

    objeto->saltando = false;
    objeto->velocidade_salto = 60;
    objeto->gravidade = 80;
    objeto->altura_maxima = 30;
    objeto->altura_atual = 0;
    objeto->direcao_anterior = DIREITA;

    objeto->frame_velocidade = 10;
    objeto->frame_contador = 0;
    objeto->alterna_imagem = 0;
    objeto->saltando = false;
    objeto->subindo = false;
    objeto->w = false;
    objeto->a = false;
    objeto->s = false;
    objeto->d = false;
    objeto->chute_contador = 0;
    objeto->chute_duracao = 2;
    objeto->andando_para_direita = false;
    objeto->andando_para_esquerda = false;
    objeto->parado = true;


    return objeto;
}


void mudareta(player* objeto){
      if (objeto->saltando || objeto->w || objeto->d ||objeto->a || objeto->s) return;
        if (tecla_pressionada(DIREITA)) {
            objeto->andando_para_direita = true;
            objeto->andando_para_esquerda = false;
            objeto->direcao = DIREITA;
        } else if (tecla_pressionada(ESQUERDA)) {
            objeto->andando_para_esquerda = true;
            objeto->andando_para_direita = false;
            objeto->direcao = ESQUERDA;
        } else {
            objeto->andando_para_direita = false;
            objeto->andando_para_esquerda = false;
        }
        if (tecla_acabou_de_ser_apertada(BAIXO)) {
            objeto->direcao = BAIXO;
        }
        if (tecla_acabou_de_ser_apertada(CIMA)) {
            objeto->saltando = true;
            objeto->subindo = true;
            objeto->altura_atual = 0;
            objeto->direcao_anterior = objeto->direcao;
        }
        if (tecla_acabou_de_ser_apertada(W)) {
            objeto->w = true;
            objeto->subindo = true;
            objeto->altura_atual = 0;
            objeto->direcao_anterior = objeto->direcao;
        }
        if (tecla_acabou_de_ser_apertada(D)) {
            objeto->d = true;
            objeto->subindo = true;
            objeto->altura_atual = 0;
            objeto->direcao_anterior = objeto->direcao;
        }
        if (tecla_acabou_de_ser_apertada(S)) {
            objeto->s = true;
            objeto->direcao_anterior = objeto->direcao;
            objeto->chute_contador = 0;
        }
        if (tecla_acabou_de_ser_apertada(A)) {
            objeto->a = true;
            objeto->direcao_anterior = objeto->direcao;
            objeto->chute_contador = 0;
        }
}
int movi(player* objeto, int direcao) {
      if (!objeto->saltando && !objeto->w && !objeto->s) {  
          if (objeto->andando_para_direita) {
               objeto->c[0].x += 15; 
         }
          if (objeto->andando_para_esquerda) {
             objeto->c[0].x -= 15;
         }
      }

    if (objeto->saltando) {
        if (objeto->subindo) {

            objeto->c[0].y -= objeto->velocidade_salto + 50;
            objeto->altura_atual += objeto->velocidade_salto;
               
      
        if (objeto->altura_atual >= objeto->altura_maxima) {
                objeto->subindo = false;  
        }
    } else {
    
            objeto->c[0].y += objeto->gravidade;
            objeto->altura_atual -= objeto->gravidade;
            objeto->c[0].x +=5;    
            
            if (objeto->altura_atual <= 0) {
                
            objeto->altura_atual = 0;
            objeto->c[0].y = 400;
            objeto->saltando = false;
            objeto->subindo = false;
            objeto->direcao = objeto->direcao_anterior;
            }
        }
    }
  if (objeto->d) {
        if (objeto->subindo) {
           
            objeto->c[0].y -= objeto->velocidade_salto + 5;
            objeto->altura_atual += objeto->velocidade_salto - 5;
            objeto->direcao = DIREITA;
            objeto->c[0].x +=45;
            if (objeto->altura_atual >= objeto->altura_maxima) {
                objeto->subindo = false; 
               
            }
        } else {

        
            objeto->c[0].y += 110;
           
            objeto->altura_atual -= objeto->gravidade - 55;

            if (objeto->altura_atual <= 0) {
                
                objeto->altura_atual = 0;
                objeto->c[0].y = 400;
                objeto->d = false;
                objeto->subindo = false;
                objeto->direcao = objeto->direcao_anterior;
            }
        }
    }
    if (objeto->w) {
        if (objeto->subindo) {
        
            objeto->c[0].y -= objeto->velocidade_salto + 50;
            objeto->altura_atual += objeto->velocidade_salto - 5;
            objeto->direcao = DIREITA;

            if (objeto->altura_atual >= objeto->altura_maxima) {
                objeto->subindo = false; 
                
            }
        } else {
            objeto->c[0].y += 100;
            objeto->altura_atual -= objeto->gravidade -30;

            if (objeto->altura_atual <= 0) {
               
                objeto->altura_atual = 0;
                objeto->c[0].y = 400;
                objeto->w = false;
                objeto->subindo = false;
                objeto->direcao = objeto->direcao_anterior;
            }
        }
    }
    if (objeto->s) {
        objeto->chute_contador++;
        objeto->c[0].x += 1;  
        objeto->direcao = BAIXO;
