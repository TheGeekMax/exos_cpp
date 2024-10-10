//
// Created by Maxime Sanciaume on 10/10/2024.
//

#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>
using namespace std;


class My_class {
private:
    string s;

public:
    void print_my_data();
    My_class(string s);
    virtual ~My_class() = default;
};

#endif //MY_CLASS_H
