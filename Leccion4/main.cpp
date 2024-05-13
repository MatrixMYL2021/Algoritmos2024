#include <iostream>
#include "string.hpp"
using namespace std;

int main() {
  string eleccion="Viva la libertad carajo";
  int d=8; int h=15;
  cout<<"Extracto: "<<substring(eleccion,d,h)<<endl;
  cout<<"cant char: "<<charCount(eleccion,'c')<<endl;
  cout<<"contador de caract: "<<length(eleccion)<<endl;

}
