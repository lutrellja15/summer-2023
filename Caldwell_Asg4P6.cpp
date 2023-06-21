/****************
Baylee Caldwell
00106404
June 21, 2023
Problem 6
*****************/
/*
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void generateBarChart(const vector<int>& data, ofstream& outputFile) {
    int year = 2015;
    for (int i = data.size() - 1; i >= 0; i--) {
        int average = data[i] / 3000;
        outputFile << year << ": ";
        for (int j = 0; j < average; j++) {
            outputFile << '*';
        }
        outputFile << endl;
        year++;
        if (year > 2021) {
            break;
        }
    }
}


int main() {
    ifstream inputFile("test.txt");
    ofstream outputFile("StockResults.txt");

    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error creating output file." << endl;
        return 1;
    }

    vector<int> closingPrices;

    int price;
    while (inputFile >> price) {
        closingPrices.push_back(price);
    }

    generateBarChart(closingPrices, outputFile);

    inputFile.close();
    outputFile.close();

    cout << "Bar chart generated and written to StockResults.txt." << endl;

    return 0;
}
*/

#include <iostream>
#include <fstream>

using namespace std;

void generateBarChart(const int* data, int size, ofstream& outputFile) {
    int year = 2015;
    for (int i = size - 1; i >= 0; i--) {
        int average = data[i] / 3000;
        outputFile << year << ": ";
        for (int j = 0; j < average; j++) {
            outputFile << '*';
        }
        outputFile << endl;
        year++;
        if (year > 2021) {
            break;
        }
    }
}

int main() {
    ifstream inputFile("test.txt");
    ofstream outputFile("StockResults.txt");

    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error creating output file." << endl;
        return 1;
    }

    int* closingPrices = nullptr;
    int capacity = 10;
    int size = 0;

    closingPrices = new int[capacity];

    int price;
    while (inputFile >> price) {
        if (size == capacity) {
            // Double the capacity if the array is full
            capacity *= 2;
            int* temp = new int[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = closingPrices[i];
            }
            delete[] closingPrices;
            closingPrices = temp;
        }
        closingPrices[size] = price;
        size++;
    }

    generateBarChart(closingPrices, size, outputFile);

    delete[] closingPrices;

    inputFile.close();
    outputFile.close();

    cout << "Bar chart generated and written to StockResults.txt." << endl;

    return 0;
}
