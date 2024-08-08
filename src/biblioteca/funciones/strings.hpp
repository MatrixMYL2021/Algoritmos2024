#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
using namespace std;

int length(string s) {
    return s.length();
}

int charCount(string s, char c) {
    int count = 0;
    for (char ch : s) {
        if (ch == c) {
            count++;
        }
    }
    return count;
}

string substring(string s, int d, int h) {
    return s.substr(d, h - d);
}

string substring(string s, int d) {
    return s.substr(d);
}

int indexOf(string s, char c) {
    size_t pos = s.find(c);
    return (pos != string::npos) ? pos : -1;
}

int indexOf(string s, char c, int offset) {
    size_t pos = s.find(c, offset);
    return (pos != string::npos) ? pos : -1;
}

int indexOf(string s, string toSearch) {
    size_t pos = s.find(toSearch);
    return (pos != string::npos) ? pos : -1;
}

int indexOf(string s, string toSearch, int offset) {
    size_t pos = s.find(toSearch, offset);
    return (pos != string::npos) ? pos : -1;
}

int lastIndexOf(string s, char c) {
    size_t pos = s.rfind(c);
    return (pos != string::npos) ? pos : -1;
}

int indexOfN(string s, char c, int n) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            count++;
            if (count == n) {
                return i;
            }
        }
    }
    return (count >= n) ? s.length() : -1;
}

int charToInt(char c) {
    if (isdigit(c)) return c - '0';
    if (isupper(c)) return c - 'A' + 10;
    if (islower(c)) return c - 'a' + 10;
    return -1;
}

char intToChar(int i) {
    if (i >= 0 && i <= 9) return '0' + i;
    if (i >= 10 && i <= 35) return 'A' + i - 10;
    return '\0';
}

// Agregar más funciones aquí siguiendo la misma estructura

#endif // STRINGS_HPP
