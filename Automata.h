//
// Created by user on 14.8.2019 г..
//

#ifndef AUTOCOMPLETE_AUTOMATA_H
#define AUTOCOMPLETE_AUTOMATA_H

#include "State.h"
class Automata {
    int first;
    std::vector<State> states;
    std::unordered_map<std::string, int> state_positions;

public:
    Automata(const std::vector<std::string> &words);
    void addWord(const std::string&);
    bool contains(const std::string&) const;
    void suggest(std::string&,int,int&) const;
    void sug(std::string&) const;
    int getfirst() const;
    int findmin(const State&);


};


#endif //AUTOCOMPLETE_AUTOMATA_H
