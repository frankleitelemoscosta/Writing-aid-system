#include "TotalMap.hpp"

TotalData::TotalData() : appearences(0) {}

void TotalMap::addWord(const std::wstring &word, const Text &text)
{
  mp[word].paragraph.insert(text.paragraph);
  mp[word].sentence.insert(text.sentence);
  mp[word].line.insert(text.line);
  ++mp[word].appearences;
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

void TotalMap::print(std::wofstream &output)
{
  unsigned short space_sz;

  output << L"======================================================================================================================================\n"
            L"=>                                                    ### FULL RESULT ###                                                             \n"
            L"======================================================================================================================================\n"
            L"\n"
            L"_______________________________________________________________________________________________________________________________________\n"
            L"WORD 			    PARAGRAPH 		    SENTENCE 		      LINE 		   APPEARANCES 		     POSITIONS\n"
            L"---------------------------------------------------------------------------------------------------------------------------------------\n";

  for(auto it = this->mp.begin(); it != this->mp.end(); ++it) {
    output << it->f
           << (it->f.length() < 8 ? L"\t\t\t\t" : it->f.length() < 16 ? L"\t\t\t" : it->f.length() < 24 ? L"\t\t" : L"\t");

    space_sz = 0;
    for(const auto &paragraph : it->s.paragraph) {
      output << paragraph << ' ';
      space_sz += countDigits(paragraph) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

    space_sz = 0;
    for(const auto &sentence : it->s.sentence) {
      output << sentence << ' ';
      space_sz += countDigits(sentence) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

    space_sz = 0;
    for(const auto &line : it->s.line) {
      output << line << ' ';
      space_sz += countDigits(line) + 1;
    }
    output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t")

           << it->s.appearences << "\t\t\t";

    for(const auto &paragraph : it->s.positions) output << paragraph << ' ';
    output << L'\n';
  }

  output << L"---------------------------------------------------------------------------------------------------------------------------------------\n";
;
}
