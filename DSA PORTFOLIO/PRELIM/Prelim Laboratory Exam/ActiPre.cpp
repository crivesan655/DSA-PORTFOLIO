#include <iostream>
#include <string>
#include "stack.h"

int main() {
    stack<char> checker;

    std::string GivenCases[] = {"10201", "1003003001", "88", "0", "202"};
    int numTests = sizeof(GivenCases) / sizeof(GivenCases[0]);

    for (int i = 0; i < numTests; ++i) {
        std::string Given = GivenCases[i];
        bool result = checker.Palindrome_check(Given);
        std::cout << "Given Number: " << Given << " ------> "
                  << (result ? " It is a Palindrome" : "It is not a Palindrome") << std::endl;
    }

    return 0;
}                           
