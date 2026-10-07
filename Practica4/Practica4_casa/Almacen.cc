// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 04/10/2026
// Archivo Clase_Almacen.cc: programa que contiene la implementación de la clase Almacen

#include <iostream>


#include "Almacen.h"

/**
 * @brief Sobrecarga del operador de extraccion de la clase Almacen
 * @param out Variable ostream para sacar por pantalla
 * @param almacen Objeto Almacen que se va a escribir
 * @return Se devuelve el out con los los valores a imprimirse
*/
std::ostream& operator<<(std::ostream& out, const Almacen& almacen) {
  // Nombre del programa
  out << "PROGRAM: " << almacen.nombre_fichero_ << "\n\n";
  
  // Descripcion
  if (almacen.hay_descripcion_ && !almacen.vector_comentarios_.empty()) {
    out << "DESCRIPTION:\n" << almacen.vector_comentarios_[0].get_texto() << "\n\n";
  }

  // Estructura
  out << "STRUCTURE:\n";
  out << "HTML: " << (almacen.hay_html_ ? "True" : "False") << "\n";
  out << "HEAD: " << (almacen.hay_head_ ? "True" : "False") << "\n";
  out << "BODY: " << (almacen.hay_body_ ? "True" : "False") << "\n";
  if (!almacen.doctype_.empty()) {
    out << "DOCTYPE: " << almacen.doctype_ << "\n";
  }
  out << "\n";

  // Etiquetas
  out << "TAGS:\n";
  for (const auto& etiqueta : almacen.vector_etiquetas_) {
    out << "[Line " << etiqueta.get_linea() << "] " << etiqueta.get_nombre() << "\n";
  }
  out << "\n";

  // Atributo
  out << "ATTRIBUTES:\n";
  for (const auto& etiqueta : almacen.vector_etiquetas_) {
    // Si el vector de atributos de esta etiqueta no está vacío, los imprimimos
    if (!etiqueta.get_atributos().empty()) {
      out << "[Line " << etiqueta.get_linea() << "] " << etiqueta.get_nombre() << "\n";
      for (const auto& atributo : etiqueta.get_atributos()) {
        out << atributo.get_nombre() << " = \"" << atributo.get_valor() << "\"\n";
      }
      out << "\n";
    }
  }

  // Comentarios
  out << "COMMENTS:\n";
  for (size_t i = 0; i < almacen.vector_comentarios_.size(); ++i) {
    const auto& comentario = almacen.vector_comentarios_[i];
    
    // Imprimimos el formato de la línea dependiendo de si es multilínea
    if (comentario.EsMultilinea()) {
      out << "[Line " << comentario.get_InicioLinea() << "-" << comentario.get_FinalLinea() << "]";
    } else {
      out << "[Line " << comentario.get_InicioLinea() << "]";
    }

    // Si es el primer comentario y está marcado como descripción, añadimos la etiqueta
    if (i == 0 && almacen.hay_descripcion_) {
      out << " DESCRIPTION\n";
    } else {
      out << "\n";
    }
    
    out << comentario.get_texto() << "\n\n";
  }

  return out;
}