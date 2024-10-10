#include <iostream>

#include <string>
#include "My_class.h"
using namespace std;

void printData(string s) {
    std::cout << s << std::endl;
}

int main(){
    std::cout << "Hello World!" << std::endl;
    printData("Hello World!");

    My_class c = My_class("Hello World!");
    c.print_my_data();
    return 0;
}
