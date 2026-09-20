// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: alu0101485515@ull.edu.es
// Fecha: 14/09/2026
// Archivo: Alumno.cc: programa que contiene la implementación de la clase alumno.
// Contiene la clase alumno
//

#include "Alumno.h"

// Constructor base, solo con un alu, pero sin notas
Alumno::Alumno(const std::string& alu) : alu_(alu), nota_(0.0) {}

// Constructor completo, pasándole un alu y directamente su vector de notas
Alumno::Alumno(const std::string& alu, const double& nota) : alu_(alu), nota_(nota) {}
