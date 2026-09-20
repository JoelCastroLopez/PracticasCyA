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
Alumno::Alumno(const std::string& alu) : alu_(alu), notas_() {}

// Constructor completo, pasándole un alu y directamente su vector de notas
Alumno::Alumno(const std::string& alu, const std::vector<double>& notas) : alu_(alu), notas_(notas) {}

// Añade una nueva calificación al vector de notas del estudiante
void Alumno::AnadirNota(double nota) {
  notas_.push_back(nota);
}

// Devuelve la nota más alta obtenida de entre todas las registradas, si no hay notas registradas, retorna la nota por defecto (0.0).
double Alumno::ObtenerNotaMaxima() const {
  if (notas_.empty()) {
    return 0.0;
  }

  double nota_maxima = notas_[0];
  for (int i = 1; i < notas_.size(); ++i) {
    if (notas_[i] > nota_maxima) {
      nota_maxima = notas_[i];
    }
  }

  return nota_maxima;
}