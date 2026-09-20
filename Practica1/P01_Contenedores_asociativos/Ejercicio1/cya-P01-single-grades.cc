// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: alu0101485515@ull.edu.es
// Fecha: 14/09/2026
// Archivo: cya-P01-single-grades.cc: programa cliente.
// Contiene la función main del ejercicio 1, que usa la clase alumno
//

#include <iostream>
#include <limits>

#include "Tools.h"
#include "Alumno.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::set<Alumno> estudiantes;
  AnalisisEntrada(argv[1], estudiantes);
  ImprimirResultado(estudiantes);

  bool no_mas_alu{false};
  while (!no_mas_alu) {
    std::string respuesta;
    std::cout << std::endl << "¿Quieres intruducir una nueva nota manualmente? ('s' = si | cualquier otro tecla = no) : ";
    std::cin >> respuesta;

    if (respuesta == "s" || respuesta == "S") {
      // Limpiamos el '\n'
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::string entrada_manual;
      std::cout << std::endl << "Escribe la nota en el siguiente formato: alu01XXXXXXXX <0-10>.XXX : ";
      
      // Ahora leemos la línea completa
      std::getline(std::cin, entrada_manual);
      std::cout << std::endl;

      IntroduccionManual(entrada_manual, estudiantes);
      ImprimirResultado(estudiantes);
    } else {
      no_mas_alu = true;
    }
  }

  return 0;
}