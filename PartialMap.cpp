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
    auto sentence = it->s.sentence.begin();
    auto line = it->s.line.begin();
    auto position = it->s.positions.begin();
    auto distance = it->s.distances.begin();
    bool loop, first = true;

    output << it->f
           << (it->f.length() < 8 ? L"\t\t\t\t" : it->f.length() < 16 ? L"\t\t\t" : it->f.length() < 24 ? L"\t\t" : L"\t")
           << paragraph << "\t\t\t";

    do {
      loop = false;

      if(!first) output << L"\t\t\t\t\t\t\t";

      space_sz = 0;
      while(sentence != it->s.sentence.end()) {
        output << *sentence << L' ';
        space_sz += countDigits(*sentence) + 1;
        ++sentence;
        if(space_sz > 16 && sentence != it->s.sentence.end()) {
          loop = true;
          break;
        }
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      space_sz = 0;
      while(line != it->s.line.end()) {
        output << *line << L' ';
        space_sz += countDigits(*line) + 1;
        ++line;
        if(space_sz > 16 && line != it->s.line.end()) {
          loop = true;
          break;
        }
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      if(first) output << it->s.appearences;
      output << "\t\t\t";

      space_sz = 0;
      while(position != it->s.positions.end()) {
        output << *position << L' ';
        space_sz += countDigits(*position) + 1;
        ++position;
        if(space_sz > 16 && position != it->s.positions.end()) {
          loop = true;
          break;
        }
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      space_sz = 0;
      while(distance != it->s.distances.end()) {
        output << *distance << L' ';
        space_sz += countDigits(*distance) + 1;
        ++distance;
        if(space_sz > 16 && distance != it->s.distances.end()) {
          loop = true;
          break;
        }
      }

      output << L'\n';

      if(first) first = false;
    } while(loop);
  }
  output << L"______________________________________________________________________________________________________________________________________________________________\n";
}
