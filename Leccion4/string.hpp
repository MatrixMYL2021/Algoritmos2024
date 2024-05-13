#include <iostream>
using namespace std;

int length(string s){ //Contador de caracteres 1.1.1.1
  return s.length();
}

int charCount(string s, char c){ //Contador de char 1.1.1.2
  int count =0;
  for(char ch:s){
    if(ch==c){
      c++;
    }
  }return count;
}

//Retorna subcadena entre indices establecidos 1.1.1.3
string substring(string s, int d, int h){
  if(d>h||d<0||h>s.length()-1){
    return "Indices invalidos";
  }return s.substr(d,h-d+1);
}
