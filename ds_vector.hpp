#include "ds_vector.h"


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
Vector<T>::Vector(int size, T value) : Vector(size){    
    for(int i = 0; i < size; i++){
        array_[i] = value;
    }

    itop_ = array_ + size - 1;
}

template<class T>
Vector<T>::~Vector(){
    delete [] array_;
    size_ = 0;
    itop_ = nullptr;
}

template<class T>
int Vector<T>::get_size(){
    return size_;
}

template<class T>
T& Vector<T>::operator[](unsigned index){
    return array_[index];
}

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

template<class T>
void Vector<T>::pop(){
    (itop_--)->~T();
    cur_num_elems--;
}

template<class T>
void Vector<T>::push_back(const T& el){
    if (cur_num_elems == size_)
        extend_array(coef_of_extension);

    array_[cur_num_elems] = el;
    cur_num_elems++;
}

template<class T>
auto Vector<T>::begin(){
    return array_;
}

template<class T>
auto Vector<T>::end(){
    return array_ + cur_num_elems;
}


