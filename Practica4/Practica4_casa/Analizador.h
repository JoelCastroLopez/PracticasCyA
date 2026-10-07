// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Analizador.cc: programa que contiene la declaración de la función que analiza el código

#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#include "Almacen.h"
#include "Comentario.h"
#include "Etiqueta.h"
#include "Atributo.h"

void AnalizadorCodigo(const std::string& inputFileName, const std::string& outputFileName);

#endif