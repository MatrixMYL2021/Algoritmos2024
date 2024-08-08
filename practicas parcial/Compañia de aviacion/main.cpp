#include <iostream>
#include "principal.hpp"
#include "CIUDADES.dat"
#include "RESERVAS.dat"
#include "VUELOS.dat"
#include "Coll.hpp"
using namespace std;

Coll<RVuelo> subirVuelos()
{
  Coll<RVuelo>ret=coll<RVuelo>();
  FILE* f=fopen("VUELOS.dat","r+b");
  Vuelo v =read<Vuelo>(f);
  while (!feof(f)) {
    RVuelo rv=rVuelo(v,0,0);
    collAdd<RVuelo>(ret,rc,rVueloToString);
    v=read<Vuelo>(f);
  }

  fclose(f);
  return {};
}
Coll<RCiudad> subirCiudades()
{
    return {};
}

void mostrarResultadoPto1(Coll<RCiudad> cCiu)
{
  collReset<RCiudad>(cCiu);
  while (collHasNext<RCiudad>(cCiu)) {
    RCiudad rc= collNext<RCiudad>(cCiu,rCiudadFromString);
    string nomCiu=rc.c.descr;
    int cant =rc.cont;
    cout<<nomCiu<<", "<<cant<<endl;
  }
}

void mostrarResultadoPto2(Coll<RVuelo> cVue )
{

}

void mostrarResultadoPto3(Coll<RCliente> cCli)
{

}

int cmpRVueloId(RVuelo rv, int id){
  return rv.v.idVue-id;
}

int cmpRCiudadId(RCiudad rc, int id){
  return rc.c.idCiu-id;
}

void procesarReservaPto1(Reserva r,Coll<RVuelo> cVue, Coll<RCiudad>& cCiu)
{
  //busco el vuelo
  int p = collFind<RVuelo,int>(cVue,r.idVue,cmpRVueloId,rVueloFromString);
  RVuelo rv=collGetAt<RVuelo>(cVue,p,rVueloFromString);

  p = collFind<RCiudad,int>(cCiu,rv.v.idDes,cmpRCiudadId,rCiudadFromString);
  RCiudad rc=collGetAt<RCiudad>(rCiu,p,rCiudadFromString);
  rc.count++;
  collSetAt<RCiudad>(cCiu,rc,p,rCiudadToString);
}


bool aceptoReserva(Reserva r,Coll<RVuelo> cVue){
  int p = collFind<RVuelo,int>(cVue,r.idVue,cmpRVueloId,rVueloFromString);
  RVuelo rv= collGetAt<RVuelo>(cVue,p,rVueloFromString);

  return rv.v.cap-rv.cpa>=r.cant;
}




void procesarReservaPto2(Reserva r,Coll<RVuelo>& cVue)
{
  int p = collFind<RVuelo,int>(cVue,r.idVue,cmpRVueloId,rVueloFromString);
  RVuelo rv=collGetAt<RVuelo>(cVue,p,rVueloFromString);

  // determino si acepto o rechazo
  if (aceptoReserva(r,cVue)) {
    rv.cpa+=r.cant;
  }else{
    rv.cpr+=r.cant;
  }
  collSetAt<RVuelo>(cVue,rv,p,rVueloToString);
}


int cpmRClienteId(RCliente rc,int id){
  return rc.idClie-id;
}

int calcularMillas(Reserva r, Coll<RVuelo> cVue,Coll<RCiudad> cCiu){

  int p = collFind<RVuelo,int>(cVue,r.idVue,cmpRVueloId,rVueloFromString);
  RVuelo rv=collGetAt<RVuelo>(cVue,p,rVueloFromString);
  //busco ciudad destino
  p = collFind<RCiudad,int>(cCiu,rv.v.idDes,cmpRCiudadId,rCiudadFromString);
  RCiudad rcd=collGetAt<RCiudad>(rCiu,p,rCiudadFromString);
  //busco ciudad origen
  p = collFind<RCiudad,int>(cCiu,rv.v.idOri,cmpRCiudadId,rCiudadFromString);
  RCiudad rco=collGetAt<RCiudad>(rCiu,p,rCiudadFromString);

  return abs(rcd.c.milla-rco.c.millas)*r.cant;
}


void procesarReservaPto3(Reserva r ,Coll<RVuelo> cVue,Coll<RCiudad> cCiu,Coll<RCliente>& cCli)
{
  int p = collFind<RCliente,int>(cCli,r.idCli,cmpRClienteId,rClienteFromString);

  if (p<0) {
    RCliente rc = rCliente(r.idCli,0);
    collAdd<RCliente>(cCli,rc,rClienteToString)
  }



  if (aceptoReserva(r,cVue)) {
    int millas=calcularMillas(r,cVue,cCiu);
    RCliente x = collGetAt<RCliente>(cCli,p,rClienteFromString);
    x.acum+=millas;
    collSetAt<RCliente>(cClie,x,p,rClienteToString);
  }

}


int main(){
//subo los archivos de consultas
Coll<RVuelo> cVue=subirVuelos();
Coll<RCiudad> cCiu=subirCiudades();
//descubrimiento x cliente
Coll<RCliente> cCli=coll<RCliente>();

//recorremos el archivo de novedades

FILE* f = fopen("RERERVAS.dat","r+b");
Reserva r= read<Reserva>(f);
while( !feof(f) ){
  procesarReservaPto1(r,cVue,cCiu);
  procesarReservaPto2(r,cVue);
  procesarReservaPto3(r,cVue,cCiu,cCli);
  r = read<Reserva>(f);
}

//muestro resultados solicitados
mostrarResultadoPto1(cCiu);
mostrarResultadoPto2(cVue);
mostrarResultadoPto3(cCli);


  return 0;
}
