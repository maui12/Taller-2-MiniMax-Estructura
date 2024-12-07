#include <iostream>
#include "Juego.cpp"
using namespace std;

int main() {
    Juego juego;
    int opcion;
    do {
		cout << "Bienvenido al juego del gato.\n";
		cout << "1) Jugar contra la IA\n";
		cout << "2) Jugar modo dos jugadores\n";
		cout << "3) Salir\n";
		cout << "Selecciona una opción: ";
		cin >> opcion;

		if (opcion == 1) {
			juego.jugarContraIA();
		} else if (opcion == 2) {
			juego.jugarDosJugadores();
		}
    }
    while(opcion!=3);

	cout << "Saliendo del juego  ";

    return 0;
}
