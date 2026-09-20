// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Alfabeto.cc: programa implementación de la clase Alfabeto.
// Contiene la implementación de la clase Alfabeto

#include "Alfabeto.h"


/**
 * @brief Constructor clase Alfabeto por defecto
*/
Alfabeto::Alfabeto(void) {}

/**
 * @brief Constructor clase Alfabeto por parámetros
 * @param entrada_alfabeto Cadena a partir de la cual se formará la cadena
*/
Alfabeto::Alfabeto(std::string& entrada_alfabeto) {
  for (int i = 0; i < entrada_alfabeto.size(); i++) {
    simbolos_alfabeto_.insert(entrada_alfabeto[i]);
  }
}

/**
 * @brief Constructor de copia clase Alfabeto
 * @param alfabeto Objeto Alfabeto que se va a copiar
*/
Alfabeto::Alfabeto(const Alfabeto& alfabeto) {
  simbolos_alfabeto_ = alfabeto.simbolos_alfabeto_;
}

/**
 * @brief Método para meter simbolos al alfabeto
 * @param nuevos_simbolos Cadena con todos los símbolos nuevos a introducir
*/
void Alfabeto::push_simbolos(std::string nuevos_simbolos) {
  for (int i = 0; i < nuevos_simbolos.size(); i++) {
    simbolos_alfabeto_.insert(nuevos_simbolos[i]);
  }
}

/**
 * @brief Método para comprobar si un caracter está dentro de un alfabeto o no
 * @param caracter_buscado Caracter a buscar dentro del alfabeto
 * @return Se devuelve si el caracter se encuentra en el alfabeto o no
*/
bool Alfabeto::busqueda_simbolo(char caracter_buscado) {
  for (char caracter : simbolos_alfabeto_) {    // Recorremos el set de simbolos correspondientes al alfabeto para verificar si uno nuevo pertenece al mismo
    if (caracter == caracter_buscado) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de extraccion de la clase Alfabeto
 * @param out Variable ostream para sacar por pantalla
 * @param alfabeto Objeto Alfabeto que se va a escribir
 * @return Se devuelve el out con los los valores a imprimirse
*/
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << "{";
  int valor_coma{0};
  for (char caracter : alfabeto.simbolos_alfabeto_) {
    if (valor_coma > 0) {
      out << ", ";
    }
    out << caracter;
    valor_coma++;
  }
  out << "}";
  return out;
}

/**
 * @brief Sobrecarga del operador de inserción de la clase Alfabeto
 * @param in Variable istream donde estará la información que recibirá alfabeto
 * @param alfabeto Objeto Alfabeto sobre el que se va a escribir
 * @return Se devuelve el in después de usarse
*/
std::istream& operator>>(std::istream& in, Alfabeto& alfabeto) {
  std::string valor_entrada;
  in >> valor_entrada;
  alfabeto.push_simbolos(valor_entrada);
  return in;
}