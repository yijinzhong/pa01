// card.h
// Author: Yijin Zhong
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H


#include <string>
#include <iostream>

class Card {
public:
    char suit;   
    std::string value; 

    Card(char suit, std::string value);

    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);

private:
    int suitRank() const;
    int valueRank() const;
};
#endif
