#include <iostream>
#include <functional>

int main() {
    int a = 0, b = 0, c = 0, d;
    [&](int x){a=++b+a;}(4);
    std::cout << a << "\n" << b;

    // const std::function<int(int)> factorial = [&factorial](int n){
    //     return n > 1 ? n * factorial(n-1):1;
    // };

    // std::cout << "\n" <<factorial(5);
    
    const auto factorial = [](int n){
        const auto factorial_1 = [](int n, const auto& val)->int{
            return n>1? n * val(n-1, val):1;
        };
        return factorial_1(n, factorial_1);
    };
    std::cout << "\n" << factorial(5);
    return 0;
}
