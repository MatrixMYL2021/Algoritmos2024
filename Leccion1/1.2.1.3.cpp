#include <iostream>
using namespace std;

int main() {
int a;
cout<<"ingresa valor : "<<endl;
cin>>a;
float quinta=static_cast<float>(a)/5;
if (a<=5) {
  int resto=0;
  cout<<"\nResto = "<<resto<<endl;}
else{
  int resto= a-(a/5)*5;
  cout<<"\nResto = "<<resto<<endl;}
float septima=static_cast<float>(quinta)/7;

cout<<"Quinta parte = "<<quinta<<endl;
cout<<"Septima parte de la quinta = "<<septima<<endl;

  return 0;
}
