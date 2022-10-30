# pacman

O seguinte projeto tem como objetivo a elaboração de uma adaptação do jogo Pacman. Para tal o
programa foi escrito em C++ e seguindo a elaboração vista em aula. A movimentação do jogador é
feito na entrada do programa, dada pelas teclas de seta para cima/baixo e esquerda/direita. Na saída
do jogo, temos o mapa com caracteres representando seus elementos da seguinte forma: a paredes,
os quadrados referentes aos fantasmas e o Pacman.
## 2. Estrutura do programa
### 2.1. Classe Main
A classe Main, possui uma variável chamada cenario. Ela é usada para chamar o método
responsável por iniciar o jogo.
#### 2.2.1. Classe Movimento
A classe movimento é responsável por inicializar o movimentos entre os fantasmas e o Pacman
dentro do cenário do jogo, se o fantasma e o Pacman encostaram, definindo a movimentação e
distâncias entres eles:
• primeiro corredor da direita (contado de fora pra dentro)
• segundo corredor da direita (contado de fora pra dentro)
• terceiro corredor da direita (contado de fora pra dentro)
• quarto corredor da direita (contado de fora pra dentro)
• corredor central vertical (contado de fora pra dentro)
• quarto corredor da esquerda (contado de fora pra dentro)
• terceiro corredor da esquerda (contado de fora pra dentro)
• segundo corredor da esquerda (contado de fora pra dentro)
• primeiro corredor da esquerda (contado de fora pra dentro)
## 3. Visão do Jogo

![image](https://user-images.githubusercontent.com/3688799/198891164-3da22204-8dd1-448e-92bb-ba3109aebd13.png)

## 4. Classe Cenário
O labirinto possui todos os objetos contidos no mapa, como os fantasmas, o jogador e as pastilhas.
Além disso, o labirinto possui um tamanho (largura e altura). O método desenhaFantasma verifica
se o jogador cruzou com algum fantasma, se ele cruzar há a chamada para o método moveFantasma
que recebe o fantasma e testa se o mesmo está ativo ou não. Caso ele esteja ativo, o jogador perde
uma vida e todos retornam às posições iniciais. Os fantasmas a cada movimento do jogador, dessa
forma o labirinto altera a posição dos fantasmas quando o jogador se move. Além disso, caso o
jogador conquiste todas as pastilhas.
## 5. Classe Fantasma
Desenha os fantasmas, suas posições no jogo e seus limites de distâncias entre eles e o Pacman.
## 6. Pacman
Define as cores e trata a colisão.
