#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base Class
class Hostel {
protected:
    string hostelName;

public:
    Hostel() {
        hostelName = "CDGI Hostel";
    }
};

// Student Class
class Student : public Hostel {
    int rollNo;
    string name;
    int roomNo;

public:
    void registerStudent() {
        ofstream file("students.txt", ios::app);
        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Room No: ";
        cin >> roomNo;

        file << rollNo << " " << name << " " << roomNo << endl;
        file.close();

        cout << "\nStudent Registered Successfully!\n";
    }

    void viewStudents() {
        ifstream file("students.txt");
        cout << "\n--- Student Records ---\n";
        while (file >> rollNo >> name >> roomNo) {
            cout << "Roll No: " << rollNo
                 << " | Name: " << name
                 << " | Room No: " << roomNo << endl;
        }
        file.close();
    }
};

// Complaint Class
class Complaint {
    int roomNo;
    string issue;

public:
    void registerComplaint() {
        ofstream file("complaints.txt", ios::app);
        cout << "\nEnter Room No: ";
        cin >> roomNo;
        cout << "Enter Complaint: ";
        cin.ignore();
        getline(cin, issue);

        file << roomNo << " " << issue << endl;
        file.close();

        cout << "\nComplaint Registered Successfully!\n";
    }

    void viewComplaints() {
        ifstream file("complaints.txt");
        cout << "\n--- Complaints List ---\n";
        while (file >> roomNo >> issue) {
            cout << "Room No: " << roomNo
                 << " | Issue: " << issue << endl;
        }
        file.close();
    }
};

// Main Function
int main() {
    Student s;
    Complaint c;
    int choice;

    do {
        cout << "\n===== SMART HOSTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Register Complaint\n";
        cout << "4. View Complaints\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.registerStudent();
            break;
        case 2:
            s.viewStudents();
            break;
        case 3:
            c.registerComplaint();
            break;
        case 4:
            c.viewComplaints();
            break;
        case 5:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}

