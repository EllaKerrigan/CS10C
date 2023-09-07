#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {
    string data;
    int height;
    Node* left;
    Node* right;
    Node* parent;
    public:
        Node();

};



#endif