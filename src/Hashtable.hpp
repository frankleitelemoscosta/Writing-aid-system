#ifndef HASHTABLE_H 
#define HASHTABLE_H

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

#define HASH(v, M) (v % M)

typedef struct DataTable DataTable;
typedef struct HashTable HashTable;


struct DataTable{
	long long int key;
	string value;
};


struct HashTable{
	DataTable *table;
	int M;
};


void Initialize(HashTable *h, int M);
void Imprime(HashTable *h);
string getValue(HashTable *h, int key);
void Insert(HashTable *h, long long int key, string value);

#endif