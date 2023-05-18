#include "stack.hpp"

namespace adapter {

template <typename T>
Stack<T>::Stack() 
    : parent() 
{
}

template <typename T>
Stack<T>::Stack(size_t size)
    : parent(size)
{
}

template <typename T>
Stack<T>::Stack(const Stack& other) 
    : parent(other) 
{
}

template <typename T>
Stack<T>::Stack(Stack&& other)
    : parent(std::move(other))
{
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other) {
        parent::operator=(other);
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
    if (this != &other) {
        parent::operator=(std::move(other));
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() 
{
}

template <typename T>
void Stack<T>::push(const T& value)
{
    parent::push_back(value);
}

template <typename T>
bool Stack<T>::empty() const
{
    return parent::empty();
}

template <typename T>
void Stack<T>::pop()
{
    if (!(this->empty())) {
        parent::pop_back();
    } else {
        throw std::runtime_error("Stack is empty. Cannot pop().");
    }
}

template <typename T>
T& Stack<T>::top()
{
    return parent::back();
}

template <typename T>
const T& Stack<T>::top() const
{
    return parent::back();
}

template <typename T>
size_t Stack<T>::size() const
{
    return parent::size();
}

} // namespace adapter 
