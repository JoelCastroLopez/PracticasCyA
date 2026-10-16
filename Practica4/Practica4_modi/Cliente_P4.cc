// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Cliente_P4.cc: programa que contiene el main.

#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#include "Tools.h"
#include "Analizador.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  AnalizadorCodigo(argv[1], argv[2]);

  return 0;
}