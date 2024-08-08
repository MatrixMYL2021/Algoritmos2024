// coll.hpp
#ifndef COLL_HPP
#define COLL_HPP

#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

template<typename T>
struct Coll {
    vector<T> elements;
    char sep;
};

// Crea una colección vacía con un separador específico
template<typename T>
Coll<T> coll(char sep) {
    return Coll<T>{vector<T>(), sep};
}

// Crea una colección vacía con el separador por defecto ','
template<typename T>
Coll<T> coll() {
    return Coll<T>{vector<T>(), ','};
}

// Retorna la cantidad de elementos en la colección
template<typename T>
int collSize(const Coll<T>& c) {
    return c.elements.size();
}

// Remueve todos los elementos de la colección
template<typename T>
void collRemoveAll(Coll<T>& c) {
    c.elements.clear();
}

// Remueve el elemento en la posición 'p' de la colección
template<typename T>
void collRemoveAt(Coll<T>& c, int p) {
    if (p >= 0 && p < c.elements.size()) {
        c.elements.erase(c.elements.begin() + p);
    }
}

// Agrega el elemento 't' al final de la colección y retorna su posición
template<typename T>
int collAdd(Coll<T>& c, const T& t, function<string(T)> tToString) {
    c.elements.push_back(t);
    return c.elements.size() - 1;
}

// Reemplaza el elemento en la posición 'p' con 't'
template<typename T>
void collSetAt(Coll<T>& c, T t, int p, function<string(T)> tToString) {
    if (p >= 0 && p < c.elements.size()) {
        c.elements[p] = t;
    }
}

// Retorna el elemento en la posición 'p'
template<typename T>
T collGetAt(const Coll<T>& c, int p, function<T(string)> tFromString) {
    if (p >= 0 && p < c.elements.size()) {
        return c.elements[p];
    }
    return T(); // Retorna valor por defecto si 'p' es inválido
}

// Encuentra la posición del elemento 'k' en la colección
template<typename T, typename K>
int collFind(const Coll<T>& c, K k, function<int(T, K)> cmpTK, function<T(string)> tFromString) {
    for (int i = 0; i < c.elements.size(); i++) {
        if (cmpTK(c.elements[i], k) == 0) {
            return i;
        }
    }
    return -1; // Retorna -1 si no se encuentra
}

// Ordena la colección usando la función de comparación 'cmpTT'
template<typename T>
void collSort(Coll<T>& c, function<int(T, T)> cmpTT, function<T(string)> tFromString, function<string(T)> tToString) {
    sort(c.elements.begin(), c.elements.end(), cmpTT);
}

// Verifica si quedan elementos en la colección para iterar
template<typename T>
bool collHasNext(const Coll<T>& c) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        currentIndex++;
        return true;
    }
    currentIndex = 0; // Reinicia el índice si se llega al final
    return false;
}

// Retorna el próximo elemento de la colección
template<typename T>
T collNext(Coll<T>& c, function<T(string)> tFromString) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        return c.elements[currentIndex++];
    }
    currentIndex = 0; // Reinicia el índice si se llega al final
    return T(); // Retorna valor por defecto si no hay más elementos
}

// Retorna el próximo elemento de la colección e indica si es el último
template<typename T>
T collNext(Coll<T>& c, bool& eoc, function<T(string)> tFromString) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        eoc = false;
        return c.elements[currentIndex++];
    }
    currentIndex = 0; // Reinicia el índice si se llega al final
    eoc = true;
    return T(); // Retorna valor por defecto si no hay más elementos
}

// Reinicia la iteración de la colección
template<typename T>
void collReset(Coll<T>& c) {
    static size_t currentIndex = 0;
    currentIndex = 0;
}

#endif // COLL_HPP
