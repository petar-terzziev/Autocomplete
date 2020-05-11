//
// Created by user on 15.8.2019 г..
//

#ifndef AUTOCOMPLETE_STATE_H
#define AUTOCOMPLETE_STATE_H

#include <iostream>
#include <unordered_map>
#include <vector>

class State {

public:
   void setTransition(wchar_t,int);
   void setFinal(bool);
   int getTransition(wchar_t) const;
   const std::unordered_map<wchar_t, int>& getTransitions() const;
   std::string getTransitionstr() const;
   void clearr();
   bool isFinal()const;



private:
        std::unordered_map<wchar_t , int> transitions;
        bool isfinal=false;
};


#endif //AUTOCOMPLETE_STATE_H
