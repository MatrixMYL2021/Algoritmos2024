#include <iostream>
using namespace std;

int length(string s){ //Contador de caracteres 1.1.1.1
  return s.length();
}

int charCount(string s, char c){ //Contador de char 1.1.1.2
  int count =0;
  for(char ch:s){
    if(ch==c){
      count++;
    }
  }return count;
}

//Retorna subcadena entre indices establecidos 1.1.1.3
string substring(string s, int d, int h){
  if( d>h || d<0 || h > s.length()-1){
    return "Indices invalidos";
  }return s.substr(d, h-d+1);
}

string overString(string s, int d){ //1.1.1.4
  return s.substr(d,s.length());
}

int indexOf(string s, char c){ //1.1.1.5
  for(int i=0;i<s.length();i++){
    if(s[i]==c){
      return i;
    }
  }
  return -1;
}

int indexOf2(string s,char c, int offset){//1.1.1.6
  for(int i=(offset+1);i<s.length();i++){
    if (s[i]==c) {
      return i;
    }
  }return -1;
}

int indexOf3(string s, string toSearch){
  for(int i=0;i<s.length();i++){
    if(s[i]==toSearch[i]){
      return i;
    }
  }return -1;
}

//funcion leccion 5 : 2.2.2
int tokenCount(string s,char c){
  if (s.empty()) { //verificamos si esta o no vacio el string
    return 0;
  }
  int count=1;
  for(char ch:s){ //recorremos todo el string con un char "ch"
    if(ch==c){ //si el char ch coincide con el char c, se incrementa el contador
      count ++;
    }
  }
  return count;
}

string addToken(string s, char c,string t){ //agregar un string luego de un token c
    if(s.empty()){
      return t;
    }else{
      return s+c+t;
    }
}
