// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 05/10/2026
// Archivo Etiqueta.h: programa que contiene la declaración la clase Etiqueta

#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <iostream>
#include <string>
#include <vector>

#include "Atributo.h"

class Etiqueta {
 public:
  // Constructores
  Etiqueta() : linea_(0), nombre_("") {}
  Etiqueta(int linea, std::string nombre) : linea_(linea), nombre_(nombre) {}
  // Destructor
  ~Etiqueta() {}

  // Getters
  int get_linea() const { return linea_; }
  std::string get_nombre() const { return nombre_; }
  std::vector<Atributo> get_atributos() const { return atributos_; }

  // Método para añadir un atributo al vector
  void AddAtributo(const Atributo& atributo);

  // Método para saber si tiene atributos
  bool TieneAtributos() const;

 private:
  int linea_;
  std::string nombre_;
  std::vector<Atributo> atributos_;
};

#endif