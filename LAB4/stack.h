#include <iostream>
using namespace std; 
#include <stdexcept>
#include <string>

#ifndef STACK_H
#define STACK_H

int const MAX_SIZE = 20;


template<typename T>
class stack{
private:
T data[MAX_SIZE];
int size; 

public:
stack(){
  size = 0;
}

void push(T val){
  if(size == MAX_SIZE){
    throw overflow_error("Called push on full stack.");
  }
  else{
    data[size]=val;
    ++size;
  }
}

void pop(){
  if(size == 0){
    throw out_of_range("Called pop on empty stack.");
  }
  else{
    --size;
    //data[size] = nullptr;
  }
}

void pop_two(){
  if(size <= 1){
    throw out_of_range("Called pop_two on a stack of size 1.");
  }
  else{
    size-=2;
  }
}

T top(){
  if(empty()){
    throw underflow_error("Called top on empty stack.");
  }
  else{
    return data[size-1];
  }
  
}

bool empty(){
  if(size == 0){
    return true;
  }
  else{
    return false; 
  }
}











};
#endif