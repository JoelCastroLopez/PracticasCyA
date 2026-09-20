// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Alfabeto.h: programa definición de la clase Alfabeto.
// Contiene la definición de la clase Alfabeto

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <set>
#include <vector>


class Alfabeto {
  public:
    // Constructores
    Alfabeto(void);
    Alfabeto(std::string& entrada_alfabeto);
    Alfabeto(const Alfabeto& alfabeto);

    // Destructor
    ~Alfabeto() {}

    // Métodos de la clase
    void push_simbolos(std::string nuevos_simbolos);
    bool busqueda_simbolo(char caracter);
    std::set<char> get_simbolos_alfabeto() const { return simbolos_alfabeto_;}

    // Sobrecarga de operador extracción
    friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);
    friend std::istream& operator>>(std::istream& in, Alfabeto& alfabeto);

  private:
    std::set<char> simbolos_alfabeto_;
};

#endif