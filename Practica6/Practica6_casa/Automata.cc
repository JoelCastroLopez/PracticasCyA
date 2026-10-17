// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Automata.cc: programa que contiene la implementación de la clase autómata


#include <iostream>


#include "Automata.h"
#include "Estado.h"



/**
 * @brief Constructor de la clase Autómata
*/
Automata::Automata(void) {}

/**
 * @brief Devuelve el estado correspondiente a cierto número
 * @param nombre Estado a buscar
 * @return Devuelve el estado encontrado
*/
Estado Automata::busqueda_estado(int nombre) {
  for (auto it = conjunto_estados_.begin(); it != conjunto_estados_.end(); ++it) {
    if (it->get_nombre() == nombre) {
      return *it;
    }
  }
  Estado estado("-1 0"); // Caso donde no se encuentre el estado
  return estado;
}

/**
 * @brief Devuelve si una cadena es aceptada o no por nuestro autómata e imprime la traza
 * @param cadena Cadena a comprobar
 * @return Se devuelve si una cadena es aceptada o no
*/
bool Automata::cadena_aceptada(Cadena cadena) {
  int estado_actual = estado_inicial_;
  
  // Imprimir cabecera de la traza
  std::cout << std::left << std::setw(15) << "Est. Actual" << std::setw(10) << "Entrada" << "Nuevo Est." << std::endl;


  for (int i = 0; i < cadena.get_simbolos().size(); i++) {
    char simbolo_actual = cadena.get_simbolos()[i];
    Estado estado_obj = busqueda_estado(estado_actual);
    
    int estado_siguiente = estado_obj.transicion_con_simbolo(simbolo_actual);
    
    // Imprimir fila de la traza
    std::cout << std::left << std::setw(15) << estado_actual << std::setw(10) << simbolo_actual << estado_siguiente << std::endl;

    estado_actual = estado_siguiente;
    
    // Si la transición devuelve -1 (no existe), el autómata se bloquea
    if (estado_actual == -1) {
      break;
    }
  }

  // Comprobar si el estado en el que terminó es de aceptación
  Estado estado_final_alcanzado = busqueda_estado(estado_actual);
  if (estado_final_alcanzado.get_aceptacion() == true) {
    std::cout << "Cadena de entrada ACEPTADA." << std::endl << std::endl;
    return true;
  } else {
    std::cout << "Cadena de entrada RECHAZADA." << std::endl << std::endl;
    return false;
  }
}


/**
 * @brief Sobrecarga del operador de extraccion de la clase Autómata
 * @param out Variable ostream para sacar por pantalla
 * @param automata Objeto Alfabeto que se va a escribir
 * @return Se devuelve el out con los los valores a imprimirse
*/
std::ostream& operator<<(std::ostream& out, const Automata& automata) {
  out << "Autómata" << std::endl;
  out << "Alfabeto: " << automata.alfabeto_ << std::endl;
  out << "Numero Estados: " << automata.conjunto_estados_.size() << std::endl;
  out << "Estado Inicial: " << automata.estado_inicial_ << std::endl;
  out << "Estados: " << std::endl;
  for (auto it = automata.conjunto_estados_.begin(); it != automata.conjunto_estados_.end(); ++it) {
    if (it != automata.conjunto_estados_.begin()) {
      out << std::endl;
    }
    out << (*it);
  }
  out << std::endl;
  out << "Estados Finales: " << std::endl;
  for (auto it = automata.estados_finales_.begin(); it != automata.estados_finales_.end(); ++it) {
    if (it != automata.estados_finales_.begin()) {
      out << std::endl;
    }
    out << (*it);
  }
  out << std::endl;

  return out;
}