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
    auto paragraph = it->s.paragraph.begin();
    auto sentence = it->s.sentence.begin();
    auto line = it->s.line.begin();
    auto position = it->s.positions.begin();
    bool loop, first = true;

    output << it->f
           << (it->f.length() < 8 ? L"\t\t\t\t" : it->f.length() < 16 ? L"\t\t\t" : it->f.length() < 24 ? L"\t\t" : L"\t");

    do {
      loop = false;

      if(!first) output << L"\t\t\t\t";

      space_sz = 0;
      while(paragraph != it->s.paragraph.end()) {
        if(space_sz > 16 && paragraph != it->s.paragraph.end()) {
          loop = true;
          break;
        }
        output << *paragraph << L' ';
        space_sz += countDigits(*paragraph) + 1;
        ++paragraph;
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      space_sz = 0;
      while(sentence != it->s.sentence.end()) {
        if(space_sz > 16 && sentence != it->s.sentence.end()) {
          loop = true;
          break;
        }
        output << *sentence << L' ';
        space_sz += countDigits(*sentence) + 1;
        ++sentence;
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      space_sz = 0;
      while(line != it->s.line.end()) {
        if(space_sz > 16 && line != it->s.line.end()) {
          loop = true;
          break;
        }
        output << *line << L' ';
        space_sz += countDigits(*line) + 1;
        ++line;
      }
      output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t");

      if(first) output << it->s.appearences;
      output << "\t\t\t";

      space_sz = 0;
      while(position != it->s.positions.end()) {
        if(space_sz > 16 && position != it->s.positions.end()) {
          loop = true;
          break;
        }
        output << *position << L' ';
        space_sz += countDigits(*position) + 1;
        ++position;
      }

      output << L'\n';

      if(first) first = false;
    } while(loop);
  }
  output << L"______________________________________________________________________________________________________________________________________________________________\n\n";
}
