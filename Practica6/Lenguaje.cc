// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2025
// Archivo Lenguaje.cc: programa implementación de la clase Lenguaje.
// Contiene la implementación de la clase Lenguaje

#include "Lenguaje.h"
#include "Cadena.h"


/**
 * @brief Constructor clase Lenguaje por defecto
*/
Lenguaje::Lenguaje(void) {}

/**
 * @brief Constructor clase Lenguaje por parámetros
 * @param secuencia_cadenas Vector con la secuencia de acdenas que corresponderán al lenguaje
*/
Lenguaje::Lenguaje(std::vector<Cadena> secuencia_cadenas) {
  for (int i = 0; i < secuencia_cadenas.size(); i++) {
    cadenas_lenguaje_.push_back(secuencia_cadenas[i]);
  }
}

/**
 * @brief Método para meter cadenas un lenguaje
 * @param cadena Cadena a introducir en el lenguaje
*/
void Lenguaje::push_cadena(Cadena cadena) {
  cadenas_lenguaje_.push_back(cadena);
}

/**
 * @brief Método para meter la cadena vacía en un lenguaje si fuese necesario
*/
void Lenguaje::push_cadena_vacia() {
  Alfabeto alfabeto;
  std::string signo_cadena_vacia{"&"};
  Cadena cadena_vacia(signo_cadena_vacia, alfabeto);
  push_cadena(cadena_vacia);
}

/**
 * @brief Sobrecarga del operador de extraccion de la clase Lenguaje
 * @param out Variable ostream para sacar por pantalla
 * @param lenguaje Objeto Lenguaje que se va a escribir
 * @return Se devuelve el out con los los valores a imprimirse
*/
std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje) {
  out << "{";
  int valor_coma{0};
  for (Cadena cadena : lenguaje.cadenas_lenguaje_) {
    if (valor_coma > 0) {
      out << ", ";
    }
    out << cadena;
    valor_coma++;
  }
  out << "}";
  return out;
}

/**
 * @brief Sobrecarga del operador de inserción de la clase Lenguaje
 * @param in Variable istream donde estará la información que recibirá lenguaje
 * @param lenguaje Objeto Lenguaje sobre el que se va a escribir
 * @return Se devuelve el in después de usarse
*/
std::istream& operator>>(std::istream& in, Lenguaje& lenguaje) {
  std::string valor_entrada;
  in >> valor_entrada;
  Alfabeto alfabeto(valor_entrada);
  Cadena cadena(valor_entrada, alfabeto);
  lenguaje.push_cadena(cadena);
  return in;
}