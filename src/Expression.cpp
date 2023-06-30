#include "Expression.hpp"


short int CheckExpression(wstring word, wstring prevWord,TotalMap &tm, vector<Sentence> &locations)
{
    short int count = 0;

    if(tm.mp.count(word) != 0){

      if(prevWord.empty()){
        set<unsigned short> P = tm.mp[word].paragraph;
        set<unsigned short> S = tm.mp[word].sentence;

        auto it1 = P.begin();
        auto it2 = S.begin();

        for (; it1 != P.end() && it2 != S.end(); ++it1, ++it2)
        {
          locations.push_back(Sentence(*it1, *it2));
        }

        return tm.mp.count(word);
      }

      set<unsigned short> prevP = tm.mp[prevWord].paragraph;
      set<unsigned short> prevS = tm.mp[prevWord].sentence;
      set<unsigned short> prevPos = tm.mp[prevWord].positions;

      set <unsigned short> par = tm.mp[word].paragraph;
      set <unsigned short> sen = tm.mp[word].sentence;
      set <unsigned short> pos = tm.mp[word].positions;

      vector<Word> newWord;
      vector<Word> oldWord;
     
      auto it1 = prevP.begin();
      auto it2 = prevS.begin();
      auto it3 = prevPos.begin();

      for (; it1 != prevP.end() && it2 != prevS.end() && it2 != prevPos.end(); ++it1, ++it2,++it3)
      {
        oldWord.push_back(Word(*it1,*it2,*it3) );
      }

      it1 = par.begin();
      it2 = sen.begin();
      it3 = pos.begin();

      for (; it1 != par.end() && it2 != sen.end() && it2 != pos.end(); ++it1, ++it2,++it3)
      {
        newWord.push_back(Word(*it1,*it2,*it3));
      }

      auto i = newWord.begin();
      auto j = oldWord.begin();

      for (; i != newWord.end() && j != oldWord.end(); ++i, ++j)
      {
        if(i->par == j->par){
          if(i->sen == j->sen){
            if(i->pos == j->pos+1){

              Sentence sen(i->par,i->sen);

              if ( find(locations.begin(), locations.end(), sen) != locations.end() ){
                count++;
              }
                
            }
          }
        }
      }
    }

    return count;
}