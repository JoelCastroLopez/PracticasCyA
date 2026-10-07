// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Analizador.cc: programa que contiene la parte que analiza el código e imprime en el documento de salida

#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#include "Analizador.h"

/**
 * @brief Analiza el código
 * @param inputFileName Nombre del fichero de entrada
 * @param outputFileName Nombre del fichero de salida
*/
void AnalizadorCodigo(const std::string& inputFileName, const std::string& outputFileName) {
  std::ifstream inputFile(inputFileName);
  std::ofstream outputFile(outputFileName);
  std::string line;
  int numero_linea = 1;

  // Patrones regex
  std::regex patronDoctype(R"regex(<!DOCTYPE\s+([a-zA-Z0-9]+)>)regex", std::regex_constants::icase);
  std::regex patronEtiqueta(R"regex(<\s*(/?)\s*(html|head|title|body|h1|p|a|img)\b([^>]*)>)regex");
  std::regex patronAtributo(R"regex(([a-zA-Z-]+)\s*=\s*"([^"]*)")regex");
  std::regex comentarioUnaLinea(R"regex(<!--(.*?)-->)regex");
  std::regex inicioComentario(R"regex(<!--(.*))regex");
  std::regex finComentario(R"regex((.*?)-->)regex");

  Almacen almacen;

  almacen.set_nombre_fichero(inputFileName);

  bool dentro_comentario = false;
  std::string auxiliar_comentarios;
  int inicio_comentario;

  bool doctype_visto = false;
  bool etiquetas_vistas = false;

  // Analizo el input del fichero de entrada por lineas
  while (std::getline(inputFile, line)) {
    // Limpiamos los espacios y tabulaciones al principio de la línea
    line = std::regex_replace(line, std::regex(R"(^\s+)"), "");
    std::smatch matches;

    // Comentarios multilínea
    if (dentro_comentario) {
      if (std::regex_search(line, matches, finComentario)) {
        auxiliar_comentarios += "\n" + line; // Guardamos la línea entera del cierre
        Comentario comentario_m(inicio_comentario, numero_linea, auxiliar_comentarios);
        almacen.PushVectorComentarios(comentario_m);
        
        // Si no hemos visto ninguna etiqueta, cuenta como descripción
        if (doctype_visto && !etiquetas_vistas) {
          almacen.set_descripcion();
        }

        // Reiniciamos variables auxiliares
        inicio_comentario = 0;
        auxiliar_comentarios.clear();
        dentro_comentario = false;
      } else {
        auxiliar_comentarios += "\n" + line;
      }
      numero_linea++;
      // Si estamos dentro del comentario, saltamos el resto de comprobaciones, ya que, al ser comentarios, no tienen validez
      continue; 
    }

    // DOCTYPE
    if (std::regex_search(line, matches, patronDoctype)) {
      almacen.set_doctype(matches[1].str());
      doctype_visto = true;
    }

    // Comentarios de una sola línea
    if (std::regex_search(line, matches, comentarioUnaLinea)) {
      Comentario comentario_simple(numero_linea, numero_linea, line); // Guardamos la línea tal cual
      almacen.PushVectorComentarios(comentario_simple);
      
      if (doctype_visto && !etiquetas_vistas) almacen.set_descripcion();
    } 

    // Inicio de comentario multilínea
    else if (std::regex_search(line, matches, inicioComentario)) {
      dentro_comentario = true;
      inicio_comentario = numero_linea;
      auxiliar_comentarios = line;
    }

    // Etiquetas y sus Atributos
    if (!dentro_comentario) {
      // Usamos sregex_iterator para buscar todas las coincidencias en la misma línea
      auto tags_begin = std::sregex_iterator(line.begin(), line.end(), patronEtiqueta);
      auto tags_end = std::sregex_iterator();

      for (std::sregex_iterator i = tags_begin; i != tags_end; ++i) {
        // Guardamos de forma troceada las coincidencias 
        std::smatch match_tag = *i;

        // Puede ser etiqueta de cierre o no
        std::string barra_cierre = match_tag[1].str();
        // Nombre de la etiqueta en sí sin contar si es de cierre
        std::string nombre_etiqueta = match_tag[2].str();
        // Guardamos el bloque de atributos entero, que se analizará más adelante
        std::string bloque_atributos = match_tag[3].str();
        
        // Unimos el nombre (donde único unirá algo relamente es si es de cierre, de forma: "/" + "a" = "/a")
        std::string nombre_completo = barra_cierre + nombre_etiqueta;
        etiquetas_vistas = true;

        // Actualizamos los booleanos de la estructura básica del HTML
        if (nombre_completo == "html") almacen.set_html();
        else if (nombre_completo == "head") almacen.set_head();
        else if (nombre_completo == "body") almacen.set_body();

        // Creamos la etiqueta
        Etiqueta etiqueta(numero_linea, nombre_completo);

        // Si es de apertura y tiene texto sobrante, buscamos atributos
        if (barra_cierre.empty() && !bloque_atributos.empty()) {
          // Usamos sregex_iterator para buscar todas las coincidencias en la cadena de atributos
          auto attr_begin = std::sregex_iterator(bloque_atributos.begin(), bloque_atributos.end(), patronAtributo);
          auto attr_end = std::sregex_iterator();

          for (std::sregex_iterator j = attr_begin; j != attr_end; ++j) {
            // Guardamos de forma troceada para crear el atributo, por un lado el nombre y por el otro el atributo
            // con .str() para guardarlas como string y las asignamos a su etiqueta correspondiente
            std::smatch match_attr = *j;
            Atributo atributo(match_attr[1].str(), match_attr[2].str());
            etiqueta.AddAtributo(atributo);
          }
        }
        
        // Metemos la etiqueta en el almacén
        almacen.PushVectorEtiquetas(etiqueta);
      }
    }

    numero_linea++;
  }

  // Escribimos todo el almacén en el fichero de salida
  outputFile << almacen;

  inputFile.close();
  outputFile.close();
}