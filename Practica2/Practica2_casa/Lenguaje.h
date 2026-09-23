// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Lenguaje.h: programa definición de la clase Lenguaje.
// Contiene la definición de la clase Lenguaje

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <vector>
#include "Alfabeto.h"


class Cadena;  // Definición anticipada de la clase Cadena (solución a dependencia circular)

class Lenguaje {
  public:
    // Constructores
    Lenguaje();
    Lenguaje(std::vector<Cadena> secuencia_cadenas);

    // Destructor
    ~Lenguaje() {}

    // Getters
    std::vector<Cadena> get_cadenas_lenguaje() { return cadenas_lenguaje_;}

    // Métodos de la clase
    void PushCadena(Cadena cadena_nueva);
    void PushCadenaVacia();

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);
    friend std::istream& operator>>(std::istream& in, Lenguaje& lenguaje);
    

  private:
    std::vector<Cadena> cadenas_lenguaje_;
};

#endif