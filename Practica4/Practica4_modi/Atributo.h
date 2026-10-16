// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 05/10/2026
// Archivo Atributo.h: programa que contiene la declaración la clase Atributo

#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <iostream>
#include <string>

class Atributo {
 public:
  // Constructores
  Atributo() : nombre_(""), valor_("") {}
  Atributo(std::string nombre, std::string valor) : nombre_(nombre), valor_(valor) {}
  // Destructor
  ~Atributo() {}

  // Getters
  std::string get_nombre() const { return nombre_; }
  std::string get_valor() const { return valor_; }

 private:
  std::string nombre_;
  std::string valor_;
};

#endif