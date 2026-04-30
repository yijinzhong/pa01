#include <iostream>
#include "card_list.h"
#include "card.h"

using namespace std;

int main(){
    // ===== BST 测试 =====

    // 测试1：空树 contains 返回 false
    CardList tree;
    cout << "Test 1 - Empty tree contains: " << 
        (tree.contains(Card('h', "5")) ? "FAIL" : "PASS") << endl;

    // 测试2：插入单节点
    tree.insert(Card('h', "5"));
    cout << "Test 2 - Single insert: " << 
        (tree.contains(Card('h', "5")) ? "PASS" : "FAIL") << endl;

    // 测试3：多节点顺序
    tree.insert(Card('c', "3"));
    tree.insert(Card('s', "10"));
    cout << "Test 3 - Multiple nodes order: ";
    for(auto it = tree.begin(); it != tree.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // 测试4：删除节点
    tree.remove(Card('h', "5"));
    cout << "Test 4 - Remove: " << 
        (tree.contains(Card('h', "5")) ? "FAIL" : "PASS") << endl;

    // 测试5：删除不存在的节点
    tree.remove(Card('d', "k"));
    cout << "Test 5 - Remove nonexistent: PASS" << endl;

    // ===== 迭代器测试 =====

    // 测试6：空树 begin==end
    CardList empty;
    cout << "Test 6 - Empty begin==end: " << 
        (empty.begin() == empty.end() ? "PASS" : "FAIL") << endl;

    // 测试7：空树 rbegin==rend
    cout << "Test 7 - Empty rbegin==rend: " << 
        (empty.rbegin() == empty.rend() ? "PASS" : "FAIL") << endl;

    // 测试8：单节点迭代器
    CardList single;
    single.insert(Card('c', "3"));
    auto it = single.begin();
    cout << "Test 8 - Single node: " << *it << endl;
    ++it;
    cout << "Test 9 - Single ++ reaches end: " << 
        (it == single.end() ? "PASS" : "FAIL") << endl;

    // 测试10：反向单节点
    auto it2 = single.rbegin();
    --it2;
    cout << "Test 10 - Single -- reaches rend: " << 
        (it2 == single.rend() ? "PASS" : "FAIL") << endl;

    // 测试11：正向多节点遍历
    CardList tree2;
    tree2.insert(Card('h', "5"));
    tree2.insert(Card('c', "3"));
    tree2.insert(Card('s', "10"));
    cout << "Test 11 - Forward traversal: ";
    for(auto it3 = tree2.begin(); it3 != tree2.end(); ++it3)
        cout << *it3 << " ";
    cout << endl;

    // 测试12：反向多节点遍历
    cout << "Test 12 - Reverse traversal: ";
    for(auto it3 = tree2.rbegin(); it3 != tree2.rend(); --it3)
        cout << *it3 << " ";
    cout << endl;

    // 测试13：!= 
    auto a = tree2.begin();
    auto b = tree2.end();
    cout << "Test 13 - != works: " << 
        (a != b ? "PASS" : "FAIL") << endl;

    // ===== playGame 测试 =====

    // 测试14：有共同牌
    cout << "Test 14 - playGame with common cards:" << endl;
    CardList alice, bob;
    alice.insert(Card('c', "3"));
    alice.insert(Card('h', "5"));
    bob.insert(Card('c', "3"));
    bob.insert(Card('d', "7"));
    playGame(alice, bob);

    // 测试15：没有共同牌
    cout << "Test 15 - playGame no common cards:" << endl;
    CardList alice2, bob2;
    alice2.insert(Card('c', "3"));
    bob2.insert(Card('h', "5"));
    playGame(alice2, bob2);

    // 测试16：空手
    cout << "Test 16 - playGame empty hand:" << endl;
    CardList alice3, bob3;
    bob3.insert(Card('h', "5"));
    playGame(alice3, bob3);

    return 0;
}
