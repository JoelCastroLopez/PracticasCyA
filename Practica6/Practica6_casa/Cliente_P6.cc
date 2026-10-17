// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Cliente_P6.cc: programa que contiene el main

#include <iostream>

#include "Tools.h"
#include "Analizador.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  Automata automata;
  Analizador_automata(argv[1], automata);
  Comprobar_cadena(argv[2], automata);

  return 0;
}