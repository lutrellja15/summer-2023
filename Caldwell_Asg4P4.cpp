/****************
Baylee Caldwell
00106404
June 21, 2023
Problem 4
*****************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// function to get grocery items for a store
void getGroceryItems(vector<string>& items) {
    cout << "Enter five grocery items:" << endl;
    for (int i = 0; i <= 5; i++) {
        string item;
        getline(cin, item);
        items.push_back(item);
    }
}

// function to display grocery items for a store
void displayGroceryItems(vector<string>& items) {
    cout << "Grocery items:" << endl;
    
    string items1;
    for (int i=0; i<=4; i++) {
        cout << "- " << items1 << endl;
    }

  //  for (string item : items) {
  //      cout << "- " << item << endl;
  //  }
}

int main() {
    vector<string> walmartItems, hometownItems, samsItems;
    char choice;
    do {
        cout << "Select a grocery store:" << endl;
        cout << "W - Wal-Mart" << endl;
        cout << "H - Hometown Market" << endl;
        cout << "S - Sam's Club" << endl;
        cout << "D - Done" << endl;
        cin >> choice;
        switch (choice) {
            case 'W':
            case 'w':
                getGroceryItems(walmartItems);
                break;
            case 'H':
            case 'h':
                getGroceryItems(hometownItems);
                break;
            case 'S':
            case 's':
                getGroceryItems(samsItems);
                break;
            case 'D':
            case 'd':
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 'D' && choice != 'd');
    
    // Sort grocery items in alphabetical order
    sort(walmartItems.begin(), walmartItems.end());
    sort(hometownItems.begin(), hometownItems.end());
    sort(samsItems.begin(), samsItems.end());
    
    // Write grocery items to the output file
    ofstream outputFile("groceryList.txt");
    if (outputFile.is_open()) {
        outputFile << "Grocery items for each store:" << endl;
        outputFile << "Wal-Mart:" << endl;
        for (string item : walmartItems) {
            outputFile << "- " << item << endl;
        }
        outputFile << "Hometown Market:" << endl;
        for (string item : hometownItems) {
            outputFile << "- " << item << endl;
        }
        outputFile << "Sam's Club:" << endl;
        for (string item : samsItems) {
            outputFile << "- " << item << endl;
        }
        outputFile.close();
        cout << "Grocery items have been written to groceryList.txt" << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
    
    ifstream inputFile("groceryList.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}
