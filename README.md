# Algoritmo MiniMax con poda alfa-beta - Taller 2 Estructura de datos

 Este proyecto implementa el juego del gato(Tic-Tac-Toe) en C++, utilizando el algoritmo Minimax con poda alfa-beta 
 
 Incluye un modo de 1 jugador contra IA, además de un modo para dos jugadores.

 # Explicación teórica: 
 ## MiniMax
El algoritmo Minimax es un algoritmo utilizado en teoría de juegos para encontrar la decisión óptima en juegos de dos jugadores con información perfecta (ambos jugadores conocen el estado del juego en todo momento) y de suma cero (lo que un jugador gana, el otro lo pierde). El objetivo del algoritmo puede resumirse en: elegir el mejor movimiento para ti mismo suponiendo que tu contrincante escogerá el peor movimiento para ti.

En Programación, este algoritmo se representa con árboles, donde sus nodos representan diferentes estados del juego, y el nivel donde se ubican representan de que jugador pertenecen los estados, los niveles pares son de un jugador, mientras que los impares corresponden al otro jugador.

## Poda alfa-beta
Es una técnica que se aplica en el algoritmo Minimax que reduce la cantidad de nodos evaluados en el árbol de decisiones, sin alterar el resultado final.

# Como funciona

