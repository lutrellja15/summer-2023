/****************
Baylee Caldwell
00106404
July 12, 2023
Problem 1
*****************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int* readNumbersFromFile(const string& fileName, int& size);
int findLowestValue(const int* numbers, int size);
int findHighestValue(const int* numbers, int size);
int calculateSum(const int* numbers, int size);
double calculateAverage(const int* numbers, int size);

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    int size;
    int* numbers = readNumbersFromFile(fileName, size);
    if (!numbers)
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int lowest = findLowestValue(numbers, size);
    int highest = findHighestValue(numbers, size);
    int sum = calculateSum(numbers, size);
    double average = calculateAverage(numbers, size);

    cout << "Lowest value: " << lowest << endl;
    cout << "Highest value: " << highest << endl;
    cout << "Sum of values: " << sum << endl;
    cout << "Average of values: " << fixed << setprecision(2) << average << endl;

    delete[] numbers;

    return 0;
}

int* readNumbersFromFile(const string& fileName, int& size)
{
    ifstream inputFile(fileName);
    if (!inputFile)
    {
        size = 0;
        return nullptr;
    }

    int count = 0;
    int number;
    while (inputFile >> number)
    {
        count++;
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    int* numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        inputFile >> numbers[i];
    }

    size = count;
    return numbers;
}

int findLowestValue(const int* numbers, int size)
{
    int lowest = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < lowest)
        {
            lowest = numbers[i];
        }
    }
    return lowest;
}

int findHighestValue(const int* numbers, int size)
{
    int highest = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > highest)
        {
            highest = numbers[i];
        }
    }
    return highest;
}

int calculateSum(const int* numbers, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

double calculateAverage(const int* numbers, int size)
{
    double sum = calculateSum(numbers, size);
    return static_cast<double>(sum) / size;
}
