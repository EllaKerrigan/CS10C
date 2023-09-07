#include <iostream>
#include <fstream>
#include <ostream>

#include "AVLTree.h"


//Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string & stringToInsert){
    

    //start with the standard insertion algorithm for a BST
    //create a new node with the given string
    Node* newNode = new Node();
    newNode->data = stringToInsert;

    //check if the tree is empty, if so then make the new node the root, you're done
    if (root == nullptr) {
        root = newNode;
        newNode->parent = nullptr;
        return;
    }

    //if the tree isn't empty then we itirate through the tree, checking if the new node is < or >= and insert in the next available slot
    Node* temp = root;
    while (temp != nullptr) {
        if (newNode->data < temp->data) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                newNode->parent = temp;
                temp = nullptr;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                newNode->parent = temp;
                temp = nullptr;
            } else {
                temp = temp->right;
            }
        }
    }

    //once the node is in the right spot then we have to go back through every ancestor of that node and check to see if it needs rebalancing

    newNode = newNode->parent;
    while (newNode != nullptr) {
        rebalanceTree(newNode);
        newNode = newNode->parent;
    }

}

//Return the balance factor of a given node.
int AVLTree::balanceFactor(Node* n) {
    int left = -1;
    int right = -1;

    if (n->left != nullptr) { left = n->left->height;}
    if (n->right != nullptr) { right = n->right->height;}

    return left - right;
}

//Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors() {
    updateNodeHeights(root);
    printBalanceFactors(root);
    cout << endl;
}

//Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree::visualizeTree(const string & outputFilename) {
    ofstream outFS(outputFilename.c_str());
            if(!outFS.is_open()){
                cout<<"Error opening "<< outputFilename<<endl;
                return;
            }
            outFS<<"digraph G {"<<endl;
            visualizeTree(outFS,root);
            outFS<<"}";
            outFS.close();
            string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
            string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
            system(command.c_str());
}

//---------------------------------------HELPER FUNCTIONS BELOW----------------------------------------------//


Node* AVLTree::rebalanceTree(Node* node) {
    updateNodeHeights(root);
    if (balanceFactor(node) == -2) {
      if (balanceFactor(node->right) == 1) {
         // Double rotation case.
         rotateRight(node->right);
      }
      return rotateLeft(node);
   }
   else if (balanceFactor(node) == 2) {
      if (balanceFactor(node->left) == -1) {
         // Double rotation case.
         rotateLeft(node->left);
      }
      return rotateRight(node);
   }        
   return node;
}

Node* AVLTree::rotateLeft(Node* subRoot) {
      
    Node* rightLeftChild = subRoot->right->left;
    if (subRoot->parent != nullptr) {
        replaceChild(subRoot->parent, subRoot, subRoot->right);
    } else {
        root = subRoot->right;
        root->parent = nullptr;
    }
    subRoot->right->left = subRoot;
    subRoot->right = rightLeftChild;

    return subRoot;
}

Node* AVLTree::rotateRight(Node* subRoot) {
    Node* leftRightChild = subRoot->left->right;
    if (subRoot->parent != nullptr) {
        replaceChild(subRoot->parent, subRoot, subRoot->left);
    } else {
        root = subRoot->left;
        root->parent = nullptr;
    }
    subRoot->left->right = subRoot;
    subRoot->left = leftRightChild;

    return subRoot;
}


void AVLTree::replaceChild(Node* parent, Node* currentChild, Node* newChild) {
    if (parent->left == currentChild) {
        parent->left = newChild;
    } else if (parent->right == currentChild) {
        parent->right = newChild;
    }

    newChild->parent = parent;
    return;
}

void AVLTree::updateNodeHeights(Node* curr) {

    if (curr == nullptr) {
        return;
    }

    curr->height = updateHeight(curr);
    updateNodeHeights(curr->left);
    updateNodeHeights(curr->right);
}


int AVLTree::updateHeight(Node* n) {

    int leftHeight;
    int rightHeight;

    if (n== nullptr) {
        return -1;
    }

    leftHeight = updateHeight(n->left);
    rightHeight = updateHeight(n->right);

    return 1 + max(leftHeight, rightHeight);

}



void AVLTree::printBalanceFactors (Node* n) {
    
    if (n == nullptr) {
        return;
    }
   
    printBalanceFactors(n->left);
    cout << n->data << "(" << balanceFactor(n) << "), ";
    printBalanceFactors(n->right);
}



void AVLTree::visualizeTree(ofstream & out, Node* n) {
        if (n == nullptr) { return; }

        if (n->left != nullptr) { out << n->data << " -> " << n->left->data << endl; }
        if (n->right != nullptr) { out << n->data << " -> " << n->right->data << endl; }


        visualizeTree(out, n->left);
        visualizeTree(out, n->right);
}
