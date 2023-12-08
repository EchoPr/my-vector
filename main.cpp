#include <iostream>
#include <string>

#include "ds_vector.h"

void print(Vector<int>& v){
    for (auto i = v.begin(); i != v.end(); i++){
        std::cout << *i << ' ';
    }
    std::cout << "\n";
}

int main(int, char**){
    int size;
    std::cin >> size;

    Vector<int> v(size, 5);

    print(v);
    v.pop();
    print(v);
    v.push_back(1);
    print(v);
    
}
