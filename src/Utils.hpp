#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <fstream>
#include <codecvt>
#include <locale>
#include <map>
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

void printStart(std::wofstream &output);
wchar_t *getText(const std::locale &loc);
std::wofstream createOutput(const std::locale &loc);
void printParagraph(const std::vector<ParagraphInfo> paragraph,
    std::wofstream &output);

#endif /* __UTILS_HPP__ */
