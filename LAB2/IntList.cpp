#include "IntList.h"
#include <iostream>

using namespace std;


IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList() {

    IntNode* deletor = dummyHead->next;
    IntNode* helper;

    while (deletor != dummyTail) {
        helper = deletor->next;
        delete deletor;
        deletor = helper;
    }
}

void IntList::push_front(int nodeNum) {

    IntNode* temp = new IntNode(nodeNum);
    IntNode* next = dummyHead->next;

    temp->next = next;
    temp->prev = dummyHead;
    next->prev = temp;
    dummyHead->next = temp;

}

void IntList::pop_front() {
    
    if (dummyHead->next == dummyTail) {
        return;

    } else {
        
        IntNode* temp = dummyHead->next;

        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;                        //might not be able to delete without NEW keyword
    }


}

void IntList::push_back(int nodeNum) {
   
    IntNode* temp = new IntNode(nodeNum);
    IntNode* prev = dummyTail->prev;

    temp->next = dummyTail;
    temp->prev = prev;
    prev->next = temp;
    dummyTail->prev = temp;


}

void IntList::pop_back() {

    if (dummyHead->next == dummyTail) {
        return;

    } else {
    
        IntNode* temp = dummyTail->prev;

        temp->prev->next = dummyTail;
        dummyTail->prev = temp->prev;
        delete temp;                        //might not be able to delete without NEW keyword
    }


}
bool IntList::empty() const {
    if (dummyHead->next == dummyTail) {
        return true;
    }

    return false;
}

ostream & operator << (ostream &out, const IntList &rhs){
    
    IntNode* traversalNode = rhs.dummyHead->next;

    while(traversalNode->next != nullptr){
        out << traversalNode->data;
        traversalNode = traversalNode->next;
        if (traversalNode != rhs.dummyTail) { out << " ";}
    }

    return out;
}

void IntList::printReverse() const {
    
    IntNode* traversalNode = dummyTail->prev;

    while(traversalNode->prev != nullptr){
        cout << traversalNode->data;
        traversalNode = traversalNode->prev;
        if (traversalNode != nullptr) { cout << " ";}
    }
}