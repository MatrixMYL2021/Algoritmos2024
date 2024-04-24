#include <iostream>
using namespace std;
int main(){
/*Se ingresan por teclado 2 numeros enteros, ayb calcular e informar:
1- la suma ayb
2- diferencia ayb
3- producto ayb
4- cociente a/b, siendo b distinto de 0 cero.
*/
int a,b;
float cociente;

cout<<"Ingresa el primer numero: "<<endl;
cin>>a;
cout<<"Ingresa el segundo numero: "<<endl;
cin>>b;

if(b!=0){
  cociente = static_cast<float>(a)/b;
}else{
  cociente=0;
  cout<<"No se puede dividir por cero"<<endl;}

cout<<"\nSuma = "<<a+b<<'\n'<<"Diferencia = "<<a-b<<'\n'<<
"Producto = "<<a*b<<'\n'<<"Cociente = "<<cociente;

return 0;
}
