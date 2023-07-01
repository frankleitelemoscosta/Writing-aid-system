#ifndef __PARTIAL_MAP_HPP__
#define __PARTIAL_MAP_HPP__

#include <map>
#include <string>
#include <set>
#include <fstream>

#define f first
#define s second

struct PartialData {
  std::set<unsigned short> sentence;
  std::set<unsigned short> line;
  unsigned short appearences;
  std::set<unsigned short> positions;
  std::set<unsigned short> distances;
  PartialData();
};

struct Text {
  unsigned short line;
  unsigned short sentence;
  unsigned short paragraph;
  unsigned short positions;
  Text();
};

struct PartialMap {
  std::map<std::wstring, PartialData> mp;
  void printStart(std::wofstream &output);
  void addWord(const std::wstring &word, const Text &text);
  void print(std::wofstream &output, unsigned short paragraph);
};

#endif /* __PARTIAL_MAP_HPP__ */
