#include <iostream>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <ostream>
#include <sstream>


#include "arithmeticExpression.h"

using namespace std;


    arithmeticExpression::arithmeticExpression(const string & expression) {
        root = nullptr;
        infixExpression = expression;
    }

    void arithmeticExpression::buildTree() {
        string exp = infix_to_postfix();
        char keyVal = 'a';
        stack<TreeNode> nodes;                          //can also try stack<TreeNode*> nodes
        for (unsigned int i=0; i<exp.size(); ++i) {
            if (exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '(' || exp.at(i) == ')') {

                // TreeNode* tempRight = nodes.top();
                // nodes.pop();
                // TreeNode* tempLeft = nodes.top();
                // nodes.pop();

                // TreeNode* tempRight = *new TreeNode*(nodes.top());
                // nodes.pop();
                // TreeNode* tempLeft = *new TreeNode*(nodes.top());
                // nodes.pop();

                TreeNode* leftChild = new TreeNode(nodes.top());
                nodes.pop();
                TreeNode* rightChild = new TreeNode(nodes.top());
                nodes.pop();
                
                TreeNode* subTree = new TreeNode(nodes.top());
                nodes.push(*subTree);

                subTree->data = exp.at(i);
                subTree->key = keyVal;  keyVal++;

                subTree->left = leftChild;
                subTree->right = rightChild;

                //nodes.push(*subTree);
                
            } else {
                TreeNode* tempVar;
                tempVar->data = exp.at(i);
                tempVar->key = keyVal;  keyVal++;
                nodes.push(*tempVar);
            }

            //TESTINGcout << "stack top is: " << nodes.top().data << "\tits key is: " << nodes.top().key << endl;

            
        }

        *root = nodes.top();
        /* just testing to see if the tree is made properly.
        //ROOT SHOULD BE: + THEN LEFT CHILD * AND RIGHT CHILD A THEN CHILDREN OF * ARE C AND B
        cout << "ROOT IS " << root->data << endl;
        cout << "LEFT CHILD OF ROOT IS " << root->left->data << endl;
        cout << "RIGHT CHILD OF ROOT IS " << root->right->data << endl;
        cout << "left CHILD OF left child IS " << root->left->left->data << endl;
        cout << "RIGHT CHILD OF right child IS " << root->left->right->data << endl; */
        
    }

    void arithmeticExpression::infix() {
        infix(root);
    }

    void arithmeticExpression::prefix() {
        prefix(root);
    }

    void arithmeticExpression::postfix() {
        postfix(root);
    }

    void arithmeticExpression::visualizeTree(const string &outputFilename) {
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

    int arithmeticExpression::priority(char op) {
        int priority = 0;
        if(op == '('){
            priority =  3;
        }
        else if(op == '*' || op == '/'){
            priority = 2;
        }
        else if(op == '+' || op == '-'){
            priority = 1;
        }
        return priority;
    }

    string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

    void arithmeticExpression::infix(TreeNode *n) {
         
        if (n) {
            if (n->data == '+' || n->data == '-' || n->data == '*' || n->data == '/' || n->data == '(' || n->data == ')') {
                cout << '(';
            }
            infix(n->left);
            cout << n->data;
            infix(n->right);
            if (n->data == '+' || n->data == '-' || n->data == '*' || n->data == '/' || n->data == '(' || n->data == ')') {
                cout << ')';
            }
        }
    }

    void arithmeticExpression::prefix(TreeNode * n) {
        if (n) {
            cout << n->data;
            prefix(n->left);
            prefix(n->right);
        }
    }

    void arithmeticExpression::postfix(TreeNode *n) {
        if (n) {
            postfix(n->left);
            postfix(n->right);
            cout << n->data;
        }
    }

    void arithmeticExpression::visualizeTree(ofstream & out, TreeNode *n) {

    }