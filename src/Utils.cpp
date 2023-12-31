#include "Utils.hpp"

using namespace std;

Count::Count() : words(0), stop_words(0) {}
void Count::clear() {words = 0; stop_words = 0;}
void Count::print(std::wofstream &output)
{
  output << L"=> Number of words with stop words: " << this->words
         << L"                                                       "
            L"=> Number of words without stop words: " << this->words - this->stop_words
         << L"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
         << endl;
}

void ParagraphInfo::print(std::wofstream &output)
{
  output << "_______________________________________________________________________________________________________________________________________\n"
            "                                                   LINE NUMBER THAT START EACH PARAGRAPH\n"
            "---------------------------------------------------------------------------------------------------------------------------------------\n"
         << "Paragraph: " << this->number
         << '\t'
         << "Begining in line: " << this->beginAtLine
         << '\t'
         << "Number of sentences: " << this->sentences
         << "_______________________________________________________________________________________________________________________________________\n"
         << endl;
}

Expression::Expression() : appearances(0) {}

Sentence::Sentence() : paragraph(0), sentence(0),
                       n_of_words(0), n_of_stop_words(0) {}

Sentence::Sentence(unsigned short paragraph, unsigned short sentence,
                   unsigned short n_of_words, unsigned short n_of_stop_words)
                 : paragraph(paragraph), sentence(sentence),
                   n_of_words(n_of_words), n_of_stop_words(n_of_stop_words) {}

void printStart(std::wofstream &output)
{
	output << L"======================================================================================================================================\n"
					  L"=>                                                    ### START PROCESS ###\n"
	          L"======================================================================================================================================\n"
            L"\n"
	          L"======================================================================================================================================\n"
				    L"=>                                                    ### PARTIAL RESULT ###\n"
	          L"======================================================================================================================================\n"
            L"\n";
}

wchar_t *getText(const std::locale &loc)
{
  wifstream txt("./dataset/input.data", ios::binary);

  if(!txt.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/input.data\"" << endl;
    exit(1);
  }

  // Set the locale to handle UTF-8 encoding
  txt.imbue(loc);

  // Determine the size of the file in bytes
  txt.seekg(0, ios::end);
  streampos fileSize = txt.tellg();
  txt.seekg(0, ios::beg);

  // Allocate memory for the wchar_t buffer
  wchar_t* buffer = new wchar_t[fileSize];

  // Read the file contents into the buffer
  txt.read(buffer, fileSize);

  // Close the file
  txt.close();

  return buffer;
}

std::wofstream createOutput(const std::locale &loc)
{
  wofstream output("./dataset/output.data");

  if(!output.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/output.data\"" << endl;
    exit(1);
  }

  output.imbue(loc);

  return output;
}

void printParagraph(const std::vector<ParagraphInfo> paragraph,
    std::wofstream &output)
{
  output << "_______________________________________________________________________________________________________________________________________\n"
            "                                                   LINE NUMBER THAT START EACH PARAGRAPH\n"
            "---------------------------------------------------------------------------------------------------------------------------------------\n";
  for(auto par : paragraph) {
    output << "Paragraph: " << par.number
           << '\t'
           << "Begining in line: " << par.beginAtLine
           << '\t'
           << "Number of sentences: " << par.sentences
           << endl;
  }
  output << "_______________________________________________________________________________________________________________________________________\n"
         << endl;
}

void readExpressions(std::map<std::wstring, Expression> &expressions, const std::locale &loc)
{
  wifstream input("./dataset/expressoes.txt");

  if(!input.is_open()) {
    wcout << L"Não foi possível abrir o arquivo \"./dataset/expressoes.txt\"" << endl;
    exit(1);
  }

  input.imbue(loc);

  wstring exp;
  wchar_t ch;

  while(input.get(ch)) {
    if(ch != L'\n') {
      exp += tolower(ch);
    } else if(!exp.empty()) {
      expressions[exp].appearances = 0;
      exp.clear();
    }
  }

  //for(auto &ex : expressions) wcout << ex.f << endl; // rascunho

  input.close();
}

static inline unsigned short countDigits(unsigned short num)
{
  return num < 10 ? 1 :
         num < 100 ? 2 :
         num < 1000 ? 3 :
         num < 10000 ? 4 :
         5;
}

void printExpressions(const std::map<std::wstring, Expression> expressions, std::wofstream &output)
{
  output << L"_______________________________________________________________________________________________________________________________________\n"
            L"EXPRESSION 								      LINE 		   APPEARANCES\n"
            L"---------------------------------------------------------------------------------------------------------------------------------------\n";

  for(auto exp = expressions.begin(); exp != expressions.end(); exp++) {
    if(exp->s.appearances == 0) continue;

    output << exp->f
           << (exp->f.length() < 8 ? L"\t\t\t\t\t\t\t\t\t\t" :
               exp->f.length() < 16 ? L"\t\t\t\t\t\t\t\t\t" :
               exp->f.length() < 24 ? L"\t\t\t\t\t\t\t\t" :
               exp->f.length() < 32 ? L"\t\t\t\t\t\t\t" :
               L"\t");

    auto line = exp->s.lines.begin();
    unsigned short space_sz;
    bool first = true, loop;

    do {
      space_sz = 0;
      loop = false;

      //output << L"começando" << endl;
      if(!first) output << L"\t\t\t\t\t\t\t\t\t\t";

      while(line != exp->s.lines.end()) {
        output << *line << L' ';
        space_sz += countDigits(*line) + 1;
        ++line;
        if(space_sz > 8 && line != exp->s.lines.end()) {
          loop = true;
          break;
        }
      }

      if(first) {
        output << (space_sz < 8 ? L"\t\t\t" : space_sz < 16 ? L"\t\t" : L"\t")
               << exp->s.appearances;
        first = false;
      }

      output << L'\n';
    } while(loop);

  }

  output << L"---------------------------------------------------------------------------------------------------------------------------------------\n"
            L"======================================================================================================================================\n"
            L"=>                                                    ### END PROCESS ###\n"
            L"======================================================================================================================================\n";
}

void printSentences(std::vector<Sentence> sentences, std::wofstream &output)
{
  output << L"_______________________________________________________________________________________________________________________________________\n"
            L"                                       NUMBER OF WORDS IN EACH SENTENCE WITH AND WITHOUT STOP WORDS\n"
            L"_______________________________________________________________________________________________________________________________________\n";

  for(const auto &sent : sentences) {
    output << L"Paragraph: " << sent.paragraph
           << L"\tSentence: " << sent.sentence
           << L"\tNumber of words with stop words: " << sent.n_of_words
           << L"\tNumber of words without stop words: " << sent.n_of_words - sent.n_of_stop_words
           << endl;
  }

  output << L"_______________________________________________________________________________________________________________________________________\n\n";
}
