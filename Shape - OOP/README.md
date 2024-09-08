# Shape - OOP

## Overview

This project demonstrates the implementation of a simple object-oriented system for managing and manipulating different shapes using C++. It involves creating a hierarchy of classes to represent various shapes and performing operations on them.

## Project Structure

- **Node**: Represents an element in a linked list.
- **LinkedList<T>**: A templated linked list class to manage nodes.
- **Shape**: A base class representing a geometric shape with virtual methods for calculating area and perimeter.
- **Square**: Inherits from `Shape`, representing a square with specific methods for drawing and calculating area and perimeter.
- **Circle**: Inherits from `Shape`, representing a circle with methods for drawing and calculating area and perimeter.
- **OrthogonalTriangle**: Inherits from `Shape`, representing a right-angled isosceles triangle with methods for drawing and calculating area and perimeter.
- **Menu**: Manages the user interface and interactions, including adding shapes to a list, removing shapes, and displaying details.

## Compilation and Execution

To compile the project, use the following command in your terminal:

```
g++ -o shape_manager main.cpp Shape.cpp Square.cpp Circle.cpp OrthogonalTriangle.cpp LinkedList.cpp
```

This will create an executable file named shape_manager.

To run the program, execute the following command:

```
./shape_manager
```

# Game Rules

- **Game Board**: The system operates with an 8x8 board.
- **Players**: Two players take turns moving their pawns ('X' and 'O') on the board.
- **Pawns Movement**: Pawns can move diagonally forward to an empty square.
- **Capturing**: A pawn can capture an opponent's pawn by jumping over it.
- **End Game**: The game ends when one player captures all of the opponent's pawns or no legal moves are available.
- **Quit Option**: Players can quit the game by entering `999` as input.

# Gameplay Instructions

1. Each player is prompted to enter the location of their pawn and its desired destination.
2. The game checks the legality of the move.
3. If the move is legal, the pawn is moved. If the move results in a capture, the opponent's pawn is removed from the board.
4. The game continues until one player wins or a player decides to quit.

# Input Format

- Enter the row and column number for the pawn you want to move.
- Enter the row and column number for the destination you want to move the pawn to.

# Classes and Methods

## Node

- **Data Members**:
  - `T data`: The data stored in the node.
  - `Node<T>* Next`: Pointer to the next node in the list.
- **Constructor**:
  - `Node(T data)`: Initializes the data field and sets the next field to `nullptr`.

## LinkedList<T>

- **Data Member**:
  - `Node<T>* head`: Pointer to the first node in the linked list.
- **Methods**:
  - `LinkedList()`: Default constructor.
  - `insert(const T&)`: Inserts a new node at the front.
  - `T deleteNode()`: Deletes and returns the first node.
  - `T deleteNode(const T&)`: Deletes a node with specific data.
  - `search(const T&)`: Searches for a node with specific data.
  - `const T& getTop() const`: Returns the last inserted node.
  - `operator<<`: Prints the nodes of the linked list.

## Shape

- **Data Member**:
  - `string color`: Color of the shape.
- **Pure Virtual Methods**:
  - `double getPerimeter()`: Returns the perimeter of the shape.
  - `double getArea()`: Returns the area of the shape.
- **Constructor**:
  - Initializes the color.

## Square

- **Data Member**:
  - `double sideLength`: Length of the square's side.
- **Methods**:
  - `void draw()`: Displays the square.
  - Implements `getPerimeter()` and `getArea()`.

## Circle

- **Data Member**:
  - `double radius`: Radius of the circle.
- **Methods**:
  - Implements `getPerimeter()` and `getArea()`.

## OrthogonalTriangle

- **Data Member**:
  - `double legLength`: Length of the legs of the right-angled triangle.
- **Methods**:
  - `void draw()`: Displays the triangle.
  - Implements `getPerimeter()` and `getArea()`.

## Menu

- **Methods**:
  - `void mainMenu()`: Displays the main menu and handles user interactions.

# Conclusion

This project showcases core concepts of object-oriented programming, including inheritance, polymorphism, and exception handling. It provides a clear example of how to implement and manage a hierarchy of classes in C++.
