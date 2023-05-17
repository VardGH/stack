#include "stack.hpp"
namespace adapter {

template <typename T>
Stack<T>::Stack() 
    : container::Vector<T>() 
    {
    }

template <typename T>
Stack<T>::Stack(size_t size)
    : container::Vector<T>(size)
    {
    }

template <typename T>
Stack<T>::Stack(const Stack& other) 
    : container::Vector<T>(other) 
    {
    }

template <typename T>
Stack<T>::Stack(Stack&& other)
    : container::Vector<T>(std::move(other))
    {
    }

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other) {
        container::Vector<T>::operator=(other);
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
    if (this != &other) {
        container::Vector<T>::operator=(std::move(other));
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
    container::Vector<T>::push_back(value);
}

template <typename T>
void Stack<T>::pop()
{
    if (container::Vector<T>::size() > 0) {
        container::Vector<T>::pop_back();
    } else {
        throw std::runtime_error("Stack is empty. Cannot pop().");
    }
}

template <typename T>
T& Stack<T>::top()
{
    return container::Vector<T>::back();
}

template <typename T>
const T& Stack<T>::top() const
{
    return container::Vector<T>::back();
}

template <typename T>
size_t Stack<T>::size() const
{
    return container::Vector<T>::size();
}

template <typename T>
bool Stack<T>::empty() const
{
    return container::Vector<T>::size() == 0;
}

} // namespace adapter 