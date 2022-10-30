#include "cenario.h"
#include "pacman.h"
#include "movimentos.h"
#include "fantasma.h"
#include <windows.h>
#include <gl/gl.h>
#include <gsl/gsl>
#include <gl/glu.h>
#include <stdlib.h>
#include <time.h>

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

//{x, y}
float posicaoPacMan[] = {0.0, -0.4};
int blink = 1;
int escolhaAleatoria;
int fimQuadradinhos;

movimentos MovimentoPacMan;
cenario cenarioJogo;
fantasma Fantasma1(0.0, 0.4);
fantasma Fantasma2(0.0, 0.6);
fantasma Fantasma3(0.0, 0.8);

void criaQuadradinho(){
	float x = -0.79;
	float y = 0.8;	
	fimQuadradinhos = 0;	
	
	for(int i = 0; i <= 8; i++){
		for(int j = 0; j <= 8; j++){
					
			if((i >= 2 && i <= 6)){
				if((j >= 3 && j <= 5)){
					x += 0.2;
					continue;	
				}				
			}
			
   			if(MovimentoPacMan.verificaMatrizMovimentosPacMan(j, i)){
				cenarioJogo.criaQuadrarinhos(x, y);
				fimQuadradinhos = 1;
			}
			x += 0.2;			
		}
		y -= 0.2;
		x = -0.79;
	}
	
	if(fimQuadradinhos == 0){
        MessageBox(NULL, "FIM DE JOGO", MB_OK);
		PostQuitMessage(0);       	
	}
	
}




int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    

    
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    
    hWnd = CreateWindow (
      "GLSample", "PacMan", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      110, 110, 500, 500,
      NULL, NULL, hInstance, NULL);

    
    EnableOpenGL (hWnd, &hDC, &hRC);

    
    while (!bQuit)
    {
        
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
           
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            
         	
			srand(time(NULL));
			
			escolhaAleatoria = rand() % 4 + 1;    
			
			pacman pc1;
            
            cenarioJogo.setCorLinha(0.0, 0.0, 1.0);
            
        //primeiro quadrado externo
            cenarioJogo.criaLinhaHorizontal(-0.9, 0.9, 0.9, 5);
        	cenarioJogo.criaLinhaVertical(-0.89, 0.89, -0.9, 5);
            cenarioJogo.criaLinhaHorizontal(-0.9, 0.9, -0.89, 5);
            cenarioJogo.criaLinhaVertical(0.89, 0.89, -0.89, 5);
            
        //segundo quadrado externo
            
            //linha esquerda
            cenarioJogo.criaLinhaVertical(-0.7, -0.7, -0.5, 4);
            cenarioJogo.criaLinhaVertical(-0.7, -0.3, 0.31, 4);
            cenarioJogo.criaLinhaVertical(-0.7, 0.51, 0.7, 4);
            
            //linha superior
            cenarioJogo.criaLinhaHorizontal(-0.71, -0.5, 0.7, 4);
            cenarioJogo.criaLinhaHorizontal(-0.3, 0.71, 0.7, 4);
            
            //linha direita
            cenarioJogo.criaLinhaVertical(0.7, -0.7, -0.5, 4);
            cenarioJogo.criaLinhaVertical(0.7, -0.3, 0.31, 4);
            cenarioJogo.criaLinhaVertical(0.7, 0.51, 0.7, 4);
                        
            //linha inferior
            cenarioJogo.criaLinhaHorizontal(-0.71, 0.3, -0.7, 4);
            cenarioJogo.criaLinhaHorizontal(0.5, 0.71, -0.7, 4);
            
        //terceiro quadrado externo
            
            //linha esquerda
            cenarioJogo.criaLinhaVertical(-0.5, -0.5, -0.1, 4);
            cenarioJogo.criaLinhaVertical(-0.5, 0.1, 0.5, 4);
                        
            //linha superior
            cenarioJogo.criaLinhaHorizontal(-0.51, 0.1, 0.5, 4);
            cenarioJogo.criaLinhaHorizontal(0.3, 0.505, 0.5, 4);
            
            //linha direita
            cenarioJogo.criaLinhaVertical(0.5, -0.5, -0.1, 4);
            cenarioJogo.criaLinhaVertical(0.5, 0.1, 0.5, 4);
                                   
            //linha inferior
            cenarioJogo.criaLinhaHorizontal(-0.51, -0.3, -0.5, 4);
            cenarioJogo.criaLinhaHorizontal(-0.1, 0.505, -0.5, 4);
            
        //quadrado interno
        
        	cenarioJogo.criaLinhaVertical(-0.3, -0.3, 0.3, 4);
        	
            cenarioJogo.criaLinhaHorizontal(-0.308, -0.1, 0.3, 4);
            cenarioJogo.criaLinhaHorizontal(0.1, 0.308, 0.3, 4);     
			       
            cenarioJogo.criaLinhaVertical(0.3, -0.3, 0.3, 4);
            
            cenarioJogo.criaLinhaHorizontal(-0.308, 0.308, -0.3, 4);
            
            
        //cria os quadrados
        //if(MovimentoPacMan.verificaMatrizMovimentosPacMan(0, 8)){
        
            criaQuadradinho();
        
    	//}
    	
        //cria o pacman
        	if(blink){
        		pc1.desenhaCirculo(posicaoPacMan[0], posicaoPacMan[1], 0.07f, blink);
        		blink = 0;
        		
        	}else{
        		pc1.desenhaCirculo(posicaoPacMan[0], posicaoPacMan[1], 0.07f, blink);
        		blink = 1;
        	}
        	
        	
        //cria os fantasmas 
        	Fantasma1.desenhaFantasma(1.0f, 0.0f, 0.0f);        	
        	Fantasma2.desenhaFantasma(0.0f, 0.8f, 0.0f);
        	Fantasma3.desenhaFantasma(0.0f, 0.0f, 0.8f);
        	
        	switch(escolhaAleatoria)
			{
				case 1:
					Fantasma1.moveFantasmaCima();
					Fantasma2.moveFantasmaBaixo();
					Fantasma3.moveFantasmaDireita();
					break;
					
				case 2:
					Fantasma1.moveFantasmaBaixo();
					Fantasma2.moveFantasmaDireita();
					Fantasma3.moveFantasmaEsquerda();
					break;
				
				case 3:
					Fantasma1.moveFantasmaDireita();
					Fantasma2.moveFantasmaCima();
					Fantasma3.moveFantasmaBaixo();
					break;
				
        		case 4:
					Fantasma1.moveFantasmaEsquerda();
					Fantasma2.moveFantasmaEsquerda();
					Fantasma3.moveFantasmaCima();
					break;
									
			}
			
			if(MovimentoPacMan.verificaSeEncostou(Fantasma1.retornaPosicaoX(), Fantasma1.retornaPosicaoY(), posicaoPacMan[0], posicaoPacMan[1])){
				
				MessageBox(NULL, "COLIDIU \n TENTAR DE NOVO?", "FIM DE JOGO", MB_OK);
								
				return 0;
			}
			
			if(MovimentoPacMan.verificaSeEncostou(Fantasma2.retornaPosicaoX(), Fantasma2.retornaPosicaoY(), posicaoPacMan[0], posicaoPacMan[1])){
				MessageBox(NULL, "COLIDIU \n TENTAR DE NOVO?", "FIM DE JOGO", MB_OK);
								
				return 0;
			}
        	
        	if(MovimentoPacMan.verificaSeEncostou(Fantasma3.retornaPosicaoX(), Fantasma3.retornaPosicaoY(), posicaoPacMan[0], posicaoPacMan[1])){
				MessageBox(NULL, "COLIDIU \n TENTAR DE NOVO?", "FIM DE JOGO", MB_OK);
								
				return 0;
			}
           
            
            glPopMatrix();
            

            SwapBuffers (hDC);

            
            Sleep (10);
        }
    }

    
    DisableOpenGL (hWnd, hDC, hRC);

    
    DestroyWindow (hWnd);

    return msg.wParam;
}



LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{	
    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
            
        case VK_UP:
        	if(MovimentoPacMan.verificaLimitesCima(posicaoPacMan[0], posicaoPacMan[1])){
        		posicaoPacMan[1] += 0.05;
        		MovimentoPacMan.registraMovimentosPacMan(posicaoPacMan[0], posicaoPacMan[1]);
        	}
        	
        	
				
        	return 0;
		    
		case VK_DOWN:
			
			if(MovimentoPacMan.verificaLimitesBaixo(posicaoPacMan[0], posicaoPacMan[1])){
        		posicaoPacMan[1] -= 0.05;
        		MovimentoPacMan.registraMovimentosPacMan(posicaoPacMan[0], posicaoPacMan[1]);
        	}
        	
        	return 0;
		
		case VK_RIGHT:
			
			if(MovimentoPacMan.verificaLimitesDireita(posicaoPacMan[0], posicaoPacMan[1])){
        		posicaoPacMan[0] += 0.05;
        		MovimentoPacMan.registraMovimentosPacMan(posicaoPacMan[0], posicaoPacMan[1]);
        	}
        	
        	return 0;
			
			
		case VK_LEFT:
			
			if(MovimentoPacMan.verificaLimitesEsquerda(posicaoPacMan[0], posicaoPacMan[1])){
        		posicaoPacMan[0] -= 0.05;
        		MovimentoPacMan.registraMovimentosPacMan(posicaoPacMan[0], posicaoPacMan[1]);
        	}
        	
        	return 0;
		
		
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}




void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    
    *hDC = GetDC (hWnd);

    
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}




void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
