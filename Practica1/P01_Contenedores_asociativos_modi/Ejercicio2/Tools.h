// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: alu0101485515@ull.edu.es
// Fecha: 14/09/2026
// Archivo: Tools.cc: programa que contiene la declaración de funciones de apoyo
//

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <regex>

#include "Alumno.h"

// Comprobar entrada
void Usage(int argc, char* argv[]);

// Función de análisis de entrada
void AnalisisEntrada(const std::string& entrada, std::set<Alumno>& estudiantes);

// Función para introducción de alu's manualmente
void IntroduccionManual(const std::string& entrada, std::set<Alumno>& estudiantes);

// Imprime los elementos del set de alumnos
void ImprimirResultado(const std::set<Alumno>& estudiantes);

#endif