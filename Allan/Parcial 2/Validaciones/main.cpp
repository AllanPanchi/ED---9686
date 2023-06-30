#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>

bool validarCedulaEcuatoriana() {
    std::string cedula;
    char tecla;

    while (true) {
        tecla = getch();

        if (tecla == '\r') {
            std::cout << std::endl;
            break;
        } else if (tecla == '\b' && !cedula.empty()) {
            cedula.pop_back();
            std::cout << "\b \b";
        } else if (std::isdigit(tecla) && cedula.length() < 10) {
            cedula += tecla;
            std::cout << tecla;
        }
    }

    if (cedula.length() == 10) {
        // Validar la cédula según las reglas ecuatorianas
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            int digit = cedula[i] - '0';
            if (i % 2 == 0) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            }
            sum += digit;
        }

        int checksum = (sum % 10 == 0) ? 0 : (10 - sum % 10);
        int lastDigit = cedula[9] - '0';

        if (checksum == lastDigit) {
            std::cout << "Cedula valida." << std::endl;
            return true;
        } else {
            std::cout << "Cedula invalida." << std::endl;
            return false;
        }
    } else {
        std::cout << "Cedula invalida." << std::endl;
        return false;
    }
}

int main() {
    std::cout << "Ingrese el numero de cedula: ";
    while(!validarCedulaEcuatoriana()){
        std::cout << "Ingrese la cedula nuevamente" << std::endl;
        validarCedulaEcuatoriana();
    };

    return 0;
}
