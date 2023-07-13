# Vector

Vector is a C++ template class that provides a dynamic array implementation with various functionality for managing a sequence of elements.

## Features

- Supports dynamic resizing to accommodate varying numbers of elements.
- Provides common container operations such as element insertion, erasure, and access.
- Supports efficient element assignment, insertion, and deletion at the beginning and end of the container.
- Allows direct element access using the subscript operator.
- Supports range-based iteration using iterators or `begin()` and `end()` member functions.

## Usage

### Basic Usage

1. Include the "MyVec.hpp" header in your C++ program.
2. Create a Vector object by specifying the element type:

   ```cpp
   #include "MyVec.hpp"

   int main() {
       Vector<int> vec;  // Create an empty vector of integers
       vec.push_back(10);  // Add an element to the vector
       // ...
       return 0;
   }
