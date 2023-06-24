#include "PartialMap.hpp"

using namespace std;

PartialData::PartialData() : appearences(0) {}

Text::Text() : line(1), sentence(1), paragraph(1), positions(1) {}

void PartialMap::addWord(const std::wstring &word, const Text &text)
{
  mp[word].sentence.insert(text.sentence);
  mp[word].line.insert(text.line);
  ++mp[word].appearences;
  mp[word].positions.insert(text.positions);
}

void PartialMap::print(std::wofstream &output,
    unsigned short paragraph)
{
  output << L"_______________________________________________________________________________________________________________________________________\n"
            L"WORD 			    PARAGRAPH 		    SENTENCE 		      LINE 		   APPEARANCES 		     POSITIONS\n"
            L"---------------------------------------------------------------------------------------------------------------------------------------\n";
// src/PartialMap.cpp: In member function ‘void PartialMap::print(std::wofstream&, short unsigned int)’:
// src/PartialMap.cpp:24:32: error: ‘struct PartialData’ has no member named ‘paragraph’
//    24 |     for(auto paragraph : it->s.paragraph) output << paragraph << ' ';
  for(auto it = this->mp.begin(); it != this->mp.end(); ++it) {
    output << left << setw(32) << it->f << setw(23) << paragraph << setw(23);
    for(auto sentence : it->s.sentence) output << sentence << ' ';
    output << left << setw(23);
    for(auto line : it->s.line) output << line << ' ';
    output << left << setw(23);
    output << it->s.appearences << ' ';
    output << left << setw(23);
    for(auto position : it->s.positions) output << position << ' ';
    output << L'\n';
  }
  output << L"_______________________________________________________________________________________________________________________________________\n";
}
