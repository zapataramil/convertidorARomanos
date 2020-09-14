# Converter to Roman Numbers

**Aplicacion ejecutable desde la terminal que transforma cualquier numero decimal (entre 1 y 3000) a numero romano, en base a programacion estructurada**

![](https://raw.githubusercontent.com/zapataramil/convertidorARomanos/master/icono.ico)

### Features

- Los numeros a convertir deben estar en un archivo de texto
- Los numeros dentro del archivo estan separados o por un espacio o por un enter
- La ruta del archivo es subido junto con la ejecucion del programa (ver 1)
- Cualquier numero que tenga algun simbolo o letra o esté mal escrito o esté fuera de rango será enviado a un archivo /log.txt
- Los numeros bien ingresados dentro del rango serán enviados a /romanos.txt
- Los archivos log.txt y romanos.txt, se crean en la ruta donde ejecuto el programa



# Bash

**Compilacion: **
```html
g++ *.cpp -o program
```
**Ejecucion: **
```html
./program ~/Documentos/proyectos/convertidorARomanos/numerosAConvertir.txt
```
