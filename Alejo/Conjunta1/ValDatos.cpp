/*#include "ValDatos.h"
#include <cstdlib>
#include <conio.h>

int ValidarDatos::generarCodigo(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(10000, 99999);

	return dis(gen);
}

// int ValidarDatos::generarCodigoValidado(ListaProducto lista){
// 	Nodo *tmp = lista.getPrimero();

// 	int codigo = ValidarDatos::generarCodigo();

// 	while(tmp){
// 		if(tmp->getProducto().getCodigo() == codigo){
// 			codigo = ValidarDatos::generarCodigo();
// 			tmp = lista.getPrimero();
// 		}
// 		else{
// 			tmp = tmp->getSiguiente();
// 		}
// 	}

//     return codigo;
// }

int ValidarDatos::validarEnteroMenu() {		
	char entrada;
	char tecla;
    while (true) {
        tecla = getch();
        
        if (tecla == '\r') {
            std::cout << std::endl;
            break;
        } else if (tecla == '\b') {
            if (entrada) {
                std::cout << "\b \b";
                entrada = '\0';
            }
        } else if (isdigit(tecla) && !entrada) {
            entrada = tecla;
            std::cout << tecla;
        }
    }
    
    if (entrada) {
        int numero = entrada - '0';
		if (numero >= 1 || numero <= 5)
		{
			return numero;
		}
		
    } else {
        return -1;
    }
	return 1;
}

int ValidarDatos::validarEntero() {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); 
		
		if (tecla == '\r') { 
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { 
			i--;						
			std::cout << "\b \b"; 
			entrada[i] = 0; 
		} else if (isdigit(tecla) && i<12) {
			  entrada[i++] = tecla;
			  std::cout << tecla; 
		}
	}

	return atoi(entrada); 
}


float ValidarDatos::validarFloat() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tecla = getch();
		
		if (tecla == '\r') { 
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { 		
			i--;						
			std::cout << "\b \b";
			if (entrada[i] == '.') { 
				punto = false;
			}
			if (i == signoMenosPos) { 
				signoMenosPos = -1;
			}
			entrada[i] = 0; 
		} else if (isdigit(tecla) && i < 15) {
			  entrada[i++] = tecla;
			  std::cout << tecla;
		} else if (tecla == '.' && !punto) {
			  entrada[i++] = tecla;
			  punto = true;
			  std::cout << tecla;
		} else if (tecla == '-' && i == 0) {
			  entrada[i++] = tecla;
			  signoMenosPos = i - 1;
			  std::cout << tecla;
		}
	}

	return atof(entrada);
  
}

// std::string validarString() {
//     std::string entrada;
//     char tecla;

//     while (true) {
        
// 		tecla = getch();

//         if (tecla == '\r') {
//             std::cout << std::endl;
//             break;
//         } else if (tecla == '\b' && !entrada.empty()) {
//             entrada.pop_back();
//             std::cout << "\b \b";
//         } else if (std::isalpha(tecla) || std::isspace(tecla)) {
//             entrada += tecla;
//             std::cout << tecla;
//         }
//     }

//     return entrada;
// }*/