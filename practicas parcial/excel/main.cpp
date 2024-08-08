#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Nombre {
    int id;
    char nombre[30];
    char apellido[30];
};

struct Club {
    int id;
    char nombre[30];
    char pais[30];
};

struct Transferencia {
    int id;
    int idNombre;
    int idClubOrigen;
    int idClubDestino;
    float monto;
};

template <typename T>
void leerDatos(const char* nombreArchivo, vector<T>& datos) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    T temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(T))) {
        datos.push_back(temp);
    }
    archivo.close();
}

template <typename T>
void mostrarDatos(const vector<T>& datos) {
    for (const auto& dato : datos) {
        cout << dato.id << " " << dato.nombre << " " << dato.apellido << endl;
    }
}

void mostrarDatos(const vector<Club>& datos) {
    for (const auto& dato : datos) {
        cout << dato.id << " " << dato.nombre << " " << dato.pais << endl;
    }
}

void mostrarDatos(const vector<Transferencia>& datos) {
    for (const auto& dato : datos) {
        cout << dato.id << " " << dato.idNombre << " " << dato.idClubOrigen << " " << dato.idClubDestino << " " << dato.monto << endl;
    }
}

template <typename T>
void agregarDato(const char* nombreArchivo, const T& nuevoDato) {
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    archivo.write(reinterpret_cast<const char*>(&nuevoDato), sizeof(T));
    archivo.close();
}

template <typename T>
void borrarDato(const char* nombreArchivo, int id) {
    vector<T> datos;
    leerDatos(nombreArchivo, datos);

    ofstream archivo(nombreArchivo, ios::binary | ios::trunc);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    for (const auto& dato : datos) {
        if (dato.id != id) {
            archivo.write(reinterpret_cast<const char*>(&dato), sizeof(T));
        }
    }

    archivo.close();
}

template <typename T>
void modificarDato(const char* nombreArchivo, const T& datoModificado) {
    vector<T> datos;
    leerDatos(nombreArchivo, datos);

    ofstream archivo(nombreArchivo, ios::binary | ios::trunc);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    for (auto& dato : datos) {
        if (dato.id == datoModificado.id) {
            archivo.write(reinterpret_cast<const char*>(&datoModificado), sizeof(T));
        } else {
            archivo.write(reinterpret_cast<const char*>(&dato), sizeof(T));
        }
    }

    archivo.close();
}

int main() {
    vector<Nombre> nombres;
    vector<Club> clubes;
    vector<Transferencia> transferencias;

    const char* archivoNombres = "nombres.dat";
    const char* archivoClubes = "clubes.dat";
    const char* archivoTransferencias = "transferencias.dat";

    leerDatos(archivoNombres, nombres);
    leerDatos(archivoClubes, clubes);
    leerDatos(archivoTransferencias, transferencias);

    cout << "Nombres:" << endl;
    mostrarDatos(nombres);

    cout << "Clubes:" << endl;
    mostrarDatos(clubes);

    cout << "Transferencias:" << endl;
    mostrarDatos(transferencias);

    // Ejemplo de agregar un nuevo nombre
    Nombre nuevoNombre = { 4, "Nuevo", "Nombre" };
    agregarDato(archivoNombres, nuevoNombre);

    // Ejemplo de borrar un nombre
    borrarDato<Nombre>(archivoNombres, 1);

    // Ejemplo de modificar un nombre
    Nombre nombreModificado = { 2, "Nombre", "Modificado" };
    modificarDato(archivoNombres, nombreModificado);

    return 0;
}
