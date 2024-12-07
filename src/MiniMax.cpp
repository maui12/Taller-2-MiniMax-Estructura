#pragma once
#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include "Tablero.cpp"

using namespace std;

class Minimax {
private:
    Tablero tablero;

public:
    Minimax(const Tablero& t) : tablero(t) { }

    pair<int, int> calcularMejorMovimiento() {
        int mejorValor = numeric_limits<int>::min();
        pair<int, int> mejorJugada = {-1, -1};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero.movimientoValido(i, j)) {
                    tablero.realizarMovimiento(i, j, 'X');
                    int valor = minimax(false, numeric_limits<int>::min(), numeric_limits<int>::max());
                    tablero.realizarMovimiento(i, j, ' ');
                    if (valor > mejorValor) {
                        mejorValor = valor;
                        mejorJugada = {i, j};
                    }


                }
            }

        }

        return mejorJugada;
    }

private:
    int minimax(bool esMax, int alfa, int beta) {
        if (tablero.verificarVictoria('X')) return 10;
        if (tablero.verificarVictoria('O')) return -10;
        if (tablero.lleno()) return 0;

        if (esMax) {
            int mejor = numeric_limits<int>::min();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tablero.movimientoValido(i, j)) {
                        tablero.realizarMovimiento(i, j, 'X');
                        mejor = max(mejor, minimax(false, alfa, beta));
                        tablero.realizarMovimiento(i, j, ' ');
                        alfa = max(alfa, mejor);
                        if (beta <= alfa) break;
                    }
                }
            }
            return mejor;
        } else {
            int peor = numeric_limits<int>::max();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tablero.movimientoValido(i, j)) {
                        tablero.realizarMovimiento(i, j, 'O');
                        peor = min(peor, minimax(true, alfa, beta));
                        tablero.realizarMovimiento(i, j, ' ');
                        beta = min(beta, peor);
                        if (beta <= alfa) break;
                    }

                }
            }
            return peor;
        }
    }
};
