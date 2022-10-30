#ifndef PACMAN_H
#define PACMAN_H
#include <gl/gl.h>
#include <gsl/gsl>

class pacman
{
	int DEG2RAD;
	
	public:
		void desenhaCirculo(GLfloat x, GLfloat y, GLfloat raio, int blink);
		
};

#endif
