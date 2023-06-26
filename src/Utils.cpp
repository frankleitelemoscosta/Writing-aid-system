#include "Utils.hpp"

using namespace std;

Count::Count() : words(0), stop_words(0) {}
void Count::clear() {words = 0; stop_words = 0;}
void Count::print(std::wofstream &output)
{
  output << L"=> Number of words with stop words: " << this->words
         << L"                                                       "
            L"=> Number of words without stop words: " << this->words - this->stop_words
         << L"\n---------------------------------------------------------------------------------------------------------------------------------------\n"
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

  if (!txt.is_open()) exit(1);

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
  wofstream output("./dataset/resultados.txt");

  if (!output.is_open()) exit(1);

  output.imbue(loc);

  //return the file output opened
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
