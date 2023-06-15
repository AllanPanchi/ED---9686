#include <iostream>
#include "tda1.cpp"
#include "tda2.cpp"

int main(int argc, char const *argv[])
{
    TDA1 tda1(1, 2);
    TDA2 tda2(tda1, 3);

    return 0;
}