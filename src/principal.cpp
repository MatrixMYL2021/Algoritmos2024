#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/colldiscord.hpp"
#include "principal.hpp"
using namespace std;




int main()
{

	/*Coll<Persona> c = coll<Persona>();
	collAdd<Persona>(c,persona(1,"Pablo","Aguero 222"),personaToString);
	collAdd<Persona>(c,persona(2,"Matias","Quesada 1248"),personaToString);
	collAdd<Persona>(c,persona(3,"Milei","Casa Rosada 1"),personaToString);

	collReset<Persona>(c);
	while(collHasNext<Persona>(c))
	{
		Persona p = collNext<Persona>(c,personaFromString);
		cout<<personaToDebug(p)<<endl;
	}*/

/*	Coll<RPersona> c = coll<RPersona>();
	collAdd<RPersona>(c,rPersona(persona(1,"Matias","Quesada 1248"),0),rPersonaToString);
	collAdd<RPersona>(c,rPersona(persona(2,"Pedro","Quesada 987"),0),rPersonaToString);
	collAdd<RPersona>(c,rPersona(persona(3,"Marion","Quesada 5111"),0),rPersonaToString);

	collReset<RPersona>(c);
	while(collHasNext<RPersona>(c)){
		RPersona x = collNext<RPersona>(c,rPersonaFromString);
		cout<<rPersonaToDebug(x)<<endl;
	}*/

	FILE* f = fopen("CIUDADES.dat","r+b");

	Ciudad p = read<Ciudad>(f);
	while(!feof(f))
	{
		cout<<ciudadToDebug(p)<<endl;
		p=read<Ciudad>(f);
	}


	fclose(f);
	return 0;
}

