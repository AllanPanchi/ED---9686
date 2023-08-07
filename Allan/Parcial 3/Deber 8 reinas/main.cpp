#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

#define N 8

int *board;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void drawBoard() {
    cleardevice();
    int cellSize = 40;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 2 == 0) {
                setfillstyle(SOLID_FILL, WHITE);
            } else {
                setfillstyle(SOLID_FILL, BLACK);
            }
            bar(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
        }
    }

    for (int i = 0; i < N; i++) {
        setfillstyle(SOLID_FILL, RED);
        fillellipse((board[i] + 0.5) * cellSize, (i + 0.5) * cellSize, cellSize / 2 - 5, cellSize / 2 - 5);
    }

    delay(500); // Pequeño retraso para ver el tablero dibujado
}

void solveNQueens() {
    board = new int[N];
    for (int i = 0; i < N; i++) {
        board[i] = i;
    }

    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(board[i], board[j]);
    }

    for (int row = 0; row < N; row++) {
        if (!isSafe(row, board[row])) {
            solveNQueens(); // Si la solución no es válida, intentamos de nuevo
        	break;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    srand(static_cast<unsigned int>(time(0))); // Semilla para obtener diferentes soluciones en cada ejecución

    char c;
    do {
        solveNQueens();
        drawBoard();
        c = getch();
    } while (c != 27); // Presionar ESC para salir

    closegraph();
    delete[] board;
    return 0;
}

