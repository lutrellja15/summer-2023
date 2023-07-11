/****************
Baylee Caldwell
00106404
July 12, 2023
Problem 2
*****************/

#include <iostream>
#include <iomanip>
using namespace std;

bool validateEntry(int score);
int findMinimum(int scores[], int size);
int findMaximum(int scores[], int size);
int findSum(int scores[], int size);
double findAverage(int scores[], int size);
int findMode(int scores[], int size);
void displayGradeStatistics(int scores[], int size);

int main()
{
    int numStudents;
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    int* scores = new int[numStudents];
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Enter the overall class score for student " << (i + 1) << ": ";
        cin >> scores[i];

        while (!validateEntry(scores[i]))
        {
            cout << "Invalid entry. Please enter a score in the range 0-100: ";
            cin >> scores[i];
        }
    }

    displayGradeStatistics(scores, numStudents);

    delete[] scores;

    return 0;
}

bool validateEntry(int score)
{
    return (score >= 0 && score <= 100);
}

int findMinimum(int scores[], int size)
{
    int minScore = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < minScore)
        {
            minScore = scores[i];
        }
    }
    return minScore;
}

int findMaximum(int scores[], int size)
{
    int maxScore = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
        }
    }
    return maxScore;
}

int findSum(int scores[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    return sum;
}

double findAverage(int scores[], int size)
{
    double sum = findSum(scores, size);
    return sum / size;
}

int findMode(int scores[], int size)
{
    int counts = new int[101]{ 0 };
    for (int i = 0; i < size; i++)
    {
        counts[scores[i]]++;
    }

    int mode = 0;
    int maxCount = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (counts[i] > maxCount)
        {
            mode = i;
            maxCount = counts[i];
        }
    }

    delete[] counts;
    return mode;
}

void displayGradeStatistics(int scores[], int size)
{
    cout << "Grade Statistics:" << endl;
    cout << "-----------------" << endl;
    cout << "Minimum grade: " << findMinimum(scores, size) << endl;
    cout << "Maximum grade: " << findMaximum(scores, size) << endl;
    cout << "Average grade: " << fixed << setprecision(2) << findAverage(scores, size) << endl;
    cout << "Mode grade: " << findMode(scores, size) << endl;
}
