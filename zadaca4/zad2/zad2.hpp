#pragma once
#include <iostream>

template<typename T>
class Stack {
  public:
    Stack(int capacity=100) : capacity(capacity), size_(0) {
    data=new T[capacity];
    }
    ~Stack(){
      delete [] data;
    }
    void push(const T& val){
      if (size_==capacity)
        throw std::overflow_error("Stack overflow");
  
      data[size_++]=val;
    }
    void pop() {
      if (empty())
        throw std::out_of_range("Stack is empty");

      size_--;

    }
    bool empty() const{
      return size_==0;
    }
    int size() const {
      return size_;
    }
    T& top(){
      if (empty())
        throw std::out_of_range("Stack is empty");

      return data[size_-1];
    }
  private:
  T* data;
  int capacity;
  int size_;
};
