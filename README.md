# Stack Adapter

This repository contains a C++ stack adapter class implemented using a vector as the underlying data structure.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
  - [Installation](#installation)
  - [Example](#example)

## Introduction

The Stack Adapter is a C++ class that provides a simple interface for working with stacks. It is implemented using the Standard Template Library (STL) `std::vector` as the underlying data structure. The class offers basic stack operations such as push, pop, top, size, and empty.

## Features

- Easy-to-use stack interface.
- Support for copy construction, copy assignment, move construction, and move assignment.
- Proper encapsulation and namespace usage.
- Efficient storage and retrieval of elements using `std::vector`.

## Usage

### Installation

To use the Stack Adapter class in your project, follow these steps:

1. Clone this repository to your local machine.
2. Include the `stack.hpp` header file in your C++ project.
3. You can then use the `adapter::stack<T>` class in your code.

### Example

```cpp
#include "stack.hpp"
#include <iostream>

int main() {
    adapter::stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    std::cout << "Stack size: " << myStack.size() << std::endl;
    std::cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```