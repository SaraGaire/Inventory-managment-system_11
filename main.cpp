#include "ISYSTEM.h"

int main() {
// the main function is the central hub of the program and it also direct the users different commands for appropriate part of the class in the program.
    InventorySystem system;
    int choice;

    try {
        system.loadInventory();
    } catch (const exception& e) {
        cerr << "Warning : the input provided here is not valid. " << e.what() << endl;
    }//exception file handling using  try and catch functions. this also help with the missing files and the invalid input form the users.

    while (true) {
        cout << "\nInventory Management System:\n";
        cout << "1. Add Product\n";
        cout << "2. Add Service\n";
        cout << "3. Display Inventory\n";
        cout << "4. Save Inventory\n";
        cout << "5. Add Order\n";
        cout << "6. Process Order\n";
        cout << "7. Display Orders\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
//the switch statement direct the program to execute the appropriate function based on the users choice.
        switch (choice) {
            case 1:
                system.addProduct();
                break;
            case 2:
                system.addService();
                break;
            case 3:
                system.displayInventory();
                break;
            case 4:
                system.saveInventory();
                break;
            case 5:
                system.addOrder();
                break;
            case 6:
                system.processOrder();
                break;
            case 7:
                system.displayOrders();
                break;
            case 8:
                cout << "Exiting the program here.\n";
                return 0;
                //for each of the cases it allows the users to execute the system. function and exist the program in case 8 and return 0.
            default:
            //if the user prompt the value outside of the range then the program will not be crashed or break with the use of default consition which therefore shows the message as invalid choice, try gain good luck wqith it.
                cout << "Invalid choice, Try again, Good luck with it.\n";
        }
    }
}
