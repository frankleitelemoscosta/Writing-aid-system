#include "Expression.hpp"
#include <locale>
#include <codecvt>


void CheckExpression(string s,TotalMap &tm)
{
  int Counter = 0;
  int Counter_aux = 0;
  string string_aux;
  wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
  int size = (s.size()-1);

  cout<< size<<endl;
  

  do{ 
    if(s[Counter] != ' ')string_aux += s[Counter];

    if(s[Counter] == ' ' || s[Counter] == '\n')
    {
      wstring wstr = converter.from_bytes(string_aux); 
      wcout << wstr <<endl;

      for (const auto& pair : tm.mp) {
          const std::wstring& key = pair.first;
      
        if(wstr == key)
        {
          wcout << "o map possui a palavra: [" << wstr << "]"<<endl;
          Counter_aux++;
        }
      
        if(Counter_aux >= 2)
        {
          printf("o pai é muito brabo\n");
          Counter_aux = 0;
        }
        if( key == L"de")
        {
          cout<<"sim"<<endl;
        }
      }
      
      wstr.clear();
      string_aux.clear();
    }
  Counter++;
  
  }while(Counter <= size);

  printf("Saindo...\n");

  return;
}