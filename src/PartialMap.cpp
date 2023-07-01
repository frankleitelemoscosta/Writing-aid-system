#include "PartialMap.hpp"

using namespace std;

PartialData::PartialData() : appearences(0) {}

Text::Text() : line(1), sentence(1), paragraph(1), positions(1) {}

void PartialMap::addWord(const std::wstring &word, const Text &text)
{
  if(mp.count(word) != 0) {
    mp[word].distances.insert(text.positions - *mp[word].positions.rbegin());
  }
  mp[word].sentence.insert(text.sentence);
  mp[word].line.insert(text.line);
  ++mp[word].appearences;
  mp[word].positions.insert(text.positions);
  mp[word].positions.insert(text.positions);
}

static inline unsigned short countDigits(unsigned short num)
{
  return num < 10 ? 1 :
         num < 100 ? 2 :
         num < 1000 ? 3 :
         num < 10000 ? 4 :
         5;
}

void PartialMap::print(std::wofstream &output,
    unsigned short paragraph)
{
  unsigned short space_sz;

  output << L"______________________________________________________________________________________________________________________________________________________________\n"
            L"WORD 			    PARAGRAPH 		    SENTENCE 		      LINE 		   APPEARANCES 		     POSITIONS 		    DISTANCES\n"
            L"--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

  for(auto it = this->mp.begin(); it != this->mp.end(); ++it) {
    output << it->f
           << (it->f.length() < 8 ? L"\t\t\t\t" : it->f.length() < 16 ? L"\t\t\t" : it->f.length() < 24 ? L"\t\t" : L"\t")
           << paragraph << "\t\t\t";

    space_sz = 0;
    for(const auto &sentence : it->s.sentence) {
      output << sentence << L' ';
      space_sz += countDigits(sentence) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

    space_sz = 0;
    for(const auto &line : it->s.line) {
      output << line << L' ';
      space_sz += countDigits(line) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t")

           << it->s.appearences << "\t\t\t";

    space_sz = 0;
    for(const auto &position : it->s.positions) {
      output << position << L' ';
      space_sz += countDigits(position) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

    for(const auto &distance : it->s.distances) {
      output << distance << L' ';
    }
    output << L'\n';
  }
  output << L"______________________________________________________________________________________________________________________________________________________________\n";
}
