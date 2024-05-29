#include <iostream>
#include "string.hpp"
using namespace std;

int main() {
  string lema="Viva la libertad caraja";

  cout<<"1.1.1.1 : "<<"length= "<<length(lema)<<endl;
  cout<<"1.1.1.2 : "<<"Veces que aparece el char = "<<charCount(lema,'l')<<endl;
  cout<<"1.1.1.3 : "<<substring(lema,8,15)<<endl;
  cout<<"1.1.1.4 : "<<overString(lema,5)<<endl;
  cout<<"1.1.1.5 : "<<"Posicion = "<<indexOf(lema,'x')<<endl;
  cout<<"1.1.1.6 : "<<"Posicion = "<<indexOf2(lema,'i',1)<<endl;
  cout<<"1.1.1.7 : "<<"Posicion = "<<indexOf3(lema, "l")<<endl;

  string s="";
  int n =tokenCount(s,'|');
  cout<<"Cant de tokens: "<<n<<endl;

  string a="";
  string c="Martinez";
  char b='|';
  string lol=addToken(a,b,c);
  //string lol2=a+b+c;
  std::cout << lol << '\n';




}
