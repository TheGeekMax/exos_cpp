#include <iostream>


void printData(char* string) {
    std::cout << string << std::endl;
}

int main(){
    std::cout << "Hello World!" << std::endl;
    printData("Hello World!");
    return 0;
}
