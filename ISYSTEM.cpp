#include "InventorySystem.h"
// Constructor for InventorySystem class
InventorySystem::InventorySystem() : transactionLogFile("transactions.log") {}
// Destructor for InventorySystem class
InventorySystem::~InventorySystem() {
    // This message is shown when the system shuts down, and any unsaved data will be saved automatically.
    cout << "Inventory System is down and the rest of the data is saved automatically.\n";
    saveInventory(); 
}

void InventorySystem::logTransaction(const string& action) {
    // Open the transaction log file in append mode
    ofstream logFile(transactionLogFile, ios::app);
    if (!logFile) throw runtime_error("Unable to open transaction log file.");
    logFile << action << endl; // Writing the transaction action to the file.
    // closing  the log file
    logFile.close();
}
// Adds a product to the inventory
void InventorySystem::addProduct() {
    try {
        string name;
        int quantity;
        double price;

        // Prompt the user to input the product details
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;

        if (quantity < 0 || price < 0) throw invalid_argument(" sorry, negative values are not allowed.");//if the user prompts negative values then it throes the invalid argument to the program.
        inventory.push_back(make_unique<Product>(name, quantity, price));//adding product to inventoery using memory managment to avoid memory leakage in the program.
        logTransaction("Added Product: " + name);//it records the evnt and add the product name.
        cout << "Product added successfully.\n";
    } 
    catch (const exception& e) 
    {
        cerr << "Error is shown in the program. " << e.what() << endl;
    }
}
// Adds a service to the inventory
void InventorySystem::addService() {
    try {
        string name;
        int sessions;
        double price;

        // Prompt the user to input the service details
        cout << "Enter service name: ";
        cin >> name;
        cout << "Enter number of sessions: ";
        cin >> sessions;
        cout << "Enter price per session: ";
        cin >> price;
        if (sessions < 0 || price < 0) throw invalid_argument("Negative values are not allowed.");

        // Add the service to the inventory
        inventory.push_back(make_unique<Service>(name, sessions, price));
        logTransaction("Added Service: " + name);
        cout << "Service added successfully.\n";
    } catch (const exception& e) 
    {
        cerr << "Error: sorry the service can not be added. " << e.what() << endl;
    }
}
void InventorySystem::displayInventory() const {
    if (inventory.empty()) {
        cout << "No items in inventory.\n";
        return;
    }//chevck the inventoery and shiw the cout.
    cout << "Inventory List:\n";

    for (const auto& item : inventory)
     {
        item->display(); // calling the display method for each items.
    }
}
//here we will be saving the inventory to the file.
void InventorySystem::saveInventory() const {
    // Open a file for saving inventory details
    ofstream outFile("inventory.dat");
    if (!outFile) throw runtime_error("Unable to open inventory file due to runtime error.");
    for (const auto& item : inventory)//writing down the  each inventory.
     {
        outFile << item->name << " " << item->quantity << " " << item->price << endl;
    }
    outFile.close();//closing the file
    cout << "Inventory saved successfully.\n";
}

// Loads the inventory from a file
void InventorySystem::loadInventory() {
    // Open the inventory file for reading
    ifstream inFile("inventory.dat");
    if (!inFile) throw runtime_error("Unable to open inventory file.");
    // Clear any existing inventory data in memory
    inventory.clear();
    string name;
    int quantity;
    double price;
    // Read each item from the file and add it to the inventory
    while (inFile >> name >> quantity >> price)
     {
        inventory.push_back(make_unique<Product>(name, quantity, price));
    }
    inFile.close();//closing thefile.
    cout << "Inventory loaded successfully.\n";
}
// Adds an order to the order queue
void InventorySystem::addOrder() {
    string order;
    cout << "Enter order details: ";
    cin.ignore(); 
    //ignoring the leftovers.
    getline(cin, order);// Read the full order description
    orderQueue.push(order);
    logTransaction("Order Added: " + order);
    cout << "Order added successfully.\n";
}

// Processing  the next order in the queue
void InventorySystem::processOrder() {
    if (orderQueue.empty()) {
        cout << "No orders to process.\n";
        return;
    }
    // Process the first order in the queue
    cout << "Processing order: " << orderQueue.front() << endl;
    logTransaction("Processed Order: " + orderQueue.front());
    // Remove the processed order from the queue
    orderQueue.pop();
}
// Displays all pending orders in the queue
void InventorySystem::displayOrders() const
 {
    if (orderQueue.empty()) {
        cout << "No pending orders.\n";
        return;
    }

    // Display all pending orders
    queue<string> tempQueue = orderQueue; // Make a copy of the queue for display
    cout << "Pending Orders are :\n";
    while (!tempQueue.empty()) {
        cout << "- " << tempQueue.front() << endl; //displying each order in queue.
        tempQueue.pop();
    }
}
