// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2025
// Archivo Analizador.cc: programa que contiene la implementación de la función que analiza el .fa


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


#include "Analizador.h"



/**
 * @brief Analiza y mete los datos al automata
 * @param nombre_archivo Nombre del fichero de entrada
 * @param automata Automata base
*/
void Analizador_automata(const std::string& nombre_archivo, Automata& automata) {
  std::ifstream archivo_entrada(nombre_archivo);
  std::string linea;

  std::getline(archivo_entrada, linea);
  linea.erase(std::remove_if(linea.begin(), linea.end(), ::isspace), linea.end()); // Elimino espacios
  Alfabeto alfabeto(linea);
  automata.set_alfabeto(alfabeto);

  std::getline(archivo_entrada, linea);
  int numero_estados = stoi(linea);

  std::getline(archivo_entrada, linea);
  int estado_inicial = stoi(linea);
  automata.set_estado_inicial(estado_inicial);
  bool esta_ok = true;
  for (int i = 0; i < numero_estados; i++) {
    std::getline(archivo_entrada, linea);
    for(int j{6}; j < linea.length() && esta_ok; j += 4) {    // Comprobar si los símbolos que entran están en el alfabeto
      if(!alfabeto.busqueda_simbolo(linea.at(j))) esta_ok = false;
    }
    if(!esta_ok) {
      std::cerr << "Algún símbolo de algún estado no se encuentra en el alfabeto introducido, por favor, verifique ";
      std::cerr << "que la entrada es correcta" << std::endl;
      exit(EXIT_FAILURE);
    }
    Estado estado(linea);
    automata.push_estado(estado);
    if (estado.get_aceptacion() == true) {
      automata.push_estados_finales(estado);
    }
  }

  archivo_entrada.close();
}


/**
 * @brief Analiza y verifica las cadenas de entrada con el autómata
 * @param nombre_archivo2 Nombre del fichero de entrada de cadenas
 * @param automata Automata base
*/
void Comprobar_cadena(std::string nombre_archivo2, Automata automata) {
  std::ifstream archivo_entrada2(nombre_archivo2);
  std::string linea;

  while(std::getline(archivo_entrada2, linea)) {
    Cadena cadena(linea, automata.get_alfabeto());
    if(automata.cadena_aceptada(cadena) == true) {
      std::cout << cadena << " --- Accepted" << std::endl;
    } else {
      std::cout << cadena << " --- Rejected" << std::endl;
    }
  }

  archivo_entrada2.close();
}


void Gramaticas(const std::string& nombre_archivo, const std::string& nombre_archivo2) {
  std::ifstream archivo_entrada(nombre_archivo);
  std::ofstream archivo_salida(nombre_archivo2);
  std::string linea;
  std::string linea2;

  std::getline(archivo_entrada, linea2);
  linea2.erase(std::remove_if(linea2.begin(), linea2.end(), ::isspace), linea2.end()); // Elimino espacios
  Alfabeto alfabeto(linea2);
  archivo_salida << alfabeto << std::endl;

  std::getline(archivo_entrada, linea);
  int numero_estados = stoi(linea);
  archivo_salida << numero_estados << std::endl;

  std::getline(archivo_entrada, linea);
  int estado_inicial = stoi(linea);
  char miembro_inicial = estado_inicial + 'A';
  archivo_salida << miembro_inicial << std::endl;
  
  for (int i = 0; i < numero_estados; i++) {
    std::getline(archivo_entrada, linea);
    std::string aux1;
    aux1.push_back(linea[0]);
    int nombre_entero = stoi(aux1);
    char nombre = nombre_entero + 'A';

    std::string aux3;
    aux3.push_back(linea[2]);
    int aceptacion = stoi(aux3);
    if (aceptacion == 1) {
      archivo_salida << nombre << " -> &" << std::endl;
    }

    std::string aux2;
    aux2.push_back(linea[4]);
    int numero_transiciones = stoi(aux2);

    if (numero_transiciones != linea2.size()) {
      std::cerr << "ESTO NO ES UN DFA, NO PUEDO SEGUIR CON ELL PROCESO" << std::endl;
      exit(EXIT_FAILURE);
    }

    for(int j{6}; j < linea.size(); j += 4) {    // Comprobar si los símbolos que entran están en el alfabeto
      std::string aux4;
      aux4.push_back(linea[j]);
      std::string aux5;
      aux5.push_back(linea[j + 1]);
      int siguiente = stoi(aux3);
      aux4.push_back(siguiente + 'A');
      archivo_salida << nombre << " -> " << aux4 << std::endl;
    }

  }
}