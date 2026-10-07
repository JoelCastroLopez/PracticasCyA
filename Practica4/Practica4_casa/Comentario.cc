// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 06/10/2025
// Archivo Comentario.cc: programa que contiene la implementación la clase Comentario

#include <iostream>
#include <string>


#include "Comentario.h"

/**
 * @brief Verifica si el comentario ocupa más de una línea en el archivo
 * @return True si ocupa varias líneas, False si está en una sola
 */
bool Comentario::EsMultilinea() const {
  if (inicio_linea_ == final_linea_) {
    return false;
  } else {
    return true;
  }
}