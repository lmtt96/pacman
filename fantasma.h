#ifndef FANTASMA_H
#define FANTASMA_H


namespace fantasma {
struct OpenGLShader;
}

/**
 * @brief OpenGL shader object and its corresponding stage.
 */
struct fantasma::OpenGLShader {
  /** @brief Shader object. */
  GLuint shader{};
  /** @brief Shader stage (e.g., `GL_VERTEX_SHADER`). */
  GLuint stage{};
};

class fantasma
{
	float posX, posY;
		
	public:		
		fantasma(float x, float y);
		void desenhaFantasma(float r, float g, float b);
		void moveFantasmaCima();
		void moveFantasmaBaixo();
		void moveFantasmaDireita();
		void moveFantasmaEsquerda();
		
		float retornaPosicaoX();
		float retornaPosicaoY();		
};

#endif
