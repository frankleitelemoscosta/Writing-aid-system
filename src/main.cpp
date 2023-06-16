#include<iostream>
#include"File.hpp"
#include"Hashtable.hpp"
#include"Convertion.hpp"

using namespace std;

int main()
{
    HashTable h;
    int Size = 0;
    char Text[100];

//extract informations of the input file
    OpenFile(Text,&Size);

    Initialize(&h,Size);

    Imprime(&h);

//to convert letters for use whit key of the hash table
    ConvertLetters(Text,&h);

    Imprime(&h);

    return 0;
}

//end code