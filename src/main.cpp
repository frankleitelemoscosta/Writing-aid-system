#include<iostream>
#include"File.hpp"
#include"Hashtable.hpp"

using namespace std;

int main()
{
    HashTable h;
    int Size = 0;
    char Text[100];

//extract informations of the input file
    OpenFile(Text,&Size);

//to convert letters for use whit key of the hash table
    ConvertLetters(Text);

    Initialize(&h,Size);

    Imprime(&h);

    return 0;
}

//end code