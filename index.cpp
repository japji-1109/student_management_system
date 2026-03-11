#include <iostream>
#include <fstream>
using namespace std;

// Class to store student information
class Student
{
private:
    string name;
    float marks;
    float income;
    int scholarship;

public:
    // Function to enter student details
    void getDetails()
    {
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Family Income: ";
        cin >> income;

        checkEligibility();
        saveToFile();
    }

    // Function to calculate scholarship eligibility
    void checkEligibility()
    {
        if (income <= 200000)
        {
            if (marks >= 90)
                scholarship = 50000;
            else if (marks >= 85)
                scholarship = 30000;
            else if (marks >= 80)
                scholarship = 20000;
            else
                scholarship = 0;
        }
        else
        {
            scholarship = 0;
        }
    }

    // Function to save data into file
    void saveToFile()
    {
        ofstream file("students.txt", ios::app);

        file << name << endl;
        file << marks << endl;
        file << income << endl;
        file << scholarship << endl;

        file.close();

        cout << "\nStudent record saved successfully!\n";
    }

    // Function to display all records from file
    void displayRecords()
    {
        ifstream file("students.txt");

        string name;
        float marks, income;
        int scholarship;

        cout << "\n---- All Student Records ----\n";

        while (file >> name >> marks >> income >> scholarship)
        {
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
            cout << "Income: " << income << endl;

            if (scholarship > 0)
                cout << "Scholarship: ₹" << scholarship << endl;
            else
                cout << "Scholarship: Not Eligible\n";

            cout << "---------------------\n";
        }

        file.close();
    }

    // Function to search student by name
    void searchStudent()
    {
        ifstream file("students.txt");

        string searchName;
        string name;
        float marks, income;
        int scholarship;
        bool found = false;

        cout << "Enter student name to search: ";
        cin >> searchName;

        while (file >> name >> marks >> income >> scholarship)
        {
            if (name == searchName)
            {
                cout << "\nStudent Found\n";
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;
                cout << "Income: " << income << endl;

                if (scholarship > 0)
                    cout << "Scholarship: ₹" << scholarship << endl;
                else
                    cout << "Scholarship: Not Eligible\n";

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Student not found.\n";
        }

        file.close();
    }
};

int main()
{

    Student s;
    int choice;

    do
    {
        cout << "\n---- Scholarship Management System ----\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid Input!! Please enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice)
        {

        case 1:
            s.getDetails();
            break;

        case 2:
            s.displayRecords();
            break;

        case 3:
            s.searchStudent();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
