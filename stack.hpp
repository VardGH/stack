#ifndef STACK_HPP
#define STACK_HPP

namespace adapter {

#include "vector.hpp"

template <typename T>
class Stack : private container::Vector<T>
{
public:
    Stack();
    Stack(size_t size);
    Stack(const Stack& other);  // copy ctor
    Stack(Stack&& other);       // move ctor
    Stack& operator=(const Stack& other);  // copy assignment operator
    Stack& operator=(Stack&& other);       // move assignment operator
    ~Stack(); // dtor
public:
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    size_t size() const;
    bool empty() const;
};

} // namespace adapter

#include "stack_impl_.hpp"

#endif // STACK_HPP