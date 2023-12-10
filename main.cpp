#include <iostream>
#include <string>

#include "./src/ds_vector.hpp"


struct Point{
    float x;
    float y;

    Point(float x_, float y_){
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
    // int size;
    // std::cin >> size;

    Point p(1, 2);
    std::cout << p << '\n';
    p = Point(3, 5);
    std::cout << p << '\n';

    Vector<Point> v;

    // v.insert(0, Point(0, 4));
    // print(v);

    std::cout << v.get_size() << " " << v.empty() << '\n';
    v.push_back(Point(1, 1));
    std::cout << v.get_size() << " " << v.empty() << '\n';
    v.push_back(Point(1, 1));
    std::cout << v.get_size() << " " << v.empty() << '\n';
    print(v);
    // print(u);

    v.push_back(Point(1, 3));
    std::cout << v.get_size() << '\n';
    v[0] = Point(1, 222);
    std::cout << v.get_size() << '\n';
    v[10] = Point(-1, 0.3);
    std::cout << v[11] << '\n';
    print(v);
    print(v);
    v.clear();
    print(v);
    std::cout << "===========\n";
    // v.insert(0, Point(0, 4));
    // print(v);
    v.push_back(Point(2, 3));
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
