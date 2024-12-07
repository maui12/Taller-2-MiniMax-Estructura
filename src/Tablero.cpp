#pragma once
#include <iostream>

class Tablero {
private:
    char tablero[3][3];

public:
    Tablero() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tablero[i][j] = ' ';
    }

    void imprimir() const {
        std::cout << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
            	std::cout << tablero[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "--|---|--" << std::endl;
        }
        std::cout << std::endl;
    }

    bool movimientoValido(int fila, int columna) const {
        return fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ';
    }

    void realizarMovimiento(int fila, int columna, char jugador) {
        if (movimientoValido(fila, columna)) {
            tablero[fila][columna] = jugador;
        }
    }

    char obtenerCelda(int fila, int columna) const {
        return tablero[fila][columna];
    }

    bool lleno() const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (tablero[i][j] == ' ') return false;
        return true;
    }

    bool verificarVictoria(char jugador) const {
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            	return true;
            }
            if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
            	return true;
            }

        }
        if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        	return true;
        }
        if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        	return true;
        }
        return false;
    }
};
