# Algoritmo MiniMax con poda alfa-beta - Taller 2 Estructura de datos

 Este proyecto implementa el juego del gato(Tic-Tac-Toe) en C++, utilizando el algoritmo Minimax con poda alfa-beta 
 
 Incluye un modo de 1 jugador contra IA, además de un modo para dos jugadores.

 # 1) Explicación teórica: 
 ### MiniMax
El algoritmo Minimax es un algoritmo utilizado en teoría de juegos para encontrar la decisión óptima en juegos de dos jugadores con información perfecta (ambos jugadores conocen el estado del juego en todo momento) y de suma cero (lo que un jugador gana, el otro lo pierde). El objetivo del algoritmo puede resumirse en: elegir el mejor movimiento para ti mismo suponiendo que tu contrincante escogerá el peor movimiento para ti.

En Programación, este algoritmo se representa con árboles, donde sus nodos representan diferentes estados del juego, y el nivel donde se ubican representan de que jugador pertenecen los estados, los niveles pares son de un jugador, mientras que los impares corresponden al otro jugador.

### Poda alfa-beta
Es una técnica que se aplica en el algoritmo Minimax que reduce la cantidad de nodos evaluados en el árbol de decisiones, sin alterar el resultado final.

## Cómo funciona

El algoritmo Minimax asume que:

* Un jugador se representa como MAX, debido a que busca maximizar la puntuación del juego.
* El otro jugador (MIN) busca minimizarla.

El algoritmo recorre un árbol de posibles decisiones de manera recursiva y evalúa cada nodo:

* Si es el turno del jugador MAX, selecciona el valor máximo posible entre las opciones.
* Si es el turno del jugador MIN, selecciona el valor mínimo.

### Evaluación del tablero:

Se utiliza una función de evaluación que le permite al algoritmo Minimax decidir qué movimientos son los más beneficiosos para el jugador(en este caso, la IA).

+10: Si gana el jugador MAX (en este caso, IA usando 'X').
-10: Si gana el jugador MIN (en este caso, el jugador humano usando 'O').
0: Si hay empate.

### Poda Alfa-Beta
La poda alfa-beta mejora Minimax al evitar la exploración de ramas del árbol que no influyen en el resultado final, usa dos límites:

* Alfa: El mejor valor que MAX puede garantizar hasta ahora.
* Beta: El mejor valor que MIN puede garantizar hasta ahora.

# 2) Implementación de MiniMax en TicTacToe
