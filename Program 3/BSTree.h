#ifndef BSTREE_HEADER
#define BSTREE_HEADER

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class BSTree {
    private:
        Node* root;
    public:

        BSTree();
        //~BSTree();

        void insert(const string&);                         //simple insert. if node exists increment its counter by 1
        void remove(const string&);
        
        bool search(const string&) const;                   //find string in tree. true if found. false if not
        string largest() const;                             //largest value. empty if empty
        string smallest() const;                            //smallest value. empty if empty
        int height(const string &) const;                   //return height of particular node. -1 if it doesn't exist


        void print()        { cout << "Preorder = ";preOrder(); cout << "\nInOrder = "; inOrder(); cout << "\nPostorder = "; postOrder(); }
        void preOrder()     { preOrder(root); }
        void inOrder()      { inOrder(root);  }
        void postOrder()    { postOrder(root);}

    private:    //private helper functions below

        int height(Node*)const;

        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
};



#endif