#include<iostream>
#include"File.hpp"
#include"Map.hpp"

using namespace std;

int main()
{
    int Size = 0;
    char Text[1000];

//extract informations of the input file
    OpenFile(Text,&Size);

//to convert letters for use whit key of the hash table
    InsertMap(Text);

    return 0;
}

//end code