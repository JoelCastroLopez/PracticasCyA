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
  Alumno(const std::string& alu, const std::vector<double>& notas);

  // Getters
  std::string get_Alu() const { return alu_; }
  const std::vector<double>& get_Notas() const { return notas_; }

  // Setters
  void set_Alu(std::string alu) { alu_ = alu; }

  // Métodos útiles
  void AnadirNota(double nota);
  double ObtenerNotaMaxima() const;

  // Sobrecarga operador "<"
  bool operator<(const Alumno& otro) const { return alu_ < otro.alu_;}

 private:
  std::string alu_;
  std::vector<double> notas_;
};

#endif