/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		-Luis Burbano
        -Mateo Condor
        -Camila Morales
        -Ricardo Rivadeneira
        -Steven Pozo
        -Jairo Quilumbaquin
        -Edwin Cantuña

	FECHA DE CREACION:
		26/12/2022       	
	FECHA DE MODIFICACION:
		05/01/2023
*/

#include "Prefijo.cpp"
#include "Postfijo.cpp"

using namespace std;

int main(){

    try{

        Operaciones op;
        Prefijo pr;
        Postfijo ps;

        Pila<string> datos;
        datos = op.ingresarDatos();

        if (op.validarExpresion(datos)) {

            Pila<string> prefija;
            Pila<string> postfija;

            prefija = pr.infijaPrefija(datos);
            cout << "\nExpresion Prefija:   ";
            prefija.mostrarNotacion();

            postfija = ps.infijaSufija(datos);
            cout << "\nExpresion Sufija:   ";
            postfija.mostrarNotacion();
            cout << "\nResultado:   ";
            cout << op.calcular(prefija) << endl;
        }
        else {
            cout << "ERROR" << endl;
        }

    }
    catch (const std::exception&){
        cout << "Error" << endl;

    }
}