// card_list.cpp
// Author: Yijin Zhong
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>
using namespace std;



CardList::CardList() : root(nullptr) {}

CardList::~CardList() {
    deleteTree(root);
}

void CardList::deleteTree(Node* node) {
    if(node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

CardList::Node* CardList::findMin(Node* node) const {
    if(node->left == nullptr) return node;
    return findMin(node->left);
}

CardList::Node* CardList::findMax(Node* node) const {
    if(node->right == nullptr) return node;
    return findMax(node->right);
}

void CardList::insert(Card c) {
    root = insertHelper(root, nullptr, c);
}

CardList::Node* CardList::insertHelper(Node* node, Node* parent, Card c) {
    if(node == nullptr){
        Node* newNode = new Node(c);
        newNode->parent = parent;
        return newNode;
    }
    if(c < node->card)
        node->left = insertHelper(node->left, node, c);
    else
        node->right = insertHelper(node->right, node, c);
    return node;
}

bool CardList::contains(Card c) const {
    return containsHelper(root, c);
}

bool CardList::containsHelper(Node* node, Card c) const {
    if(node == nullptr) return false;
    if(c == node->card) return true;
    if(c < node->card) return containsHelper(node->left, c);
    return containsHelper(node->right, c);
}

void CardList::remove(Card c) {
    root = removeHelper(root, c);
}

CardList::Node* CardList::removeHelper(Node* node, Card c) {
    if(node == nullptr) return nullptr;
    
    if(c < node->card)
        node->left = removeHelper(node->left, c);
    else if(c > node->card)
        node->right = removeHelper(node->right, c);
    else {
       
        if(node->left == nullptr && node->right == nullptr){
            
            delete node;
            return nullptr;
        } else if(node->left == nullptr){
           
            Node* temp = node->right;
            temp->parent = node->parent;
            delete node;
            return temp;
        } else if(node->right == nullptr){
           
            Node* temp = node->left;
            temp->parent = node->parent;
            delete node;
            return temp;
        } else {
            
            Node* minNode = findMin(node->right);
            node->card = minNode->card;
            node->right = removeHelper(node->right, minNode->card);
        }
    }
    return node;
}


Card& CardList::iterator::operator*() {
    return current->card;
}


CardList::iterator& CardList::iterator::operator++() {
    if(current->right != nullptr){
        current = current->right;
        while(current->left != nullptr)
            current = current->left;
    } else {
        
        Node* parent = current->parent;
        while(parent != nullptr && current == parent->right){
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return *this;
}

CardList::iterator& CardList::iterator::operator--() {
    if(current == nullptr){
     
        current = root;
        while(current->right != nullptr)
            current = current->right;
    } else if(current->left != nullptr){
       
        current = current->left;
        while(current->right != nullptr)
            current = current->right;
    } else {
     
        Node* parent = current->parent;
        while(parent != nullptr && current == parent->left){
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return *this;
}

bool CardList::iterator::operator==(const iterator& other) const {
    return current == other.current;
}

bool CardList::iterator::operator!=(const iterator& other) const {
    return current != other.current;
}

CardList::iterator CardList::begin() {
    if(root == nullptr) return end();
    return iterator(findMin(root), root);
}

CardList::iterator CardList::end() {
    return iterator(nullptr, root);
}

CardList::iterator CardList::rbegin() {
    if(root == nullptr) return rend();
    return iterator(findMax(root), root);
}

CardList::iterator CardList::rend() {
    return iterator(nullptr, root);
}

void playGame(CardList& alice, CardList& bob){
    bool running = true;
    while(running){
        bool aliceFound = false;
        for(auto it = alice.begin(); it != alice.end(); ++it){
            if(bob.contains(*it)){
                Card matched = *it;
                cout << "Alice picked matching card " << *it << endl;
                bob.remove(matched);
                alice.remove(matched);
                aliceFound = true;
                break;
            }
        }
        if(!aliceFound) break;

        bool bobFound = false;
        for(auto it = bob.rbegin(); it != bob.rend(); --it){
            if(alice.contains(*it)){
                Card matched = *it;
                cout << "Bob picked matching card " << *it << endl;
                alice.remove(matched);
                bob.remove(matched);
                bobFound = true;
                break;
            }
        }
        if(!bobFound) break;
    }

    cout << "Alice's cards:" << endl;
    for(auto it = alice.begin(); it != alice.end(); ++it)
        cout << *it << endl;
    cout << "Bob's cards:" << endl;
    for(auto it = bob.begin(); it != bob.end(); ++it)
        cout << *it << endl;
}


