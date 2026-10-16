// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Estado.h: programa que contiene la implementación de la clase estado


#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>


#include "Alfabeto.h"



class Estado {
 public:
  // Constructores
  Estado(void);
  Estado(std::string informacion);

  // Método para buscar las transiciones con un signo desde cierto estado
  std::set<int> transicion_con_simbolo(char simbolo);
  std::set<char> get_simbolos_transiciones();
  //Estado busqueda_estado(int nombre, std::set<Estado> estados_totales);
  //void epsilon_clausura(std::set<int> clausura, std::set<Estado> estados_totales);
  
  // Sobrecargas de operadores útiles
  friend std::ostream& operator<<(std::ostream& out, const Estado& estado);
  friend bool operator<(Estado estado1, Estado estado2);
  bool operator==(const Estado& estado2);

  // Getters (constantes y normales)
  int get_nombre() { return nombre_; }
  bool get_aceptacion() { return aceptacion_; }
  std::multimap<char, int> get_transiciones() { return transiciones_; }

  int get_nombre() const { return nombre_; }
  bool get_aceptacion() const { return aceptacion_; }
  std::multimap<char, int> get_transiciones() const { return transiciones_; }

 private:
  int nombre_;
  bool aceptacion_;
  std::multimap<char, int> transiciones_;
};

#endif