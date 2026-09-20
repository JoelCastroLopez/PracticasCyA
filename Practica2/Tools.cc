// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Joel Castro López
// Correo: alu0101485515@ull.edu.es
// Fecha: 20/09/2026
// Archivo Tools.cc: programa implementación de funciones auxiliares.
// Contiene la implementación de funciones auxiliares

#include "Cadena.h"
#include "Tools.h"
#include "Alfabeto.h"
#include "Lenguaje.h"

// Función que revisa la entrada
void Usage(int argc, std::string argv1) {
  if (argc != 4 && argv1 == "--help") {  // Mensaje de ayuda
    std::cout << "El programa funciona con el nombre del ejecutable, luego el fichero de entrada, ";
    std::cout << "donde se encontrarán los datos, en tercer lugar el fichero de salida,"<< std::endl << "donde se mostrarán ";
    std::cout << "los resultados al opcode sugerido, y por último el opcode en sí, este indicará la ";
    std::cout << "instrucción a realizar entre 6 posibles opciones: " << std::endl;
    std::cout << "1(Alfabeto), 2(Longitud), 3(Inversa), 4(Prefijos), 5(Sufijos), 6(Validación)" << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc != 4) {  // Asegurarse de que hay exactamente 3 argumentos además del nombre del programa
    std::cerr << "Modo de empleo: ./Cadenas_lenguajes filein.txt fileout.txt opcode" << std::endl;
    std::cerr << "Pruebe ./Cadenas_lenguajes --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Función que realiza la instrucción dada
void Instruccion(std::string opcode, std::string argv1, std::string argv2) {
  int valor_opcode = std::stoi(opcode);
  std::ifstream archivo_entrada{argv1};
  std::ofstream archivo_salida{argv2};
  std::string primera_parte_entrada, segunda_parte_entrada;
  if (!archivo_entrada.is_open()) {  // Verifica si el archivo fue abierto correctamente
    std::cout << "Error al abrir el archivo para leer." << std::endl;
    exit(EXIT_FAILURE);
  }
  switch (valor_opcode) {
    case 1:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {  // Lee línea por línea y asigna la primera string a la cadena y la segunda al alfabeto
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena << ": " << alfabeto << std::endl;
      }
      break;
    case 2:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.get_longitud() << std::endl;
      }
      break;
    case 3:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);  
        archivo_salida << cadena << " -> " << cadena.inversa() << std::endl;
      }
      break;
    case 4:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {  
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.prefijos() << std::endl;
      }
      break;
    case 5:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.sufijos() << std::endl;
      }
      break;
    case 6:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        if (Cadena_perteneciente(primera_parte_entrada, alfabeto)  == true) {
          archivo_salida << "OK" << std::endl;
        } else {
          archivo_salida << "ERROR" << std::endl;
        }
      }
      break;
    default:  // En caso de opcode incorecto se lanza un mensaje de eeror
      std::cout << "El opcode seleccionado no se encuentra entre los posibles, por favor, escoja un número del 1 al 4 (incluidos)" << std::endl;
      break;
  }
}

// Función que verifica que el caracter '&' no esté en el alfabeto
void Alfabeto_incorrecto(std::string cadena) {  
  for (int i = 0; i < cadena.size(); i++) {
    if (cadena[i] == '&') {
      std::cout << "No se puede usar el caracter '&' en un alfabeto, ya que es el usado en esta práctica ";
      std::cout << "para representar la cadena vacía, queda reservado para la cadena '&', que sí podrá utilizar" << std::endl;
      std::cout << "Ha cometido el error en el alfabeto: {" << cadena << "}" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

// Función que verifica que la cadena pertenece al alfabeto
bool Cadena_perteneciente(std::string cadena, Alfabeto alfabeto) {
  for (int i{0}; i < cadena.size(); i++) {
    if (alfabeto.busqueda_simbolo(cadena[i]) == false) {
      if (!(cadena.size() == 1 && cadena[0] == '&')) {
        return false;
      }
    }
  }
  return true;
}