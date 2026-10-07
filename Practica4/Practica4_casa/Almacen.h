// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Clase_Almacen.h: programa que contiene la declaración de la clase Almacen

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <vector>
#include <string>


#include "Comentario.h"
#include "Etiqueta.h"
#include "Atributo.h"

class Almacen {
 public:
  // Contructor
  Almacen() : doctype_("") {}
  // Destructor
  ~Almacen() {}

  // Setters
  void set_nombre_fichero(const std::string& nombre) { nombre_fichero_ = nombre; }
  void set_descripcion() { hay_descripcion_ = true; }
  void set_html() { hay_html_ = true; }
  void set_head() { hay_head_ = true; }
  void set_body() { hay_body_ = true; }
  void set_doctype(const std::string& doctype) { doctype_ = doctype; }

  // Métodos para meter valores en los vectores
  void PushVectorEtiquetas(const Etiqueta& etiqueta) { vector_etiquetas_.push_back(etiqueta); }
  void PushVectorComentarios(const Comentario& comentario) { vector_comentarios_.push_back(comentario); }
 
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& out, const Almacen& almacen);

 private:
  std::string nombre_fichero_;
  bool hay_descripcion_ = false;
  bool hay_html_ = false;
  bool hay_head_ = false;
  bool hay_body_ = false;
  std::string doctype_;
  std::vector<Etiqueta> vector_etiquetas_;
  std::vector<Comentario> vector_comentarios_;
};

#endif