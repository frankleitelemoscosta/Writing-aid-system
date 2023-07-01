#include "Utils.hpp"
#include "StopWords.hpp"
#include "PartialMap.hpp"
#include "TotalMap.hpp"

using namespace std;

int main()
{
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
  vector<Expression> expressions = readExpressions(loc);
  vector<Sentence> sentences;
  ParagraphInfo tmp_paragraph;
  Sentence sent;
  bool new_line = false;

  tmp_paragraph.number = 1;
  tmp_paragraph.beginAtLine = 1;

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

        mp_partial.print(output, text.paragraph);
        count.print(output);
        mp_partial.mp.clear();

        sentences.push_back(Sentence(text.paragraph, text.sentence,
                                     count.words, count.stop_words));

        count.clear();

        text.positions = 1;
        if(new_line) new_line = false;
        ++text.sentence;
        //cout << text.sentence << endl; // rascunho
        break;

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
        if(word.empty()) {
          //wcout << *ch << ':' << endl; // rascunho
          size_t i;

          for(auto &exp : expressions) {
            ptr = ch;
            
            for(i = 0; exp.str[i] != '\0'; i++) {
              //wcout << exp.str[i] << " != " << ptr[i] << endl; // rascunho
              if(exp.str[i] != tolower(ptr[i])) break;
            }

            if(i == exp.str.length() && !isalpha(ptr[i])) {
              ++exp.appearances;
              exp.lines.insert(text.line);
              //wcout << L"A expressão " << exp.str
              //      << L" existe no texto!" << endl;
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

  output.close();
  delete[] txt;

  return 0;
}
