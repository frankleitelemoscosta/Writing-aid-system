#include<iostream>
#include<cstring>
#include"Convertion.hpp"
#include"Hashtable.hpp"

using namespace std;

void ConvertLetters(char Text[100],HashTable *h){

    char *AID;
    int Counter = 0;
    int Counter_Aux = 0;
    long long int Number;
    char NumberAux[10];
    char *result;

    AID = (char *)malloc(100*sizeof(char));

    while(Text[Counter] != '*')
    {
        if(Text[Counter] == ' ' || Text[Counter] == '.')
        {
            for(int i = 0 ; i < Counter_Aux ; i++)
            {
                Number = int(AID[i]);// a conversão funciona corretamente
                printf("Letter(%d):[%lld]\n",i,Number);
                sprintf(NumberAux, "%lld" ,Number);
                cout<<"Número auxiliar"<<i<<": "<< NumberAux<<endl;
                strcat(result,NumberAux);
            }
            
            cout << result <<endl;

            Number = stol(result);

            free(result);

            //in here, i pass to function insert hash the key and the word

            Insert(h,Number,AID);

            free(AID);
            AID = (char *)malloc(100*sizeof(char));

            Counter_Aux = 0;
            Counter++;
        }

        result = (char *)malloc(50*sizeof(char));


        AID[Counter_Aux] = Text[Counter]; 
        Counter_Aux++;
        Counter++;
    }

}