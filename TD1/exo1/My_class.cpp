//
// Created by Maxime Sanciaume on 10/10/2024.
//

#include "My_class.h"

#include <iostream>
#include <string>

using namespace std;

void My_class::print_my_data() {
    std::cout << s << std::endl;
}

My_class::My_class(string s_): s(s_) {}

