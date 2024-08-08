// leer_y_escribir_excel.hpp
#ifndef LEER_Y_ESCRIBIR_EXCEL_HPP
#define LEER_Y_ESCRIBIR_EXCEL_HPP

#include "estructuras.hpp"
#include <xlnt/xlnt.hpp>

using namespace std;

vector<Nombre> leerNombresDesdeExcel(const string& filename) {
    xlnt::workbook wb;
    wb.load(filename);
    xlnt::worksheet ws = wb.sheet_by_title("NOMBRES");

    vector<Nombre> nombres;
    for (auto row : ws.rows(false)) {
        Nombre nombre;
        nombre.id = row[0].value<int>();
        strcpy(nombre.nombre, row[1].value<string>().c_str());
        strcpy(nombre.apellido, row[2].value<string>().c_str());
        nombres.push_back(nombre);
    }
    return nombres;
}

vector<Club> leerClubesDesdeExcel(const string& filename) {
    xlnt::workbook wb;
    wb.load(filename);
    xlnt::worksheet ws = wb.sheet_by_title("CLUBES");

    vector<Club> clubes;
    for (auto row : ws.rows(false)) {
        Club club;
        club.id = row[0].value<int>();
        strcpy(club.nombre, row[1].value<string>().c_str());
        strcpy(club.pais, row[2].value<string>().c_str());
        clubes.push_back(club);
    }
    return clubes;
}

vector<Transferencia> leerTransferenciasDesdeExcel(const string& filename) {
    xlnt::workbook wb;
    wb.load(filename);
    xlnt::worksheet ws = wb.sheet_by_title("TRANSFERENCIAS");

    vector<Transferencia> transferencias;
    for (auto row : ws.rows(false)) {
        Transferencia transferencia;
        transferencia.id = row[0].value<int>();
        transferencia.idNombre = row[1].value<int>();
        strcpy(transferencia.nombre, row[2].value<string>().c_str());
        strcpy(transferencia.apellido, row[3].value<string>().c_str());
        transferencia.clubOrigen = row[4].value<int>();
        transferencia.clubDestino = row[5].value<int>();
        transferencia.monto = row[6].value<double>();
        transferencias.push_back(transferencia);
    }
    return transferencias;
}

template<typename T>
void escribirBinario(const string& filename, const vector<T>& datos) {
    ofstream file(filename, ios::binary);
    for (const auto& dato : datos) {
        file.write(reinterpret_cast<const char*>(&dato), sizeof(T));
    }
    file.close();
}

#endif // LEER_Y_ESCRIBIR_EXCEL_HPP
