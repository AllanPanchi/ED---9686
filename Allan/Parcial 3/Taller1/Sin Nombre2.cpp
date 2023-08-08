#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int ladoCasilla = 60;
const int margen = 50;
const int n = 8;

struct Peon {
    int fila;
    int columna;
};

bool seAmenazan(const Peon& peon1, const Peon& peon2) {
    return (peon1.fila == peon2.fila && peon1.columna == peon2.columna);
}

void dibujarTablero() {
    int filaAleatoria, columnaAleatoria;
    Peon peones[4];

    initwindow(8 * ladoCasilla + 2 * margen, 8 * ladoCasilla + 2 * margen);
    srand(time(0));

    for (int i = 0; i < 4; i++) {
        filaAleatoria = rand() % n;
        columnaAleatoria = rand() % n;
        peones[i] = {filaAleatoria, columnaAleatoria};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = margen + j * ladoCasilla;
                int y = margen + i * ladoCasilla;

                if ((i + j) % 2 == 0) { // Alternar color de casillas
                    setfillstyle(SOLID_FILL, WHITE);
                } else {
                    setfillstyle(SOLID_FILL, BLACK);
                }

                bar(x, y, x + ladoCasilla, y + ladoCasilla);

                if (i == filaAleatoria && j == columnaAleatoria) {
                    int radio = ladoCasilla / 3;
                    int centroX = x + ladoCasilla / 2;
                    int centroY = y + ladoCasilla / 2;
                    setfillstyle(SOLID_FILL, RED);
                    fillellipse(centroX, centroY, radio, radio);
                }
            }
        }
    }

    bool amenaza = false;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (seAmenazan(peones[i], peones[j])) {
                amenaza = true;
                break;
            }
        }
        if (amenaza) {
            break;
        }
    }

    if (amenaza) {
        cout << "Al menos dos peones se amenazan mutuamente." << endl;
    } else {
        cout << "Los peones no se amenazan entre sí." << endl;
    }

    delay(5000);
    closegraph();
}

int main() {
    dibujarTablero();
    return 0;
}

