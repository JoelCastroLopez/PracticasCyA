// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Analizador.cc: programa que contiene la implementación de la función que analiza el .dfa

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>

#include "Analizador.h"

/**
 * @brief Comprueba si una línea leída es válida (no está vacía y no es un comentario)
 * @param linea Cadena de texto a evaluar
 * @return True si tiene datos útiles, False si es un comentario o está vacía
*/
bool EsLineaValida(std::string linea) {
  linea.erase(std::remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
  
  if (linea.empty()) {
    return false;
  }

  std::regex patron_comentario("^//.*");
  if (std::regex_match(linea, patron_comentario)) {
    return false;
  }

  return true;
}

/**
 * @brief Analiza y mete los datos al automata
 * @param nombre_archivo Nombre del fichero de entrada
 * @param automata Automata base
*/
void Analizador_automata(const std::string& nombre_archivo, Automata& automata) {
  std::ifstream archivo_entrada(nombre_archivo);
  
  // Verificación de apertura correcta del archivo
  if (!archivo_entrada.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de especificación del autómata '" << nombre_archivo << "'." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linea;

  // Buscar alfabeto
  while (std::getline(archivo_entrada, linea)) {
    if (EsLineaValida(linea)) break;
  }
  linea.erase(std::remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
  Alfabeto alfabeto(linea);
  automata.set_alfabeto(alfabeto);

  // Buscar número de estados
  while (std::getline(archivo_entrada, linea)) {
    if (EsLineaValida(linea)) break;
  }
  int numero_estados = stoi(linea);

  // Buscar estado inicial
  while (std::getline(archivo_entrada, linea)) {
    if (EsLineaValida(linea)) break;
  }
  int estado_inicial = stoi(linea);
  automata.set_estado_inicial(estado_inicial);
  
  // Buscar las transiciones de cada estado
  for (int i = 0; i < numero_estados; i++) {
    while (std::getline(archivo_entrada, linea)) {
      if (EsLineaValida(linea)) break;
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
  
  // Verificación de apertura correcta del archivo
  if (!archivo_entrada2.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de cadenas '" << nombre_archivo2 << "'." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linea;

  while(std::getline(archivo_entrada2, linea)) {
    Cadena cadena(linea, automata.get_alfabeto());
    
    std::cout << "Evaluando cadena: " << cadena << std::endl;
    automata.cadena_aceptada(cadena);
    std::cout << "----------------------------------------" << std::endl;
  }

  archivo_entrada2.close();
}