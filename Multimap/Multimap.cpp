// Multimap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <map>
#include <string>
#include <iostream>
#include <algorithm>    // std::sort
using namespace std;

//typedef multimap<int, string> MULTI_MAP;
typedef multimap<int, int> MULTI_MAP;
typedef MULTI_MAP::iterator ITERATOR;




int main()
{
   MULTI_MAP  m;            // Multimap anlegen.
   ITERATOR pos;            // Iterator.
                            // Einfügen:   
  /*
   m.insert(pair<int, string>(7, "Uwe") );        
   m.insert(pair<int, string>(3, "Edith"));
   m.insert(pair<int, string>(1, "Dina"));
   m.insert(pair<int, string>(1, "Lino"));

   cout << "Hier die Multimap: " << endl;
 
   for(pos = m.begin(); pos!= m.end(); pos++)
       cout << pos->first << "  "
            << pos->second << endl;      
   cout << endl;

   pos = m.find(3);       // Paar zum Schlüssel suchen
   if( pos != m.end())
     cout << pos->first << "  " << pos->second << endl;

   int key = 1;            // Anzahl Objekte bestimmen
   cout << "Zum Schluessel " << key << " gibt es " 
        <<  m.count(key) << " Objekte " << endl;
   */


   int myints2[][2] = { { 32, 0 }, { 71, 1 }, { 12, 2 }, { 45, 3 }, { 26, 4 }, { 80, 5 }, { 53, 6 }, { 33, 7 } };

   for(int i = 0; i < 8; i++)
   {
      m.insert(pair<int, int>(myints2[i][0],myints2[i][1] ));
   }
 
   pos = m.begin();
   int index = 3;
   for (int i = 0; i < index; ++i)
   {
	   printf("i: %d\n",i);
	   pos++;
   }

   cout << pos->first << endl;
   
   pos = m.find(71);       // Paar zum Schlüssel suchen
   if( pos != m.end())
   {
       cout << pos->first << "  " << pos->second << endl;
   }
   else
   {
	   cout << "Nicht vorhanden!" << endl;
   }
   //////////////////////////////////////////////
   cout << "Hier die Multimap: " << endl;
 
   for(pos = m.begin(); pos!= m.end(); pos++)
       cout << pos->first << "  "
            << pos->second << endl;      
   cout << endl;
   return 0;
}

