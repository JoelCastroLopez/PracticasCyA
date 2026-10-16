// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2025
// Archivo Estado.cc: programa que contiene la declaración de la clase estado
// Contiene el programa principal


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
  int n_transiciones;

  std::istringstream flujo_enteros(informacion);   // Creamos un flujo de emteros para analizar los primeros tres apartados del string que nos llega
  flujo_enteros >> nombre_ >> veredicto >> n_transiciones;

  if (veredicto == 0) {
    aceptacion_ = false;
  } else {
    aceptacion_ = true;
  }
  
  std::string valores_transiciones;                // Con otro flujo, esta vez de strings, analizamos lo que queda de la cadena
  for (int i{6}; i < informacion.size(); i++) {
    valores_transiciones.push_back(informacion[i]);
  }
  
  std::stringstream flujo_strings(valores_transiciones);
  std::string entrada_string, estado_resultante;

  while (flujo_strings >> entrada_string >> estado_resultante) {   // Meto los datos en el multimap del estado en sí
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
 * @brief Devuelve los estados siguientes de un vector con cierto símbolo
 * @param simbolo Símbolo a buscar
 * @return Devuelve el vector con los estados correspondientes a la transición
*/
std::set<int> Estado::transicion_con_simbolo(char simbolo) {
  std::set<int> transiciones;
  auto rango = transiciones_.equal_range(simbolo);
    for (auto it = rango.first; it != rango.second; ++it) {
      transiciones.insert(it->second);
    }
  return transiciones;
}


/*Estado busqueda_estado(int nombre, std::set<Estado> estados_totales) {
  for (Estado iterador : estados_totales) {
    if (iterador.get_nombre() == nombre) {
      return iterador;
    }
  }
  Estado estado("-1 0 0");
  return estado;
}*/


/*void Estado::epsilon_clausura(std::set<int> clausura, std::set<Estado> estados_totales) {
  // Si este estado ya está en la clausura, no hacemos nada
    if (clausura.find(get_nombre()) != clausura.end())
        return;

    // Añadimos este estado a la clausura
    clausura.insert(get_nombre());

    // Buscamos los destinos por epsilon
    std::set<int> epsilons = transicion_con_simbolo('&');

    // Para cada destino, llamamos recursivamente
    for (int id : epsilons) {
        Estado auxiliar;
        Estado siguiente = auxiliar.busqueda_estado(id, estados_totales);
        siguiente.epsilon_clausura(clausura, estados_totales);
    }
}*/


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