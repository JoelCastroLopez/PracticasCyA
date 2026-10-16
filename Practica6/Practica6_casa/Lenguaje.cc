// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Lenguaje.cc: programa implementación de la clase Lenguaje.
// Contiene la implementación de la clase Lenguaje

#include "Lenguaje.h"
#include "Cadena.h"


// Constructor clase Lenguaje por defecto
Lenguaje::Lenguaje(void) {}

// Constructor clase Lenguaje por parámetros
Lenguaje::Lenguaje(std::vector<Cadena> secuencia_cadenas) {
  for (int i = 0; i < secuencia_cadenas.size(); i++) {
    cadenas_lenguaje_.push_back(secuencia_cadenas[i]);
  }
}

// Método para meter cadenas un lenguaje
void Lenguaje::PushCadena(Cadena cadena) {
  cadenas_lenguaje_.push_back(cadena);
}

// Método para meter la cadena vacía en un lenguaje si fuese necesario
void Lenguaje::PushCadenaVacia() {
  Alfabeto alfabeto;
  std::string signo_cadena_vacia{"&"};
  Cadena cadena_vacia(signo_cadena_vacia, alfabeto);
  PushCadena(cadena_vacia);
}

// Sobrecarga del operador de extraccion de la clase Lenguaje
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

// Sobrecarga del operador de inserción de la clase Lenguaje
std::istream& operator>>(std::istream& in, Lenguaje& lenguaje) {
  std::string valor_entrada;
  in >> valor_entrada;
  Alfabeto alfabeto(valor_entrada);
  Cadena cadena(valor_entrada, alfabeto);
  lenguaje.PushCadena(cadena);
  return in;
}