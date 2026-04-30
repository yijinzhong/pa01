// card_list.h
// Author: Yijin Zhong
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H


#include "card.h"

class CardList {
private:
    struct Node {
        Card card;
        Node* left;
        Node* right;
        Node* parent;
        Node(Card c) : card(c), left(nullptr), 
                       right(nullptr), parent(nullptr) {}
    };

    Node* root;

  
    void deleteTree(Node* node);
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;

public:
    CardList();
    ~CardList();

    void insert(Card c);
    void remove(Card c);
    bool contains(Card c) const;
    Node* insertHelper(Node* node, Node* parent, Card c);
    bool containsHelper(Node* node, Card c) const;
    Node* removeHelper(Node* node, Card c);
    



    class iterator {
    private:
        Node* current;
        Node* root;
    public:
        iterator(Node* n, Node* r) : current(n), root(r) {}
        Card& operator*();
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };

    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();
};
void playGame(CardList& alice, CardList& bob);
#endif
