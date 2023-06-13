#include"Hashtable.hpp"
#include"File.hpp"
#include<string>
#include<string.h>

using namespace std;

void ConvertLetters(char Text[100]){

    char AID[100];
    int Counter = 0;
    int Counter_Aux = 0;
    int Number;
    char NumberAux[10];
    char result[10];

    while(Text[Counter] != '*')
    {
        if(Text[Counter] == ' ' || Text[Counter] == '.')
        {
            for(int i = 0 ; i < Counter_Aux ; i++)
            {
                Number = int(AID[i]);
                sprintf(NumberAux, "%d" ,Number);
                strcat(result,NumberAux);
            }
            
            Counter_Aux = 0;
            Counter++;
        }

        AID[Counter_Aux] = Text[Counter]; 
        Counter_Aux++;
        Counter++;
    }

}


void ReadFile(FILE **File,int *Size,char *Text)
{

    int Counter = 0;
    int Counter_aux = 0;

//initialize the vet
    for(int i = 0; i < 100; i++)
    {
        Text[i] = '*';
    }

//extract the data of the file
    while(!feof(*File)){
        fscanf(*File,"%c",&Text[Counter]);
        Counter++;
    }

//extract the quantiti of words that exist in the input file
    while(Text[Counter_aux] != '*')
    {
        if(Text[Counter_aux] == ' ' || Text[Counter_aux] == '.')
        {
            *Size = *Size + 1;
        }
        Counter_aux++; 
    }
}

void OpenFile(char *Text,int *Size){

    FILE *File = fopen("dataset/input.data","r");

    ReadFile(&File,Size,Text);
}