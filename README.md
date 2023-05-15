# Tic Tac Toe Game em C++ com wxWidgets

Este repositório contém a implementação de um jogo da velha em C++ usando a biblioteca wxWidgets para criar uma interface gráfica. O código fornece uma interface simples e funcional para jogar o jogo da velha entre dois jogadores humanos.O código foi instruído pelo professor @pietromartinso. 

## Regras do jogo

1. O jogador 1 escolhe "X" e o jogador 2 escolhe "O".
2. Os jogadores se revezam colocando suas marcas em uma grade 3x3.
3. O objetivo é criar uma linha reta de três marcas na horizontal, na vertical ou na diagonal.
4. O jogo termina quando um dos jogadores atingir esse objetivo, ou todas as posições do tabuleiro forem ocupadas, resultando em empate.

## Visão geral do código

O código inicializa o tabuleiro do jogo, gerencia o estado do jogo e manipula a interface do usuário usando wxWidgets. As principais funções são `initBoard()` para inicializar o tabuleiro e `checkBoard()` para verificar o estado atual do tabuleiro para determinar se há um vencedor ou um empate. O programa também inclui manipuladores de eventos para cliques de botão e ações de menu, habilitando ou desabilitando a grade e gerenciando o final do jogo.
A classe `ticTacToe` herda de `wxApp` e é responsável por inicializar a janela principal do jogo. A classe `MainFrame` herda de `wxFrame` e manipula os elementos da interface do usuário, como botões e menus.

## Créditos

Essa implementação do Tic Tac Toe foi instruída pelo professor @pietromartinso.

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
