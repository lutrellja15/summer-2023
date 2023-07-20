#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
//Part 1


// User input
string value_selected;
string firstName;
string lastName;
int studentID;

double tuitionCost;



double totalAmountDue;
bool is_class_selected[12];
string class_selected[12];
int class_selected_numbers[12];
string prefix[12];
int totalcreds =0;
string scholarship_choice_value = "";

string class1_short = "Computer Science 1";
string class2_short = "Networking Fundamentals";
string class3_short = "Ethics of Computing";

string class1 = "CS        317       Computer Science 1       3";
string class2 = "ITE       305       Networking Fundamentals  2";
string class3 = "CS        310       Ethics of Computing      1";

int menu_choice, totalCreditHours = 0;
int choice;

int number_of_classes;

//start of something great
int courseNo[4] = {310,452,305,308};
string mathClass[4] = {"mat & lin alg", "intro real analysis","cal 3", "dis math"};
string infoTechClass[4] = {"data","capstone","networking fund", "network arch"};
string compSciClass[4] = {"ethic","capstone","programming","computer science 2"};

bool class_has_been_selected =false;
void displayallclasscombos()
{
    int ii = 1;
    for (int i =0;i<4;i++){
        cout<< ii <<". "<<courseNo[i]<< setw(20) << mathClass[i] <<endl;
        ii++;
    }
    for (int i =0;i<4;i++)
    {
        cout<< ii <<". "<< courseNo[i]<< setw(20) << infoTechClass[i] <<endl;
        ii++;
    }
    for (int i =0;i<4;i++){
        cout<< ii <<". "<<courseNo[i]<< setw(20) << compSciClass[i] <<endl;
        ii++;
    }
}
void SelectClasses(int& number_of_classes){

    int choice=0;
    int choice1=0;
    cout << "How many classes do you plan to register for?" << endl;
    while(number_of_classes>12 || number_of_classes<1)
    {
        cin >> number_of_classes;
    }
    for (int i = 0; i < number_of_classes; i++)
    {
        class_has_been_selected=true;
        cout<< "choose a class prefix 1,2, or 3"<<endl;
        cout<<"1. CS"<<endl;
        cout<<"2. ITE"<<endl;
        cout<<"3. MA"<<endl;
        cin>>choice;

        cout<< "choose a class number 1,2,3, or 4"<<endl;
        cout<<"1. 310"<<endl;
        cout<<"2. 452"<<endl;
        cout<<"3. 305"<<endl;
        cout<<"4. 308"<<endl;

        cin>>choice1;

        cout << endl << endl;
        if(choice==3){
            is_class_selected[i] = true;
            class_selected[i] = mathClass[choice1-1];
            class_selected_numbers[i] = courseNo[choice1-1];
            prefix[i]="MA";
        }
        else if(choice==2){
            is_class_selected[i] = true;
            class_selected[i] = infoTechClass[choice1-1];
            class_selected_numbers[i] = courseNo[choice1-1];
            prefix[i]="ITE";
        }
        else if(choice==1)
        {
            is_class_selected[i] = true;
            class_selected[i] = compSciClass[choice1-1];
            class_selected_numbers[i] = courseNo[choice1-1];
            prefix[i]="CS";
        }
    
        cout << "You selected: " << class_selected[i] << endl << endl;
    }
}

double Scholarship(string & name)
    {
    const double Academic_Scholarship_val = 500.00;
    const double Foundation_Scholarship_val = 750.00;
    int scholarship_choice;
    cout << "You selected Enter Scholarship Amount." << endl << endl;
    cout << "Did you recieve a scholarship, if so what type of scholarship did you receive?" << endl;
    cout << "1. Academic Scholarship" << endl;
    cout << "2. Foundation Scholarship" << endl;
    cout << "3. None" << endl;
    while(scholarship_choice<1 || scholarship_choice>3)
    {
        cin >> scholarship_choice; 
        if(scholarship_choice<1 || scholarship_choice>3){
            cout<<"please input a valid answer"<<endl;
        }
    }

    if (scholarship_choice == 1) {
    cout << "Academic Scholarship!" << endl;
    name = "Academic Scholarship";
    return Academic_Scholarship_val;

    }
    else if (scholarship_choice == 2) {
    cout << "Foundation Scholarship!" << endl;
    name = "Foundation Scholarship";
    return Foundation_Scholarship_val;
    }
    else{
        cout<<"No scholarship for you."<<endl;
        return 0;
    }
    cout<<name<<endl;
}

void ViewSchedule(int numofclassestaken){
    
    if (class_has_been_selected) {
        cout << " you must select a class first" << endl;
        
    }
    else{
        totalcreds=0;
        cout << "You selected: View Schedule." << endl << endl;
        cout << "Dear " << firstName << " " << lastName << " " << "(" << studentID << ")" << endl;
        cout << "Thank you for entering your information, below is your class listing the Spring 2023 semester." << endl;
        cout << endl << endl;
        cout << "           **********COURSE DETAILS**********" << endl;
        cout << std::left <<"Prefix" << setw(10) << "No." << setw(10) << "Title " << setw(30) << "Credit Hour" << endl;
        for (int i=0; i<numofclassestaken;i++)
        {
            
            int cred=3;
            if(class_selected_numbers[i]==310 && prefix[i] =="CS" )
            {
                cred =1;
            }
            if(class_selected_numbers[i]==305 && prefix[i] =="ITE" )
            {
                cred=2;
            }
            if(class_selected_numbers[i]==308 && prefix[i] =="ITE" )
            {
                cred=2;
            }
            cout<<prefix[i]<< setw(10) << class_selected_numbers[i] << setw(10) << class_selected[i]<<setw(30)<<cred<<endl;
            totalcreds+= cred;
        }
        cout<<"your total totalCreditHours is"<<totalcreds<<endl;
        cout << endl << endl;
    }
    
}

void SaveSchedule(int numofclassestaken,string filename){
    
    if (class_has_been_selected) {
        cout << " you must select a class first" << endl;
    }
    else{
        //do the printing to file
        ofstream scheduleFile(filename);
        if (scheduleFile.is_open())
        {
            scheduleFile << "Dear " << firstName << " " << lastName << " " << "(" << studentID << ")" << endl;
            scheduleFile << "Thank you for entering your information, below is your class listing the Spring 2023 semester." << endl;
            scheduleFile << endl << endl;
            scheduleFile << "           **********COURSE DETAILS**********" << endl;
            scheduleFile << "Prefix" << setw(10) << "No." << setw(10) << "Title " << setw(30) << "Credit Hour" << endl;
            for (int i=0; i<numofclassestaken;i++)
            {
                
                int cred=3;
                if(class_selected_numbers[i]==310 && prefix[i] =="CS" )
                {
                    cred =1;
                }
                if(class_selected_numbers[i]==305 && prefix[i] =="ITE" )
                {
                    cred=2;
                }
                if(class_selected_numbers[i]==308 && prefix[i] =="ITE" )
                {
                    cred=2;
                }
                scheduleFile<<prefix[i]<< setw(10) << class_selected_numbers[i] << setw(10) << class_selected[i]<<setw(30)<<cred<<endl;
                totalcreds+= cred;
            }
            scheduleFile<<"your total total Credit Hours is"<<totalcreds<<endl;
            scheduleFile << endl << endl;
            scheduleFile.close();
            cout << "Schedule written to Schedule.txt\n";
        }
    }
}

void ViewBill(int numofclassestaken,double schamount){
    // Constants
const double tuition_per_credit_hour = 263.00;
const double registration_fees = 162.50;
    if (class_has_been_selected) {
        cout << " you must select a class first" << endl;
        
    }
    else{
    int costofattend =totalcreds*tuition_per_credit_hour+registration_fees;
    costofattend=-schamount;
    ViewSchedule(numofclassestaken);
    
    cout<<"Your bill for the year is "<<costofattend<<endl;
    }
}

void SaveBill(){
    // Constants
    /*
const double tuition_per_credit_hour = 263.00;
const double registration_fees = 162.50;
    if (class1_selected == "" && class2_selected == "" && class3_selected == "") {
        cout << " you must select a class first" << endl;
        //return to menu
    }
    else
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
                scheduleFile << class1 << endl;
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
    */
}

void PrintDetails(){
    /*
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
        //cout << "Scholarship amount" << scholarshipAmount << endl;
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
            //detailsFile << "Scholarship amount: " << scholarshipAmount << endl;
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
*/
}



void menu()
{
    int numofclassestaken=0;
double scharlarshipamount=0;
string scharlarshipname="";

cout << "            ***************WELCOME TO THE SEMESTER**************" << endl;
cout << endl;

cout << "Please enter your first name, followed by your last name, and your student ID " << endl;
cout << "Do not include the A or leading 0s in your ID" << endl;
cout << endl;
cin >> firstName >> lastName >> studentID;
cout << endl;



while (menu_choice != 8)
{

    cout << "Please select what you would like to do next: " << endl;
    cout << "1. Select Classes" << endl;
    cout << "2. Select Scholarship Amount" << endl;
    cout << "3. View Class Schedule" << endl;
    cout << "4. Save Class Schedule" << endl;
    cout << "5. View Bill" << endl;
    cout << "6. Save Bill" << endl;
    cout << "7. Print Details" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice (1-8): " << endl;
    cin >> menu_choice;
    cout << endl;

    switch (menu_choice) {

    case 1: //Select Classes
        SelectClasses(numofclassestaken);
        break;

    case 2: //Enter Scholarship Amount
        scharlarshipamount = Scholarship(scharlarshipname );
        break;

    case 3: // View Schedule
        ViewSchedule(numofclassestaken);
        break;
    case 4:
        SaveSchedule(numofclassestaken,"Schedule.txt");
        break;
    case 5:
        ViewBill(numofclassestaken,scharlarshipamount);
        break;
    case 6:
        SaveBill();
        break;

    case 7:
        // View Details
        PrintDetails();
        break;

    case 8: //Exit

        break;

    }
}
}


int main() {
menu();

return 0;

}
