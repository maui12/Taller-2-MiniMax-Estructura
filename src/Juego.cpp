#pragma once
#include <iostream>
#include <limits>
#include <utility>
#include "Tablero.cpp"
#include "MiniMax.cpp"

class Juego {
private:
    Tablero tablero;
    char turnoActual;
public:
    Juego() : turnoActual('O') {}

    void jugarContraIA() {
        while (true) {
            tablero.imprimir();

            if (turnoActual == 'O') {
                turnoHumano();
            } else {
                turnoIA();
            }

            if (tablero.verificarVictoria(turnoActual)) {
                tablero.imprimir();
                cout << "¡" << (turnoActual == 'O' ? "Jugador" : "IA") << " gana!" << endl;
                break;
            } else if (tablero.lleno()) {
                tablero.imprimir();
                cout << "¡Es un empate!" << endl;
                break;
            }

            cambiarTurno();
        }
    }


    void jugarDosJugadores() {
        while (true) {
            tablero.imprimir();
            cout << "Turno del jugador " << (turnoActual == 'O' ? "1 (O)" : "2 (X)") << endl;
            turnoHumano();

            if (tablero.verificarVictoria(turnoActual)) {
                tablero.imprimir();
                cout << "¡El jugador " << (turnoActual == 'O' ? "1 (O)" : "2 (X)") << " gana!" << endl;
                break;
            } else if (tablero.lleno()) {
                tablero.imprimir();
                cout << "¡Es un empate!" << endl;
                break;
            }

            cambiarTurno();
        }
    }
private:
    void turnoHumano() {
        int fila, columna;
        do {
            cout << "Ingresa tu movimiento (fila y columna): ";
            cin >> fila >> columna;
        } while (!tablero.movimientoValido(fila, columna));
        tablero.realizarMovimiento(fila, columna, turnoActual);
    }

    void turnoIA() {
        Minimax minimax(tablero);
        pair<int, int> mejorMovimiento = minimax.calcularMejorMovimiento();
        tablero.realizarMovimiento(mejorMovimiento.first, mejorMovimiento.second, 'X');
    }
    void cambiarTurno() {
        turnoActual = (turnoActual == 'O') ? 'X' : 'O';
    }
};