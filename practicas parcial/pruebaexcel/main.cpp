#include "estructuras.hpp"
#include "leer_y_escribir_excel.hpp"
#include "leer_datos.hpp"
#include "procesar_transferencias.hpp"

int main() {
    string filename = "datos.xlsx"; // Reemplaza con el nombre de tu archivo Excel

    vector<Nombre> nombres = leerNombresDesdeExcel(filename);
    vector<Club> clubes = leerClubesDesdeExcel(filename);
    vector<Transferencia> transferencias = leerTransferenciasDesdeExcel(filename);

    escribirBinario("NOMBRES.dat", nombres);
    escribirBinario("CLUBES.dat", clubes);
    escribirBinario("TRANSFERENCIAS.dat", transferencias);

    cout << "Archivos binarios creados con éxito." << endl;

    vector<Nombre> nombresBin = leerNombres("NOMBRES.dat");
    vector<Club> clubesBin = leerClubes("CLUBES.dat");
    vector<Transferencia> transferenciasBin = leerTransferencias("TRANSFERENCIAS.dat");

    procesarTransferencias(nombresBin, clubesBin, transferenciasBin);

    return 0;
}
