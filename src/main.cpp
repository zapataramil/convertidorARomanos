#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#include "funciones.h"

int main(int argc, char* argv[]){

//ABRO ARCHIVOS PARA LECTURA Y ESCRITURA
	ifstream archivo(argv[1]);
	ofstream archivoError("log.txt");
	ofstream archivoRomano("romanos.txt");

//CONTENDRA LA CORRESPONDIENTE LINEA DEL ARCHIVO DE TEXTO
	string linea;

//MIENTRAS NO SEA FIN DE ARCHIVO, LEO LINEA, VALIDO, PASO A ROMANO(EN TAL CASO) MANDO LINEA AL ARCHIVO CORRESPONDIENTE
	if(!archivo.eof()){
		while(archivo >> linea){
			if (!tieneLetra(linea))
				if(rangoValido(linea)){
					string romano;
					transformarNumeroRomano(linea,romano);
					archivoRomano << romano << endl;
				}else
					archivoError << linea + ": VALOR FUERA DE RANGO"<< endl;
			else
				archivoError << linea + ": VALOR ERRONEO"<< endl;
		}
	}

//CIERRO ARCHIVOS
	archivoError.close();
	archivoRomano.close();
	archivo.close();
	return 0;
}


