// tokens.hpp
#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int tokenCount(const string& s, char sep) {
    if (s.empty()) return 0;
    int count = 1;
    for (char c : s) {
        if (c == sep) count++;
    }
    return count;
}

void addToken(string& s, char sep, const string& t) {
    if (!s.empty()) s += sep;
    s += t;
}

string getTokenAt(const string& s, char sep, int i) {
    istringstream iss(s);
    string token;
    while (i-- >= 0) {
        getline(iss, token, sep);
    }
    return token;
}

void removeTokenAt(string& s, char sep, int i) {
    vector<string> tokens;
    istringstream iss(s);
    string token;
    while (getline(iss, token, sep)) {
        tokens.push_back(token);
    }
    if (i >= 0 && i < tokens.size()) {
        tokens.erase(tokens.begin() + i);
    }
    s = "";
    for (size_t j = 0; j < tokens.size(); j++) {
        if (j > 0) s += sep;
        s += tokens[j];
    }
}

void setTokenAt(string& s, char sep, const string& t, int i) {
    vector<string> tokens;
    istringstream iss(s);
    string token;
    while (getline(iss, token, sep)) {
        tokens.push_back(token);
    }
    if (i >= 0 && i < tokens.size()) {
        tokens[i] = t;
    }
    s = "";
    for (size_t j = 0; j < tokens.size(); j++) {
        if (j > 0) s += sep;
        s += tokens[j];
    }
}

int findToken(const string& s, char sep, const string& t) {
    vector<string> tokens;
    istringstream iss(s);
    string token;
    int pos = 0;
    while (getline(iss, token, sep)) {
        if (token == t) return pos;
        pos++;
    }
    return -1;
}

#endif // TOKENS_HPP
