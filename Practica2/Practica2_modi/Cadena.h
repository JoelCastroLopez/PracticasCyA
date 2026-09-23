// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Cadena.h: programa definición de la clase Cadena.
// Contiene la definición de la clase Cadena

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>
#include <string>
#include "Alfabeto.h"


class Lenguaje;  // Definición anticipada de la clase Lenguaje (solución a dependencia circular)

class Cadena {
  public:
    // Constructores
    Cadena(void);
    Cadena(std::string simbolos, Alfabeto alfabeto);

    //Destructor
    ~Cadena() {}

    // Métodos de la clase
    void PushSimbolo(char nuevo_simbolo);
    Cadena Inversa();
    Lenguaje Prefijos();
    Lenguaje Sufijos();
    int get_longitud() { return longitud_;}  // Getter para obtener el tamaño de la cadena

    // Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& out, const Cadena& cadena);

    // Modificación
    Cadena Potencia(int potencia);
  
  private:
    std::vector<char> simbolos_cadena_;
    Alfabeto alfabeto_;
    int longitud_;
    bool vacia_;
};

#endif