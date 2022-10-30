#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

#include <vector>


class movimentos
{
	//posição x e y dos limites dos quadrados	
	float limiteExterno[2];
	float SegundoQuad[2];
	float TerceiroQuad[2];
	float QuadInterno[2];
	
	int movimentosPacMan[9][9];
	int contaQuadradinhos;
	
	public:		
		
		movimentos(){
			for(int i = 0; i <= 8; i++){
				for(int j = 0; j <= 8; j++){
					this->movimentosPacMan[i][j] = 0;
				}
			}	
	
			this->limiteExterno[0] = -0.9;
			this->limiteExterno[1] = 0.9;
			this->SegundoQuad[0] = -0.7;
			this->SegundoQuad[1] =  0.7;
			this->TerceiroQuad[0] = -0.5;
			this->TerceiroQuad[1] = 0.5;
			this->QuadInterno[0] = -0.3;
			this->QuadInterno[1] = 0.3;
			
			this->contaQuadradinhos = 0;	
		}	
		
		int verificaLimitesCima(float posicaoPacManX, float posicaoPacManY);
		int verificaLimitesBaixo(float posicaoPacManX, float posicaoPacManY);
		int verificaLimitesDireita(float posicaoPacManX, float posicaoPacManY);
		int verificaLimitesEsquerda(float posicaoPacManX, float posicaoPacManY);
		
		void registraMovimentosPacMan(float posicaoPacManX, float posicaoPacManY);
		int registraPosicaoX(float x);
		int registraPosicaoY(float y);
		int verificaMatrizMovimentosPacMan(int posicaoX, int posicaoY);
		int verificaFimDoJogo();		
		int verificaSeEncostou(float posicaoFantasmaX, float posicaoFantasmaY, float posicaoPacManX, float posicaoPacManY);
		
	
};

#endif
