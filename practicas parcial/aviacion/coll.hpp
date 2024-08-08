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

template<typename T>
Coll<T> coll(char sep) {
    return Coll<T>{vector<T>(), sep};
}

template<typename T>
Coll<T> coll() {
    return Coll<T>{vector<T>(), ','};
}

template<typename T>
int collSize(const Coll<T>& c) {
    return c.elements.size();
}

template<typename T>
void collRemoveAll(Coll<T>& c) {
    c.elements.clear();
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p) {
    if (p >= 0 && p < c.elements.size()) {
        c.elements.erase(c.elements.begin() + p);
    }
}

template<typename T>
int collAdd(Coll<T>& c, const T& t, function<string(T)> tToString) {
    c.elements.push_back(t);
    return c.elements.size() - 1;
}

template<typename T>
void collSetAt(Coll<T>& c, T t, int p, function<string(T)> tToString) {
    if (p >= 0 && p < c.elements.size()) {
        c.elements[p] = t;
    }
}

template<typename T>
T collGetAt(const Coll<T>& c, int p, function<T(string)> tFromString) {
    if (p >= 0 && p < c.elements.size()) {
        return c.elements[p];
    }
    return T();
}

template<typename T, typename K>
int collFind(const Coll<T>& c, K k, function<int(T, K)> cmpTK, function<T(string)> tFromString) {
    for (int i = 0; i < c.elements.size(); i++) {
        if (cmpTK(c.elements[i], k) == 0) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void collSort(Coll<T>& c, function<int(T, T)> cmpTT, function<T(string)> tFromString, function<string(T)> tToString) {
    sort(c.elements.begin(), c.elements.end(), cmpTT);
}

template<typename T>
bool collHasNext(const Coll<T>& c) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        currentIndex++;
        return true;
    }
    currentIndex = 0;
    return false;
}

template<typename T>
T collNext(Coll<T>& c, function<T(string)> tFromString) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        return c.elements[currentIndex++];
    }
    currentIndex = 0;
    return T();
}

template<typename T>
T collNext(Coll<T>& c, bool& eoc, function<T(string)> tFromString) {
    static size_t currentIndex = 0;
    if (currentIndex < c.elements.size()) {
        eoc = false;
        return c.elements[currentIndex++];
    }
    currentIndex = 0;
    eoc = true;
    return T();
}

template<typename T>
void collReset(Coll<T>& c) {
    static size_t currentIndex = 0;
    currentIndex = 0;
}

#endif // COLL_HPP
