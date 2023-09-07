#include <iostream>
#include "AVLTree.h"

//WORKED ON THIS LAB WITH ELLA K. FROM SECTION 002


using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  int choice = menu();

  string entry;

  while (choice != 3) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();

    }
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }

  tree.visualizeTree("outputfile");

  // AVLTree tree;
  // char letter = 'a';

  // for (unsigned int i=0; i<26; ++i) {
  //   string let(1, letter);
  //   tree.insert(let);
  //   cout << "inserted: " << let << endl;
  //   letter++;
  // }


  // cout << endl << "printing node info" << endl << endl;
  // tree.printBalanceFactors();
  // tree.visualizeTree("outputfile.dot");

  return 0;
}