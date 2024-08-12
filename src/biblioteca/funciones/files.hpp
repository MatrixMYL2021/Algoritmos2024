#ifndef FILES_HPP
#define FILES_HPP

#include <cstdio>

using namespace std;

// Función para escribir un registro de tipo T en el archivo f
template <typename T>
void write(FILE* f, T t) {
    fwrite(&t, sizeof(T), 1, f);
}

// Función para leer un registro de tipo T desde el archivo f
template <typename T>
T read(FILE* f) {
    T t;
    fread(&t, sizeof(T), 1, f);
    return t;
}

// Función para sobreescribir un registro de tipo T en una posición específica del archivo f
template <typename T>
void overwrite(FILE* f, T t, int pos) {
    fseek(f, pos * sizeof(T), SEEK_SET);
    write<T>(f, t);
}

// Función para leer un registro de tipo T desde una posición específica del archivo f
template <typename T>
T readAt(FILE* f, int pos) {
    fseek(f, pos * sizeof(T), SEEK_SET);
    return read<T>(f);
}

// Función para obtener el tamaño del archivo en cantidad de registros de tipo T
template <typename T>
int fileSize(FILE* f) {
    fseek(f, 0, SEEK_END);
    return ftell(f) / sizeof(T);
}

// Función para mover el cursor de lectura/escritura a la posición inicial del archivo
void rewindFile(FILE* f) {
    rewind(f);
}

#endif // FILES_HPP
