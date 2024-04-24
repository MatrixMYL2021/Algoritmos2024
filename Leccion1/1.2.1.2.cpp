#include <iostream>
using namespace std;
int main(){
  int a,b;
  float cociente;
  cout << "ingrese primer valor" << '\n';
  cin>>a;
  cout << "ingrese segundo valor" << '\n';
  cin>>b;
  if (b!=0) {
    cociente=static_cast<float>(a)/b;
    cout<<"Cociente = "<<cociente;
  }else{cout<<"\nError, no puede ingresar 0 cero como denominador"<<endl;}
}
