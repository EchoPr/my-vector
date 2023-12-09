#pragma once
#include <iostream>


template <class T>
class Vector{
public:
    Vector();
    Vector(int);
    Vector(int, T);

    ~Vector();

    int get_size();

    T& operator[](unsigned);

    void pop();
    void push_back(const T&);

    template<class... A>
    void emplace_back(const A& ...);

    T* begin();
    T* end();


private:
    int size_ = 0;
    T *itop_;
    int cur_num_elems = 0;
    int coef_of_extension = 2;

    T *array_;

    void extend_array(const int&);
};
