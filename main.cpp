#include <iostream>
#include "vector.hpp"
#include "stack.hpp"

namespace test
{

void test_vec()
{
    // vec
    container::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    std::cout << "Print vec: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // vec1
    container::Vector<int> vec1 = vec;
    vec1.push_back(5);

    std::cout << "Print vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    //vec2
    const container::Vector<int> vec2 = vec1;
    std::cout << "Print const vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    vec1.clear();
    std::cout << "Print const vec2: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    
    // vec3
    container::Vector<int> vec3;
    vec3 = std::move(vec);

    std::cout << "Print vec3: ";
    for (size_t i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "vac2.back() " << vec2.back() << std::endl;
    std::cout << "vac3.back() " << vec3.back() << std::endl;

    try {
        vec3.pop_back();
        vec3.pop_back();
        vec3.pop_back();
        vec3.pop_back();
        vec3.pop_back();
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
}

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


}

int main() 
{
    test::test_stack();

    return 0;
}