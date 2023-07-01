#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <fstream>
#include <codecvt>
#include <locale>
#include <map>
#include <set>
#include <vector>
#include <unordered_set>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl;

struct Count {
  unsigned short words;
  unsigned short stop_words;
  Count();
  void clear();
  void print(std::wofstream &output);
};

struct ParagraphInfo {
  unsigned short number;
  unsigned short beginAtLine;
  unsigned short sentences;
  void print(std::wofstream &output);
};

struct Expression {
  std::wstring str;
  unsigned short appearances;
  std::set<unsigned short> lines;
  Expression();
};

struct Sentence {
  unsigned short paragraph;
  unsigned short sentence;
  unsigned short n_of_words;
  unsigned short n_of_stop_words;
  Sentence();
  Sentence(unsigned short paragraph, unsigned short sentence,
           unsigned short n_of_words, unsigned short n_of_stop_words);
};

void printStart(std::wofstream &output);
wchar_t *getText(const std::locale &loc);
std::wofstream createOutput(const std::locale &loc);
void printParagraph(const std::vector<ParagraphInfo> paragraph,
    std::wofstream &output);
std::vector<Expression> readExpressions(const std::locale &loc);
void printExpressions(const std::vector<Expression> expressions, std::wofstream &output);
void printSentences(std::vector<Sentence> sentences, std::wofstream &output);

#endif /* __UTILS_HPP__ */
