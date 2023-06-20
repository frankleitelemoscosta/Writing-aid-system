#include"File.hpp"
#include<string>
#include<string.h>

using namespace std;

void ReadFile(FILE **File,int *Size,char *Text)
{

    int Counter = 0;
    int Counter_aux = 0;


//extract the data of the file
    while(!feof(*File)){
        fscanf(*File,"%c",&Text[Counter]);
        Counter++;
    }

    Text[Counter] = '\0';

//extract the quantiti of words that exist in the input file
    while(Text[Counter_aux] != '\0')
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