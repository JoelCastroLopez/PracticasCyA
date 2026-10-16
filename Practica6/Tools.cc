// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2025
// Archivo Tools.cc: programa que contiene las herramientas básicas para el programa


#include <iostream>
#include <string>
#include <fstream>


#include "Tools.h"



/**
 * @brief Función Usage para comprobar que los parámetros pasados sean correctos
 * @param argc Variable que nos dirá el número de parámetros pasados
 * @param argv Variable con los valores que entran por comandos
*/
void Usage(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa funciona con el nombre del ejecutable, luego el fichero con los datos del autómata, ";
    std::cout << "en tercer lugar el fichero con las cadenas a probar y en cuarto lugar el fichero para escribir gramáticas" << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (argc != 4) {
    std::cerr << "Modo de empleo: ./Practica6 input.fa input.txt output.txt" << std::endl;
    std::cerr << "Pruebe ./Practica6 --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}