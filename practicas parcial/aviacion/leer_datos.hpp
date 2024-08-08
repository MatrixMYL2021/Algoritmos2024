// leer_datos.hpp
#ifndef LEER_DATOS_HPP
#define LEER_DATOS_HPP

#include "estructuras.hpp"

vector<Ciudad> leerCiudades(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Ciudad> ciudades;
    Ciudad ciudad;
    while (file.read(reinterpret_cast<char*>(&ciudad), sizeof(Ciudad))) {
        ciudades.push_back(ciudad);
    }
    file.close();
    return ciudades;
}

vector<Vuelo> leerVuelos(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Vuelo> vuelos;
    Vuelo vuelo;
    while (file.read(reinterpret_cast<char*>(&vuelo), sizeof(Vuelo))) {
        vuelos.push_back(vuelo);
    }
    file.close();
    return vuelos;
}

vector<Reserva> leerReservas(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Reserva> reservas;
    Reserva reserva;
    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        reservas.push_back(reserva);
    }
    file.close();
    return reservas;
}

#endif // LEER_DATOS_HPP
