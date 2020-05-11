//
// Created by user on 14.8.2019 г..
//

#include "Automata.h"

Automata::Automata(const std::vector<std::string> &words) {
    std::vector<State> temp(200);
    std::string prev;
    std::string cur;

    for(const std::string& word: words){
        cur=word;
        int common_prefix=0;
        while(cur[common_prefix] && prev[common_prefix] && cur[common_prefix]==prev[common_prefix])
            common_prefix++;
        for(int i=prev.length(); i>=common_prefix+1;i--){
            temp[i-1].setTransition(prev[i-1],findmin(temp[i]));

        }
        for(unsigned int i=common_prefix+1; i<=cur.length();i++){
            temp[i].clearr();
            temp[i-1].setTransition(cur[i-1],-1);
        }
        temp[cur.length()].setFinal(true);
        prev=cur;

    }

    for(int i=cur.length(); i>0; i--){
        temp[i-1].setTransition(cur[i-1],findmin(temp[i]));
    }
    first=findmin(temp[0]);
    temp.clear();
    state_positions.clear();
}
int Automata::findmin(const State& state){
    std::string key= state.getTransitionstr();
    if(state_positions.find(key)==state_positions.end()){
        states.push_back(state);
        state_positions.emplace(std::make_pair(key,states.size()-1));
    }
    return state_positions[key];
}

void Automata::addWord(const std::string& str){
    if(!str.empty()){
        int cur = first;
        int prev;
        for(char c: str){
            prev = cur;
            cur = states[cur].getTransition(c);
            if(cur==-1){
                states.push_back(State());
                cur = states.size()-1;
                states[prev].setTransition(c,cur);
            }

        }
        states[cur].setFinal(true);

    }
}

void Automata::sug( std::string& str) const{
    int state=first;
    for(char c: str){
        state=states[state].getTransition(c);
        if(state==-1)
            return;
    }
    int h=3;
    suggest(str,state,h);
}

void Automata::suggest(std::string& str,int state,int& k) const{
    if(k<=0)
        return;
    if(states[state].isFinal()){
        std::cout<<str<<std::endl;
        --k;
    }
    auto transitions= states[state].getTransitions();
    for(auto it: transitions){
        str+=it.first;
        suggest(str,it.second,k);
        str.pop_back();
    }
}

bool Automata::contains(const std::string & str) const{
   int state= first;
    for(const char &c:str){
        if(state ==-1){
            return false;
        }
        else {
            state=states[state].getTransition(c);
        }
    }
    return states[state].isFinal();

}
int Automata::getfirst() const {
    return first;
}