# Tic Tac Toe Game

Este repositório contém a implementação de um jogo da velha em C++ usando a biblioteca wxWidgets para criar uma interface gráfica. O código fornece uma interface simples e funcional para jogar o jogo da velha entre dois jogadores humanos.

## Código

O código consiste em funções para inicializar o tabuleiro, verificar o status do tabuleiro e identificar o vencedor, além de uma classe `ticTacToe` que herda de `wxApp` e uma classe `MainFrame` que herda de `wxFrame`.

### Funções

As funções `initBoard()` e `checkBoard()` são responsáveis por inicializar o tabuleiro e verificar se há um vencedor, respectivamente.

### Classe ticTacToe

A classe `ticTacToe` herda de `wxApp` e implementa o método `OnInit()` para criar e exibir a janela principal do jogo.

### Classe MainFrame

A classe `MainFrame` herda de `wxFrame` e contém a implementação da interface gráfica, incluindo botões para cada célula do tabuleiro, menus e uma barra de status.

Métodos como `OnNewGame()`, `OnExit()`, `OnAbout()`, `EnableGrid()`, `DisableGrid()` e `EndGame()` são responsáveis pelo controle do jogo e eventos relacionados aos menus e botões.

Os métodos `OnBtnTopLeftClick()`, `OnBtnTopMidClick()`, `OnBtnTopRightClick()`, `OnBtnMidLeftClick()`, `OnBtnMidMidClick()`, `OnBtnMidRightClick()`, `OnBtnLowLeftClick()`, `OnBtnLowMidClick()` e `OnBtnLowRightClick()` são responsáveis por lidar com os eventos de clique nos botões do tabuleiro.

# Como Contribuir
- Faça um fork do repositório.
- Crie uma branch com as suas alterações.
- Faça um pull request para a branch principal.
- Agradeço a sua contribuição para este projeto!
