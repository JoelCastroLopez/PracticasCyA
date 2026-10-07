// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Tools.cc: programa que contiene las herramientas básicas del código

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
    std::cout << "El programa funciona con el nombre del ejecutable, luego el fichero de entrada, ";
    std::cout << "donde se encontrarán los datos, y en tercer lugar el fichero de salida, donde se mostrarán ";
    std::cout << "los resultados al analizar el código" << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (argc != 3) {
    std::cerr << "Modo de empleo:  ./p04_html_analyzer pagina.html esquema.txt" << std::endl;
    std::cerr << "Pruebe ./Practica4 --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}