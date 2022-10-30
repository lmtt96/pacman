#ifndef CENARIO_H
#define CENARIO_H

class cenario
{
	float r;
	float g;
	float b;	
	
	public:
		void criaLinhaHorizontal(float x0, float x1, float y, int exp);
		void criaLinhaVertical(float x, float y0, float y1, int exp);
		void setCorLinha(float r, float g, float b);
		void criaQuadrarinhos(float x, float y);
				
};

#endif
