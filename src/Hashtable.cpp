#include "Hashtable.hpp"

void Initialize(HashTable *h, int M){

	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	for(int i=0; i<M; i++){
		h->table[i].key   = -1;
		h->table[i].value = 0;
	}

	h->M = M;
}

void Imprime(HashTable *h){
	
    for(int i = 0; i < h->M ; i++) printf("KEY:%d - VALUE:%d\n", h->table[i].key, h->table[i].value);
}

int getValue(HashTable *h, int key){

	int idx = HASH(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != key){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			return -1;
		}
	}

	return h->table[idx].value;
}

void Insert(HashTable *h, int key, int value){
    
	int idx = HASH(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != -1){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			printf("OPENED HASH IS FULL!\n");
			return;
		}
	}	
	
	h->table[idx].key   = key;
	h->table[idx].value = value;
}