#ifndef __EXPRESSION_HPP
#define __EXPRESSION_HPP

#include "TotalMap.hpp"
#include <string>
#include <vector>

using namespace std;

typedef struct word {
    short int par;
    short int sen;
    short int pos;

    word(short int par, short int sen, short int pos){
        this->par = par;
        this->sen = sen;
        this->pos = pos;
    }
} Word;

typedef struct sentence{
    short int par;
    short int sen;

    sentence(short int par, short int sen){
        this->par = par;
        this->sen = sen;
    }
} Sentence;

short int CheckExpression(wstring word, wstring prevWord,TotalMap &tm, vector<Sentence> &locations);

#endif