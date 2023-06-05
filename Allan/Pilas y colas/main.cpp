//pilas
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> pila;
    queue<int> cola;


    pila.push(10);
    pila.push(20);
    pila.push(30);

    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }

//colas
    cola.push(10);
    cola.push(20);
    cola.push(30);

    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }

    return 0;
}
