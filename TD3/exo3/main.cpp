//
// Created by Maxime Sanciaume on 18/10/2024.
//

#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    //create a stack and a queue
    stack<char> stack;
    queue<char> queue;
    //push all the characters of the input string to the stack and the queue
    for (char c : input) {
        if (isalpha(c)) {
            stack.push(tolower(c));
            queue.push(tolower(c));
        }
    }

    //test if the stack and the queue are equal
    while (!stack.empty() && !queue.empty()) {
        if (stack.top() != queue.front()) {
            return false;
        }
        stack.pop();
        queue.pop();
    }
    return true;
}

int main() {
    cout << boolalpha ;
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    return 0 ;
}