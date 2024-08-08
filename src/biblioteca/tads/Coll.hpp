#ifndef COLL_HPP
#define COLL_HPP

#include <string>
#include <vector>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
using namespace std;

template<typename T>
struct Coll {
    string s;
    char sep;
    int curr;
};

template<typename T>
Coll<T> coll(char sep = '|') {
    Coll<T> c;
    c.sep = sep;
    c.curr = 0;
    return c;
}

template<typename T>
int collSize(Coll<T> c) {
    return tokenCount(c.s, c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c) {
    c.s.clear();
    c.curr = 0;
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p) {
    removeTokenAt(c.s, c.sep, p);
}

template<typename T>
int collAdd(Coll<T>& c, T t, string tToString(T)) {
    addToken(c.s, c.sep, tToString(t));
    return collSize(c) - 1;
}

template<typename T>
void collSetAt(Coll<T>& c, T t, int p, string tToString(T)) {
    setTokenAt(c.s, c.sep, tToString(t), p);
}

template<typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string)) {
    return tFromString(getTokenAt(c.s, c.sep, p));
}

template<typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string)) {
    for (int i = 0; i < collSize(c); i++) {
        T t = collGetAt(c, i, tFromString);
        if (cmpTK(t, k) == 0) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string), string tToString(T)) {
    vector<T> elements;
    for (int i = 0; i < collSize(c); i++) {
        elements.push_back(collGetAt(c, i, tFromString));
    }
    sort(elements.begin(), elements.end(), cmpTT);
    collRemoveAll(c);
    for (T t : elements) {
        collAdd(c, t, tToString);
    }
}

template<typename T>
bool collHasNext(Coll<T> c) {
    return c.curr < collSize(c);
}

template<typename T>
T collNext(Coll<T>& c, T tFromString(string)) {
    T t = collGetAt(c, c.curr, tFromString);
    c.curr++;
    return t;
}

template<typename T>
T collNext(Coll<T>& c, bool& eoc, T tFromString(string)) {
    eoc = (c.curr >= collSize(c));
    if (!eoc) {
        return collNext(c, tFromString);
    }
    return T();
}

template<typename T>
void collReset(Coll<T>& c) {
    c.curr = 0;
}

template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.s=substring(s,1);
	return c;
}



#endif // COLL_HPP
