/***************
Baylee Caldwell
00106404
June 7, 2023
Project 1
****************/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Constants
    const double tuition_per_credit_hour = 263.00;
    const double registration_fees = 162.50;

    // User input
    string firstName;
    string lastName;
    int studentID;
    double scholarshipAmount;

    // Get user information
    cout << "Enter your first name, followed by your last name, and your student ID " << endl;
    cout << "Do not include the A or leading 0s in your ID" << endl;
    cin >> firstName >> lastName >> studentID;
    cout << endl << endl;
    

    // Confirmation statement
    cout << "Dear " << firstName << " " << lastName << " " << "("<<studentID<<")" << endl;
    cout << "Thank you for entering your information, below is your class listing and bill for the Spring 2023 semester." << endl;
    cout << endl << endl;

    // Course Details
    cout << "**********COURSE DETAILS**********"<< endl;
    cout << "Prefix" << setw(10) << "No." << setw(10) << "Title " << setw(20) << "Credit Hour" << endl;
    cout << "************************************************" << endl;
    cout << "CS" << setw(10) << "310" << setw(10) << "Ethics of Computing" << setw(20) << "1" << endl;

    cout << endl << endl;

   return 0;
}




 /*   
    << fixed << setprecision(2) << scholarshipAmount << "\n";
    
    // Course Details
    cout << "***************COURSE DETAILS***************";
    cout << "Name: " << firstName << " " << lastName << "\n";
    cout << "Student ID: " << studentID << "\n";
    cout << "Scholarship Amount: $" << fixed << setprecision(2) << scholarshipAmount << "\n";

    // Class schedule
    cout << "\nClass Schedule:\n";
    
    cout << setw(10) << left << "Course" << setw(15) << right << "Credit Hours\n";
   
    cout << setw(10) << left << "CS 310" << setw(15) << right << "3" << endl;
    cout << setw(10) << left << "ITE 308" << setw(15) << right << "2" << endl;
    cout << setw(10) << left << "PHYS 301" << setw(15) << right << "4" << endl;
    

    // Billing statement
    int totalCreditHours = 3 + 2 + 4;
    double tuitionCost = tuition_per_credit_hour * totalCreditHours;
    double totalAmountDue = tuitionCost + registration_fees - scholarshipAmount;

    cout << "\nBilling Statement:\n";
    cout << "-------------------\n";
    cout << fixed << setprecision(2);
    cout << "Tuition" << tuition_per_credit_hour << endl;
    cout << "Fees" << registration_fees << endl;
    cout << "Scholarship" << scholarshipAmount << endl;
    
    cout << "Total Due: $" << totalAmountDue << endl;
*/


 