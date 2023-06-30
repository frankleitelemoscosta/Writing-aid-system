#include "Expression.hpp"


bool CheckExpression(wstring word, wstring prevWord,TotalMap &tm)
{
    if(tm.mp.count(word) != 0){

      if(prevWord.empty()){
        printf("a palavra está no texto");
        return true;
      }
     

    set <unsigned short> prevP = tm.mp[prevWord].paragraph;
    set <unsigned short> prevS = tm.mp[prevWord].sentence;
    set <unsigned short> prevPos = tm.mp[prevWord].positions;

      set <unsigned short> p = tm.mp[word].paragraph;
      set <unsigned short> s = tm.mp[word].sentence;
      set <unsigned short> pos = tm.mp[word].positions;

      auto it1 = p.begin();
      auto it2 = prevP.begin();

        for(; it1 != p.end() && it2 != prevP.end(); ++it1, ++it2){
            if(*it1 != *it2){
                pos.erase(*it1);
                prevPos.erase(*it2);
            }
        
        }

     it1 = s.begin();
       it2 = prevS.begin();

        for(; it1 != s.end() && it2 != prevS.end(); ++it1, ++it2){
             if(*it1 != *it2){
                pos.erase(*it1);
                prevPos.erase(*it2);
            } 
        }
    
     it1 = pos.begin();
       it2 = prevPos.begin();

        for(; it1 != s.end() && it2 != prevS.end(); ++it1, ++it2){
             if(*it1 == *it2 + 1){
               return true;
            } 
        }
    }

    return false;
}