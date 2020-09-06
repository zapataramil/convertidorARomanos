#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#include "funciones.h"


//NUMERO EN TIPO STRING A NUMERO EN TIPO ENTERO
void transformarLineaANumero(string linea,int &numero){
	stringstream ss(linea);
	ss >> numero;
}

//DEVUELVE LA CANTIDAD DE CEROS A IZQUIERDA DEL NUMERO
int cerosIrrelevantes(string romano){
	int i = 0;
	while(romano[i] == '0')
		i++;
	return i;
}

//DEVUELVE LA CANTIDAD DE DIGITOS NETO QUE TIENE EL NUMERO
int obtenerTamanioNumero(string romano){
	return romano.length()-cerosIrrelevantes(romano);
}

//SE CARGAN LOS NUMEROS ROMANOS DE MENOR A MAYOR
void cargarNivelDePrecedencias(char letras[]){
	letras[0]='I';
	letras[1]='V';
	letras[2]='X';
	letras[3]='L';
	letras[4]='C';
	letras[5]='D';
	letras[6]='M';
}

//DEVUELVE TRUE SI EL RANGO DEL NUMERO ES VALIDO, EN OTRO CASO FALSE
bool rangoValido(string linea){
	int numero = 0;
	transformarLineaANumero(linea,numero);
	if ((numero>=1)&&(numero<=3000))
		return true;
	return false;
}

//DEVUELVE TRUE SI TIENE ALGUNA LETRA, EN OTRO CASO FALSE
bool tieneLetra(string linea){
	unsigned int i=0;
	    while(i<linea.length()){
	    	if(!((linea[i] == '1')||(linea[i] == '2')||(linea[i] == '3')||(linea[i] == '4')||(linea[i] == '5')||(linea[i] == '6')||(linea[i] == '7')||(linea[i] == '8')||(linea[i] == '9')||(linea[i] == '0')))
	    		return true;
	    	i++;
	    }
	    return false;
}

//EL NUMERO CONTENIDO EN LINEA LO PASA A ROMANO
void transformarNumeroRomano(string linea,string &romano){

//CEROS A LA IZQUIERDA DEL NUMERO SON IRRELEVANTES
	int posicion = cerosIrrelevantes(linea);

//DEFINO ORDEN DE PRECEDENCIAS DE LOS NUMEROS ROMANOS (I,V,X,L,C,D,M)
	char letras[7];
	cargarNivelDePrecedencias(letras);

//ALMACENARA EL NUMERO CORRESPONDIENTE A LA UBICACION DE LA LETRA ROMANA DE TIPO 1 (I,X,C,M)
	int precedencia;

//CONTIENE LA CANTIDAD NETA DE DIGITOS DEL NUMERO (NETA PORQUE NO CONSIDERO LOS CEROS DE IZQUIERDA )
	int digitos = obtenerTamanioNumero(linea);


	while (digitos>=1){

		switch (digitos){
		case 1: precedencia=0;
		break;
		case 2: precedencia=2;
		break;
		case 3: precedencia=4;
		break;
		case 4: precedencia=6;
		break;
		default: break; //NUNCA ENTRA A DEFAULT
		}

		switch (linea[posicion]){
		case '1': romano = romano + letras[precedencia];
		break;
		case '2': romano = romano + letras[precedencia] + letras[precedencia];
		break;
		case '3': romano = romano + letras[precedencia] + letras[precedencia] + letras[precedencia];
		break;
		case '4': romano = romano + letras[precedencia] + letras[precedencia+1];
		break;
		case '5': romano = romano + letras[precedencia+1];
		break;
		case '6': romano = romano + letras[precedencia+1] + letras[precedencia];
		break;
		case '7': romano = romano + letras[precedencia+1] + letras[precedencia] + letras[precedencia];
		break;
		case '8': romano = romano + letras[precedencia+1] + letras[precedencia] + letras[precedencia] + letras[precedencia];
		break;
		case '9': romano = romano + letras[precedencia] + letras[precedencia+2];
		break;
		default:
		break;
		}

//AVANZO CHAR A CHAR DEL STRING LINEA
		posicion++;
//DECREMENTO DIGITOS HASTA QUE NO HAYAN MAS DIGITOS PARA ANALIZAR
		digitos--;
	}
}
