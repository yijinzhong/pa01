// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  set<Card> alice;
set<Card> bob;

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }


  while (getline(cardFile1, line)){
    if (line.length() == 0) continue;
    char suit = line[0];
    string value = line.substr(2);
    alice.insert(Card(suit, value));
}

  cardFile1.close();


 while (getline(cardFile2, line)){
    if (line.length() == 0) continue;
    char suit = line[0];
    string value = line.substr(2);
    bob.insert(Card(suit, value));
}

  cardFile2.close();
  

bool running = true;
while(running){
    bool aliceFound = false;
    for(auto it = alice.begin(); it != alice.end(); ++it){
        if(bob.count(*it)){
            cout << "Alice picked matching card " << *it << endl;
            bob.erase(*it);
            alice.erase(it);
            aliceFound = true;
            break;
        }
    }
    if(!aliceFound) break;

    bool bobFound = false;
    for(auto it = prev(bob.end()); ; --it){
        if(alice.count(*it)){
            cout << "Bob picked matching card " << *it << endl;
            alice.erase(*it);
            bob.erase(it);
            bobFound = true;
            break;
        }
        if(it == bob.begin()) break;
    }
    if(!bobFound) break;
}

cout << "Alice's cards:" << endl;
for(auto it = alice.begin(); it != alice.end(); ++it)
    cout << *it << endl;
cout << "Bob's cards:" << endl;
for(auto it = bob.begin(); it != bob.end(); ++it)
    cout << *it << endl;
 

 
  
  return 0;
}
