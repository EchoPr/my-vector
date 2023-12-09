#include <iostream>
#include <string>

#include "ds_vector.hpp"


struct Point{
    int x;
    int y;

    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    Point(){
        x = 0;
        y = 0;
    }

    Point& operator= (const Point& op){
        x = op.x;
        y = op.y;

        return *this;
    }

    ~Point(){}
};

std::ostream& operator<< (std::ostream& os, const Point& p){
    return os << p.x << " " << p.y;
}

void print(Vector<Point>& v){
    for (auto i = v.begin(); i != v.end(); i++){
        std::cout << *i << " | ";
    }
    std::cout << "\n";
}

int main(int, char**){
    int size;
    std::cin >> size;

    Vector<Point> v(size, Point(1, 2));
    Vector<Point> u(v);

    // print(u);

    print(v);
    v.pop();
    print(v);
    v.push_back(Point(2, 3));
    print(v);
    v.emplace_back(3, 4);
    print(v);
    v.insert(1, Point(5, 6));
    print(v);

    std::cout << "===========\n";

    v.pop();
    print(v);
    v.push_back(Point(2, 3));
    print(v);
    v.emplace_back(3, 4);
    print(v);
    v.insert(1, Point(5, 6));
    print(v);
}
