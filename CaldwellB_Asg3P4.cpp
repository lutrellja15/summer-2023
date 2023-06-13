/****************
Baylee Caldwell
00106404
June 14
Problem 4
****************/

#include <iostream>
#include <iomanip>
using namespace std;

struct Competitor {
    string name;
    double attempt1;
    double attempt2;
};

void displayMenu() {
    cout << "Enter the number corresponding to the event you want to enter the information for:\n";
    cout << "1. Stone Over Bar" << endl;
    cout << "2. Farmers Frame Medley" << endl;
    cout << "3. Axle Deadlift" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
}

int getRanking(const Competitor competitors[], int numCompetitors, int event) {
    int ranking = 1;
    double bestAttempt = competitors[0].attempt1;
    
    for (int i = 1; i < numCompetitors; i++) {
        double currentAttempt;
        if (event == 1)
            currentAttempt = competitors[i].attempt1;
        else if (event == 2)
            currentAttempt = competitors[i].attempt2;
        else
            currentAttempt = competitors[i].attempt1;
        
        if (currentAttempt > bestAttempt) {
            bestAttempt = currentAttempt;
            ranking = i + 1;
        }
    }
    
    return ranking;
}

void displayResults(const Competitor competitors[], int numCompetitors, int event) {
    string eventName;
    if (event == 1)
        eventName = "Stone Over Bar";
    else if (event == 2)
        eventName = "Farmers Frame Medley";
    else
        eventName = "Axle Deadlift";
    
    cout << "Event: " << eventName << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < numCompetitors; i++) {
        string attempt;
        if (event == 1)
            attempt = "Attempt 1";
        else if (event == 2)
            attempt = "Attempt 2";
        else
            attempt = "Attempt 1";
        
        cout << "Competitor: " << competitors[i].name << endl;
        cout << "Best Attempt: ";
        
        if (event == 1 || event == 3)
            cout << competitors[i].attempt1 << endl;
        else
            cout << competitors[i].attempt2 << " seconds" << endl;
        
        cout << "Ranking: " << getRanking(competitors, numCompetitors, event) << " place" << endl;
        cout << "Points earned: ";
        
        int ranking = getRanking(competitors, numCompetitors, event);
        if (ranking == 1)
            cout << "3";
        else if (ranking == 2)
            cout << "2";
        else
            cout << "1";
        
        cout << endl;
        cout << "----------------------------------------" << endl;
    }
}

int main()
{
    const int MAX_COMPETITORS = 3;
    Competitor competitors[MAX_COMPETITORS];
    
    for (int i = 0; i < MAX_COMPETITORS; i++) {
        cout << "Enter the name of competitor " << (i + 1) << ": ";
        getline(cin, competitors[i].name);
    }
    
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            for (int i = 0; i < MAX_COMPETITORS; i++) {
                // Get the stone over bar attempt for each competitor
                cout << "Enter the stone over bar attempt for " << competitors[i];
                