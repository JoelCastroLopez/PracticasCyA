// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 06/10/2025
// Archivo Comentario.h: programa que contiene la declaración la clase Comentario

#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include <string>

class Comentario {
 public:
  // Constructores
  Comentario() : inicio_linea_(0), final_linea_(0), texto_("") {}
  Comentario(int inicio_linea, int final_linea, std::string texto) : inicio_linea_(inicio_linea), final_linea_(final_linea),  texto_(texto) {}

  // Destructor
  ~Comentario() {}

  // Getters
  int get_InicioLinea(void) const { return inicio_linea_; }
  int get_FinalLinea(void) const { return final_linea_; }
  std::string get_texto(void) const { return texto_; }

  // Método para verificar si el comentario es multilínea o no
  bool EsMultilinea() const;

 private:
  int inicio_linea_;
  int final_linea_;
  std::string texto_;
};

#endif