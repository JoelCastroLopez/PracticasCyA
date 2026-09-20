// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2025
// Archivo Tools.h: programa definición de funciones auxiliares.
// Contiene la definición de funciones auxiliares

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <fstream>


void Usage(int argc, std::string argv1);
void Instruccion(std::string opcode, std::string argv1, std::string argv2);
void Alfabeto_incorrecto(std::string cadena);

#endif