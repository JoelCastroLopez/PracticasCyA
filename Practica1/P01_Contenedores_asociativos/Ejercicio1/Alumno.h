// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: alu0101485515@ull.edu.es
// Fecha: 14/09/2026
// Archivo: Alumno.h: programa que contiene la declaración de la clase alumno.
// Contiene la clase alumno
//

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <vector>

class Alumno {
 public:
  // Constructores
  Alumno(const std::string& alu);
  Alumno(const std::string& alu, const double& nota);

  // Getters
  std::string get_Alu() const { return alu_; }
  double get_Nota() const { return nota_; }

  // Setters
  void set_Alu(std::string alu) { alu_ = alu; }
  void set_Nota(double nota) { nota_ = nota; }

  // Sobrecarga operador "<"
  bool operator<(const Alumno& otro) const { return alu_ < otro.alu_;}

 private:
  std::string alu_;
  double nota_;
};

#endif