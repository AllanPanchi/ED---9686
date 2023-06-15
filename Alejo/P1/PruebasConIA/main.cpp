#include <iostream>
#include <functional>

int main() {
    int n;
    std::cout << "Ingrese el numero de veces que desea calcular la secuencia de Fibonacci: ";
    std::cin >> n;

    std::function<int(int)> fibonacci = [&](int num) {
        if (num <= 1)
            return num;
        else
            return fibonacci(num - 1) + fibonacci(num - 2);
    };

    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}
