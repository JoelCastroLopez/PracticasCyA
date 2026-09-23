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


// Constructor clase Alfabeto por defecto
Alfabeto::Alfabeto(void) {}

// Constructor clase Alfabeto por parámetros
Alfabeto::Alfabeto(std::string& entrada_alfabeto) {
  for (int i = 0; i < entrada_alfabeto.size(); i++) {
    simbolos_alfabeto_.insert(entrada_alfabeto[i]);
  }
}

// Constructor de copia clase Alfabeto
Alfabeto::Alfabeto(const Alfabeto& alfabeto) {
  simbolos_alfabeto_ = alfabeto.simbolos_alfabeto_;
}

// Método para meter simbolos al alfabeto
void Alfabeto::PushSimbolos(const std::string& nuevos_simbolos) {
  for (int i = 0; i < nuevos_simbolos.size(); i++) {
    simbolos_alfabeto_.insert(nuevos_simbolos[i]);
  }
}

// Método para comprobar si un caracter está dentro de un alfabeto o no
bool Alfabeto::BusquedaSimbolo(const char& caracter_buscado) {
  for (char caracter : simbolos_alfabeto_) {    // Recorremos el set de simbolos correspondientes al alfabeto para verificar si uno nuevo pertenece al mismo
    if (caracter == caracter_buscado) {
      return true;
    }
  }
  return false;
}

// Sobrecarga del operador de extraccion de la clase Alfabeto
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

// Sobrecarga del operador de inserción de la clase Alfabeto
std::istream& operator>>(std::istream& in, Alfabeto& alfabeto) {
  std::string valor_entrada;
  in >> valor_entrada;
  alfabeto.PushSimbolos(valor_entrada);
  return in;
}