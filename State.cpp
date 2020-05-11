//
// Created by user on 15.8.2019 г..
//

#include "State.h"

void State::setTransition(wchar_t key, int value) {

    transitions[key]=value;

}

void State::setFinal(bool f) {
    isfinal = f;

}

int State::getTransition(wchar_t key) const {
   return transitions.find(key)==transitions.end() ? -1 : transitions.find(key)->second;
}

void State::clearr() {
    transitions.clear();
    isfinal=false;

}

std::string State::getTransitionstr() const{
    std::string str;
    str+= isfinal ? 't':'f';
    for(auto c : transitions){
        str+=c.first;
        str+=std::to_string(c.second);
    }
    return str;
}

bool State::isFinal() const {
    return isfinal;
}

const std::unordered_map<wchar_t, int> &State::getTransitions() const {
    return transitions;
}

