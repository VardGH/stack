#include <iostream>
#include "stack.hpp"

namespace test 
{
    void test_stack();
}

int main() 
{
    test::test_stack();

    return 0;
}

namespace test
{
    
void test_stack()
{
    // st1
    adapter::Stack<int> st1;

    for (size_t i = 0; i < 5; ++i) {
        st1.push(i*10);
    }

    std::cout << "Top elem st1: " << st1.top() << std::endl;

    st1.pop();
    std::cout << "Top elem st1: " << st1.top() << std::endl;

    // st2
    adapter::Stack<int> st2 = st1; // copy ctor
    std::cout << "Top elem st2: " << st1.top() << std::endl;

    // st3
    adapter::Stack<double> st3;

    st3.push(1.1);
    st3.push(2.2);
    st3.push(3.3);
    st3.push(4.4);

    std::cout << "Top elem st3: " << st3.top() << std::endl;
    st3.pop();
    std::cout << "Top elem st3: " << st3.top() << std::endl;

    // st4
    adapter::Stack<char> st4;

    st4.push('a');
    st4.push('b');
    st4.push('c');
    st4.push('d');
    st4.push('f');

    std::cout << "st4.size() == " << st4.size() << std::endl;

    std::cout << "Top elem st4: " << st4.top() << std::endl;
    st4.pop();
    st4.pop();
    std::cout << "Top elem st4: " << st4.top() << std::endl;

    std::cout << std::boolalpha << "st4 is empty: " << st4.empty() << std::endl;

    st4.pop();
    st4.pop();
    st4.pop();

    std::cout << std::boolalpha << "st4 is empty: " << st4.empty() << std::endl;
    std::cout << "st4.size() == " << st4.size() << std::endl;

    try {   
        st2.pop();
        st2.pop();
        st2.pop();
        st2.pop();
    } catch (std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
}

} // namespace test
