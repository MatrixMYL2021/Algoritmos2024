// estructuras.hpp
#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> // Para strcpy

using namespace std;

struct Ciudad {
    int idCiu;
    char descr[20];
    int millas;
};

struct Vuelo {
    int idVue;
    int cap;
    int idOri; // idCiu origen
    int idDes; // idCiu destino
};

struct Reserva {
    int idCli;
    int idVue;
    int cant;
};

#endif // ESTRUCTURAS_HPP
