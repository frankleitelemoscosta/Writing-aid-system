#include"Readtext.hpp"
#include "Utils.hpp"
#include "StopWords.hpp"
#include "PartialMap.hpp"
#include "TotalMap.hpp"
#include<vector>
#include<iostream>

using namespace std;

void Read()
{
  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  wchar_t *txt = getText(loc), *ch = txt;
  wofstream output = createOutput(loc);
  wstring word;
  Text text;
  Count count;
  StopWords stop_words(loc);
  PartialMap mp_partial;
  TotalMap mp_total;
  vector<ParagraphInfo> paragraph;
  ParagraphInfo tmp_paragraph;
  bool new_line = false;
  tmp_paragraph.number = 1;
  tmp_paragraph.beginAtLine = 1;

  printStart(output);

  while (*ch) {
    switch(*ch) {

      // first case, this case is when the ch arrived in sentence end
      case L'.': case L'!': case L'?':
        if(!word.empty()) {
          //counter words for register the quantiti
          ++count.words;

          //check if the word that a stop word
          if(stop_words.isStopWord(word)) {
            ++count.stop_words;
          } else {
            mp_partial.addWord(word, text);
            mp_total.addWord(word, text);
          }
          word.clear();
        }

      //insert int the 
        mp_partial.print(output, text.paragraph);
        count.print(output);
        count.clear();
        mp_partial.mp.clear();

        text.positions = 1;
        if(new_line) new_line = false;
        ++text.sentence;
        //cout << text.sentence << endl; // rascunho
        break;

      //second case
      case L'\n':
        if(!word.empty()) {
          ++count.words;
          if(stop_words.isStopWord(word)) {
            ++count.stop_words;
          } else {
            //cout << text.positions << endl; // rascunho
            mp_partial.addWord(word, text);
            mp_total.addWord(word, text);
          }
          word.clear();
          ++text.positions;
        }

        ++text.line;

        if(new_line) {
          //cout << text.line << endl; // rascunho
          tmp_paragraph.sentences = text.sentence - 1;
          paragraph.push_back(tmp_paragraph);
          tmp_paragraph.beginAtLine = text.line;
          tmp_paragraph.number = ++text.paragraph;
          text.sentence = 1;
        } else {
          new_line = true;
        }

        break;

      //last case
      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
        if(!word.empty()) {
          ++count.words;
          if(stop_words.isStopWord(word)) {
            ++count.stop_words;
          } else {
            mp_partial.addWord(word, text);
            mp_total.addWord(word, text);
          }
          word.clear();
          ++text.positions;
        }

        if(new_line) new_line = false;
        break;

      default:
        word += tolower(*ch);
        break;
    }
    ++ch;
  }

  tmp_paragraph.sentences = text.sentence - 1;
  paragraph.push_back(tmp_paragraph);

  mp_total.print(output);
  printParagraph(paragraph, output);

  output.close();
  delete[] txt;

}