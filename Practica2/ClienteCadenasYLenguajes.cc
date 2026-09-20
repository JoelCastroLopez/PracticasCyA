// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2025
// Archivo ClienteCadenasYLenguajes.cc: programa cliente
// Contiene el programa cliente

#include "Cadena.h"
#include "Tools.h"
#include "Alfabeto.h"
#include "Lenguaje.h"



int main (int argc, char* argv[]) {
  Usage(argc, argv[1]); 
  Instruccion(argv[3], argv[1], argv[2]);
  
  return 0;
}