// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Tools.cc: programa que contiene las herramientas básicas para el programa

#include <iostream>
#include <string>
#include <cstdlib>

#include "Tools.h"

/**
 * @brief Función Usage para comprobar que los parámetros pasados sean correctos
 * @param argc Variable que nos dirá el número de parámetros pasados
 * @param argv Variable con los valores que entran por comandos
*/
void Usage(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa funciona con el nombre del ejecutable, seguido del fichero con los datos del DFA (.dfa), ";
    std::cout << "y finalmente el fichero con las cadenas a probar (.txt)." << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (argc != 3) {
    std::cerr << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt" << std::endl;
    std::cerr << "Pruebe ./p06_DFA_simulator --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}