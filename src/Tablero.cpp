#include <climits>
#include <iostream>

struct Movimiento {
    int x, y;
    Movimiento() : x(-1), y(-1) {}
    Movimiento(int x, int y) : x(x), y(y) {}
};

class Tablero {
private:
    int tablero[3][3]; //0:vacio, 1:IA, 2:humano

public:
    Tablero() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                tablero[i][j] = 0;
            }
        }
    }

    void mostrarTablero() {
        std::cout << "\nTablero:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == 1)
                    std::cout << "X ";
                else if (tablero[i][j] == 2)
                    std::cout << "O ";
                else
                    std::cout << "- ";
            }
            std::cout << "\n";
        }
    }

    void limpiarTablero() {
        for (int i = 0; i < 3; ++i) {
        	for (int j = 0; j < 3; ++j) {
        		tablero[i][j] = 0;
        	}
        }
    }

    bool hacerMovimiento(int x, int y, int jugador) {
        if (x < 0 || x >= 3 || y < 0 || y >= 3)
            return false; //fuera de la matriz
        if (tablero[x][y] != 0)
            return false; //casilla ocupada
        tablero[x][y] = jugador;
        return true;
    }

    bool chequearVictoria(int jugador) {
        for (int i = 0; i < 3; ++i) {
        	//verificar filas y columnas
            if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
                (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) {
                return true;
            }
        }
        //diagonales
        if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
            (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
            return true;
        }
        return false;
    }

    bool chequearEmpate() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    void iniciarJuego() {
        while (true) {
            mostrarTablero();
            if (chequearVictoria(1)) {
                std::cout << "La IA gana!" << std::endl;
                break;
            }
            if (chequearVictoria(2)) {
                std::cout << "El jugador gana!!" << std::endl;
                break;
            }
            if (chequearEmpate()) {
                std::cout << "Es un empate!" << std::endl;
                break;
            }

            Movimiento movimiento = minimax(9, INT_MIN, INT_MAX, true);
            hacerMovimiento(movimiento.x, movimiento.y, 1);

            mostrarTablero();

            if (chequearVictoria(1)) {
                std::cout << "La IA gana!" << std::endl;
                break;
            }
            if (chequearEmpate()) {
                std::cout << "Es un empate!" << std::endl;
                break;
            }

            //turno jugador
            int x, y;
            bool movimientoValido;
            do {
                std::cout << "Tu turno\nIngresa fila y columna (0-2): Fila: ";
                std::cin >> x;
                std::cout << "Columna: ";
                std::cin >> y;
                movimientoValido = hacerMovimiento(x, y, 2);
                if (!movimientoValido)
                    std::cerr << "Movimiento invalido intenta nuevamente.\n";
            } while (!movimientoValido);

            if (chequearVictoria(2)) {
                mostrarTablero();
                std::cout << "El jugador gana!!" << std::endl;
                break;
            }
            if (chequearEmpate()) {
                mostrarTablero();
                std::cout << "Es un empate!" << std::endl;
                break;
            }
        }
    }

    void iniciarJuego2J() {
            int jugadorActual = 1;
            while (true) {
                mostrarTablero();

                // Verificar si hay un ganador o empate antes de cada turno
                if (chequearVictoria(1)) {
                    std::cout << "Jugador 1 (X) gana!" << std::endl;
                    break;
                }
                if (chequearVictoria(2)) {
                    std::cout << "Jugador 2 (O) gana!" << std::endl;
                    break;
                }
                if (chequearEmpate()) {
                    std::cout << "Es un empate!" << std::endl;
                    break;
                }

                int x, y;
                bool movimientoValido;
                do {
                    std::cout << "Turno del jugador " << jugadorActual
                              << (jugadorActual == 1 ? " (X)" : " (O)") << ".\n";
                    std::cout << "Ingresa fila y columna (0-2): Fila: ";
                    std::cin >> x;
                    std::cout << "Columna: ";
                    std::cin >> y;
                    movimientoValido = hacerMovimiento(x, y, jugadorActual);
                    if (!movimientoValido)
                        std::cout << "Movimiento invalido intenta nuevamente.\n";
                } while (!movimientoValido);

                //cambiar turno al otro jugador
                jugadorActual = (jugadorActual == 1) ? 2 : 1;
            }
        }

private:
    Movimiento minimax(int profundidad, int alfa, int beta, bool esMaximizador) {
        Movimiento mejorMovimiento;
        int mejorPuntaje = (esMaximizador) ? INT_MIN : INT_MAX;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == 0) { // Espacio vacío
                    tablero[i][j] = esMaximizador ? 1 : 2;

                    int puntaje = minimaxRecursivo(profundidad - 1, alfa, beta, !esMaximizador);

                    tablero[i][j] = 0; //deshacer movimiento

                    if ((esMaximizador && puntaje > mejorPuntaje) ||
                        (!esMaximizador && puntaje < mejorPuntaje)) {
                        mejorPuntaje = puntaje;
                        mejorMovimiento = Movimiento(i, j);
                    }

                    //poda alfa-beta
                    if (esMaximizador) {
                        alfa = std::max(alfa, mejorPuntaje);
                    } else {
                        beta = std::min(beta, mejorPuntaje);
                    }

                    if (alfa >= beta)
                        break;
                }
            }
        }

        return mejorMovimiento;
    }

    int minimaxRecursivo(int profundidad, int alfa, int beta, bool esMaximizador) {
        int puntaje = evaluarTablero();
        if (puntaje != 0 || profundidad == 0 || chequearEmpate()) {
            return puntaje;
        }

        int mejorPuntaje = esMaximizador ? INT_MIN : INT_MAX;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == 0) {
                    tablero[i][j] = esMaximizador ? 1 : 2;

                    int puntajeMovimiento = minimaxRecursivo(profundidad - 1, alfa, beta, !esMaximizador);
                    tablero[i][j] = 0;

                    if (esMaximizador) {
                        mejorPuntaje = std::max(mejorPuntaje, puntajeMovimiento);
                        alfa = std::max(alfa, mejorPuntaje);
                    } else {
                        mejorPuntaje = std::min(mejorPuntaje, puntajeMovimiento);
                        beta = std::min(beta, mejorPuntaje);
                    }

                    if (alfa >= beta)
                        break;
                }
            }
        }

        return mejorPuntaje;
    }

    int evaluarTablero() {
        if (chequearVictoria(1))
            return 10;
        if (chequearVictoria(2))
            return -10;
        return 0;
    }



};
