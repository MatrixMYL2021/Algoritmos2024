// strings.hpp
#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int length(const string& s) {
    return s.length();
}

int charCount(const string& s, char c) {
    int count = 0;
    for (char ch : s) {
        if (ch == c) count++;
    }
    return count;
}

string substring(const string& s, int d, int h) {
    return s.substr(d, h - d);
}

string substring(const string& s, int d) {
    return s.substr(d);
}

int indexOf(const string& s, char c) {
    return s.find(c);
}

int indexOf(const string& s, char c, int offset) {
    return s.find(c, offset);
}

int indexOf(const string& s, const string& toSearch) {
    return s.find(toSearch);
}

int indexOf(const string& s, const string& toSearch, int offset) {
    return s.find(toSearch, offset);
}

int lastIndexOf(const string& s, char c) {
    return s.rfind(c);
}

int indexOfN(const string& s, char c, int n) {
    int count = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            count++;
            if (count == n) return i;
        }
    }
    return -1;
}

int charToInt(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 10;
    return -1;
}

char intToChar(int i) {
    if (i >= 0 && i <= 9) return '0' + i;
    if (i >= 10 && i <= 35) return 'A' + i - 10;
    return '\0';
}

int getDigit(int n, int i) {
    string s = to_string(n);
    return s[s.length() - 1 - i] - '0';
}

int digitCount(int n) {
    return to_string(n).length();
}

string intToString(int i) {
    return to_string(i);
}

int stringToInt(const string& s, int b) {
    return stoi(s, nullptr, b);
}

int stringToInt(const string& s) {
    return stoi(s);
}

string charToString(char c) {
    return string(1, c);
}

char stringToChar(const string& s) {
    if (s.length() == 1) return s[0];
    return '\0';
}

string stringToString(const string& s) {
    return s;
}

string doubleToString(double d) {
    return to_string(d);
}

double stringToDouble(const string& s) {
    return stod(s);
}

bool isEmpty(const string& s) {
    return s.empty();
}

bool startsWith(const string& s, const string& x) {
    return s.find(x) == 0;
}

bool endsWith(const string& s, const string& x) {
    return s.rfind(x) == s.length() - x.length();
}

bool contains(const string& s, char c) {
    return s.find(c) != string::npos;
}

string replace(string s, char oldChar, char newChar) {
    replace(s.begin(), s.end(), oldChar, newChar);
    return s;
}

string insertAt(string s, int pos, char c) {
    s.insert(s.begin() + pos, c);
    return s;
}

string removeAt(string s, int pos) {
    s.erase(s.begin() + pos);
    return s;
}

string ltrim(string s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
    return s;
}

string rtrim(string s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
    return s;
}

string trim(string s) {
    return ltrim(rtrim(s));
}

string replicate(char c, int n) {
    return string(n, c);
}

string spaces(int n) {
    return replicate(' ', n);
}

string lpad(const string& s, int n, char c) {
    if (s.length() >= n) return s;
    return string(n - s.length(), c) + s;
}

string rpad(const string& s, int n, char c) {
    if (s.length() >= n) return s;
    return s + string(n - s.length(), c);
}

string cpad(const string& s, int n, char c) {
    int totalPadding = n - s.length();
    if (totalPadding <= 0) return s;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;
    return string(leftPadding, c) + s + string(rightPadding, c);
}

bool isDigit(char c) {
    return isdigit(c);
}

bool isLetter(char c) {
    return isalpha(c);
}

bool isUpperCase(char c) {
    return isupper(c);
}

bool isLowerCase(char c) {
    return islower(c);
}

char toUpperCase(char c) {
    return toupper(c);
}

char toLowerCase(char c) {
    return tolower(c);
}

string toUpperCase(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string toLowerCase(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int cmpString(const string& a, const string& b) {
    return a.compare(b);
}

int cmpDouble(double a, double b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

#endif // STRINGS_HPP
