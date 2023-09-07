#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <fstream>

#include "WordLadder.h"
using namespace std;

WordLadder::WordLadder(const string & fileName) {

    ifstream file;                          //input file stream
    file.open(fileName);                    //open file using parameter name

    string fileWord;                        //var used for putting words in dict

    if (!file.is_open()) {                  //check if opened correctly
        cout << "error opening file" << endl;
        return;
    }

    while (!file.eof()) {                   //while the end isn't reached read in
        file >> fileWord;
        if (fileWord.size() != 5) {         //every word should be exactly 5 char
            cout << "non 5 letter words found, exiting" << endl;
            return;
        }
        dict.push_back(fileWord);           //use push front?? IDK
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    
    ofstream OFILE;
    OFILE.open(outputFile);
    if (!OFILE.is_open()) {
        cout << "error opening file" << endl;
        return;
    }


    if (start == end) {
        OFILE << start << endl;
        return;
    }

    unsigned short locators =0;
    for (auto i = dict.begin(); i!=dict.end(); ++i){
        if (*i == start || *i == end) {
            locators ++;
        }
    }
    if (locators < 2) {
        cout << "START & END WORDS MUST BE REAL AND IN DICTIONARY" << endl;
        return;
    }
    

//-----------------------------------------------------------------------------------------------------//

    stack<string> pancake;
    pancake.push(start);

    queue<stack<string>> line;
    line.push(pancake);
    
    string topWord;
    string tempWord;

    stack<string> backwardsLadder;

    while (!line.empty()){
        topWord = line.front().top();
        for (auto i = dict.begin(); i!=dict.end(); ++i){

             if (isOffByOne(topWord, *i)) {

                stack<string> tempStack = line.front();
                tempWord = *i;
                tempStack.push(tempWord);

                if (*i == end) {
                    while (!tempStack.empty()) {
                        backwardsLadder.push(tempStack.top());
                        tempStack.pop();
                    }
                    while (!backwardsLadder.empty()) {
                        OFILE << backwardsLadder.top() << endl;
                        backwardsLadder.pop();
                    }
                    return;
                } else {
                    line.push(tempStack);
                    dict.erase(i);
                    i=dict.begin();
                }
            }
        }
        line.pop();
    }

    if (line.empty()) {
        OFILE << "No Word Ladder Found." << endl;
    }


}

//-------------------------------------------------------------------HELPER FUNCTIONS BELOW-----------------------------------------------------------//

bool isOffByOne(const string word1, const string word2) {
    
    unsigned int checker = 0;
    
    for (unsigned int i=0; i<word1.size(); ++i){
        if (word1.at(i) != word2.at(i)) {
            checker++;
        }
    }

    if (checker <= 1) {
        return true;
    } else {
        return false;
    }
}
