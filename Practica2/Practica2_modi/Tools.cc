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
void Usage(int argc, char* argv[]) {
  if (argc > 1 && std::string(argv[1]) == "--help") {
    std::cout << "El programa funciona con el nombre del ejecutable, luego el fichero de entrada, ";
    std::cout << "donde se encontrarán los datos, en tercer lugar el fichero de salida," << std::endl;
    std::cout << "donde se mostrarán los resultados al opcode sugerido, y por último el opcode en sí, ";
    std::cout << "e instruccional opcional de potencia para opcode 7:" << std::endl;
    std::cout << "1(Alfabeto), 2(Longitud), 3(Inversa), 4(Prefijos), 5(Sufijos), 6(Validación), 7(Potencia)" << std::endl;
    exit(EXIT_SUCCESS);
  }

  if (argc < 4) {
    std::cerr << "Modo de empleo: ./Cadenas_lenguajes filein.txt fileout.txt opcode [potencia]" << std::endl;
    std::cerr << "Pruebe ./Cadenas_lenguajes --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }

  int opcode = std::stoi(argv[3]);
  if (opcode == 7 && argc != 5) {
    std::cerr << "Error: Para el opcode 7 debe indicar el exponente de la potencia." << std::endl;
    std::cerr << "Uso: ./Cadenas_lenguajes filein.txt fileout.txt 7 <potencia>" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Función que realiza la instrucción dada
void Instruccion(int argc, char* argv[]) {
  int valor_opcode = std::stoi(argv[3]);
  std::ifstream archivo_entrada{argv[1]};
  std::ofstream archivo_salida{argv[2]};
  std::string primera_parte_entrada, segunda_parte_entrada;
  
  int potencia{0};
  if (argc > 4) {
    potencia = std::stoi(argv[4]);
  }

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
        archivo_salida << cadena << " -> " << cadena.Inversa() << std::endl;
      }
      break;
    case 4:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {  
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.Prefijos() << std::endl;
      }
      break;
    case 5:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.Sufijos() << std::endl;
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
    case 7:
      while (archivo_entrada >> primera_parte_entrada >> segunda_parte_entrada) {  
        Alfabeto_incorrecto(segunda_parte_entrada);
        Alfabeto alfabeto(segunda_parte_entrada);
        Cadena cadena(primera_parte_entrada, alfabeto);
        archivo_salida << cadena.Potencia(potencia) << std::endl;
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
    if (alfabeto.BusquedaSimbolo(cadena[i]) == false) {
      if (!(cadena.size() == 1 && cadena[0] == '&')) {
        return false;
      }
    }
  }
  return true;
}