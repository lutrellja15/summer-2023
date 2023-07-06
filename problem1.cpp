#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_COMPETITORS = 3;

string competitors1,competitors2,competitors3;
float competitor1attempt1,competitor1attempt2,competitor2attempt1,competitor2attempt2,competitor3attempt1,competitor3attempt2;
float competitor1bestAttempt,competitor2bestAttempt,competitor3bestAttempt;
float competitor1totalscore, competitor2totalscore, competitor3totalscore;
int competitors1points,competitors2points,competitors3points;


// Function prototypes
void displayMenu();
void enterCompetitors();
bool verifyPositiveValue(float value);
void enterAttempt(const string& eventName);
void enterAttemptMin(const string& eventName);
void rankCompetitors( const string& eventName);
void displayResults();
void farm_fram_med();
void axle_deadlift();
void stonethrow();

int main() {

    int eventChoice;
    enterCompetitors();
    while(true){
        displayMenu();
        cout << "Enter your choice: ";
        cin >> eventChoice;
        switch (eventChoice) {
            case 1:
                farm_fram_med();
                break;

            case 2:
                axle_deadlift();
                break;

            case 3:
                stonethrow();
                break;

            case 4:
                
                displayResults();
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                return 0;
                break;


        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nChoose the event:\n";
    cout << "1. Farmers Frame Medley\n";
    cout << "2. Axle Deadlift\n";
    cout << "3. Stone Over Bar\n";
    cout << "4. Quit\n";
}

void enterCompetitors() {
    
    cout << "Enter the name of competitor 1: ";
    cin>>competitors1;
    cout << "Enter the name of competitor 2: ";
    cin>>competitors2;
    cout << "Enter the name of competitor 3: ";
    cin>>competitors3;

}

bool verifyPositiveValue(float value) {
    return value < 0;
}

void enterAttempt(const string& eventName) {

    cout << "Enter the result for " << competitors1 << "'s " << eventName << " attempt 1: ";
    cin >> competitor1attempt1;
        if(verifyPositiveValue(competitor1attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors1 << "'s " << eventName << " attempt 2: ";
    cin >> competitor1attempt2;
             if(verifyPositiveValue(competitor1attempt2))
            cout<<"bad input";

    cout << "Enter the result for " << competitors2 << "'s " << eventName << " attempt 2: ";
    cin >> competitor2attempt1;
            if(verifyPositiveValue(competitor2attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors2 << "'s " << eventName << " attempt 2: ";
    cin >> competitor2attempt2;
            if(verifyPositiveValue(competitor2attempt2))
            cout<<"bad input";
    
    cout << "Enter the result for " << competitors3 << "'s " << eventName << " attempt 2: ";
    cin >> competitor3attempt1;
            if(verifyPositiveValue(competitor3attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors3 << "'s " << eventName << " attempt 2: ";
    cin >> competitor3attempt2;
            if(verifyPositiveValue(competitor3attempt2))
            cout<<"bad input";
    competitor1bestAttempt = max(competitor1attempt1, competitor1attempt2);
    competitor2bestAttempt = max(competitor2attempt1, competitor2attempt2);
    competitor3bestAttempt = max(competitor3attempt1, competitor3attempt2);

    competitors1points+=1;
    competitors2points+=1;
    competitors3points+=1;
    if(competitor1bestAttempt > competitor2bestAttempt)
    {
        competitors1points++;
    }
    if(competitor1bestAttempt > competitor3bestAttempt)
    {
        competitors1points++;
    }
    if(competitor2bestAttempt > competitor1bestAttempt)
    {
        competitors2points++;
    }
    if(competitor2bestAttempt > competitor3bestAttempt)
    {
        competitors2points++;
    }
    if(competitor3bestAttempt > competitor1bestAttempt)
    {
        competitors3points++;
    }
    if(competitor3bestAttempt > competitor2bestAttempt)
    {
        competitors3points++;
    }
    

}

void enterAttemptMin( const string& eventName) {
    cout << "Enter the result for " << competitors1 << "'s " << eventName << " attempt 1: ";
    cin >> competitor1attempt1;
            if(verifyPositiveValue(competitor1attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors1 << "'s " << eventName << " attempt 2: ";
    cin >> competitor1attempt2;
            if(verifyPositiveValue(competitor1attempt2))
            cout<<"bad input";

    cout << "Enter the result for " << competitors2 << "'s " << eventName << " attempt 2: ";
    cin >> competitor2attempt1;
            if(verifyPositiveValue(competitor2attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors2 << "'s " << eventName << " attempt 2: ";
    cin >> competitor2attempt2;
            if(verifyPositiveValue(competitor2attempt2))
            cout<<"bad input";
    cout << "Enter the result for " << competitors3 << "'s " << eventName << " attempt 2: ";
    cin >> competitor3attempt1;
            if(verifyPositiveValue(competitor3attempt1))
            cout<<"bad input";
    cout << "Enter the result for " << competitors3 << "'s " << eventName << " attempt 2: ";
    cin >> competitor3attempt2;
            if(verifyPositiveValue(competitor3attempt2))
            cout<<"bad input";
    competitor1bestAttempt = min(competitor1attempt1, competitor1attempt2);
    competitor2bestAttempt = min(competitor2attempt1, competitor2attempt2);
    competitor3bestAttempt = min(competitor3attempt1, competitor3attempt2);
    competitors1points+=1;
    competitors2points+=1;
    competitors3points+=1;
    if(competitor1bestAttempt < competitor2bestAttempt)
    {
        competitors1points++;
    }
    if(competitor1bestAttempt < competitor3bestAttempt)
    {
        competitors1points++;
    }
    if(competitor2bestAttempt < competitor1bestAttempt)
    {
        competitors2points++;
    }
    if(competitor2bestAttempt < competitor3bestAttempt)
    {
        competitors2points++;
    }
    if(competitor3bestAttempt < competitor1bestAttempt)
    {
        competitors3points++;
    }
    if(competitor3bestAttempt < competitor2bestAttempt)
    {
        competitors3points++;
    }
}

void rankCompetitors( const string& eventName) {


    cout << "\nEvent: " << eventName << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << setw(10) << "Rank" << setw(15) << "Competitor" << setw(10) << setw(10) << "Points" << endl;
    cout << "-------------------------------------------------------" << endl;
    string firstplace,secondplace,thirdplace;
    int firstscore=competitors1points,secondscore=competitors2points,thirdscore=competitors3points;
    firstplace=competitors1;
    secondplace=competitors2;
    thirdplace= competitors3;
    string hold="";
    int holdint=0;
    if(firstscore<secondscore)
    {
        hold=firstplace;
        firstplace=secondplace;
        secondplace=hold;
        holdint=firstscore;
        firstscore=secondscore;
        secondscore=holdint;
    }
    if(secondscore<thirdscore)
    {
        hold=secondplace;
        secondplace=thirdplace;
        thirdplace=hold;
        holdint=secondscore;
        secondscore=thirdscore;
        thirdscore=holdint;
    }
    if(firstscore<secondscore)
    {
        hold=firstplace;
        firstplace=secondplace;
        secondplace=hold;
        holdint=firstscore;
        firstscore=secondscore;
        secondscore=holdint;
    }
    if(secondscore<thirdscore)
    {
        hold=secondplace;
        secondplace=thirdplace;
        thirdplace=hold;
        holdint=secondscore;
        secondscore=thirdscore;
        thirdscore=holdint;
    }

    cout<<firstplace <<" is currently in first place "<<endl;
    cout<<secondplace <<" is currently in second place"<<endl;
    cout<<thirdplace <<" is currently in third place"<<endl;

}


void displayResults() {
    cout << "\nFinal Results\n";
    cout << "-------------------------------------------------------" << endl;
    cout << setw(10) << "Competitor" << setw(10) << "Points" << endl;
    cout << "-------------------------------------------------------" << endl;
    
    cout << setw(10) << competitors1 << setw(10) << competitors1points << endl;
    cout << setw(10) << competitors2 << setw(10) << competitors2points << endl;
    cout << setw(10) << competitors3 << setw(10) << competitors3points << endl;
    
}

void farm_fram_med()
{
    enterAttemptMin( "Farmers Frame Medley");
    rankCompetitors("Farmers Frame Medley");
    
}

void axle_deadlift()
{
    enterAttempt("Axle Deadlift");
    rankCompetitors("Axle Deadlift");
}

void stonethrow()
{
               
    enterAttempt("Stone Over Bar");
    rankCompetitors("Stone Over Bar");
                
}