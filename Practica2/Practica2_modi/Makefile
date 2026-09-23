# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Cadenas y lenguajes
# Autor: Joel Castro López
# Correo: alu0101485515@ull.edu.es
# Fecha: 21/09/2024
# Archivo: Makefile

# Nombre del archivo de salida
TARGET = Practica2

# Lista de archivos fuente
SOURCES = Cadena.cc Alfabeto.cc Lenguaje.cc Tools.cc ClienteCadenasYLenguajes.cc

# Dependencias de los archivos fuente
DEPENDENCIES = Cadena.h Alfabeto.h Lenguaje.h Tools.h

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++11

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)
