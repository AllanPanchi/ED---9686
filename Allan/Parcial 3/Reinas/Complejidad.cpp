#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int myFunction(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result++;
        }
    }
    return result;
}

int main() {
    int n = 1000;
    auto start = high_resolution_clock::now();
    int result = myFunction(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Resultado: " << result << endl;
    cout << "Duracion: " << duration.count() << " microsegundos" << endl;
    return 0;
}
