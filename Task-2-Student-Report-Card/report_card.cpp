#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to calculate total marks
int calculateTotal(int marks[], int subjects) {
    int total = 0;

    for (int i = 0; i < subjects; i++) {
        total += marks[i];
    }

    return total;
}

// Function to calculate percentage
double calculatePercentage(int total, int subjects) {
    return (static_cast<double>(total) / (subjects * 100)) * 100;
}

// Function to calculate grade
char calculateGrade(double percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage >= 50)
        return 'E';
    else
        return 'F';
}

// Function to display report card
void displayReport(string name, int subjects, int total, double percentage, char grade) {
    cout << "\n====================================" << endl;
    cout << "          STUDENT REPORT CARD       " << endl;
    cout << "====================================" << endl;

    cout << "Student Name : " << name << endl;
    cout << "Subjects     : " << subjects << endl;

    cout << "------------------------------------" << endl;

    cout << "Total Marks  : " << total << " / " << subjects * 100 << endl;
    cout << fixed << setprecision(2);
    cout << "Percentage   : " << percentage << "%" << endl;
    cout << "Grade        : " << grade << endl;

    cout << "====================================" << endl;
}

int main() {
    string name;
    int subjects;
    int marks[5];

    cout << "===== Student Report Card Generator =====" << endl;

    cout << "\nEnter student name: ";
    getline(cin, name);

    // Validate number of subjects
    do {
        cout << "Enter number of subjects (3-5): ";
        cin >> subjects;

        if (subjects < 3 || subjects > 5) {
            cout << "Please enter a number between 3 and 5." << endl;
        }

    } while (subjects < 3 || subjects > 5);

    // Input marks
    for (int i = 0; i < subjects; i++) {
        do {
            cout << "Enter marks for Subject " << i + 1 << " (0-100): ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid marks! Please enter marks between 0 and 100." << endl;
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    // Calculate results using functions
    int total = calculateTotal(marks, subjects);
    double percentage = calculatePercentage(total, subjects);
    char grade = calculateGrade(percentage);

    // Display final report
    displayReport(name, subjects, total, percentage, grade);

    return 0;
}
