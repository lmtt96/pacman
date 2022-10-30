/**
 * @file abcgOpenGLWindow.cpp
 * @brief Definition of abcg::OpenGLWindow members.
 *
 * This file is part of ABCg (https://github.com/hbatagelo/abcg).
 *
 * @copyright (c) 2021--2022 Harlen Batagelo. All rights reserved.
 * This project is released under the MIT License.
 */


#include "movimentos.h"
#include <SDL_events.h>
#include <SDL_image.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>


int movimentos::verificaLimitesCima(float posicaoPacManX, float posicaoPacManY){	
	
	//teto do cenario
	if(posicaoPacManY + 0.1 > this->limiteExterno[1]){
		return 0;
	}	
	
	//primeiro corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->limiteExterno[1] && posicaoPacManX - 0.07 > this->SegundoQuad[1]){
		return 1;			
	}

	//segundo corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->SegundoQuad[1] && posicaoPacManX - 0.07 > this->TerceiroQuad[1]){
		
		if(posicaoPacManY + 0.1 > this->SegundoQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.15 > this->SegundoQuad[0] && posicaoPacManY - 0.15 < this->limiteExterno[0]){
			return 0;
		}		
		
		return 1;		
	}
	
	//terceiro corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->TerceiroQuad[1] && posicaoPacManX - 0.07 > this->QuadInterno[1]){
		
		if(posicaoPacManY + 0.1 > this->TerceiroQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.15 > this->TerceiroQuad[0] && posicaoPacManY - 0.15 < this->SegundoQuad[0]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//quarto corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->QuadInterno[1] && posicaoPacManX - 0.07 > 0.1){
		
		if(posicaoPacManY + 0.1 > this->SegundoQuad[1]){
			return 0;
		}else{
			if(posicaoPacManY + 0.15 > this->QuadInterno[1] && posicaoPacManY - 0.15 < 0.2){
				return 0;	
			}
		}
		
		if(posicaoPacManY < this->QuadInterno[0]){
			return 0;
		}
		
		
		
		
		return 1;
	}
	
	
	//corredor central vertical (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < 0.1 && posicaoPacManX - 0.07 > -0.1){
		
		if(posicaoPacManY > this->QuadInterno[1] && posicaoPacManY < this->QuadInterno[0]){
			return 1;
		}
		
		if(posicaoPacManY + 0.1 > this->TerceiroQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY < this->QuadInterno[0]){
			return 0;
		}
		
		
		
		
		return 1;
	}
	
	//quarto corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < -0.1 && posicaoPacManX - 0.07 > this->QuadInterno[0]){
		
		if(posicaoPacManY + 0.15 >= this->QuadInterno[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > this->QuadInterno[0] && posicaoPacManY - 0.11 < this->TerceiroQuad[0]){
			return 0;
		}
		
		
		
		
		return 1;
	}	
	
	//terceiro corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->QuadInterno[0] && posicaoPacManX - 0.07 > this->TerceiroQuad[0]){
		
		if(posicaoPacManY < this->TerceiroQuad[0]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > this->TerceiroQuad[1] && posicaoPacManY - 0.11 < this->QuadInterno[1]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//segundo corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->TerceiroQuad[0] && posicaoPacManX - 0.07 > this->SegundoQuad[0]){
		
		if(posicaoPacManY + 0.1 > this->SegundoQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.15 > this->SegundoQuad[0] && posicaoPacManY - 0.15 < this->limiteExterno[0]){
			return 0;
		}		
		
		return 1;		
	}
	
	//primeiro corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX - 0.07 > this->limiteExterno[0] && posicaoPacManX + 0.07 < this->SegundoQuad[0]){
		return 1;			
	}
	
	
	return 0;
}


int movimentos::verificaLimitesBaixo(float posicaoPacManX, float posicaoPacManY){
	
	//chao do cenario
	if(posicaoPacManY - 0.1 < this->limiteExterno[0]){
		return 0;
	}	
	
	//primeiro corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->limiteExterno[1] && posicaoPacManX - 0.07 > this->SegundoQuad[1]){
		return 1;			
	}
	
	//segundo corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->SegundoQuad[1] && posicaoPacManX - 0.07 > this->TerceiroQuad[1]){
		
		if(posicaoPacManY - 0.1 < this->SegundoQuad[0]){
			return 0;
		}
		
		if(posicaoPacManY > this->SegundoQuad[1]){
			return 0;
		}		
		
		return 1;		
	}
	
	//terceiro corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->TerceiroQuad[1] && posicaoPacManX - 0.07 > this->QuadInterno[1]){
		
		if(posicaoPacManY > this->TerceiroQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > this->QuadInterno[0] && posicaoPacManY - 0.11 < this->TerceiroQuad[0]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//quarto corredor da direita (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->QuadInterno[1] && posicaoPacManX - 0.07 > 0.1){
		
		if(posicaoPacManY < - 0.2){
			return 0;
		}
		
		if(posicaoPacManY - 0.11 <= QuadInterno[1] && posicaoPacManY + 0.11 >= this->TerceiroQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.15 >= this->limiteExterno[1]){
			return 0;
		}		
		
		return 1;
	}
	
	
	//corredor central vertical (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < 0.1 && posicaoPacManX - 0.07 > -0.1){
		
		if(posicaoPacManY < this->TerceiroQuad[1] && posicaoPacManY > -0.17){
			return 1;
		}	
		
		return 0;
	}
	
	//quarto corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < -0.1 && posicaoPacManX - 0.07 > this->QuadInterno[0]){
		
		if(posicaoPacManY > this->QuadInterno[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > -0.2 && posicaoPacManY - 0.11 < this->QuadInterno[0]){
			return 0;
		}
		
		if(posicaoPacManY - 0.11 < this->SegundoQuad[0]){
			return 0;
		}		
		
		return 1;
	}	
	
	//terceiro corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->QuadInterno[0] && posicaoPacManX - 0.07 > this->TerceiroQuad[0]){
		
		if(posicaoPacManY + 0.07 < this->QuadInterno[0]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > this->SegundoQuad[1] && posicaoPacManY - 0.11 < this->TerceiroQuad[1]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//segundo corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX + 0.07 < this->TerceiroQuad[0] && posicaoPacManX - 0.07 > this->SegundoQuad[0]){
		
		if(posicaoPacManY > this->SegundoQuad[1]){
			return 0;
		}
		
		if(posicaoPacManY + 0.11 > this->TerceiroQuad[0] && posicaoPacManY - 0.11 < this->SegundoQuad[0]){
			return 0;
		}		
		
		return 1;		
	}
	
	//primeiro corredor da esquerda (contado de fora pra dentro)
	if(posicaoPacManX - 0.07 > this->limiteExterno[0] && posicaoPacManX + 0.07 < this->SegundoQuad[0]){
		return 1;			
	}
	
	
	return 0;
}

int movimentos::verificaLimitesDireita(float posicaoPacManX, float posicaoPacManY){
	
	//canto direito do cenario
	if(posicaoPacManX + 0.1 > this->limiteExterno[1]){
		return 0;
	}	
	
	//primeiro corredor de cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->limiteExterno[1] && posicaoPacManY - 0.07 > this->SegundoQuad[1]){
		return 1;			
	}
	
	//segundo corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->SegundoQuad[1] && posicaoPacManY - 0.07 > this->TerceiroQuad[1]){
		
		if(posicaoPacManX + 0.1 > this->SegundoQuad[1]){
			return 0;
		}
		
		if(posicaoPacManX < this->SegundoQuad[0]){
			return 0;
		}		
		
		return 1;		
	}
	
	//terceiro corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->TerceiroQuad[1] && posicaoPacManY - 0.07 > this->QuadInterno[1]){
		
		if(posicaoPacManX + 0.15 > this->TerceiroQuad[0] && posicaoPacManX - 0.15 < this->SegundoQuad[0]){
			return 0;
		}
		
		if(posicaoPacManX + 0.11 > this->TerceiroQuad[1] && posicaoPacManX - 0.15 < this->QuadInterno[1]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//quarto corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->QuadInterno[1] && posicaoPacManY - 0.07 > 0.1){
		
		if(posicaoPacManX > this->QuadInterno[0] && posicaoPacManX + 0.15 < this->QuadInterno[1]){
			return 1;
		}
		
		return 0;
	}
	
	//corredor central horizontal (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < 0.1 && posicaoPacManY - 0.07 > -0.1){
		
		if(posicaoPacManX > this->SegundoQuad[0] && posicaoPacManX + 0.11 < this->QuadInterno[0]){
			return 1;
		}	
		
		if(posicaoPacManX > this->QuadInterno[0] && posicaoPacManX + 0.11 < this->QuadInterno[1]){
			return 1;
		}
		
		if(posicaoPacManX > this->QuadInterno[1] && posicaoPacManX + 0.11 < this->SegundoQuad[1]){
			return 1;
		}
		
		return 0;
	}
	
	//quarto corredor da baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < -0.1 && posicaoPacManY - 0.07 > this->QuadInterno[0]){
		
		if(posicaoPacManX > this->QuadInterno[0] && posicaoPacManX + 0.15 < this->QuadInterno[1]){
			return 1;
		}
		
		return 0;
	}
	
	//terceiro corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->QuadInterno[0] && posicaoPacManY - 0.07 > this->TerceiroQuad[0]){
		
		if(posicaoPacManX + 0.15 > this->TerceiroQuad[0] && posicaoPacManX - 0.15 < this->SegundoQuad[0]){
			return 0;
		}
		
		if(posicaoPacManX + 0.11 > this->TerceiroQuad[1] && posicaoPacManX - 0.15 < this->QuadInterno[1]){
			return 0;
		}	
		
		
		return 1;
	}
	
	//segundo corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->TerceiroQuad[0] && posicaoPacManY - 0.07 > this->SegundoQuad[0]){
		
		if(posicaoPacManX + 0.1 > this->SegundoQuad[1]){
			return 0;
		}
		
		if(posicaoPacManX < this->SegundoQuad[0]){
			return 0;
		}		
		
		return 1;			
	}
	
	//primeiro corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY - 0.07 > this->limiteExterno[0] && posicaoPacManY + 0.07 < this->SegundoQuad[0]){
		return 1;			
	}
	
	return 0;
}

int movimentos::verificaLimitesEsquerda(float posicaoPacManX, float posicaoPacManY){
	
	//canto direito do cenario
	if(posicaoPacManX - 0.1 < this->limiteExterno[0]){
		return 0;
	}	
	
	//primeiro corredor de cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->limiteExterno[1] && posicaoPacManY - 0.07 > this->SegundoQuad[1]){
		return 1;			
	}
	
	//segundo corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->SegundoQuad[1] && posicaoPacManY - 0.07 > this->TerceiroQuad[1]){
		
		if(posicaoPacManX - 0.1 < this->SegundoQuad[0]){
			return 0;
		}
		
		if(posicaoPacManX > this->SegundoQuad[1]){
			return 0;
		}		
		
		return 1;		
	}
	
	//terceiro corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->TerceiroQuad[1] && posicaoPacManY - 0.07 > this->QuadInterno[1]){
		
		if(posicaoPacManX - 0.11 < this->TerceiroQuad[0] && posicaoPacManX + 0.11 > this->QuadInterno[0]){
			return 0;
		}
		
		if(posicaoPacManX - 0.11 < this->TerceiroQuad[1] && posicaoPacManX + 0.11 > this->SegundoQuad[1]){
			return 0;
		}	
		
		return 1;
	}
	
	//quarto corredor da cima (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->QuadInterno[1] && posicaoPacManY - 0.07 > 0.1){
		
		if(posicaoPacManX - 0.15 > this->QuadInterno[0] && posicaoPacManX < this->QuadInterno[1]){
			return 1;
		}
		
		return 0;
	}
	
	//corredor central horizontal (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < 0.1 && posicaoPacManY - 0.07 > -0.1){
		
		if(posicaoPacManX < this->QuadInterno[0] && posicaoPacManX - 0.11 > this->SegundoQuad[0]){
			return 1;
		}	
		
		if(posicaoPacManX - 0.15 > this->QuadInterno[0] && posicaoPacManX < this->QuadInterno[1]){
			return 1;
		}
		
		if(posicaoPacManX - 0.11 > this->QuadInterno[1] && posicaoPacManX < this->SegundoQuad[1]){
			return 1;
		}
		
		return 0;
	}
	
	//quarto corredor da baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < -0.1 && posicaoPacManY - 0.07 > this->QuadInterno[0]){
		
		if(posicaoPacManX - 0.15 > this->QuadInterno[0] && posicaoPacManX < this->QuadInterno[1]){
			return 1;
		}
		
		return 0;
	}
	
	//terceiro corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->QuadInterno[0] && posicaoPacManY - 0.07 > this->TerceiroQuad[0]){
		
		if(posicaoPacManX - 0.11 < this->TerceiroQuad[0] && posicaoPacManX + 0.11 > this->QuadInterno[0]){
			return 0;
		}
		
		if(posicaoPacManX - 0.11 < this->TerceiroQuad[1] && posicaoPacManX + 0.11 > this->SegundoQuad[1]){
			return 0;
		}	
		
		return 1;
	}
	
	//segundo corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY + 0.07 < this->TerceiroQuad[0] && posicaoPacManY - 0.07 > this->SegundoQuad[0]){
		
		if(posicaoPacManX - 0.1 < this->SegundoQuad[0]){
			return 0;
		}
		
		if(posicaoPacManX > this->SegundoQuad[1]){
			return 0;
		}		
		
		return 1;			
	}
	
	//primeiro corredor de baixo (contado de fora pra dentro)
	if(posicaoPacManY - 0.07 > this->limiteExterno[0] && posicaoPacManY + 0.07 < this->SegundoQuad[0]){
		return 1;			
	}
	
	return 0;
}

void movimentos::registraMovimentosPacMan(float posicaoPacManX, float posicaoPacManY){
	
	int i = registraPosicaoX(posicaoPacManX);
	int j = registraPosicaoY(posicaoPacManY);	
	
	if((i >= 0 || i <= 8)&&(j >= 0 || j <= 8))
		this->movimentosPacMan[i][j] = 1;
}

int movimentos::verificaMatrizMovimentosPacMan(int posicaoX, int posicaoY){
	
	int resultado = (this->movimentosPacMan[posicaoX][posicaoY] == 1 ? 0 : 1); 
	
	return resultado;
}

int movimentos::registraPosicaoX(float x){
	
	int i;
	
	//primeiro corredor da direita (contado de fora pra dentro)
	if(x < this->limiteExterno[1] && x >= this->SegundoQuad[1]){
		i = 8;		
	}

	//segundo corredor da direita (contado de fora pra dentro)
	if(x < this->SegundoQuad[1] && x >= this->TerceiroQuad[1]){
		i = 7;		
	}
	
	//terceiro corredor da direita (contado de fora pra dentro)
	if(x < this->TerceiroQuad[1] && x >= this->QuadInterno[1]){
		i = 6;
	}
	
	//quarto corredor da direita (contado de fora pra dentro)
	if(x < this->QuadInterno[1] && x  >= 0.1){
		i = 5;
	}
	
	//corredor central vertical (contado de fora pra dentro)
	if(x  < 0.1 && x > -0.1){
		i = 4;
	}
	
	//quarto corredor da esquerda (contado de fora pra dentro)
	if(x <= -0.1 && x > this->QuadInterno[0]){
		i = 3;
	}	
	
	//terceiro corredor da esquerda (contado de fora pra dentro)
	if(x <= this->QuadInterno[0] && x > this->TerceiroQuad[0]){
		i = 2;
	}
	
	//segundo corredor da esquerda (contado de fora pra dentro)
	if(x <= this->TerceiroQuad[0] && x > this->SegundoQuad[0]){
		i = 1;		
	}
	
	//primeiro corredor da esquerda (contado de fora pra dentro)
	if(x > this->limiteExterno[0] && x <= this->SegundoQuad[0]){
		i = 0;			
	}
	
	return i;
}

int movimentos::registraPosicaoY(float y){
	
	int j;
	
	//primeiro corredor de cima (contado de fora pra dentro)
	if(y < this->limiteExterno[1] && y >= this->SegundoQuad[1]){
		j = 0;			
	}
	
	//segundo corredor da cima (contado de fora pra dentro)
	if(y < this->SegundoQuad[1] && y >= this->TerceiroQuad[1]){
		j = 1;		
	}
	
	//terceiro corredor da cima (contado de fora pra dentro)
	if(y < this->TerceiroQuad[1] && y >= this->QuadInterno[1]){
		j = 2;
	}
	
	//quarto corredor da cima (contado de fora pra dentro)
	if(y < this->QuadInterno[1] && y >= 0.1){
		j = 3;
	}
	
	//corredor central horizontal (contado de fora pra dentro)
	if(y < 0.1 && y >= -0.1){
		j = 4;
	}
	
	//quarto corredor da baixo (contado de fora pra dentro)
	if(y < -0.1 && y >= this->QuadInterno[0]){
		j = 5;
	}
	
	//terceiro corredor de baixo (contado de fora pra dentro)
	if(y < this->QuadInterno[0] && y >= this->TerceiroQuad[0]){
		j = 6;
	}
	
	//segundo corredor de baixo (contado de fora pra dentro)
	if(y < this->TerceiroQuad[0] && y >= this->SegundoQuad[0]){
		j = 7;			
	}
	
	//primeiro corredor de baixo (contado de fora pra dentro)
	if(y > this->limiteExterno[0] && y < this->SegundoQuad[0]){
		j = 8;			
	}
	
	return j;
}


int movimentos::verificaFimDoJogo(){
	int fimDoJogo = 0;
	
	for(int i = 0; i <= 8; i++){
		for(int j = 0; j <= 8; j++){
			
			if((i >= 2 && i <= 6)){
				if((j >= 3 && j <= 5)){
					continue;	
				}				
			}
			
   			if(this->movimentosPacMan[i][j] == 1){
				fimDoJogo++;
			}			
		}
	}
		
	return fimDoJogo;	
}

int movimentos::verificaSeEncostou(float posicaoFantasmaX, float posicaoFantasmaY, float posicaoPacManX, float posicaoPacManY){
	
	int iFantasma = registraPosicaoX(posicaoFantasmaX);
	int jFantasma = registraPosicaoY(posicaoFantasmaY);
	int iPacMan = registraPosicaoX(posicaoPacManX);
	int jPacMan = registraPosicaoY(posicaoPacManY);
	
	if(iFantasma == iPacMan && jFantasma == jPacMan){
		return 1;
	}
	
	return 0;	
}



