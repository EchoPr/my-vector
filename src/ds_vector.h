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

    template<class... A>
    void emplace_back(const A& ...);

    void insert(int index, const T&);

    T* begin() const;
    T* end() const;


private:
    int size_ = 0;
    T *itop_;
    int cur_num_elems = 0;
    int coef_of_extension = 2;

    T *array_;

    void extend_array(const int&);
    bool is_full();
};
