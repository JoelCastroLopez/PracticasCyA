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

void Usage(int argc, char* argv[], bool& search, double& valor_search) {
  // Comprobamos primero si el usuario solicita ayuda
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa funciona con el nombre del ejecutable y luego el fichero de entrada, ";
    std::cout << "donde se encontrarán las notas y los alumnos a organizar." << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc == 4 && std::string(argv[2]) == "--search") {  // Modificación: --search
    search = true;
    valor_search = std::stod(argv[3]);
  }
  // Si no es la ayuda y no tiene exactamente 2 argumentos, mostramos error de uso
  else if (argc != 2) {
    std::cerr << "Modo de empleo 1: " << argv[0] << " filein.txt" << std::endl;
    std::cerr << "Modo de empleo 2: " << argv[0] << " filein.txt --search <valor>" << std::endl;
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
        Alumno nuevo_alumno(alu_nuevo, valor_double);
        estudiantes.insert(nuevo_alumno);
      } 
      // Si existe tendgo que modificar el set extrayendo el existente, hacer la comparación y volver a meter el alumno con el resultado que corresponda
      else {
        // Comprobamos si la nota que nos entra es mayor que la que ya tiene
        if (valor_double > it->get_Nota()) {
          // Extraigo el nodo
          auto nodo = estudiantes.extract(it);
          // Modifico la nota para colocar solo la mayor
          nodo.value().set_Nota(valor_double);
          // Se vuelve a meter ya con la nota máxima correcta
          estudiantes.insert(std::move(nodo));
        }
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
      Alumno nuevo_alumno(alu_nuevo, valor_double);
      estudiantes.insert(nuevo_alumno);
    } 
    // Si existe tendgo que modificar el set extrayendo el existente, hacer la comparación y volver a meter el alumno con el resultado que corresponda
    else {
      // Comprobamos si la nota que nos entra es mayor que la que ya tiene
      if (valor_double > it->get_Nota()) {
        // Extraigo el nodo
        auto nodo = estudiantes.extract(it);
        // Modifico la nota para colocar solo la mayor
        nodo.value().set_Nota(valor_double);
        // Se vuelve a meter ya con la nota máxima correcta
        estudiantes.insert(std::move(nodo));
      }
    }
  }
}

void ImprimirResultado(const std::set<Alumno>& estudiantes, const bool& search, const double& valor_search) {
  if (estudiantes.empty()) {  // Verificamos si hay estudiantes registrados
    std::cout << "No hay estudiantes registrados." << std::endl << std::endl;
    return;
  }

  if (search == true) {
    std::cout << "Alumnos con notas mayores a '" << valor_search << "' :" << std::endl << std::endl;
    bool mayores_search{false};

    for (const auto& alumno : estudiantes) {  // Recorremos el set ordenado y escribimos los atributos de los alumnos en ese orden
      if (search == true) {
        if (alumno.get_Nota() >= valor_search) {
          std::cout << alumno.get_Alu() << ": " << alumno.get_Nota() << std::endl;
          mayores_search = true;
        }
      } 
    }

    if (mayores_search == false) {
      std::cout << "No hay estudiantes con notas mayores a la dada" << std::endl << std::endl;
    }

  } else {
    for (const auto& alumno : estudiantes) {  // Recorremos el set ordenado y escribimos los atributos de los alumnos en ese orden
      std::cout << alumno.get_Alu() << ": " << alumno.get_Nota() << std::endl;
    }
  }

}