# Operator Overloading and Vectors

This project demonstrates the use of operator overloading and vectors in C++. 
It focuses on implementing custom operators for a class and using vectors to manage collections of objects.

## Project Structure

- **`main.cpp`**: Contains the main function and demonstrates the usage of operator overloading and vectors with custom objects.
- **`VectorExample.cpp`**: Implements a class that uses operator overloading for various operations and manages its elements with vectors.
- **`VectorExample.h`**: Header file for the `VectorExample` class, declaring its methods and data members.

## Features

- **Operator Overloading**: Custom implementation of operators for the `VectorExample` class, including:
  - `+` (Addition)
  - `-` (Subtraction)
  - `==` (Equality Comparison)
  - `<<` (Output Stream)

- **Vectors**: Utilizes the `std::vector` container to manage a dynamic array of objects, demonstrating how to:
  - Add elements
  - Access elements
  - Iterate through elements

## Compilation and Execution

To compile and run the project, follow these steps:

1. **Compile the Code**:
   ```
   g++ -o VectorExample main.cpp VectorExample.cpp
   ```
2. **Run the Executable**:

To run the compiled executable, use the following command:

```
./VectorExample
```
## Usage

- **Addition Operator**: Demonstrates how to use the `+` operator to add two `VectorExample` objects.
- **Subtraction Operator**: Demonstrates how to use the `-` operator to subtract one `VectorExample` object from another.
- **Equality Operator**: Demonstrates how to compare two `VectorExample` objects for equality.
- **Output Stream Operator**: Demonstrates how to use the `<<` operator to print `VectorExample` objects to the console.

## Classes and Methods

### VectorExample

- **Data Members:**
  - `int value`: Represents the integer value stored in the object.

- **Constructors:**
  - `VectorExample(int val)`: Initializes the object with a given value.

- **Methods:**
  - `VectorExample operator+(const VectorExample& other) const`: Overloads the `+` operator.
  - `VectorExample operator-(const VectorExample& other) const`: Overloads the `-` operator.
  - `bool operator==(const VectorExample& other) const`: Overloads the `==` operator.
  - `friend std::ostream& operator<<(std::ostream& os, const VectorExample& obj)`: Overloads the `<<` operator for output.

## Conclusion

This project illustrates key concepts in C++ programming, such as operator overloading and the use of vectors. 
It provides a clear example of how to enhance class functionality and manage collections of objects effectively.
