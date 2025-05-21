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
    objeto2->chute_duracao = 10; // duração do chute em frames
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
