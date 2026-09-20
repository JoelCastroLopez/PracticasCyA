// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: alu0101485515@ull.edu.es
// Fecha: 14/09/2026
// Archivo: Tools.cc: programa que contiene la implementación de funciones de apoyo
//

#include "Tools.h"

void Usage(int argc, char* argv[]) {
  // Comprobamos primero si el usuario solicita ayuda
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa funciona con el nombre del ejecutable y luego el fichero de entrada, ";
    std::cout << "donde se encontrarán las notas y los alumnos a organizar." << std::endl;
    exit(EXIT_SUCCESS);
  } 
  // Si no es la ayuda y no tiene exactamente 2 argumentos, mostramos error de uso
  else if (argc != 2) {
    std::cerr << "Modo de empleo: " << argv[0] << " filein.txt" << std::endl;
    std::cerr << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}

void AnalisisEntrada(const std::string& entrada, std::set<Alumno>& estudiantes) {
  std::ifstream archivo_entrada{entrada};
  std::string alu_nuevo, valor;

   // Expresión regular: "alu01" seguido de exactamente 8 dígitos
  const std::regex kPatronAlu("^alu01[0-9]{8}$");
  // Expresión regular: "X.XXX" para que solo acepte decimales entre el 0 y 10, con no más de tres décimas
  const std::regex kPatronNota("^(10(\\.0{1,3})?|[0-9](\\.[0-9]{1,3})?)$");

  if (!archivo_entrada.is_open()) {  // Verifica si el archivo fue abierto correctamente
    std::cout << "Error al abrir el archivo para leer." << std::endl;
    exit(EXIT_FAILURE);
  }
  while (archivo_entrada >> alu_nuevo >> valor) {  // Lee línea por línea y asigna la primera string al alu y la segunda al valor de la nota
    double valor_double {std::stod(valor)};
    if (!std::regex_match(alu_nuevo, kPatronAlu)) {
      std::cerr << "Advertencia: Formato de ALU no válido ignorado: " << alu_nuevo << std::endl << std::endl;  // Comprobamos que el alu sea válido
    } else if (!std::regex_match(valor, kPatronNota)) {
      std::cerr << "Advertencia: Formato de nota no válido ignorado: " << valor << std::endl << std::endl;  // Comprobamos que la nota sea válida (del 0 al 10)
    } else {
      // Buscamos si ya existe un alumno con ese alu
      Alumno alumno_buscado(alu_nuevo);
      auto it = estudiantes.find(alumno_buscado);

      // Si no existe simplemente lo añado al set
      if (it == estudiantes.end()) {
        Alumno nuevo_alumno(alu_nuevo);
        nuevo_alumno.AnadirNota(valor_double);
        estudiantes.insert(nuevo_alumno);
      } 
      // Si existe tendgo que modificar el set extrayendo el existente, añadiendo la nota al vector de notas del alumno en concreto y devolverlo al set
      else {
        // Extraemos el nodo
        auto nodo = estudiantes.extract(it);
        // Añado la nueva nota
        nodo.value().AnadirNota(valor_double);
        // Lo volvemos a meter actualizado
        estudiantes.insert(std::move(nodo));
      }
    }
  }  
}

void IntroduccionManual(const std::string& entrada, std::set<Alumno>& estudiantes) {
  std::stringstream flujo_entrada(entrada);
  std::string alu_nuevo, valor;

  // Extraemos los datos del string
  if (!(flujo_entrada >> alu_nuevo >> valor)) {
    std::cerr << "Error: Debe introducir el ALU y la nota separados por un espacio (ej. alu0101010101 8.5)." << std::endl << std::endl;
    return;
  }

  // Expresión regular: "alu01" seguido de exactamente 8 dígitos
  const std::regex kPatronAlu("^alu01[0-9]{8}$");
  // Expresión regular: "X.XXX" para que solo acepte decimales entre el 0 y 10, con no más de tres décimas
  const std::regex kPatronNota("^(10(\\.0{1,3})?|[0-9](\\.[0-9]{1,3})?)$");

  double valor_double {std::stod(valor)};
  if (!std::regex_match(alu_nuevo, kPatronAlu)) {
    std::cerr << "Advertencia: Formato de ALU no válido ignorado: " << alu_nuevo << std::endl << std::endl;  // Comprobamos que el alu sea válido
  } else if (!std::regex_match(valor, kPatronNota)) {
    std::cerr << "Advertencia: Formato de nota no válido ignorado: " << valor << std::endl << std::endl;  // Comprobamos que la nota sea válida (del 0 al 10)
  } else {
    // Buscamos si ya existe un alumno con ese alu
    Alumno alumno_buscado(alu_nuevo);
    auto it = estudiantes.find(alumno_buscado);

    // Si no existe simplemente lo añado al set
    if (it == estudiantes.end()) {
      Alumno nuevo_alumno(alu_nuevo);
      nuevo_alumno.AnadirNota(valor_double);
      estudiantes.insert(nuevo_alumno);
    } 
    // Si existe tendgo que modificar el set extrayendo el existente, añadiendo la nota al vector de notas del alumno en concreto y devolverlo al set
    else {
      // Extraemos el nodo
      auto nodo = estudiantes.extract(it);
      // Añado la nueva nota
      nodo.value().AnadirNota(valor_double);
      // Lo volvemos a meter actualizado
      estudiantes.insert(std::move(nodo));
    }
  }
}  

void ImprimirResultado(const std::set<Alumno>& estudiantes) {
  if (estudiantes.empty()) {  // Verificamos si hay estudiantes registrados
    std::cout << "No hay estudiantes registrados." << std::endl;
    return;
  }

  for (const auto& alumno : estudiantes) {  // Recorremos el set ordenado y escribimos los atributos de los alumnos en ese orden
    std::cout << alumno.get_Alu() << ": ";
    for (int i{0}; i < alumno.get_Notas().size(); i++) {
      std::cout << alumno.get_Notas()[i];
      if (!(i + 1 == alumno.get_Notas().size())) {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }
}