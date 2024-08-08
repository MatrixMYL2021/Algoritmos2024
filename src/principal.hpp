#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/colldiscord.hpp"
using namespace std;

struct Persona
{
	int dni;
	string nombre;
	string direccion;
};

struct RPersona
{
	Persona p;
	int cont;
};

string personaToString(Persona x)
{
	char sep = 1;
	string sDni=to_string(x.dni);
	string sNombre=x.nombre;
	string sDireccion=x.direccion;
	return sDni+sep+sNombre+sep+sDireccion;
}

Persona personaFromString(string s)
{
	char sep = 1;
	Persona x;
	string t0 = getTokenAt(s,sep,0);
	x.dni=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.nombre=t1;
	string t2 = getTokenAt(s,sep,2);
	x.direccion=t2;
	return x;
}

string personaToDebug(Persona x)
{
	stringstream sout;
	sout<< "[";
	sout << x.dni;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout<< "]";
	return sout.str();
}

string personaToDebug(string mssg,Persona x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.dni;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout<< "]";
	return sout.str();
}

Persona persona(int dni,string nombre,string direccion)
{
	Persona a;
	a.dni = dni;
	a.nombre = nombre;
	a.direccion = direccion;
	return a;
}

bool personaEquals(Persona a,Persona b)
{
	if(a.dni!=b.dni) return false;
	if(a.nombre!=b.nombre) return false;
	if(a.direccion!=b.direccion) return false;
	return true;
}

string rPersonaToString(RPersona x)
{
	char sep = 2;
	string sP=personaToString(x.p);
	string sCont=to_string(x.cont);
	return sP+sep+sCont;
}

RPersona rPersonaFromString(string s)
{
	char sep = 2;
	RPersona x;
	string t0 = getTokenAt(s,sep,0);
	x.p=personaFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont=stoi(t1);
	return x;
}

string rPersonaToDebug(RPersona x)
{
	stringstream sout;
	sout<< "[";
	sout << personaToDebug(x.p);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

string rPersonaToDebug(string mssg,RPersona x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << personaToDebug(x.p);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

RPersona rPersona(Persona p,int cont)
{
	RPersona a;
	a.p = p;
	a.cont = cont;
	return a;
}

bool rPersonaEquals(RPersona a,RPersona b)
{
	if(!personaEquals(a.p,b.p)) return false;
	if(a.cont!=b.cont) return false;
	return true;
}

#endif
