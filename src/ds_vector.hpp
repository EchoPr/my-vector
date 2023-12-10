#include "ds_vector.h"

#include <stdexcept>


const int& max(const int& a, const int& b){
    return a > b ? a : b;
}

const int& min(const int& a, const int& b){
    return a < b ? a : b;
}

// Constructors and Destructors

template<class T>
Vector<T>::Vector(){
    size_ = 0;
    cur_num_elems_ = 0;
}

template<class T>
Vector<T>::Vector(int size){
    if (size <= 0)
        throw std::runtime_error("Size of the vector must be positive");

    size_ = size;
    cur_num_elems_ = size;
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
    return array_[min(cur_num_elems_ - 1, max(index, 0))];
}


// public modifying methods

template<class T>
void Vector<T>::pop(){
    if (cur_num_elems_ == 0)
        throw std::runtime_error("Vector is empty");

    (itop_--)->~T();
    cur_num_elems_--;
}

template<class T>
void Vector<T>::push_back(const T& el){
    if (is_full()){
        extend_array(coef_of_extension_);
    }
    
    if (itop_ != nullptr){
        array_[cur_num_elems_] = el;
        cur_num_elems_++;
        itop_++;
    }
    else{
        size_ = 1;
        cur_num_elems_ = 1;
        if (array_ == nullptr) array_ = new T[1];    
        array_[0] = el;
        itop_ = array_;
    }
}

template<class T>
template<class... Args>
void Vector<T>::emplace_back(const Args&... args){
    push_back(T(args...));
}

template<class T>
void Vector<T>::insert(int index, const T& el){
    if (!(index >= 0 && index <= cur_num_elems_) || empty())
        throw std::runtime_error("Insertion possible only in borders of vector size");

    if (is_full())
        extend_array(coef_of_extension_);

    int t = cur_num_elems_ - 1;
    while(t >= index){
        array_[t + 1] = array_[t];
        t--;
    }
    array_[index] = el;
    
    cur_num_elems_++;
    itop_ != nullptr ? itop_++: itop_ = array_;
}

template<class T>
void Vector<T>::clear(){
    cur_num_elems_ = 0;
    itop_ = nullptr;
}


// public const methods

template<class T>
T* Vector<T>::begin() const{
    if (array_ == nullptr)
        throw std::runtime_error("Vector is not initialized");
    
    return array_;
}

template<class T>
T* Vector<T>::end() const{
    if (array_ == nullptr)
        throw std::runtime_error("Vector is not initialized");

    return array_ + cur_num_elems_;
}

template<class T>
bool Vector<T>::empty() const {
    return cur_num_elems_ == 0;
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
    return (cur_num_elems_ == size_) && (size_ != 0);
}