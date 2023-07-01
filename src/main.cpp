#include "Utils.hpp"
#include "StopWords.hpp"
#include "PartialMap.hpp"
#include "TotalMap.hpp"

#include <chrono>

using namespace std;


int main()
{
  auto start = chrono::high_resolution_clock::now();

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  wchar_t *txt = getText(loc), *ch = txt;
  wchar_t *ptr;
  wofstream output = createOutput(loc);
  wstring word;
  Text text;
  Count count;
  StopWords stop_words(loc);
  PartialMap mp_partial;
  TotalMap mp_total;
  vector<ParagraphInfo> paragraph;
  map<wstring, Expression> expressions;
  vector<Sentence> sentences;
  ParagraphInfo tmp_paragraph;
  Sentence sent;
  bool new_line = false;

  tmp_paragraph.number = 1;
  tmp_paragraph.beginAtLine = 1;

  readExpressions(expressions, loc);
  printStart(output);

  while (*ch) {
    switch(*ch) {
      case L'.': case L'!': case L'?':
        if(!word.empty()) {
          ++count.words;
          if(stop_words.isStopWord(word)) {
            ++count.stop_words;
          } else {
            mp_partial.addWord(word, text);
            mp_total.addWord(word, text);
          }
          word.clear();
        }

        if(mp_partial.mp.size()) {
          mp_partial.print(output, text.paragraph);
          count.print(output);
        }
        mp_partial.mp.clear();

        sentences.push_back(Sentence(text.paragraph, text.sentence,
                                     count.words, count.stop_words));

        count.clear();

        text.positions = 1;
        if(new_line) new_line = false;
        ++text.sentence;
        break;

      case L'\n':
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

        ++text.line;

        if(new_line) {
          tmp_paragraph.sentences = text.sentence - 1;
          paragraph.push_back(tmp_paragraph);
          tmp_paragraph.beginAtLine = text.line;
          tmp_paragraph.number = ++text.paragraph;
          text.sentence = 1;
        } else {
          new_line = true;
        }

        break;

      case L' ': case L',': case L':':
      case L';': case L'(': case L')':
      case L'"': case L'-': case L'/':
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
        if(word.empty()) {
          size_t i;

          for(auto &exp : expressions) {
            ptr = ch;
            
            for(i = 0; exp.f[i] != '\0'; i++) {
              if(exp.f[i] != tolower(ptr[i])) break;
            }

            if(i == exp.f.length() && !isalpha(ptr[i])) {
              ++exp.s.appearances;
              exp.s.lines.insert(text.line);
            }
          }
        }
        word += tolower(*ch);
        break;
    }
    ++ch;
  }

  tmp_paragraph.sentences = text.sentence - 1;
  paragraph.push_back(tmp_paragraph);

  mp_total.print(output);
  printSentences(sentences, output);
  printParagraph(paragraph, output);
  printExpressions(expressions, output);

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  wcout << duration.count() << " microsegundos" << endl;

  output.close();
  delete[] txt;

  return 0;
}
