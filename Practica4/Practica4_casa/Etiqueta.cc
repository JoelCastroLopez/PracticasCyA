// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 05/10/2026
// Archivo Etiqueta.cc: programa que contiene la implementación la clase Etiqueta

#include "Etiqueta.h"

/**
 * @brief Método para introducir atributos a la etiqueta
 * @param atributo Atributo a introducir en el vector de Atributos
*/
void Etiqueta::AddAtributo(const Atributo& atributo) {
  atributos_.push_back(atributo);
}

/**
 * @brief Método que verifica si una etiqueta tiene atributos
 * @return Se devuelve si se encuentras atributos o no
*/
bool Etiqueta::TieneAtributos() const {
  return !atributos_.empty();
}