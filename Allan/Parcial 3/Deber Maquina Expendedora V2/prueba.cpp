#include <iostream>
#include <string>

std::string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
std::string especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
std::string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
std::string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

std::string transformarNumerosALetras(float numero) {
    int parte_entera = static_cast<int>(numero);
    int parte_decimal = static_cast<int>((numero - parte_entera) * 100);

    std::string resultado;

    if (parte_entera < 0 || parte_entera >= 1000000) {
        return "Número fuera de rango";
    }

    if (parte_entera == 1000000) {
        return "un millón";
    }

    if (parte_entera >= 1000) {
        int miles = parte_entera / 1000;
        parte_entera %= 1000;

        if (miles == 1) {
            resultado += "mil ";
        } else {
            resultado += unidades[miles] + " mil ";
        }
    }

    if (parte_entera >= 100) {
        int centena = parte_entera / 100;
        parte_entera %= 100;

        resultado += centenas[centena] + " ";
    }

    if (parte_entera >= 20) {
        int decena = parte_entera / 10;
        int unidad = parte_entera % 10;

        resultado += decenas[decena] + " ";

        if (unidad > 0) {
            resultado += "y " + unidades[unidad] + " ";
        }
    } else if (parte_entera >= 10) {
        resultado += especiales[parte_entera - 10] + " ";
    } else if (parte_entera > 0) {
        resultado += unidades[parte_entera] + " ";
    }

    if (parte_decimal > 0) {
        resultado += "con " + unidades[parte_decimal / 10] + " y " + unidades[parte_decimal % 10];
    }

    return resultado;
}

int main() {
    float numero;
    std::cout << "Ingrese un numero: ";
    std::cin >> numero;
    std::string numeroEnLetras = transformarNumerosALetras(numero);
    std::cout << numero << " se escribe como: " << numeroEnLetras << std::endl;

    return 0;
}
