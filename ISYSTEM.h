#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H
//it checks if the macro is defined  or not and define the macro.
#include <iostream>
#include <vector>
 //Used for managing a collection of items in the inventory.
#include <fstream>// this is used foe saving and loading inventory data.
#include <stdexcept>
//header for handling the runtime error in the program.
#include<queue>
#include <queue>
//manages the ques of the itesm in the orders.
#include <string>
using namespace std;

// Base class for inventory items
class Item
 {
public:
    string name; // Name of the item
    int quantity; // Quantity of the item
    double price; // Price of the item
//cunstructor of the program for the data items.
Item(const string& name, int quantity, double price) {
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}// virtual destructor.
    virtual ~Item() = default; 
    // = default will tell the compiler to generate the destructor automatically. 

    virtual void display() const {
        cout << "Item: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;// here we will be able to print the items in the detailed form.
    }
};

class InventorySystem {
    //class for managing the inventory in the order system.
private:
    vector<unique_ptr<Item> > inventory; // Stores all items in the inventory and the unique_ptr helps with the memory management and leakage in the program.
    queue<string> orderQueue; // Queue to manage orders

    void logTransaction(const string& action); // Logs transactions  to keep the track of the adding and removing of th iteams in the files.
public:
    InventorySystem();
    void addItem(); 
    void addProduct();
    void addService();
    void displayInventory() const; 
    void saveInventory() const; // Save inventory data to a file
    void loadInventory(); // Load inventory data from a file
    void addOrder(); // Add a new order to the queue
    void processOrder(); // Process the next order in the queue
    void displayOrders() const; // Display all pending orders
};
#endif // INVENTORYSYSTEM_H
