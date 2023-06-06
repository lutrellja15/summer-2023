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

    cout << "***************WELCOME TO THE SEMESTER**************" << endl;
    cout << endl;
    
    // Get user information
    cout << "Please enter your first name, followed by your last name, and your student ID " << endl;
    cout << "Do not include the A or leading 0s in your ID" << endl;
    cout << endl;
    cin >> firstName >> lastName >> studentID;
    cout << endl << endl;
    
    // Scholarship Information
    cout << "Did you recieve a scholarship, if so please enter that amount or enter 0." << endl;
    cin >> scholarshipAmount;

    // Confirmation statement
    cout << endl << endl;
    cout << "Dear " << firstName << " " << lastName << " " << "("<<studentID<<")" << endl;
    cout << "Thank you for entering your information, below is your class listing and bill for the Spring 2023 semester." << endl;
    cout << endl << endl;

    // Course Details
    cout << "           **********COURSE DETAILS**********" <<endl;
    cout << "Prefix" << setw(10) << "No." << setw(15) << "Title " << setw(30) << "Credit Hour" << endl;
    cout << "**************************************************************" << endl;
    cout << "CS" << setw(14) << "310" << setw(28) << "Ethics of Computing" << setw(12) << "1" << endl;
    cout << "CS" << setw(14) << "317" << setw(27) << "Computer Science 1" << setw(13) << "3" << endl;
    cout << "ITE" << setw(13) << "305" << setw(32) << "Networking Fundamentals" << setw(8) << "2" << endl;
    cout << "ITE" << setw(13) << "306" << setw(28) << "Local Area Networks" << setw(12) << "2" << endl;
    cout << endl << endl;
    
    int totalCreditHours = 1 + 3 + 2 + 2;
    cout << "Total Enrollement Hours:" << setw(32) << totalCreditHours << endl;
    cout << endl << endl;
    
    double tuitionCost = tuition_per_credit_hour * totalCreditHours;
    double totalAmountDue = tuitionCost + registration_fees - scholarshipAmount;
    cout << fixed << setprecision(2);
    cout << " **********BILLING INFORMATION**********" << endl;
    cout << setw(11) << "Tuition" << setw(29) << tuitionCost << endl;
    cout << setw(11) << "Fees" << setw(29) << registration_fees << endl;
    cout << setw(8) << "Scholarship" << setw(29) << scholarshipAmount << endl;
    cout << endl;
    cout << "Total Due:" << setw(30) << totalAmountDue << endl;
    

   return 0;
}


// current classes are : CS 310 - Professional Ethis of Computing - 1 hour
//                      CS 317 - Computer Science 1 - 3 hours
//                      ITE 305 - Networking Fundamentals - 2 hours
//                      ITE 306 - Local Area Networks - 2 hours

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
 
