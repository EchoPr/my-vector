#pragma once
#include <iostream>


template <class T>
class Vector{
public:
    Vector();
    Vector(int);
    Vector(int, const T&);
    Vector(const Vector<T>&);

    ~Vector();

    int get_size() const;

    T& operator[](unsigned) const;

    void pop();
    void push_back(const T&);
    void clear();
    void insert(int index, const T&);
    template<class... A>
    void emplace_back(const A& ...);

    T* begin() const;
    T* end() const;
    bool empty() const;


private:
    int size_ = 0;
    T *itop_ = nullptr;
    int cur_num_elems_ = 0;
    int coef_of_extension_ = 2;

    T *array_ = nullptr;

    void extend_array(const int&);
    bool is_full();
};
