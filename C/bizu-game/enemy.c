player2* cria_player2() {
    player2* objeto2 = (player2*)malloc(sizeof(player2));
    objeto2->tamanho = 1;
    objeto2->c = (Coord*)malloc(3600 * sizeof(Coord));  
    objeto2->c[0].x = 430;
    objeto2->c[0].y = 380;
    objeto2->direcao = BAIXO;
    
    objeto2->saltando = false;
    objeto2->velocidade_salto = 30;
    objeto2->gravidade = 8;
    objeto2->altura_maxima = 150;
    objeto2->altura_atual = 0;
    objeto2->direcao_anterior = ESQUERDA;

    objeto2->frame_velocidade = 10;
    objeto2->frame_contador = 0;
    objeto2->alterna_imagem = 0;
    objeto2->saltando = false;
    objeto2->subindo = false;
    objeto2->w = false;
    objeto2->a = false;
    objeto2->s = false;
    objeto2->d = false;
    objeto2->chute_contador = 0;
    objeto2->chute_duracao = 10; 
    objeto2->andando_para_direita = false;
    objeto2->andando_para_esquerda = false;
    objeto2->parado = true;
    objeto2->recuando = false;
    objeto2->life = 3;

    return objeto2;
}

player2* cria_player3() {
    player2* objeto2 = (player2*)malloc(sizeof(player2));
    objeto2->tamanho = 1;
    objeto2->c = (Coord*)malloc(3600 * sizeof(Coord));  
    objeto2->c[0].x = 430;
    objeto2->c[0].y = 480;
    objeto2->direcao = BAIXO;
    
    objeto2->saltando = false;
    objeto2->velocidade_salto = 30;
    objeto2->gravidade = 8;
    objeto2->altura_maxima = 150;
    objeto2->altura_atual = 0;
    objeto2->direcao_anterior = ESQUERDA;

    objeto2->frame_velocidade = 10;
    objeto2->frame_contador = 0;
    objeto2->alterna_imagem = 0;
    objeto2->saltando = false;
    objeto2->subindo = false;
    objeto2->w = false;
    objeto2->a = false;
    objeto2->s = false;
    objeto2->d = false;
    objeto2->chute_contador = 0;
    objeto2->chute_duracao = 10; 
    objeto2->andando_para_direita = false;
    objeto2->andando_para_esquerda = false;
    objeto2->parado = true;
    objeto2->recuando = false;
    objeto2->life = 9;

    return objeto2;
}


void atacar(player* objeto,player2* objeto2 ){
  
    int dx = abs(objeto->c[0].x - objeto2->c[0].x);
    int dy = abs(objeto->c[0].y - objeto2->c[0].y);
    
    if (objeto2->cooldown_ataque > 0) {
        objeto2->cooldown_ataque--;
        return;
    }
  
    if (dx < 150 && dy < 50) { 
        int tipo_ataque =   rand() % 4; 

        switch (tipo_ataque) {
            case 0:
                objeto2->s = true;
              
                break;
            case 1:
                objeto2->w = true; 
                objeto2->subindo = true;
                objeto2->altura_atual = 0;
             //   printf("\nataque w\n");
                break;
            case 2:
                objeto2->a = true; 
             //   printf("\nataque a\n");
                break;
            case 3:
                objeto2->d = true; 
         
                break;
        }
 
        objeto2->chute_contador = 0;
        objeto2->direcao_anterior = objeto2->direcao;
        objeto2->cooldown_ataque = 50;
    }

    
}
void mudareta2(player* objeto,player2* objeto2) {
        if (objeto2->saltando || objeto2->s || objeto2->w || objeto2->d || objeto2->a) return;
          
            if (objeto2->recuando && !objeto2->tomo) {
                printf("recuando normal. recuo restante: %d\n", objeto2->recuo_restante);
                if (objeto2->direcao == DIREITA) {
                    objeto2->andando_para_esquerda = true;
                    objeto2->andando_para_direita = false;
                } else {
                    objeto2->andando_para_esquerda = false;
                    objeto2->andando_para_direita = true;
                }
                objeto2->recuo_restante -= 2;
            
                if (objeto2->recuo_restante <= 0) {
                    objeto2->recuando = false;
                
                }
             return;
            } else if (objeto2->tomo) {
            
                printf("tomo! recuo restante: %d\n", objeto2->recuo_restante);
                if (objeto2->direcao == DIREITA) {
                    objeto2->andando_para_esquerda = true;
                    objeto2->andando_para_direita = false;// Recuar para a esquerda
                } else {
                    objeto2->andando_para_esquerda = false;
                    objeto2->andando_para_direita = true;// Recuar para a direita
                }
                objeto2->recuo_restante -= 8;
            
                if (objeto2->recuo_restante <= 0) {
                    printf("recuo finalizado\n");
                    objeto2->recuando = false;
                    objeto2->tomo = false;
                    objeto2->life --;
                }     
            }

            int x2_dir = objeto2->c[0].x + 55;
            int y2_dir = objeto2->c[0].y + 5;
            int x1_esq = objeto->c[0].x - 35;
            int y1_esq = objeto->c[0].y;
            int x2_esq = objeto2->c[0].x - 105;
            int y2_esq = objeto2->c[0].y + 5;
            int largura2 = 38;
            int altura2 = 18;
            int x1_dir = objeto->c[0].x + 15;
            int y1_dir = objeto->c[0].y;
            int largura1 = 20;
            int altura1 = 10;

            bool colisao = x1_dir < x2_esq + largura2 && x1_dir + largura1 > x2_esq && y1_dir < y2_esq + altura2 && y1_dir + altura1 > y2_esq; 
            bool colisao2 = x1_esq < x2_dir + largura2 && x1_esq + largura1 > x2_dir &&  y1_esq < y2_dir + altura2 && y1_esq + altura1 > y2_dir;
        
            if ((colisao || colisao2) && !objeto2->recuando && !objeto2->tomo) {
                if(objeto->s || objeto->w || objeto->a || objeto->d) {
                    objeto2->tomo = true;
                }else{ 
                    objeto2->tomo = false;
                }   
                objeto2->recuo_restante = 200;
                objeto2->recuando = true;
                objeto2->direcao_anterior = objeto2->direcao;
            return;
            )
            if(objeto2->recuando == false ){
                printf("\ntoma\n");
                if (objeto2->c[0].x < objeto->c[0].x) {
                    objeto2->andando_para_direita = false;
                    objeto2->andando_para_esquerda = true;
                    objeto2->direcao = ESQUERDA;
                    
                    printf("\nANDO PRA DIREITA\n");
                    } else if (objeto2->c[0].x > objeto->c[0].x) {
                        objeto2->andando_para_direita = true;
                        objeto2->andando_para_esquerda = false;
                        objeto2->direcao = DIREITA;
                        printf("\nANDO PRA ESQUERDA\n");
                    } 
    
                    if (abs(objeto2->c[0].x - objeto->c[0].x) < 30) 
                    {
                        if (objeto->direcao == ESQUERDA)objeto2->c[0].x = objeto->c[0].x + 150;
                        if (objeto->direcao == DIREITA)objeto2->c[0].x = objeto->c[0].x - 150;
                    }
            }
        }
}

int movi2(player2* objeto2, int direcao) {
    if (!objeto2->saltando || !objeto2->w || !objeto2->s || objeto2->d || objeto2->a ) { 
        if (objeto2->andando_para_direita) {
            objeto2->c[0].x -= 2; 
        }
        if (objeto2->andando_para_esquerda) {
            objeto2->c[0].x += 2; 
        }
 }
    if (objeto2->direcao == DIREITA){
         if (objeto2->saltando) {
            if (objeto2->subindo) {
                objeto2->c[0].y -= objeto2->velocidade_salto ;
                objeto2->altura_atual += objeto2->velocidade_salto ;
                if (objeto2->altura_atual >= objeto2->altura_maxima) {
                    objeto2->subindo = false;  // Começa a descer
                }
            } else {
                objeto2->c[0].y += objeto2->gravidade;
                objeto2->altura_atual -= objeto2->gravidade;
                objeto2->c[0].x -=1;    
                if (objeto2->altura_atual <= 0) {
                    objeto2->altura_atual = 0;
                    objeto2->c[0].y = 380;
                    objeto2->saltando = false;
                    objeto2->subindo = false;
                    objeto2->direcao = objeto2->direcao_anterior;
                }
            }
        }
        if (objeto2->d) {
            objeto2->c[0].y = 410;
            objeto2->chute_contador++;
            objeto2->c[0].x -= 5; 
            if (objeto2->chute_contador >= (objeto2->chute_duracao + 10)) {
                objeto2->d= false;
                objeto2->chute_contador = 0;
                objeto2->direcao = objeto2->direcao_anterior;
                objeto2->c[0].y = 380;
            }
        }
        if (objeto2->w) {
            if (objeto2->subindo) {
                objeto2->c[0].y -= objeto2->velocidade_salto - 20;
                objeto2->altura_atual += objeto2->velocidade_salto -20;
                objeto2->c[0].x -= 1;
                if (objeto2->altura_atual >= objeto2->altura_maxima) {
                    objeto2->subindo = false; 
                }
            } else {
                objeto2->c[0].y += 11;
                objeto2->altura_atual -= objeto2->gravidade;
                objeto2->c[0].x -= 1;
                if (objeto2->altura_atual <= 0) {
                    objeto2->altura_atual = 0;
                    objeto2->c[0].y = 380;
                    objeto2->w = false;
                    objeto2->subindo = false;
                    objeto2->direcao = objeto2->direcao_anterior;
                }
            }
        }
        if (objeto2->s) {
            objeto2->c[0].y = 400;
            objeto2->chute_contador++;
            objeto2->c[0].x -= 3;  
            if (objeto2->chute_contador >= objeto2->chute_duracao) {
                objeto2->s = false;
                objeto2->chute_contador = 0;
                objeto2->direcao = objeto2->direcao_anterior;
                objeto2->c[0].y = 380;
            }
        }
        if (objeto2->a) {
            objeto2->chute_contador++;
            objeto2->c[0].x -= 10;
            if (objeto2->chute_contador >= objeto2->chute_duracao  ) {
