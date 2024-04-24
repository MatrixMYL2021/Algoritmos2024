#include<iostream>
using namespace std;
int main() {
int a,b;
cout<<"primer valor: "<<endl;
cin>>a;
cout<<"segundo valor: "<<endl;
cin>>b;

if (a==b) {
  cout << "\nLos valores son iguales";
}else{
  if (a>b) {
    cout<<"\nMayor = "<<a<<" || "<<"Menor = "<<b<<endl;}
  else{
    cout<<"\nMayor = "<<b<<" || "<<"Menor = "<<a<<endl;}
}


  return 0;
}
