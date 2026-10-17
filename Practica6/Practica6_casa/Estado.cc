// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Estado.cc: programa que contiene la declaración de la clase estado

#include "Estado.h"

/**
 * @brief Constructor de la clase Estado
*/
Estado::Estado(void) {}

/**
 * @brief Constructor clase estado
 * @param informacion Linea de la cual sacar los estados
*/
Estado::Estado(std::string informacion) {
  int veredicto;

  std::istringstream flujo_enteros(informacion);   
  flujo_enteros >> nombre_ >> veredicto;

  if (veredicto == 0) {
    aceptacion_ = false;
  } else {
    aceptacion_ = true;
  }
  
  std::string entrada_string, estado_resultante;

  // Seguimos leyendo del mismo flujo hasta que se acabe la línea en pares
  while (flujo_enteros >> entrada_string >> estado_resultante) {   // Meto los datos en el map del estado en sí
    char entrada = entrada_string[0];
    int estado_siguiente = stoi(estado_resultante);
    transiciones_.insert({entrada, estado_siguiente});
  }
}

/**
 * @brief Devuelve los símbolos del estado
 * @return Devuelve el set con los símbolos del estado
*/
std::set<char> Estado::get_simbolos_transiciones() {
  std::set<char> simbolos;
    for (const auto& par : transiciones_) {
      simbolos.insert(par.first);
    }
  return simbolos;
}

/**
 * @brief Devuelve el estado siguiente de cierto símbolo
 * @param simbolo Símbolo a buscar
 * @return Devuelve el estado correspondiente a la transición
*/
int Estado::transicion_con_simbolo(char simbolo) {
  auto it = transiciones_.find(simbolo);
  if (it != transiciones_.end()) {
    return it->second;
  }
  return -1; // Devuelve -1 si no hay transición definida
}

/**
 * @brief Sobrecarga operador <<
 * @param out Salida por pantalla
 * @param estado Estado a imprimir
 * @return Se devuelve lo que sale por pantalla
*/
std::ostream& operator<<(std::ostream& out, const Estado& estado) {
  out << "[" << estado.nombre_ << "] " << " -> " << estado.aceptacion_;
  return out;
}

/**
 * @brief Sobrecarga del operador menor de la clase Estado
 * @param estado1 Primer objeto Cadena que se va a comparar
 * @param estado2 Segundo objeto Cadena que se va a comparar
 * @return Se devuelve si el primero es menor que el segundo
*/
bool operator<(Estado estado1, Estado estado2) {
  if (estado1.nombre_ < estado2.nombre_) {
    return true;
  } 
  return false;
}

/**
 * @brief Sobrecarga del operador == de la clase Estado
 * @param estado2 Segundo objeto estado que se va a comparar
 * @return Se devuelve si el primero es igual que el segundo
*/
bool Estado::operator==(const Estado& estado2) {
  return nombre_ == estado2.nombre_ && aceptacion_ == estado2.aceptacion_ && transiciones_ == estado2.transiciones_;
}