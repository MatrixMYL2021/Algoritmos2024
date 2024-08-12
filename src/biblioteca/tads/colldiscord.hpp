#ifndef TCOLL_T
#define TCOLL_T

#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../funciones/files.hpp"


using namespace std;

template<typename T>
struct Coll
{
   string s="";
   char sepa;
   int pos;
};

template<typename T>
Coll<T> coll(char sep)//Crea una coleccion vacia y nos dan el separador
{
   Coll<T> c;
   c.sepa=sep;
   c.pos = 0;
   return c;
}

template<typename T>
Coll<T> coll()//Crea una coleccion vacia y elegimos nosotros el separador
{
   Coll<T> c;
   c.sepa='|';
   c.pos = 0;
   return c;
}

template<typename T>
int collSize(Coll<T> c)//cantidad de elementos que contiene c
{
   int cToken = tokenCount(c.s,c.sepa) ;
   //Juan|pedro|Agustin
   return cToken;
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sepa,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   string r = tToString(t);
   addToken(c.s,c.sepa,r);
   return tokenCount(c.s,c.sepa)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s,c.sepa,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   t=tFromString(getTokenAt(c.s,c.sepa,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   T t;
   int a;
   for(int i = 0;i<tokenCount(c.s,c.sepa);i++){
      t = tFromString(getTokenAt(c.s,c.sepa,i));
      if(cmpTK(t,k) == 0){
         a = i;
      }
   }
   return a;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   T t1,t2,temp;

   for(int i=0;i<collSize(c);i++){
      for(int j=0;j<collSize(c);j++){
         t1=tFromString(getTokenAt(c.s,c.sepa,i));
         t2=tFromString(getTokenAt(c.s,c.sepa,j));
         if(cmpTT(t1,t2)>0){
            temp = t2;
            t2 = t1;
            t1 = temp;
            collSetAt(c,t1,i,tToString);
            collSetAt(c,t2,j,tToString);
         }
      }
   }
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   if(collSize(c)>c.pos){
      return true;
   } else{
      return false;
   }
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t;
   string s;
   if (collHasNext<T>(c)){
      s = getTokenAt(c.s,c.sepa,c.pos);
      t = tFromString(s);
      c.pos++;
   }
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   c.pos++;
   T t;
   string s;
   if (c.pos == tokenCount(c.s,c.sepa)){
      s = getTokenAt(c.s,c.sepa,c.pos);
      t = tFromString(s);
      endOfColl = true;
   } else {
      s = getTokenAt(c.s,c.sepa,c.pos);
      t = tFromString(s);
      endOfColl = false;
   }

   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.pos = 0;
}


template<typename T>
string collToString(Coll<T> c)
{
	return c.sepa+c.s="";
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sepa=s[0];
	c.s=""+substring(s,1);
	return c;
}


#endif
