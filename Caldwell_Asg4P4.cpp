/****************
Baylee Caldwell
00106404
June 21, 2023
Problem 4
*****************/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX_ITEMS = 5;

// Function to get grocery items for a store
void getGroceryItems(string storeName, string items[]) {
    cout << "Enter five grocery items for " << storeName << ":" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << "Item " << (i + 1) << ": ";
        getline(cin, items[i]);
    }
}

// Function to display grocery items for a store
void displayGroceryItems(string storeName, string items[]) {
    cout << "Grocery items for " << storeName << ":" << endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << "- " << items[i] << endl;
    }
    cout << endl;
}

int main() {
    string walmartItems[MAX_ITEMS], hometownItems[MAX_ITEMS], samsItems[MAX_ITEMS];
    char choice;
    bool walmartEntered = false, hometownEntered = false, samsEntered = false;

    do {
        cout << "Select a grocery store:" << endl;
        cout << "W - Wal-Mart" << endl;
        cout << "H - Hometown Market" << endl;
        cout << "S - Sam's Club" << endl;
        cout << "D - Done" << endl;
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        switch (toupper(choice)) {
            case 'W':
                getGroceryItems("Wal-Mart", walmartItems);
                walmartEntered = true;
                break;
            case 'H':
                getGroceryItems("Hometown Market", hometownItems);
                hometownEntered = true;
                break;
            case 'S':
                getGroceryItems("Sam's Club", samsItems);
                samsEntered = true;
                break;
            case 'D':
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (toupper(choice) != 'D');

    // Sort grocery items in alphabetical order
    sort(walmartItems, walmartItems + MAX_ITEMS);
    sort(hometownItems, hometownItems + MAX_ITEMS);
    sort(samsItems, samsItems + MAX_ITEMS);

    // Write grocery items to the output file
    ofstream outputFile("groceryList.txt");
    if (outputFile.is_open()) {
        outputFile << "Grocery List:" << endl;
        if (walmartEntered) {
            outputFile << "Wal-Mart:" << endl;
            for (int i = 0; i < MAX_ITEMS; i++) {
                outputFile << "- " << walmartItems[i] << endl;
            }
            outputFile << endl;
        }
        if (hometownEntered) {
            outputFile << "Hometown Market:" << endl;
            for (int i = 0; i < MAX_ITEMS; i++) {
                outputFile << "- " << hometownItems[i] << endl;
            }
            outputFile << endl;
        }
        if (samsEntered) {
            outputFile << "Sam's Club:" << endl;
            for (int i = 0; i < MAX_ITEMS; i++) {
                outputFile << "- " << samsItems[i] << endl;
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Grocery items have been written to groceryList.txt" << endl;
    } else {
        cout << "Unable to open the file." << endl;
   }
// Display grocery items

if (walmartEntered) {
    displayGroceryItems("Wal-Mart", walmartItems);
}
if (hometownEntered) {
    displayGroceryItems("Hometown Market", hometownItems);
}
if (samsEntered) {
    displayGroceryItems("Sam's Club", samsItems);
}

return 0;
}
