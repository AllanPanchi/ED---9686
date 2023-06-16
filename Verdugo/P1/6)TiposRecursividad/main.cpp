#include <iostream>
#include <functional>

int main() {
    // int a = 0;
    // int b = 0;
    
    // [&](int x){a=++b+x;}(4);
    // std::cout << a << "\n" << b << std::endl;

    // const std::function<int(int)> factorial = [&](int n) {
    //     return n > 1 ? n * factorial(n - 1) : 1;
    // };

    
    const auto factorial = [](int n, const auto& val) -> int {
        return n > 1 ? n * val(n - 1, val) : 1;
    };

    std::cout << factorial(5, factorial) << std::endl;

    const auto fibonacci = [](int i, int n, int anterior, int actual, const auto& val) -> void{
        if (i == 0)
        {
            std::cout << "0 ";
            i = 2;
            anterior = 0;
            actual = 1;
        }
        
        if(i <= n)
        {
            std::cout << actual << " ";
            i++;
            val(i, n, actual, anterior + actual, val);
        }
    };

    fibonacci(0, 20, 0, 0, fibonacci);

    return 0;
}