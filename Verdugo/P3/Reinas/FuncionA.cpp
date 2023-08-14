/***********************************************************************
 * Module:  Tablero.cpp
 * Author:  Jeimy Morales y Orrico Camilo
 * Modified: Martes, 7  de febrero de 2023 18:19:30
 * Purpose: Implementation of the class CuboMagico
 ***********************************************************************/

#include "FuncionA.h"
#include <windows.h>
#include <graphics.h>
#include "lineas.h"
void FuncionA::encerarTablero(){
		dibujarBigOExponecialAzul();
	for(int i=0;i<MAX;i++){
		this->alfil->validar[i]=new bool[MAX];
		this->alfil->tablero[i]=new char[MAX];
		for(int j=0;j<MAX;j++){
			*(*(this->alfil->validar+i)+j)=false;
			*(*(this->alfil->tablero+i)+j)='*';
			}
	}	
}
void FuncionA::crearArchivo(){
	LineaA();
	cout<<"Archivo"<<endl;
	this->archivo.open("exaustivoAlfiles.txt",fstream::out);
	this->archivo<<"solucion"<<this->alfil->n<<"*"<<this->alfil->n<<endl<<endl;
	this->alfil->contador=0;
}


void FuncionA::bloquearAlfiles(int x, int y){
	int aux1,aux2;
	dibujarBigOExponecialAzul();
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	while(aux1>=0 && aux2<MAX){
		*(*(this->alfil->validar+aux1)+aux2)=true;
		aux1++;
		aux2++;
		//cout<<"  diagonal "<<aux1<<" "<<aux2<<endl;
	}
	aux2=y;
	aux1=x;
	while(aux1<MAX && aux2>0){
		aux1++;
		aux2--;
	}
	if (aux1<8 && aux2 <8){
		*(*(this->alfil->validar+aux1)+aux2)=true;
	}
	
	aux1--;
	aux2++;
	
	while(aux1>=0 && aux2<MAX){
		*(*(this->alfil->validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	//	cout<<aux1<<" "<<aux2<<endl;
	}
	
	}
	void FuncionA::mostrarAlfil(){
		dibujarBigOExponecialAzul();
		this->alfil->contador++;
		this->archivo<<"solucion N "<<this->alfil->contador <<endl;
		cout<<"solucion N "<<this->alfil->contador <<endl;
		cout<<endl;
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if((i+j)%2==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
				}
				if(	*(*(this->alfil->validar+i)+j)==true){
					circulo(i,j);
					*(*(this->alfil->tablero +i)+j)='A';
				}
				this->archivo<<*(*(this->alfil->tablero+i)+j)<<" ";
				cout<<*(*(this->alfil->tablero+i)+j)<<" ";
			}
			this->archivo<<endl;
			cout<<endl;
		}
		this->archivo<<endl;
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
	}

	void FuncionA::quitarRelleno(int x, int y){
		dibujarBigOExponecialAzul();
		*(*(this->alfil->tablero +x)+y)='*';
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				*(*(this->alfil->validar+i)+j)=false;
			}
		}
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if(*(*(this->alfil->tablero +i)+j)=='A')
				bloquear(i,j);
			}	
		}
	}

	
	void FuncionA::solucionAlfiles(int x, int y, int n1){
		graficarBigTiempoLineal();
		*(*(this->alfil->tablero +x)+y)='A';
		bloquearAlfiles(x,y);
		if(n1==this->alfil->n){
			mostrarAlfil();
		}
	}
	void FuncionA::solucionReinas(){
		dibujarBigOExponecialAzul();
		dibujarBigOExponecialAzul();
		for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			solucion(i,j,1);
		}
	}
		archivo.close();	
	}
	void FuncionA::solucion(int x, int y, int n1){
		graficarBigHoraSuperLineal();
		*(*(this->alfil->tablero +x)+y)='A';
		bloquear(x,y);
		if(n1==this->alfil->n){
			mostrar();
		}else{
			for(int i=0;i<MAX;i++){
				if(*(*(this->alfil->validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void FuncionA::bloquear(int x, int y){
	dibujarBigOExponecialAzul();	
	int aux1,aux2;
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	while (aux1<MAX && aux2<MAX){
		*(*(this->alfil->validar+aux1)+aux2)=true;
		aux1++;
		aux2++;
	}
	aux2=y;
	aux1=x;
	while(aux1<MAX && aux2>0){
		aux1++;
		aux2--;
	}
	aux1--;
	aux2++;
	if(x+y>=MAX){
		aux1--;
		aux2++;
	}
	while(aux1>=0 && aux2<MAX){
		*(*(this->alfil->validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	}
	
	}
	void FuncionA::mostrar(){
		this->alfil->contador++;
		this->archivo<<"solucion N "<<this->alfil->contador <<endl;
		cout<<"solucion N "<<this->alfil->contador <<endl;
		cout<<endl;
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if((i+j)%2==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}
				else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
				}
				
				this->archivo<<*(*(this->alfil->tablero+i)+j)<<" ";
				cout<<*(*(this->alfil->tablero+i)+j)<<" ";
			}
			this->archivo<<endl;
			cout<<endl;
		}
		this->archivo<<endl;
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
	}
	void FuncionA::solucionAlfilA(int i, int j){
			solucionAlfiles(i,j,1);
		archivo.close();	
	}
	
	void FuncionA::cuadrado2(int dimension){
		setbkcolor(1);
		setcolor(3);
		settextstyle(3,HORIZ_DIR,6);
		outtextxy(220,1,"Tablero ajedrez Generado");
		setcolor(15);
		settextstyle(7,HORIZ_DIR,2);

		rectangle(251,151,409,309);
		setfillstyle(SOLID_FILL, 13);
		bar(251,151,301,201);
		
		int x=251;
		int y=151;
		int x1=301;
		int y1=201;
		for(int i=0;i<dimension;i++){
			bar(x,y,x1,y1);
			for(int j=0;j<dimension;j++){
				if ((i+j)%2==0){
					    setfillstyle(SOLID_FILL, 15);
					}else{ 
					setfillstyle(SOLID_FILL, 0);
					}
			bar(x,y,x1,y1);
			
			x+=51;
			x1+=51;
		}x=250;
		x1=300;
		y+=51;
		y1+=51;
	}
	
	}


	std::vector<std::vector<char>> FuncionA::createChessboard (int dimension){

	std::vector<std::vector<char>> chessboard(dimension, std::vector<char>(dimension, ' '));

    for (int row = 0; row < dimension; ++row) {
        for (int col = 0; col < dimension; ++col) {
            if ((row + col) % 2 == 0) {
                chessboard[row][col] = '+';
            } else {
                chessboard[row][col] = '#';
            }
        }
    }

    return chessboard;
	}

	void FuncionA::saveChessboardToFile(const std::vector<std::vector<char>>& chessboard, const std::string& filename){

	ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& row : chessboard) {
            for (size_t i = 0; i < row.size(); ++i) {
                outfile << row[i];
                if (i != row.size() - 1) {
                    outfile << ' '; // Add a space after each character except for the last character
                }
            }
            outfile << '\n';
        }
        outfile.close();
        cout << "Chessboard saved to chessboard.txt" << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
	}


	std::vector<std::vector<char>> FuncionA::readChessboardFromFile(const std::string& filename){

		ifstream infile(filename);
    vector<vector<char>> chessboard;

    if (infile.is_open()) {
        char square;
        vector<char> row;
        while (infile >> square) {
            if (square == '\n') {
                chessboard.push_back(row);
                row.clear();
            } else {
                row.push_back(square);
            }
        }
        infile.close();

        // Add the last row to the chessboard
        if (!row.empty()) {
            chessboard.push_back(row);
        }
    } else {
        cerr << "Unable to open file." << endl;
    }

    return chessboard;
	}


	void FuncionA::printChessboardToFile(const std::vector<std::vector<char>>& chessboard, int dimension){
		
	ofstream outfile("chessboard_output.txt");
    if (outfile.is_open()) {
        for (const auto& row : chessboard) {
            for (char square : row) {
                outfile << square << ' ';
            }
            outfile << '\n';
        }
        outfile.close();
        //cout << "Chessboard saved to chessboard_output.txt" << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
	}

	void FuncionA::printChessboardFromTxtFile(const std::string& filename){
/*
		 ifstream infile(filename);
    if (infile.is_open()) {
        char ch;
        while (infile.get(ch)) {
            if (ch == '#') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0); // Fondo blanco
            } else if (ch == '+') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | BACKGROUND_INTENSITY); // Fondo negro
            } else {
                // Para otros caracteres, restaurar el color original de la consola
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0);
            }

            cout << ch;
        }
        infile.close();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 0); // Restaurar color original de la consola
    } else {
        cerr << "Unable to open file." << endl;
    }*/

	  ifstream infile(filename);
    if (infile.is_open()) {
        char ch;
        while (infile.get(ch)) {
            if (ch == '+') {
                
				changeTextColor(97); // Texto negro
				
                cout << "+";
                
				changeTextColor(0); // Restaurar color original
				
            } else if (ch == '#') {
               
				changeTextColor(30); // Fondo blanco
				
                cout << "#";
               
				changeTextColor(0); // Restaurar color original
				
            } else {
                cout << ch;
            }
        }
        infile.close();
    } else {
        cerr << "Unable to open file." << endl;
    }

	}

	void FuncionA::changeTextColor(int color) {
    cout << "\x1B[" << color << "m";
	}


	

	

	void FuncionA::cuadrado(){
		setbkcolor(1);
		setcolor(3);
		settextstyle(3,HORIZ_DIR,6);
		outtextxy(220,1,"Tablero ajedrez");
		setcolor(15);
		settextstyle(7,HORIZ_DIR,2);
//		outtextxy(200,650,"Morales Jeimy");
//		outtextxy(550,650,"Orrico Camilo");
		//outtextxy(100,30,"Orrico Camilo");
		//rectangle(199,100,709,609);
		setfillstyle(SOLID_FILL, 13);
		bar(248,150,659,559);
		
		int x=251;
		int y=151;
		int x1=301;
		int y1=201;
		for(int i=0;i<MAX;i++){
			bar(x,y,x1,y1);
			for(int j=0;j<MAX;j++){
				if ((i+j)%2==0){
					    setfillstyle(SOLID_FILL, 15);
					}else{ 
					setfillstyle(SOLID_FILL, 0);
					}
			bar(x,y,x1,y1);
			
			x+=51;
			x1+=51;
		}x=250;
		x1=300;
		y+=51;
		y1+=51;
	}

	}
/*	 void FuncionA::circulo1(int fila, int columna){
	int x=275;
	int y=172;
	int radio=20;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(i==fila &&j==columna){
				setcolor(0);
				setfillstyle(11, 6);
				fillellipse(x,y, radio+5, radio);
			}
			
			x+=51;
		}
		x=275;
		y+=51;
	}
	*/
	void FuncionA::circulo(int fila, int columna){
	int x=250;
	int y=150;
	int x1=301;
	int y1=200;
	int aux2=50;
	int aux3=50;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(i==fila &&j==columna){
			readimagefile("alfil.jpg",x,y,x1,y1);
		//	setfillstyle(SOLID_FILL, 6);
		//  fillellipse(x,y, 5, 10);
		//  fillellipse(x,y+aux, 10, 15);
		//  bar(x1,y+aux1,x1+aux,y1);
		   }
		   	x+=aux2;
		   	x1+=aux2;
		}
		x=251;
		x1=301;
		y+=aux3;
		y1+=aux3;
	}

	}
       