#ifndef __TOTAL_MAP_HPP__
#define __TOTAL_MAP_HPP__

#include "PartialMap.hpp"

struct TotalData {
  std::set<unsigned short> paragraph;
  std::set<unsigned short> sentence;
  std::set<unsigned short> line;
  unsigned short appearences;
  std::set<unsigned short> positions;
  TotalData();
};

struct TotalMap {
  std::map<std::wstring, TotalData> mp;
  void printStart(std::wofstream &output);
  void addWord(const std::wstring &word, const Text &text);
  void print(std::wofstream &output);
};

#endif /* __TOTAL_MAP_HPP__ */
