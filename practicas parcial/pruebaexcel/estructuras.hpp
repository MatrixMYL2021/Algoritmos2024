// estructuras.hpp
#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> // Para strcpy

using namespace std;

struct Nombre {
    int id;
    char nombre[20];
    char apellido[20];
};

struct Club {
    int id;
    char nombre[20];
    char pais[20];
};

struct Transferencia {
    int id;
    int idNombre;
    char nombre[20];
    char apellido[20];
    int clubOrigen;
    int clubDestino;
    double monto;
};

#endif // ESTRUCTURAS_HPP
