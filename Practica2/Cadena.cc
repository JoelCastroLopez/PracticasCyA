// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2025
// Archivo Cadena.cc: programa implementación de la clase Cadena.
// Contiene la implementación de la clase Cadena

#include "Cadena.h"
#include "Lenguaje.h"


/**
 * @brief Constructor clase Cadena por defecto
*/
Cadena::Cadena(void) {}

/**
 * @brief Constructor clase Cadena por parámetros
 * @param simbolos Simbolos de la cadena
 * @param alfabeto Alfabeto al que pertenecerá la cadena
*/
Cadena::Cadena(std::string simbolos, Alfabeto alfabeto) {
  alfabeto_ = alfabeto;
  if (simbolos.size() == 1 && simbolos[0] == '&') {  // Comprobamos si la cadena que se nos ha dado es la cadena vacía, en dado caso se activa el atributo a true
    vacia_ == true;                                  // y el vector de la cadena queda vacío
  } else {
    for (int i = 0; i < simbolos.size(); i++) {      // Si la cadena no es la vacía, se pasan los caracteres de la string al vector de la cadena 
      if (alfabeto.busqueda_simbolo(simbolos[i]) == false) {  // Comprobamos que los símbolos pertenecen al alfabeto correspondiente
        if (simbolos[i] == '&') {
          std::cout << "No se puede introducir el simbolo '&', solo se puede usar en el fichero filein.txt para representar la cadena vacía, " << std::endl;
          std::cout << "esto sería de manera individual, no delante, detras o entre otros símbolos de la cadena" << std::endl;
          exit(EXIT_FAILURE);
        }
        std::cout << "El símbolo '" << simbolos[i] << "' no pertenece al alfabeto " << alfabeto << std::endl;
        exit(EXIT_FAILURE);
      }
      simbolos_cadena_.push_back(simbolos[i]);
    }
  }
  longitud_ = simbolos_cadena_.size();  // Damos valor a la longuitud con el size() del vector
}

/**
 * @brief Método para meter simbolos a la cadena
 * @param nuevo_simbolo Caracter nuevo a introducir
*/
void Cadena::push_simbolo(char nuevo_simbolo) {
  if (nuevo_simbolo == '&') {
    std::cout << "No se puede introducir el simbolo '&', solo se puede usar en el fichero filein.txt para representar la cadena vacía" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (alfabeto_.busqueda_simbolo(nuevo_simbolo) == false) {  // Comprobamos que los símbolos pertenecen al alfabeto correspondiente
    std::cout << "El símbolo '" << nuevo_simbolo << "' no pertenece al alfabeto " << alfabeto_ << std::endl;
    exit(EXIT_FAILURE);
  }
  simbolos_cadena_.push_back(nuevo_simbolo);
}

/**
 * @brief Método para sacar la cadena inversa a una dada
 * @return Se devuelve la cadena inversa
*/
Cadena Cadena::inversa() {
  std::string inversa_string;
  if (simbolos_cadena_.size() == 0) {  // Caso exclusivo de la cadena vacía
    inversa_string.push_back('&');
  } else {
    for (int i = ((simbolos_cadena_.size()) - 1); i >= 0; i--) {  // Recorremos la cadena en orden inverso, y vamos metiendo símbolos en un string auxiliar
      inversa_string.push_back(simbolos_cadena_[i]);
    }
  }
  Cadena cadena_inversa(inversa_string, alfabeto_);
  return cadena_inversa;
}

/**
 * @brief Método para conformar el lenguaje formado por los prefijos de la cadena
 * @return Se devuelve el lenguaje formado por los prefijos de la cadena
*/
Lenguaje Cadena::prefijos() {
  Lenguaje lenguaje_final;
  lenguaje_final.push_cadena_vacia();
  if (simbolos_cadena_.size() == 0) {  // Caso exclusivo de la cadena vacía
    return lenguaje_final;
  } else {
    for (int i = 0; i < simbolos_cadena_.size(); i++) {  // Primer bucle para recorrer la cadena
      std::string string_aux;
      for (int j = 0; j <= i; j++) {                     // Segundo bucle para ir sacando prefijos del tamaño correspondiente a la iteración del primero
        string_aux.push_back(simbolos_cadena_[j]);
      }
      Cadena cadena_aux(string_aux, alfabeto_);
      lenguaje_final.push_cadena(cadena_aux);
    }
  }
  
  return lenguaje_final;
}

/**
 * @brief Método para conformar el lenguaje formado por los sufijos de la cadena
 * @return Se devuelve el lenguaje formado por los sufijos de la cadena
*/
Lenguaje Cadena::sufijos() {
  Lenguaje lenguaje_final;
  lenguaje_final.push_cadena_vacia();
  if (simbolos_cadena_.size() == 0) {   // Caso exclusivo de la cadena vacía
    return lenguaje_final;
  } else {
    for (int i = simbolos_cadena_.size() - 1; i >= 0; i--) {  // Primer bucle para recorrer la cadena desde el final
      std::string string_aux;
      for (size_t j = i; j < simbolos_cadena_.size(); j++) {  // Segundo bucle para ir sacando sufijos del tamaño correspondiente a la iteración del primero
        string_aux.push_back(simbolos_cadena_[j]);
      }
      Cadena cadena_aux(string_aux, alfabeto_);
      lenguaje_final.push_cadena(cadena_aux);
    }
    return lenguaje_final;
  }
}
/**
 * @brief Sobrecarga del operador de extraccion de la clase Cadena
 * @param out Variable ostream para sacar por pantalla
 * @param cadena Objeto Cadena que se va a escribir
 * @return Se devuelve el out con los los valores a imprimirse
*/
std::ostream& operator<<(std::ostream& out, const Cadena& cadena) {
  if (cadena.simbolos_cadena_.size() == 0) {  // Caso exclusivo para mostrar la cadena vacía
    out << '&';
    return out;
  }
  for (int i = 0; i < cadena.simbolos_cadena_.size(); i++) {
    out << cadena.simbolos_cadena_[i];
  }
  return out;
}

/**
 * @brief Sobrecarga del operador de inserción de la clase Cadena
 * @param in Variable istream donde estará la información que recibirá cadena
 * @param cadena Objeto Cadena sobre el que se va a escribir
 * @return Se devuelve el in después de usarse
*/
std::istream& operator>>(std::istream& in, Cadena& cadena) {
  std::string valor_entrada;
  in >> valor_entrada;
  for (int i = 0; i < valor_entrada.size(); i++) {
    cadena.push_simbolo(valor_entrada[i]);
  }
  return in;
}

// Modificación
bool Cadena::iguales(Cadena cadena2) {
  if (longitud_ != cadena2.longitud_) {
    return false;
  }
  for (int i = 0; i < simbolos_cadena_.size(); i++) {
    if (simbolos_cadena_[i] != cadena2.simbolos_cadena_[i]) {
      return false;
    }
  }
  return true;
}

Lenguaje Cadena::lss() {
  Lenguaje lenguaje_lss;
  lenguaje_lss.push_cadena_vacia();
  std::string string_aux;
  int tamanio{1};
  for (int i = 0; i < simbolos_cadena_.size(); i++) {
    for (int j = 0; j < simbolos_cadena_.size(); j++) {
      string_aux.clear();
      for (int k = 0; k < tamanio; k++) {
        string_aux.push_back(k);
      }
      Cadena cadena_aux(string_aux, alfabeto_);
      lenguaje_lss.push_cadena(cadena_aux);
    }
    tamanio++;
  }
}