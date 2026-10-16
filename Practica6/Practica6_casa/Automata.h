// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2025
// Archivo Automata.h: programa que contiene la declaración de la clase autómata


#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <set>


#include "Alfabeto.h"
#include "Estado.h"
#include "Cadena.h"



class Automata {
 public:
  // Constructor
  Automata(void);

  // Métodos para meter elementos en los atributos del autómata
  void push_estado(Estado estado) { conjunto_estados_.insert(estado); }
  void push_estados_finales(Estado estado) { estados_finales_.insert(estado);}
  void push_estados_actuales(Estado estado) { estados_actuales_.insert(estado);}

  // Getters (constantes y normales)
  int get_estado_inicial() const { return estado_inicial_; }
  int get_estado_inicial() { return estado_inicial_; }

  Alfabeto get_alfabeto() const { return alfabeto_; }
  Alfabeto get_alfabeto() { return alfabeto_; }

  // Setters
  void set_alfabeto(Alfabeto alfabeto) { alfabeto_= alfabeto; }
  void set_estado_inicial(int estado_inicial) { estado_inicial_= estado_inicial; }

  // Método para mostrar los estados actuales (no tiene un uso específico en la práctica, solo lo usé para verificar el proceso)
  void mostrar_estados_actuales();

  // Métodos usados en proceso de autómata
  Estado busqueda_estado(int nombre);
  bool comprobacion_estados_finales();
  void vaciar_estado_actual() { estados_actuales_.clear();}
  bool cadena_aceptada(Cadena cadena);

  // Sobrecarga del operador <<
  friend std::ostream& operator<<(std::ostream& out, const Automata& automata);

 private:
  Alfabeto alfabeto_;
  std::set<Estado> conjunto_estados_;
  int estado_inicial_;
  std::set<Estado> estados_finales_;
  std::set<Estado> estados_actuales_;
};

#endif