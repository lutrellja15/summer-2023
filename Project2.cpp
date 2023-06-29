/***************
Baylee Caldwell
00106404
June 7, 2023
Project 2
****************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
    //Part 1
    // Constants
    const double tuition_per_credit_hour = 263.00;
    const double registration_fees = 162.50;

    // User input
    string value_selected;
    string firstName;
    string lastName;
    int studentID;
    double scholarshipAmount;
    double tuitionCost;

    //Number of Credit Hours
    const int class3_credit = 1;
    const int class2_credit = 2;
    const int class1_credit = 3;

    double totalAmountDue;
    string class1_selected = "";
    string class2_selected = "";
    string class3_selected = "";

    string scholarship_choice_value = "";

    string class1_short = "Computer Science 1";
    string class2_short = "Networking Fundamentals";
    string class3_short = "Ethics of Computing";

    string class1 = "CS        317       Computer Science 1       3";
    string class2 = "ITE       305       Networking Fundamentals  2";
    string class3 = "CS        310       Ethics of Computing      1";

    cout << "            ***************WELCOME TO THE SEMESTER**************" << endl;
    cout << endl;

    // Get user information

    cout << "Please enter your first name, followed by your last name, and your student ID " << endl;
    cout << "Do not include the A or leading 0s in your ID" << endl;
    cout << endl;
    cin >> firstName >> lastName >> studentID;
    cout << endl;

    int menu_choice, totalCreditHours = 0;
    int choice, choice2, choice3, choice4, choice5;
    int scholarship_choice;
    int number_of_classes;

    while (menu_choice != 6)
    {

        cout << "Please select what you would like to do next: " << endl;
        cout << "1. Select Classes" << endl;
        cout << "2. Enter Scholarship Amount" << endl;
        cout << "3. View Class Schedule" << endl;
        cout << "4. View Bill" << endl;
        cout << "5. View Details" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): " << endl;
        cin >> menu_choice;
        cout << endl;

        switch (menu_choice) {

        case 1: //Select Classes

            // cout << "You selected: Select Classes" << endl << endl;
            cout << "How many classes do you plan to register for? (Please enter 1, 2, or 3)" << endl;
            cin >> number_of_classes;
            cout << endl << endl;
            cout << "Choose a class from the following options: " << endl;
            cout << "1. CS 317 - Computer Science 1" << endl;
            cout << "2. ITE 305 - Networking Fundamentals" << endl;
            cout << "3. CS 310 - Ethics of Computing" << endl << endl;

            cout << "Please choose " << number_of_classes << " classes: ";
            for (int i = 0; i < number_of_classes; i++)
            {
                cin >> choice;
                if (choice == 1) {
                    totalCreditHours += 3;
                    class1_selected = class1;
                    value_selected = class1_short;
                }
                else if (choice == 2) {
                    totalCreditHours += 2;
                    class2_selected = class2;
                    value_selected = class2_short;
                }
                else if (choice == 3) {
                    totalCreditHours += 1;
                    class3_selected = class3;
                    value_selected = class3_short;
                }
                else {
                    cout << "Invalid Choice." << endl;

                }
                cout << "You selected: " << value_selected << endl << endl;
            }
            break;

        case 2: //Enter Scholarship Amount
            cout << "You selected Enter Scholarship Amount." << endl << endl;
            cout << "Did you recieve a scholarship, if so what type of scholarship did you receive? (1 or 2)" << endl;
            cout << "1. Academic Scholarship" << endl;
            cout << "2. Foundation Scholarship" << endl;
            cin >> scholarship_choice;

            if (scholarship_choice == 1) {
                cout << "Academic Scholarship" << endl;
                scholarship_choice_value = "Academic Scholarship";

            }
            else if (scholarship_choice == 2) {
                cout << "Foundation Scholarship" << endl;
                scholarship_choice_value = "Foundation Scholarship";

            }

            else {
                cout << "Invalid choice given, please select 1 or 2: " << endl;
                cin >> scholarship_choice;

            }

            cout << "Please enter the amount of your scholarship: " << endl;
            cin >> scholarshipAmount;
            cout << endl << endl;
            break;

        case 3: // View Schedule
            if (class1_selected == "" && class2_selected == "" && class3_selected == "") {
                cout << " you must select a class first" << endl;
                break;
            }
            cout << "You selected View Schedule." << endl << endl;
            cout << "Would you like to:" << endl;
            cout << "1. View the schedule on the screen" << endl;
            cout << "2. Print the file" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Dear " << firstName << " " << lastName << " " << "(" << studentID << ")" << endl;
                cout << "Thank you for entering your information, below is your class listing the Spring 2023 semester." << endl;
                cout << endl << endl;
                cout << "           **********COURSE DETAILS**********" << endl;
                cout << "Prefix" << setw(10) << "No." << setw(10) << "Title " << setw(30) << "Credit Hour" << endl;

                if (class1_selected == class1)
                    cout << class1 << endl;
                if (class2_selected == class2)
                    cout << class2 << endl;
                if (class3_selected == class3)
                    cout << class3 << endl;
                cout << endl << endl;

            }
            if (choice == 2)
            {
                //do the printing to file
                ofstream scheduleFile("Schedule.txt");
                if (scheduleFile.is_open())
                {
                    scheduleFile << "Dear " << firstName << " " << lastName << " " << "(" << studentID << ")" << endl;
                    scheduleFile << "Thank you for entering your information, below is your class listing the Spring 2023 semester." << endl;
                    scheduleFile << endl << endl;
                    scheduleFile << "           **********COURSE DETAILS**********" << endl;
                    scheduleFile << "Prefix" << setw(10) << "No." << setw(10) << "Title " << setw(30) << "Credit Hour" << endl;
                    if (class1_selected == class1)
                        scheduleFile << class1;
                    if (class2_selected == class2)
                        scheduleFile << class2 << endl;
                    if (class3_selected == class3)
                        scheduleFile << class3 << endl;


                    scheduleFile.close();
                    cout << "Schedule written to Schedule.txt\n";
                }
                else
                {
                    cout << "Failed to write to file.\n";
                }

            }

            break;
        case 4:
            cout << "You selected View Bill." << endl << endl;
            cout << "Would you like to:" << endl;
            cout << "1. View the bill on the screen" << endl;
            cout << "2. Print the file" << endl;
            cin >> choice;

            tuitionCost = tuition_per_credit_hour * totalCreditHours;
            totalAmountDue = tuitionCost + registration_fees - scholarshipAmount;
            cout << fixed << setprecision(2);

            if (choice == 1) {
                cout << " **********BILLING INFORMATION**********" << endl;
                cout << fixed << setprecision(2);
                cout << setw(11) << "Tuition" << setw(29) << tuitionCost << endl;
                cout << setw(11) << "Fees" << setw(29) << registration_fees << endl;
                cout << setw(8) << "Scholarship" << setw(29) << scholarshipAmount << endl;
                cout << endl;
                cout << "Total Due:" << setw(30) << totalAmountDue << endl;
            }
            else if (choice == 2) {
                ofstream outputFile("Bill.txt");

                if (outputFile.is_open()) {
                    outputFile << " **********BILLING INFORMATION**********" << endl;
                    outputFile << fixed << setprecision(2);
                    outputFile << setw(11) << "Tuition" << setw(29) << tuitionCost << endl;
                    outputFile << setw(11) << "Fees" << setw(29) << registration_fees << endl;
                    outputFile << setw(8) << "Scholarship" << setw(29) << scholarshipAmount << endl;
                    outputFile << endl;
                    outputFile << "Total Due:" << setw(30) << totalAmountDue << endl;
                    outputFile.close();
                    cout << "Bill written to Bill.txt successfully." << endl;
                }
                else {
                    cout << "Unable to open the file Bill.txt. Failed to write the bill." << endl;
                }
            }

            break;



        case 5:
            // View Details
            cout << "Would you like to:" << endl;
            cout << "1. View the details on the screen" << endl;
            cout << "2. Print the file" << endl;

            cin >> choice;

            if (choice == 1) {
                cout << "\nStudent Details:" << endl;
                cout << "*****************" << endl;
                cout << "Name: " << firstName << " " << lastName << endl;
                cout << "Student ID: " << studentID << endl;
                cout << "Number of Classes: " << number_of_classes << endl;
                if (class1_selected == class1)
                    cout << class1 << endl;
                if (class2_selected == class2)
                    cout << class2 << endl;
                if (class3_selected == class3)
                    cout << class3 << endl;
                cout << endl << endl;
                cout << "Scholarship Type: " << scholarship_choice_value << endl;
                cout << "Scholarship amount" << scholarshipAmount << endl;
                cout << "Total Amount Due for Spring 2023 Semester: $" << totalAmountDue << endl;
            }
            else if (choice == 2) {
                ofstream detailsFile("Details.txt");

                if (detailsFile.is_open()) {
                    detailsFile << fixed << setprecision(2);
                    detailsFile << "\nStudent Details:" << endl;
                    detailsFile << "***************" << endl;
                    detailsFile << "Name: " << firstName << " " << lastName << endl;
                    detailsFile << "Student ID: " << studentID << endl;
                    detailsFile << "Number of Classes: " << number_of_classes << endl;
                    if (class1_selected == class1)
                        cout << class1 << endl;
                    if (class2_selected == class2)
                        cout << class2 << endl;
                    if (class3_selected == class3)
                        cout << class3 << endl;
                    detailsFile << "Scholarship Type: " << scholarship_choice_value << endl;
                    detailsFile << "Scholarship amount: " << scholarshipAmount << endl;
                    detailsFile << "Total Amount Due for Spring 2023 Semester: $" << totalAmountDue << endl;

                    detailsFile.close();

                    cout << "Details written to Details.txt successfully." << endl;
                }
                else {
                    cout << "Unable to open the file Details.txt. Failed to write the details." << endl;
                }
            }
            else {
                cout << "Invalid choice. Please select 1 or 2." << endl;
            }

            break;

        case 6: //Exit

            break;

        }
    }
    return 0;

}