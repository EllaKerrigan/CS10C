#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>                                                        //allows functions to use this parameter for various data types. used for dif types of vectors

unsigned min_index (const vector<T> & vals, unsigned index){                //returns the index in which the smallest element is at. makes function depending on vector type

    unsigned smallestIndex = index;                                             //make it the first element in the vector first

    for (unsigned int i=index; i<vals.size(); ++i){                             //itirate through the vector
        if (vals.at(i) < vals.at(smallestIndex)) {                          //if current index value is smaller than smallest index value
            smallestIndex = i;                                              //make i index the smallest index yet
        }
    }

    return smallestIndex;                                                   //return smallest index
}

template<typename T>
void selection_sort(vector<T> & vals){

    int minIndex;

    for (unsigned int i=0; i<vals.size(); ++i){
        minIndex = min_index(vals, i);
        swap (vals.at(i), vals.at(minIndex));
    }

}

// template<typename T>
// void printVector(const vector<T> & vals) {
//     for (unsigned int i=0; i<vals.size(); ++i) {
//         cout << vals.at(i) << " ";
//     }

//     cout << endl;
// }

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, unsigned int index) {
    
    try {
        if (index < 0 || index >= vals.size()) {
            throw runtime_error("Invalid index.");
        }
    }

    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
    
    return vals.at(index);
}

int main() {


    //PART A
    /*
    vector<string> testString;
    vector<int> testInt;
    vector<char> testChar;
    vector<double> testDouble;
    int startAt = 0;

    testString.push_back("Eddie");
    testString.push_back("Ella");
    testString.push_back("Emilyn");
    testString.push_back("Alexandra");
    testString.push_back("Bryant");
    testString.push_back("Wesley");
    testInt.push_back(69);
    testInt.push_back(420);
    testInt.push_back(80085);
    testInt.push_back(17);
    testInt.push_back(101);
    testChar.push_back('z');
    testChar.push_back('b');
    testChar.push_back('a');
    testChar.push_back('l');
    testChar.push_back('q');
    testDouble.push_back(2.15);
    testDouble.push_back(1.01);
    testDouble.push_back(3.14);
    testDouble.push_back(10.0);
    testDouble.push_back(5.0);


    printVector(testString);
    printVector(testInt);
    printVector(testChar);
    printVector(testDouble);

    cout << endl;

    selection_sort(testString);
    selection_sort(testInt);
    selection_sort(testChar);
    selection_sort(testDouble);

    cout << endl << endl;

    printVector(testString);
    printVector(testInt);
    printVector(testChar);
    printVector(testDouble);
    */

    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
    }

    return 0;
}