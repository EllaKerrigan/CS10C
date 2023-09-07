#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
#include "Node.h"

using namespace std;


class AVLTree {

    public:
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors();
        void visualizeTree(const string &);
    
    private:
        Node* root = nullptr;    
        
        //UPDATE THE RETURN TYPE OF THESE FUNCTIONS AS THEY ARE NOT ACCURATE AS WELL AS PARAMETERS
        //Node* findUnbalancedNode(Node* n);
        //void rotate(Node*);

        Node* rotateLeft(Node*);
        Node* rotateRight(Node*);

        void printBalanceFactors(Node*);
        void visualizeTree(ofstream &, Node*);

        void updateNodeHeights(Node*);
        int updateHeight(Node*);

        void replaceChild(Node*, Node*, Node*);
        Node* rebalanceTree(Node*);
};






#endif