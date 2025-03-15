#include "SetType.h"


#include <iostream>
#include <functional>

void testbind(int a, int b, int c) {
    std::cout << a << " " << b << " " << c;
}

int main() {
    auto tb = std::bind(testbind, std::placeholders::_2, 3, std::placeholders::_1);
    tb(10, 4);
    std::cout << std::endl; 
    return 0;
}

