//
// Created by Maxime Sanciaume on 10/10/2024.
//

#include "My_class.h"

#include <iostream>

void My_class::print_my_data() {
    std::cout << string << std::endl;
}

My_class::My_class(char* string_): string(string_) {}

