#include "TotalMap.hpp"

void TotalMap::addWord(const std::wstring &word, const Text &text)
{
  mp[word].paragraph.insert(text.paragraph);
  mp[word].sentence.insert(text.sentence);
  mp[word].line.insert(text.line);
  ++mp[word].appearences;
  mp[word].positions.insert(text.positions);
}

void TotalMap::print(std::wofstream &output)
{
  output << L"_______________________________________________________________________________________________________________________________________\n"
            L"WORD 			    PARAGRAPH 		    SENTENCE 		      LINE 		   APPEARANCES 		     POSITIONS\n"
            L"---------------------------------------------------------------------------------------------------------------------------------------\n";

  for(auto it = this->mp.begin(); it != this->mp.end(); ++it) {
    output << it->f << L"\t\t\t";
    for(auto paragraph : it->s.paragraph) output << paragraph << ' ';
    output << L"\t\t\t";
    for(auto paragraph : it->s.sentence) output << paragraph << ' ';
    output << L"\t\t\t";
    for(auto paragraph : it->s.line) output << paragraph << ' ';
    output << L"\t\t\t";
    output << it->s.appearences << ' ';
    output << L"\t\t\t";
    for(auto paragraph : it->s.positions) output << paragraph << ' ';
    output << L'\n';
  }
  output << L"_______________________________________________________________________________________________________________________________________\n";
}
