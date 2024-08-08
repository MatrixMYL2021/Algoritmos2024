// procesar_transferencias.hpp
#ifndef PROCESAR_TRANSFERENCIAS_HPP
#define PROCESAR_TRANSFERENCIAS_HPP

#include "estructuras.hpp"
#include "coll.hpp"
#include "strings.hpp"
#include "tokens.hpp"
#include <functional>

using namespace std;

void procesarTransferencias(const vector<Nombre>& nombres, const vector<Club>& clubes, const vector<Transferencia>& transferencias) {
    Coll<int> transferenciasPorClub = coll<int>();
    Coll<double> montoPorCliente = coll<double>();

    function<string(int)> intToStringFunc = [](int i) -> string { return intToString(i); };
    function<int(string)> stringToIntFunc = [](string s) -> int { return stringToInt(s); };
    function<string(double)> doubleToStringFunc = [](double d) -> string { return doubleToString(d); };
    function<double(string)> stringToDoubleFunc = [](string s) -> double { return stringToDouble(s); };

    for (const Transferencia& transferencia : transferencias) {
        int clienteIndex = -1;
        for (int i = 0; i < collSize(montoPorCliente); i++) {
            if (collGetAt(montoPorCliente, i, stringToIntFunc) == transferencia.idNombre) {
                clienteIndex = i;
                break;
            }
        }
        if (clienteIndex == -1) {
            collAdd(montoPorCliente, transferencia.monto, doubleToStringFunc);
        } else {
            double montoActual = collGetAt(montoPorCliente, clienteIndex, stringToDoubleFunc);
            collSetAt(montoPorCliente, montoActual + transferencia.monto, clienteIndex, doubleToStringFunc);
        }

        int clubDestinoIndex = -1;
        for (int i = 0; i < collSize(transferenciasPorClub); i++) {
            if (collGetAt(transferenciasPorClub, i, stringToIntFunc) == transferencia.clubDestino) {
                clubDestinoIndex = i;
                break;
            }
        }
        if (clubDestinoIndex == -1) {
            collAdd(transferenciasPorClub, transferencia.clubDestino, intToStringFunc);
        }
    }

    cout << "Transferencias por club de destino:" << endl;
    for (int i = 0; i < collSize(transferenciasPorClub); i++) {
        int idClub = collGetAt(transferenciasPorClub, i, stringToIntFunc);
        cout << "Club ID " << idClub << ": " << collGetAt(transferenciasPorClub, i, stringToIntFunc) << " transferencias" << endl;
    }

    cout << "\nMonto total transferido por cliente:" << endl;
    for (int i = 0; i < collSize(montoPorCliente); i++) {
        double monto = collGetAt(montoPorCliente, i, stringToDoubleFunc);
        cout << "Cliente ID " << i << ": " << monto << " monto total transferido" << endl;
    }
}

#endif // PROCESAR_TRANSFERENCIAS_HPP
