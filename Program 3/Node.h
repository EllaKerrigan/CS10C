#ifndef NODE_HEADER
#define NODE_HEADER

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    int count;
    int height;
    Node* left;
    Node* right;

    Node();
};



#endif