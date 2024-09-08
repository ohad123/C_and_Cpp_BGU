# Vending Machine

## Overview

This project implements a simple Vending Machine system in C++. The system simulates the operation of a vending machine, allowing users to select products, insert coins, and manage inventory.

## Features

- **Product Selection:** Users can select products from the available options.
- **Coin Insertion:** Users can insert coins to pay for selected products.
- **Inventory Management:** The system tracks and manages product inventory.
- **Transaction Handling:** Handles the logic for transactions including change calculation and error handling.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- Basic understanding of C++ programming and concepts such as classes, operator overloading, and data structures.

### Compiling

To compile the source code, use the following command:

```
g++ -o VendingMachine VendingMachine.cpp
```

### Running the Executable
To run the compiled executable, use the following command:

```
./VendingMachine
```

## Usage

- **Select Product:** Choose a product from the vending machine's menu.
- **Insert Coins:** Insert coins into the machine. The system will calculate if enough money has been inserted.
- **Complete Transaction:** If sufficient money is inserted, the product will be dispensed. Otherwise, you will be prompted to insert more coins or cancel the transaction.
- **View Inventory:** The system displays the remaining inventory and allows for restocking.

## Classes and Methods

- **Data Members:**
  - `std::map<std::string, int> inventory`: Stores the products and their quantities.
  - `int balance`: Represents the current amount of money inserted.

- **Methods:**
  - `void selectProduct(const std::string& product)`: Allows the user to select a product.
  - `void insertCoin(int coin)`: Adds the value of the coin to the balance.
  - `void dispenseProduct()`: Dispenses the selected product if the balance is sufficient.
  - `void viewInventory()`: Displays the current inventory and allows restocking.
  - `void cancelTransaction()`: Cancels the current transaction and returns the inserted money.

## Conclusion

This project demonstrates the use of classes and objects to simulate a real-world system. It provides practical experience in managing state, handling user input, and implementing core functionalities of a vending machine.


