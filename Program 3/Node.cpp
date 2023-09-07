#include <iostream>
#include <string>

#include "Node.h"

using namespace std;


Node::Node() {
    data = "";
    count = 1;
    height = 0;
    left = nullptr;
    right = nullptr;
}