#include <iostream>
using namespace std;
#include "Node.h"
#include "doublylinkedlist.h"

int main()
{
    cout << "=== Testing drawDoublyLinkedList() ===" << endl;
    // Test case for drawDoublyLinkedList
    DoublyLinkedList Dll_draw;
    Node n_d1(10);
    Node n_d2(20);
    Node n_d3(30);
    Node n_d4(40);
    Node n_d5(50);
    
    Dll_draw.addNewNodeToFront(&n_d1);
    Dll_draw.addNewNodeToBack(&n_d2);
    Dll_draw.addNewNodeToFront(&n_d3);
    Dll_draw.addNewNodeToBack(&n_d4);
    Dll_draw.addNewNodeToFront(&n_d5);
    Dll_draw.drawDoublyLinkedList();
    cout << endl;
    
    cout << "=== Testing isPalindrome() ===" << endl;
    // Test case 1 for isPalindrome - Not a palindrome
    DoublyLinkedList Dll_1;
    Node n11(10);
    Node n12(20);
    Node n13(30);
    Node n14(40);
    Node n15(50);
    
    Dll_1.addNewNodeToFront(&n11);
    Dll_1.addNewNodeToFront(&n12);
    Dll_1.addNewNodeToFront(&n13);
    Dll_1.addNewNodeToFront(&n14);
    Dll_1.addNewNodeToFront(&n15);
    cout << "Test 1 (50,40,30,20,10): " << Dll_1.isPalindrome() << endl;
    
    // Test case 2 for isPalindrome - Is a palindrome
    DoublyLinkedList Dll_2;
    Node n21(10);
    Node n22(20);
    Node n23(20);
    Node n24(10);
    
    Dll_2.addNewNodeToFront(&n21);
    Dll_2.addNewNodeToFront(&n22);
    Dll_2.addNewNodeToFront(&n23);
    Dll_2.addNewNodeToFront(&n24);
    cout << "Test 2 (10,20,20,10): " << Dll_2.isPalindrome() << endl;
    cout << endl;
    
    cout << "=== Testing split() ===" << endl;
    // Test case 1 for split - Can be evenly split
    DoublyLinkedList *Dll_split1 = new DoublyLinkedList;
    Node ns11(1);
    Node ns12(2);
    Node ns13(3);
    Node ns14(4);
    Node ns15(5);
    Node ns16(6);
    
    Dll_split1->addNewNodeToBack(&ns11);
    Dll_split1->addNewNodeToBack(&ns12);
    Dll_split1->addNewNodeToBack(&ns13);
    Dll_split1->addNewNodeToBack(&ns14);
    Dll_split1->addNewNodeToBack(&ns15);
    Dll_split1->addNewNodeToBack(&ns16);
    cout << "Splitting 6 nodes into 3 sublists:" << endl;
    Dll_split1->split(3);
    cout << endl;
    
    // Test case 2 for split - Cannot be evenly split
    DoublyLinkedList *Dll_split2 = new DoublyLinkedList;
    Node ns21(1);
    Node ns22(2);
    Node ns23(3);
    Node ns24(4);
    Node ns25(5);
    Node ns26(6);
    Node ns27(7);
    
    Dll_split2->addNewNodeToBack(&ns21);
    Dll_split2->addNewNodeToBack(&ns22);
    Dll_split2->addNewNodeToBack(&ns23);
    Dll_split2->addNewNodeToBack(&ns24);
    Dll_split2->addNewNodeToBack(&ns25);
    Dll_split2->addNewNodeToBack(&ns26);
    Dll_split2->addNewNodeToBack(&ns27);
    cout << "Attempting to split 7 nodes into 3 sublists:" << endl;
    Dll_split2->split(3);
    
    system("PAUSE");
    return 0;
}