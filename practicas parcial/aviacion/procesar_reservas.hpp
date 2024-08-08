// procesar_reservas.hpp
#ifndef PROCESAR_RESERVAS_HPP
#define PROCESAR_RESERVAS_HPP

#include "estructuras.hpp"
#include "coll.hpp"
#include "strings.hpp"
#include "tokens.hpp"
#include <functional>

using namespace std;

void procesarReservas(const vector<Ciudad>& ciudades, vector<Vuelo>& vuelos, const vector<Reserva>& reservas) {
    Coll<int> familiasPorCiudad = coll<int>();
    Coll<int> millasPorCliente = coll<int>();
    Coll<int> plazasRechazadasPorVuelo = coll<int>();

    // Convertir funciones a std::function
    function<string(int)> intToStringFunc = [](int i) -> string { return intToString(i); };
    function<int(string)> stringToIntFunc = [](string s) -> int { return stringToInt(s); };

    for (const Reserva& reserva : reservas) {
        Vuelo* vuelo = nullptr;
        for (Vuelo& v : vuelos) {
            if (v.idVue == reserva.idVue) {
                vuelo = &v;
                break;
            }
        }
        if (!vuelo) continue;

        if (reserva.cant <= vuelo->cap) {
            vuelo->cap -= reserva.cant;

            int millasOrigen = 0;
            int millasDestino = 0;
            for (const Ciudad& ciudad : ciudades) {
                if (ciudad.idCiu == vuelo->idOri) {
                    millasOrigen = ciudad.millas;
                } else if (ciudad.idCiu == vuelo->idDes) {
                    millasDestino = ciudad.millas;
                }
            }

            int millasAcumuladas = abs(millasDestino - millasOrigen) * reserva.cant;
            int clienteIndex = -1;
            for (int i = 0; i < collSize(millasPorCliente); i++) {
                if (collGetAt(millasPorCliente, i, stringToIntFunc) == reserva.idCli) {
                    clienteIndex = i;
                    break;
                }
            }
            if (clienteIndex == -1) {
                collAdd(millasPorCliente, millasAcumuladas, intToStringFunc);
            } else {
                int millasActuales = collGetAt(millasPorCliente, clienteIndex, stringToIntFunc);
                collSetAt(millasPorCliente, millasActuales + millasAcumuladas, clienteIndex, intToStringFunc);
            }

            int ciudadIndex = -1;
            for (int i = 0; i < collSize(familiasPorCiudad); i++) {
                if (collGetAt(familiasPorCiudad, i, stringToIntFunc) == vuelo->idDes) {
                    ciudadIndex = i;
                    break;
                }
            }
            if (ciudadIndex == -1) {
                collAdd(familiasPorCiudad, vuelo->idDes, intToStringFunc);
            }
        } else {
            int plazasRechazadas = reserva.cant;
            collAdd(plazasRechazadasPorVuelo, plazasRechazadas, intToStringFunc);
        }
    }

    // Output de resultados
    cout << "Familias por ciudad de destino:" << endl;
    for (int i = 0; i < collSize(familiasPorCiudad); i++) {
        int idCiudad = collGetAt(familiasPorCiudad, i, stringToIntFunc);
        cout << "Ciudad ID " << idCiudad << ": " << collGetAt(familiasPorCiudad, i, stringToIntFunc) << " familias" << endl;
    }

    cout << "\nPlazas rechazadas por vuelo y estado del vuelo:" << endl;
    for (int i = 0; i < vuelos.size(); i++) {
        Vuelo vuelo = vuelos[i];
        int plazasRechazadas = collGetAt(plazasRechazadasPorVuelo, i, stringToIntFunc);
        cout << "Vuelo ID " << vuelo.idVue << ": " << plazasRechazadas << " plazas rechazadas. Estado: "
             << (vuelo.cap == 0 ? "Completo" : "Incompleto") << endl;
    }

    cout << "\nMillas acumuladas por cliente:" << endl;
    for (int i = 0; i < collSize(millasPorCliente); i++) {
        int millas = collGetAt(millasPorCliente, i, stringToIntFunc);
        cout << "Cliente ID " << i << ": " << millas << " millas acumuladas" << endl;
    }
}

#endif // PROCESAR_RESERVAS_HPP
