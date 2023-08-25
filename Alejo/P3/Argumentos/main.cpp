#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);

    std::cout << argv[1] << " + " << argv[2] << " = " << (a+b) << std::endl;
    return 0;
}