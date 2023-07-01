#ifndef __EXPRESSION_HPP
#define __EXPRESSION_HPP

#include "TotalMap.hpp"
#include <string>
#include <vector>
#include<iostream>

using namespace std;

typedef struct Expression{
    string expressoes[100];
    int Size;
}Expression;

void CheckExpression(string s,TotalMap &tm);

#endif