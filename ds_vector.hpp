#include "ds_vector.h"


// Constructors and Destructors

template<class T>
Vector<T>::Vector(){
    size_ = 0;
}

template<class T>
Vector<T>::Vector(int size){
    size_ = size;
    cur_num_elems = size;
    array_ = new T[size];
}

template<class T>
Vector<T>::Vector(int size, const T& value) : Vector(size){    
    for(int i = 0; i < size; i++)
        array_[i] = value;
    

    itop_ = array_ + size - 1;
}

template<class T>
Vector<T>::Vector(const Vector<T>& v) : Vector(v.get_size()){
    for (int i = 0; i < size_; i++)
        array_[i] = v[i];

    itop_ = array_ + size_ - 1;
}

template<class T>
Vector<T>::~Vector(){
    delete [] array_;
    size_ = 0;
    itop_ = nullptr;
}


// getters and setters

template<class T>
int Vector<T>::get_size() const{
    return size_;
}


// operators

template<class T>
T& Vector<T>::operator[](unsigned index) const{
    return array_[index];
}


// public modifying methods

template<class T>
void Vector<T>::pop(){
    (itop_--)->~T();
    cur_num_elems--;
}

template<class T>
void Vector<T>::push_back(const T& el){
    if (is_full())
        extend_array(coef_of_extension);

    array_[cur_num_elems] = el;
    cur_num_elems++;
    itop_++;
}

template<class T>
template<class... Args>
void Vector<T>::emplace_back(const Args&... args){
    push_back(T(args...));
}

template<class T>
void Vector<T>::insert(int index, const T& el){
    if (is_full())
        extend_array(coef_of_extension);

    int t = cur_num_elems - 1;
    while(t >= index){
        array_[t + 1] = array_[t];
        t--;
    }
    array_[index] = el;
    
    cur_num_elems++;
    itop_++;
}


// public const methods

template<class T>
T* Vector<T>::begin() const{
    return array_;
}

template<class T>
T* Vector<T>::end() const{
    return array_ + cur_num_elems;
}


// private utility methods

template<class T>
void Vector<T>::extend_array(const int& extend_degree){
    T *temp_array = new T[size_ * extend_degree];

    for (int i = 0; i < size_; i++)
        temp_array[i] = array_[i];

    delete [] array_;
    array_ = temp_array;

    itop_ = end() - 1;
    size_ *= extend_degree; 
}

template <class T>
bool Vector<T>::is_full(){
    return cur_num_elems == size_;
}