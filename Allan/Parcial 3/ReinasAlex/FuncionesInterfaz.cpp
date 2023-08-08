#include "FuncionesInterfaz.h"
#include <windows.h>
#include <graphics.h>
#include <math.h>
//#include "Reina.cpp"


void FuncionesInterfaz::encerarTablero(void){
	
	dibujarBigOExponecialAzul();
	for(int i=0;i<reina->getDimension();i++){//O(n)
		this->reina->validar[i]=new bool[reina->getDimension()];//O(1)
		this->reina->tablero[i]=new char[reina->getDimension()];//O(1)
		for(int j=0;j<reina->getDimension();j++){//O(n)
			*(*(this->reina->validar+i)+j)=false;//O(1)
			*(*(this->reina->tablero+i)+j)='*';//O(1)
		}
	}
	//O(n)*(0(1)+0(1))*O(n)*(0(1)+O(1))=O(n^2)
}


void FuncionesInterfaz::crearArchivo(void){
	Reina *rei;
	LineaA();
	this->archivo.open("exaustivo.txt",fstream::out); //0(1)
	this->archivo<<"solucion"<<reina->getDimension()<<"*"<<reina->getDimension()<<endl<<endl;//0(1)
	this->reina->contador=0;//O(1)
	//O(1)+O(1)+O(1)=O(1)
	LineaA();
}

void FuncionesInterfaz::bloquear(int x, int y){
	graficarBigTiempoLineal();
	int aux1,aux2;
	aux2=y;//O(1)
	aux1=0;
	while(aux1<DIMENSION){//vertical//O(n)
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux1++;
	}
	aux2=0;
	aux1=x;
	while(aux2<DIMENSION){//horizontal
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux2++;
	}
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	
	while (aux1 < DIMENSION && aux2 < DIMENSION) { //FALTABA
        *(*(this->reina->validar+aux1)+aux2)=true; //FALTABA
        aux1++; //FALTABA
        aux2++; //FALTABA
    	}
		aux2=y;
		aux1=x;
		while(aux1<DIMENSION && aux2>0){//O(n)
			aux1++;
			aux2--;
		}
		if (x + y >= DIMENSION) { //FALTABA  //O(n)
            aux1--;
            aux2++;
        } //FALTABA    
        while(aux1>=0 && aux2<DIMENSION){//O(n)
			*(*(this->reina->validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
}

void FuncionesInterfaz::bloquearR(int x, int y){
	
	graficarBigTiempoLineal();
	int aux1,aux2;
	Reina *rei;
	aux2=y;
	aux1=0;
	while(aux1<rei->getDimension()){//vertical
	cout<<aux1<<aux2<<endl;
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux1++;
	}
	aux2=0;
	aux1=x;
	while(aux2<rei->getDimension()){//horizontal
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux2++;
	}
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	
	while (aux1 < rei->getDimension() && aux2 < rei->getDimension()) { //FALTABA
        *(*(this->reina->validar+aux1)+aux2)=true; //FALTABA
        aux1++; //FALTABA
        aux2++; //FALTABA
    	}
		aux2=y;
		aux1=x;
		while(aux1<rei->getDimension() && aux2>0){
			aux1++;
			aux2--;
		}
		if (x + y >= rei->getDimension()) { //FALTABA
            aux1--;
            aux2++;
        } //FALTABA
        while(aux1>=0 && aux2<rei->getDimension()){
			*(*(this->reina->validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
}

void FuncionesInterfaz::mostrar(void){
	dibujarBigOExponecialAzul();
	this->reina->contador++;
	this->archivo<<"solucion N "<<this->reina->contador<<endl;
	cout<<"solucion N "<<this->reina->contador<<endl;
	cout<<endl;
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			if((i+j)%2==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}
				else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
				}
				if (*(*(this->reina->tablero+i)+j)=='R'){
					dibujoReina(i,j);
				}
			this->archivo<<*(*(this->reina->tablero+i)+j)<<" ";
			cout<<*(*(this->reina->tablero+i)+j)<<" ";
		}
		this->archivo<<endl;
		cout<<endl;
	}
	this->archivo<<endl;
	cout<<endl;
	
}

void FuncionesInterfaz::mostrarReina(void){
	dibujarBigOExponecialAzul();
	this->reina->contador++;
	this->archivo<<"solucion N "<<this->reina->contador<<endl;
	cout<<"solucion N "<<this->reina->contador<<endl;
	cout<<endl;
	for(int i=0;i<reina->getDimension();i++){
		for(int j=0;j<reina->getDimension();j++){
			if((i+j)%2==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}
				else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
				}
				if(	*(*(this->reina->validar+i)+j)==true){
					reinaB(i,j);
					*(*(this->reina->tablero+i)+j)='R';
			}
			this->archivo<<*(*(this->reina->tablero+i)+j)<<" ";
			cout<<*(*(this->reina->tablero+i)+j)<<" ";
		}
		this->archivo<<endl;
		cout<<endl;
	}
	this->archivo<<endl;
	cout<<endl;

}

void FuncionesInterfaz::quitarRelleno(int x, int y){
	*(*(this->reina->tablero +x)+y)='*';
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			*(*(this->reina->validar +i)+j)=false;
		}
			}
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			if(*(*(this->reina->tablero  +i)+j)=='R')
			bloquear(i,j);
		}	
	}
}

void FuncionesInterfaz::solucion(int x, int y, int n1){
//	graficarBigHoraSuperLineal();
	dibujarBigOExponecialNaranja();
	*(*(this->reina->tablero +x)+y)='R';//O(1)
	bloquear(x,y);
	if(n1==this->reina->n){//O(n)
		mostrar();
	}else{//O(nlogn)
		for(int i=0;i<this->reina->n ;i++){//O(n)
			if(*(*(this->reina->validar +i )+ y+1)==false){
				solucion(i,y+1,n1+1);//O(2^n)
			}
		}
	}
	quitarRelleno(x,y);	
	//O(1)+O(n)+O(nlogn)+O(n)+O(2n^n)= 
}

void FuncionesInterfaz::solucionReinas(void){
	for(int i=2;i<DIMENSION ;i++){//O(n)
		for(int j=0;j<DIMENSION;j++){//O(n)
			solucion(i,j,1);
		}
	}
	archivo.close();
	//O(n)*O(n)=O(n^2)
}

void FuncionesInterfaz::solucionRB(int x, int y, int n1){
	graficarBigTiempoLineal();
	*(*(this->reina->tablero +x)+y)='R';//O(1)
		bloquearR(x,y);
		if(n1==this->reina->n){//O(n)
			cout<<"SolucionRB"<<endl;//O(1)
			mostrarReina();
		}
	//O(1)+O(n)*O(1)=O(n)
}

void FuncionesInterfaz::solucionReinasB(int i, int j){
	solucionRB(i,j,1);
	archivo.close();
}

void FuncionesInterfaz::dibujoReina(int fila, int columna){
	int x=250;
	int y=150;
	int x1=301;
	int y1=200;
	int aux2=50;
	int aux3=50;
	cout<<"Posicion dimension: "<<6<<endl;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i==fila &&j==columna){
			readimagefile("reina.jpg",x,y,x1,y1);
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

void FuncionesInterfaz::dibujoReinaB(int fila, int columna,int dimension){
	int x=250;
	int y=150;
	int x1=301;
	int y1=200;
	int aux2=50;
	int aux3=50;
	cout<<"Posicion dimension: "<<dimension<<endl;
	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
			if(i==fila &&j==columna){
			readimagefile("reina.jpg",x,y,x1,y1);
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

	void FuncionesInterfaz::reinaB(int fila, int columna){
	int x=250;
	int y=150;
	int x1=301;
	int y1=200;
	int aux2=50;
	int aux3=50;
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			if(i==fila &&j==columna){
			readimagefile("reina.jpg",x,y,x1,y1);
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

	}///////////////////////////777777
	
	void FuncionesInterfaz::caballoP(int fila, int columna){
		*(*(this->reina->validar+fila)+columna)=true;
		cout<<endl;
		solucionCP(fila, columna, 1);
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				if((i+j)%2==0){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
					}
					else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
					}
					if(	*(*(this->reina->validar+i)+j)==true){
					dibujocaballo(i,j);
					*(*(this->reina->tablero+i)+j)='C';
			}
				this->archivo<<*(*(this->reina->tablero+i)+j)<<" ";
				cout<<*(*(this->reina->tablero+i)+j)<<" ";
			}
			this->archivo<<endl;
			cout<<endl;
		}
		this->archivo<<endl;
		cout<<endl;	
	}
	
	void FuncionesInterfaz::solucionCP(int f, int c, int cont){
		if(f>=7){
			cout<<"SALTOS ES  "<<cont<<endl;
		}
		if(c>=7){
			system("pause");
			cout<<f<<c<<"Salto "<<cont<<endl;
			*(*(this->reina->validar+f+2)+c-1)=true;
			solucionCP(f+2, c-1, cont+1);
		}
		if(f<7){
			system("pause");
			cout<<f<<c<<"Salto menor fila 8  "<<cont<<endl;
			*(*(this->reina->validar+f+2)+(c+1))=true;
			solucionCP(f+2, c+1, cont+1);
		}
		if (c<0){
			*(*(this->reina->validar+f+2)+c+1)=true;
			solucionCP(f+2, c+1, cont+1);
		}
	}

	/////////////////////////////////////////
	void FuncionesInterfaz::caballo(int fila, int columna){
		caballoS(fila,columna,1);
		archivo.close();
		
	}
	
	void FuncionesInterfaz::caballoS(int x ,int y, int n1){
		graficarBigTiempoLineal();
		*(*(this->reina->tablero +x)+y)='C';
		BolquearCaballo(x,y);
		if(n1==this->reina->n){
			mostrarCaballo();
		}
	}
	
	void FuncionesInterfaz::mostrarCaballo(void){
	dibujarBigOExponecialAzul();
	this->reina->contador++;
	this->archivo<<"solucion N "<<this->reina->contador<<endl;
	cout<<endl;
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			if((i+j)%2==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}
				else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|0);
				}
				if(	*(*(this->reina->validar+i)+j)==true){
					dibujocaballo(i,j);
					*(*(this->reina->tablero+i)+j)='C';
			}
			this->archivo<<*(*(this->reina->tablero+i)+j)<<" ";
			cout<<*(*(this->reina->tablero+i)+j)<<" ";
		}
		this->archivo<<endl;
		cout<<endl;
	}
	this->archivo<<endl;
	cout<<endl;

}

void FuncionesInterfaz::BolquearCaballo(int x, int y){
	graficarBigTiempoLineal();
	*(*(this->reina->validar+x)+y)=true;//O(1)
	//abajo
	if(x<6){//O(n)
		*(*(this->reina->validar+x+2)+y+1)=true;//O(1)
		*(*(this->reina->validar+x+2)+y-1)=true;//O(1)
	}
	if (x>1){//O(n)
		//Arriba
	*(*(this->reina->validar+x-2)+y-1)=true;  //O(1)
	*(*(this->reina->validar+x-2)+y+1)=true;//O(1)
	}
	
	if (y>1){//O(n)
		//IZQUIERDO
		*(*(this->reina->validar+x-1)+y-2)=true;//O(1)
		*(*(this->reina->validar+x+1)+y-2)=true;//O(1)
	}
	
	if(y<6){//O(n)
		//Drecha
		*(*(this->reina->validar+x+1)+y+2)=true;//O(1)
		*(*(this->reina->validar+x-1)+y+2)=true;//O(1)
	}
	//O(n)(O(1)+O(1))+O(n)(O(1)+O(1))+O(n)(O(1)+O(1))+O(n)(O(1)+O(1))=O(n)
}

void FuncionesInterfaz::dibujocaballo(int fila, int columna){
	int x=250;
	int y=150;
	int x1=301;
	int y1=200;
	int aux2=50;
	int aux3=50;
	for(int i=0;i<DIMENSION;i++){
		for(int j=0;j<DIMENSION;j++){
			if(i==fila &&j==columna){
			readimagefile("caballo.jpg",x,y,x1,y1);
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
	
	void FuncionesInterfaz::ejes(){
		setcolor(15);
		settextstyle(3,0,1);
		outtextxy(890,435,"Elementos");
		settextstyle(3,1,1);
		outtextxy(800,180,"O");
		outtextxy(800,200,"p");
		outtextxy(800,220,"e");
		outtextxy(800,240,"r");
		outtextxy(800,260,"a");
		outtextxy(800,280,"c");
		outtextxy(800,300,"i");
		outtextxy(800,320,"o");
		outtextxy(800,340,"n");
		outtextxy(800,360,"e");
		outtextxy(800,380,"s");
		line(850,400,850,150);
		line(850,400,1100,400);
	}
  	void FuncionesInterfaz::LineaRoja(){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		setcolor(4);
		outtextxy(1100,373,"O(log n )");
		line(850,399,1100,396);
	}
	void FuncionesInterfaz::LineaA(){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		setcolor(3);
		outtextxy(1100,390,"O(1)");
		//outtextxy(1100,390,"O(n)");
		line(850,399,1100,398);
	}
	
	void FuncionesInterfaz::graficarBigHoraSuperLineal(){
	setcolor(GREEN);
	line(850,400,1100,225);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(WHITE);
//	outtextxy(950,200,nombreFuncion);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(GREEN);
	outtextxy(1100,225,"O(nlogn)");
}
void FuncionesInterfaz::graficarBigTiempoLineal(){
	setcolor(MAGENTA);
	line(850,400,1100,350);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(WHITE);
//	outtextxy(950,390,nombreFuncion);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(MAGENTA);
	outtextxy(1100,350,"O(n)");
}

void FuncionesInterfaz::dibujarBigOExponecialCeleste(){
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		int x, y;
	    double a = 20;
	    for (x = 0; x <= 38; x++)
	    {
	        y = 415 - a * pow(2, x / 10.0);
	        putpixel(x+850, y, CYAN);
	    }
	    setcolor(CYAN);
		outtextxy(838,120,"O(n!)");
	}
	void FuncionesInterfaz::dibujarBigOExponecialAzul(){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		int x2, y2;
	    double c = 8;
	    for (x2 = 0; x2 <=100; x2++)
	    {
	        y2 = 400 - c * pow(2, x2 / 20.0);
	        putpixel(x2+850, y2, BLUE);
	    }
	    setcolor(BLUE);
		outtextxy(970,150,"O(n^2)");
	}
	void FuncionesInterfaz::dibujarBigOExponecialNaranja(){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		int x1, y1;
	    double b = 15;
	    for (x1 = 0; x1 <= 54; x1++)
	    {
	        y1 = 414 - b * pow(2, x1 / 13.0);
	        putpixel(x1+850, y1, 6);
	    }setcolor(6);
		outtextxy(888,125,"O(2^n)");

	}


	void FuncionesInterfaz::presentacio(){
		ejes();
		LineaRoja();
		LineaA();
		graficarBigTiempoLineal();
		graficarBigHoraSuperLineal();
		dibujarBigOExponecialCeleste();
		dibujarBigOExponecialAzul();
		dibujarBigOExponecialNaranja();
		setcolor(3);
		settextstyle(3,HORIZ_DIR,6);
		outtextxy(250,20,"Aritmetica de la notacion O");
		readimagefile("BIGO.jpg",100,150,600,400);
		setcolor(15);
		settextstyle(3,HORIZ_DIR,1);
	/*
		outtextxy(100,500,"Imbaquinga Jose ");
		outtextxy(100,525,"Jairo Quilumbaquin");
		outtextxy(100,750,"   ");
		
  	*/

	}