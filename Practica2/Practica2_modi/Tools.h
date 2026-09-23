// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Tools.h: programa definición de funciones auxiliares.
// Contiene la definición de funciones auxiliares

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <fstream>


void Usage(int argc, char* argv[]);
void Instruccion(int argc, char* argv[]);
void Alfabeto_incorrecto(std::string cadena);
bool Cadena_perteneciente(std::string cadena, Alfabeto alfabeto);

#endif