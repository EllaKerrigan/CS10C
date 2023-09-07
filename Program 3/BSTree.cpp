#include <iostream>
#include <string>
#include "BSTree.h"

using namespace std;

BSTree::BSTree(){
    root = nullptr;
}

void BSTree::insert(const string& data) {

    Node* newNode = new Node();
    newNode->data = data;

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* curr = root;
    while (curr != nullptr) {
        if (newNode->data == curr->data) {
            curr->count ++;
            return;
        } else if (newNode->data < curr->data) {
            if (curr->left == nullptr) {
                curr->left = newNode;
                return;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == nullptr) {
                curr->right = newNode;
                return;
            } else {
                curr = curr->right;
            }
        }
    }
}

void BSTree::remove(const string& key) {
    Node* par = nullptr;
    Node* cur = root;

    while (cur != nullptr) {                                        // Search for node
        if (cur->data == key) {                                     // Node found 
            if (cur->count > 1) { cur->count --; return;}           // Duplicate case. decrement & return

            if (cur->left == nullptr && cur->right == nullptr) {    // Remove leaf
                if (par == nullptr) { root = nullptr; }             // Node is root
                else if (par->left == cur) { par->left = nullptr; }
                else { par->right = nullptr; }
            }
            else if (cur->right == nullptr) {                       // Remove node with only left child
                if (par == nullptr)  {root = cur->left;}            // Node is root
                else if (par->left == cur) {par->left = cur->left;}
                else {par->right = cur->left;}
            }
            else if (cur->left == nullptr) {                        // Remove node with only right child
                if (par == nullptr)  {root = cur->right;}           // Node is root
                else if (par->left == cur) {par->left = cur->right;}
                else {par->right = cur->right;}
            }
            else {                                                  // Remove node with two children
                // Find successor (leftmost child of right subtree)
                Node* suc = cur->right;
                while (suc->left != nullptr) {suc = suc->left;}
                string successorData = suc->data;
                remove(suc->data);                                  // Remove successor
                cur->data = successorData;
            }
            return;                                                 // Node found and removed
        }
        else if (cur->data < key) {                                 // Search right
            par = cur;
            cur = cur->right;
        }
        else {                                                      // Search left
            par = cur;
            cur = cur->left;
        }
    }

    return;
}

bool BSTree::search(const string& toFind) const {
    
    if (root == nullptr) { return false; }
    
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->data == toFind) {
            return true;
        } else if (toFind > curr->data) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return false;
}

string BSTree::largest() const {

    if (root == nullptr) { return ""; }
    string bigBoi = root->data;

    Node* curr = root;
    while (curr != nullptr) {
        bigBoi = curr->data;
        curr = curr->right;
    }

    return bigBoi;
}

string BSTree::smallest() const {
    
    if (root == nullptr) { return ""; }
    string lilBoi = root->data;

    Node* curr = root;
    while (curr != nullptr) {
        lilBoi = curr->data;
        curr = curr->left;
    }

    return lilBoi;
}

int BSTree::height(const string & content) const {
    
    if(!root) {return -1;}
    if (!search(content)) { return -1;}
    
    Node* curr = root;
    Node* heightOfThis;
    while (curr != nullptr) {
        if (curr->data == content) {
            heightOfThis = curr;
            curr = nullptr;
        } else if (content < curr->data){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return height(heightOfThis);
}


//--------------------------------------------------------PRIVATE HELPER FUNCTIONS BELOW------------------------------------------------------------//

void BSTree::preOrder(Node*n) {
    if (!n) {return;}

    cout << n->data << "(" << n->count << "), ";
    preOrder(n->left);
    preOrder(n->right);
}

void BSTree::inOrder(Node*n) {
    if (!n) {return;}

    preOrder(n->left);
    cout << n->data << "(" << n->count << "), ";
    preOrder(n->right);
}

void BSTree::postOrder(Node*n) {
    if (!n) {return;}

    preOrder(n->left);
    preOrder(n->right);
    cout << n->data << "(" << n->count << "), ";
}

int BSTree::height(Node* bruv)const {
    if (bruv == nullptr) {
        return -1;
    }

    int left = height(bruv->left);
    int right = height(bruv->right);

    return 1 + max(left,right);

}