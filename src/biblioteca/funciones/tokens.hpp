#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>
#include <vector>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep) {
    int count = 0;
    for (char ch : s) {
        if (ch == sep) {
            count++;
        }
    }
    return s.empty() ? 0 : count + 1;
}

void addToken(string& s, char sep, string t) {
    if (!s.empty()) {
        s += sep;
    }
    s += t;
}

string getTokenAt(string s, char sep, int i) {
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(sep)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);
    return (i >= 0 && i < tokens.size()) ? tokens[i] : "";
}

void removeTokenAt(string& s, char sep, int i) {
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(sep)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);
    if (i >= 0 && i < tokens.size()) {
        tokens.erase(tokens.begin() + i);
        s.clear();
        for (int j = 0; j < tokens.size(); j++) {
            if (j > 0) s += sep;
            s += tokens[j];
        }
    }
}

void setTokenAt(string& s, char sep, string t, int i) {
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(sep)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);
    if (i >= 0 && i < tokens.size()) {
        tokens[i] = t;
        s.clear();
        for (int j = 0; j < tokens.size(); j++) {
            if (j > 0) s += sep;
            s += tokens[j];
        }
    }
}

int findToken(string s, char sep, string t) {
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(sep)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == t) return i;
    }
    return -1;
}

#endif // TOKENS_HPP
