//
// Created by Maxime Sanciaume on 10/10/2024.
//

#ifndef MY_CLASS_H
#define MY_CLASS_H



class My_class {
private:
    char* string;

public:
    void print_my_data();
    My_class(char* string);
    virtual ~My_class() = default;
};

#endif //MY_CLASS_H
