// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Autómatas finitos
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 16/10/2026
// Archivo Analizador.h: programa que contiene la declaración de la función que analiza el .fa


#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#include "Automata.h"



void Analizador_automata(const std::string& nombre_archivo, Automata& automata);
void Comprobar_cadena(std::string nombre_archivo2, Automata automata);

#endif