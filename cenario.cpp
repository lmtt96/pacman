#include "cenario.h"
#include <gl/gl.h>
#include <gsl/gsl>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <span>


#if defined(__EMSCRIPTEN__)

#endif

#if defined(__EMSCRIPTEN__)

void cenario::criaLinhaHorizontal(float x0, float x1, float y, int exp){
	
	glLineWidth(exp);
	
	glBegin (GL_LINES);
        glColor3f (this->r, this->g, this->b);   glVertex2f (x0, y);
        glColor3f (this->r, this->g, this->b);   glVertex2f (x1, y);
    glEnd();
}

void cenario::criaLinhaVertical(float x, float y0, float y1, int exp){

	glLineWidth(exp);

	glBegin (GL_LINES);
        glColor3f (this->r, this->g, this->b);   glVertex2f (x, y0);
        glColor3f (this->r, this->g, this->b);   glVertex2f (x, y1);
    glEnd();
}

void cenario::setCorLinha(float r, float g, float b){
	this->r = r;
	this->g = g;
	this->b = b;
}

void cenario::criaQuadrarinhos(float x, float y){
	
	glLineWidth(10);

	glBegin (GL_LINES);
        glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (x, y);
        glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (x + 0.03, y);
    glEnd();
		
}




