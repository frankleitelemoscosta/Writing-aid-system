#include<iostream>
#include<cstring>
#include<stdint.h>
#include"Map.hpp"
#include<map>

using namespace std;

void PrintMap(map<string,string> &Mymap)
{

    for (auto it = Mymap.begin(); it != Mymap.end(); ++it) {
        cout << "Chave: " << it->first << ", Valor: " << it->second << endl;
    }

}

void InsertMap(char Text[1000]){

    //this map have how key a string, and how value a string 
    map<string,string> Mymap;
    string Aux;
    string AID;
    int Counter = 0;
    int Counter_Aux = 0;

    while(Text[Counter] != '\0')
    {
        if(Text[Counter] == ' ' || Text[Counter] == '.')
        {

            Mymap[AID];

            AID.clear();

            Counter++;
            Counter_Aux++;
        }

        AID += Text[Counter];        
        Counter++;
    }

    PrintMap(Mymap);

}

