#include<iostream>
#include<cstring>
#include<stdint.h>
#include"Convertion.hpp"
#include"Hashtable.hpp"

using namespace std;

void ConvertLetters(char Text[100],HashTable *h){

    string AID;
    int Counter = 0;
    int Counter_Aux = 0;
    unsigned long long int Number;
    string NumberAux;
    string result;
    string resultado;


    while(Text[Counter] != '*')
    {
        if(Text[Counter] == ' ' || Text[Counter] == '.')
        {
            for(int i = 0 ; i < Counter_Aux ; i++)
            {
                Number = int(AID[i]);// a conversão funciona corretamente
                NumberAux = to_string(Number);
                result = result + NumberAux;
            }

            NumberAux.clear();

            resultado = result;

            cout<< result<<endl;
            cout<<resultado<<endl;

            Number = stoull(resultado);

            resultado.clear();
            result.clear();

            //in here, i pass to function insert hash the key and the word

            Insert(h,Number,AID);

            AID.clear();

            Counter_Aux = 0;
            Counter++;
        }


        AID += Text[Counter];        
        Counter_Aux++;
        Counter++;
    }

}