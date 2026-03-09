#include <iostream>
#include <fstream>
using namespace std;

class Student{
private:
    float marks;
    float income;
    int scholarship;
    string name;

public:

    void getDetails(){
        cin.ignore();

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter the marks: ";
        cin >> marks;

        cout << "Enter the income: ";
        cin >> income;

        cout << "Student Details saved successfully!!";
    }

    void checkEligibility(){
        if(income <= 200000){
            if(marks >= 90){
                scholarship = 50000;
            }
            else if(marks >= 85){
                scholarship = 30000;
            }
            else if(marks >= 80){
                scholarship = 20000;
            }
            else{
                scholarship = 0;
            }
        }else{
            scholarship = 0;
        }
    }

    void saveToFile(){
        ofstream file("scholarship.txt", ios:: app);

        file << "Name: " << name << endl;
        file << "Marks: " << marks << endl;
        file << "Income: ₹" << income << endl;

        if(scholarship > 0){
            file << "Scholarship: ₹" << scholarship << endl;
        }
        else{
            file << "Scholarship: Not Eligibile" << endl;
        }
        file << "-----------------------------" << endl; // separator
        file << endl;

        file.close();
    }

    void displayScholarship(){
        if(scholarship > 0){
            cout << "\nScholarship is approved." << endl;
            cout << "Amount: ₹" << scholarship << endl;
        }
        else{
            cout << "\nStudent is not eligible for scholarship." << endl;
        }
    }
};


int main(){
    Student s;
    int choice;

    do{
        cout << "\n---- Student Scholarship Management System ----\n";
        cout << "1. Enter Student Details\n";
        cout << "2. Check Eligibility\n";
        cout << "3. View Scholarship\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                s.getDetails();
                break;
            case 2:
                s.checkEligibility();
                s.saveToFile();
                cout << "Eligibility Checked Successfully!\n";
                break;
            case 3:
                s.displayScholarship();
                break;
            case 4:
                cout << "Exiting Program.....\n";
                break;
            default:
                cout << "Invalid Input!\n";
        }
    }while (choice != 4);

    return 0;
}