#include <iostream>

#include "IntList.h"

using namespace std;


int main (){

    IntList test1;

    cout << "FINISHED CREATING CLASS OBJECT" << endl;
    test1.push_front(5);
    test1.push_front(4);
    test1.push_front(3);
    test1.push_front(2);
    test1.push_front(1);
    cout << "FINISHED PUSHING FRONT 5 VALUES" << endl;
    test1.push_back(6);
    test1.push_back(7);
    test1.push_back(8);
    test1.push_back(9);
    test1.push_back(10);
    cout << "FINISHED PUSHING BACK 5 VALUES" << endl;
    cout << "OUTPUTING THE LIST" << endl;
    cout<<test1;
    cout << endl << "OUTPUTING THE LIST IN REVERSE" << endl;
    test1.printReverse();
    test1.pop_back();
    test1.pop_back();
    test1.pop_front();
    test1.pop_back();
    cout << "OUTPUTING THE LIST" << endl;
    cout<<test1;
    cout << endl << "OUTPUTING THE LIST IN REVERSE" << endl;
    test1.printReverse();




    cout << endl << endl << "NEW TEST OF EMPTY SIZE LIST" << endl;
    IntList test2; 
    cout << test2;  cout << endl << "NOW PRINT IT BACKWARDS" << endl;
    test2.printReverse();
    test2.pop_back();
    test2.pop_front();
    cout << "OUTPUTING THE LIST" << endl;
    cout<<test2;
    cout << endl << "OUTPUTING THE LIST IN REVERSE" << endl;
    test2.printReverse();   
    cout << "FINISHED";




    cout << endl << endl << "NEW TEST OF 1 SIZE LIST" << endl;
    IntList test3;
    test3.push_back(69);
    cout << test3 << "!";  cout << endl << "NOW PRINT IT BACKWARDS" << endl;
    test3.printReverse();
    test3.pop_back();
    cout << endl << "OUTPUTING THE LIST" << endl;
    cout<<test3 << "!!" << endl;
    cout << endl << "OUTPUTING THE LIST IN REVERSE" << endl;
    test3.printReverse();    


    return 0;
}