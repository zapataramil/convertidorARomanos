
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//PRE: recibe una linea de texto
//POST: devuelve TRUE si tiene un rango de [1,3000], sino FALSE
bool rangoValido(string linea);

//PRE: recibe una linea de texto
//POST: devuelve TRUE si tiene una letra, sino FALSE
bool tieneLetra(string linea);

//PRE: recibe una linea de texto, y un texto romano vacio
//POST: romano tiene expresado en numeros romanos el numero contenido por linea
void transformarNumeroRomano(string linea,string &romano);


#endif /* FUNCIONES_H_ */
