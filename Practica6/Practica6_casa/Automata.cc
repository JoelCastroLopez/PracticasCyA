// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2025
// Archivo Automata.cc: programa que contiene la implementación de la clase autómata


#include <iostream>


#include "Automata.h"
#include "Estado.h"



/**
 * @brief Constructor de la clase Autómata
*/
Automata::Automata(void) {}


/**
 * @brief Muestra los estados en el set de estados actuales
*/
void Automata::mostrar_estados_actuales() {
  for (const Estado& estado : estados_actuales_) {
    std::cout << estado.get_nombre() << " ";
  }
  std::cout << std::endl;
}


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
  Estado estado("-1 0 0");
  return estado;
}


/**
 * @brief Comprueba estados actuales y finales
 * @return Devuelve si alguno de los estados actuales se encuentra también entre los finales
*/
bool Automata::comprobacion_estados_finales() {
  for (Estado estado_aux1 : estados_actuales_) {
    for (Estado estado_aux2 : estados_finales_) {
      if (estado_aux1 == estado_aux2) {
        return true;
      }
    }
  }
  return false;
}


/**
 * @brief Devuelve si una cadena es aceptada o no por nuestro autómata
 * @param cadena Cadena a comprobar
 * @return Se devuelve si una cadena es aceptada o no
*/
bool Automata::cadena_aceptada(Cadena cadena) {
  vaciar_estado_actual();  // Vacío los estados actuales por si ya se ha hecho este proceso antes
  push_estados_actuales(busqueda_estado(estado_inicial_));

  for (int i = 0; i < cadena.get_simbolos().size(); i++) {   // Se recorre símbolo a símbolos de la cadena a comprobar
    std::set<Estado> copia_estados_actuales = estados_actuales_;   // Creamos una copia y vaciamos los estados actuales para no perderlos ni mezclarlos con los siguientes
    vaciar_estado_actual();   

    for (Estado estado_aux1 : copia_estados_actuales) {   // Recorremos los estados actuales y buscamos en ellos las transiciones con un símbolo
      std::set<int> vector_aux = estado_aux1.transicion_con_simbolo(cadena.get_simbolos()[i]);

      for (int identificador_estado2 : vector_aux) {   // Recorremos el vector de estados siguientes con la transición y los metemos en el vector de estados actuales
        if (busqueda_estado(identificador_estado2).get_nombre() != -1) {
          push_estados_actuales(busqueda_estado(identificador_estado2));
        }
      }
    }
  }

  if (comprobacion_estados_finales() == true) {   // Comprobamos si, tras el recorrido, se ha quedado en un estado de finalización o no
    return true;
  } else {
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
  out << "Estado(s) Actual(es): " << std::endl;
  for (auto it = automata.estados_actuales_.begin(); it != automata.estados_actuales_.end(); ++it) {
    if (it != automata.estados_actuales_.begin()) {
      out << std::endl;
    }
    out << (*it);
  }
  out << std::endl;

  return out;
}
