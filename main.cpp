#include "Automata.h"
#include <fstream>
#include <algorithm>

int main() {
   std::fstream file("words.txt");
   if(!file){
       std::cout<<"sdtfj"<<std::endl;
   }
   std::string temp;
   std::vector<std::string> words;
    file>>temp;
   while(file){
       words.push_back(temp);
       file>>temp;
   }
   std::sort(words.begin(),words.end());
   Automata k(words);
   file.close();
   int h=3;
   getline(std::cin,temp);
   while(temp!="exit"){

       k.sug(temp);
       getline(std::cin, temp);
   }
    return 0;
}