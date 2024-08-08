// main.cpp
#include "estructuras.hpp"
#include "leer_datos.hpp"
#include "procesar_reservas.hpp"

int main() {
    vector<Ciudad> ciudades = leerCiudades("CIUDADES.dat");
    vector<Vuelo> vuelos = leerVuelos("VUELOS.dat");
    vector<Reserva> reservas = leerReservas("RESERVAS.dat");

    procesarReservas(ciudades, vuelos, reservas);

    return 0;
}
