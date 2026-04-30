// card.cpp
// Author: Yijin Zhong
// Implementation of the classes defined in card.h

#include "card.h"

Card::Card(char suit, std::string value)
    : suit(suit), value(value) {}

int Card::suitRank() const {
    if (suit == 'c') return 0;
    if (suit == 'd') return 1;
    if (suit == 's') return 2;
    return 3;
}

int Card::valueRank() const {
    if (value == "a")  return 1;
    if (value == "j")  return 11;
    if (value == "q")  return 12;
    if (value == "k")  return 13;
    return std::stoi(value); 
}

bool Card::operator<(const Card& other) const {
    if (suitRank() != other.suitRank())
        return suitRank() < other.suitRank();
    return valueRank() < other.valueRank();
}

bool Card::operator>(const Card& other) const {
    return other < *this;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.suit << " " << c.value;
    return os;
}
