Mauricio Díaz 21227728-2 
# Como compilar
g++ src/main.cpp src/Tablero.cpp

./a.out

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

Para esta Implementación de tic-tac-toe:
+10: Si gana el jugador MAX (en este caso, IA usando 'X').
-10: Si gana el jugador MIN (en este caso, el jugador humano usando 'O').
0: Si hay empate.

### Poda Alfa-Beta
La poda alfa-beta mejora Minimax al evitar la exploración de ramas del árbol que no influyen en el resultado final, usa dos límites:

* Alfa: El mejor valor que MAX puede garantizar hasta ahora.
* Beta: El mejor valor que MIN puede garantizar hasta ahora.

# 2) Implementación de MiniMax en TicTacToe
![alt text](https://media.geeksforgeeks.org/wp-content/uploads/TIC_TAC.jpg)
En la imagen, se muestra un árbol de juego que utiliza el algoritmo MiniMax:
* Cada nodo representa un estado del tablero tras una jugada
* En la raíz, es el turno de "Max" (IA), y tiene 3 opciones de movimiento
* Los nodos terminales representan los estados finales de la partida, es decir, empate, victoria de X o victoria de O
* El algoritmo prueba con todos los posibles movimientos, si los movimientos no resultan en un estado de fin de partida, el algoritmo se llama recursivamente para seguir probando diferentes movimientos
* Si encuentra un estado terminal, se devolverá un puntaje dependiendo si es victoria o empate, en el caso de la imagen: 
    * si X gana, +10
    * si O gana, -10
    * si hay empate, 0
* La poda alfa-beta se implementa creando variables que guarden ciertos valores:
    * Alfa: Es el valor máximo que "Max" garantiza en el camino actual
    * Beta: Es el valor mínimo que "Min" garantiza en el camino actual
* Si un nodo tiene un valor peor que el valor de poda (alfa o beta), se descarta (no se evalúan sus hijos). Esto ahorra tiempo al evitar ramas que no influirán en la decisión final
* Al terminar la recursion, el nodo raíz contiene el mejor movimiento para "Max", que será seleccionado como su jugada.

# 3) Analisis de complejidad temporal
### Sin poda alfa-beta
* El árbol de juego tiene una complejidad de O(b^d), donde:
    * b: Número promedio de movimientos por turno (hasta 9 en tic-tac-toe)
    * d: Profundidad máxima del árbol (9 en tic-tac-toe)
* En el caso del tic-tac-toe, la complejidad sin poda sería de O(9!)

### Con poda alfa-beta
* La poda reduce el número de nodos explorados, optimizando el tiempo
* La poda reduce la complejidad a O(b^d/2) en el mejor caso.



