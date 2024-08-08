// leer_datos.hpp
#ifndef LEER_DATOS_HPP
#define LEER_DATOS_HPP

#include "estructuras.hpp"
#include <fstream>
#include <vector>

using namespace std;

vector<Nombre> leerNombres(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Nombre> nombres;
    Nombre nombre;
    while (file.read(reinterpret_cast<char*>(&nombre), sizeof(Nombre))) {
        nombres.push_back(nombre);
    }
    file.close();
    return nombres;
}

vector<Club> leerClubes(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Club> clubes;
    Club club;
    while (file.read(reinterpret_cast<char*>(&club), sizeof(Club))) {
        clubes.push_back(club);
    }
    file.close();
    return clubes;
}

vector<Transferencia> leerTransferencias(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Transferencia> transferencias;
    Transferencia transferencia;
    while (file.read(reinterpret_cast<char*>(&transferencia), sizeof(Transferencia))) {
        transferencias.push_back(transferencia);
    }
    file.close();
    return transferencias;
}

#endif // LEER_DATOS_HPP
