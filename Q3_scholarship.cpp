/*
 * Name       : Usman Waheed
 * Reg No     : L1S26BSCS0131
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char filename[100];
    cout << "Enter the file name: ";
    cin.getline(filename, 100);

    ifstream inFile(filename);

    if (!inFile) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    ofstream outFile("scholarship.txt");

    if (!outFile) {
        cout << "Unable to create schlorship.txt!" << endl;
        return 1;
    }

    int totalStudents;
    inFile >> totalStudents;
    inFile.ignore(100, '\n');

    char name[100];
    char topStudent[100] = "";
    double cgpa;
    double totalCGPA = 0;
    double highestCGPA = 0;
    double averageCGPA = 0;

    int eligible = 0;
    int count = 0;

    while (count < totalStudents &&
        inFile.getline(name, 100, ',')) {

        if (!(inFile >> cgpa)) {
            break;
        }
        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        outFile << "[" << name << "] CGPA: " << cgpa << endl;

        totalCGPA += cgpa;
        count++;

        if (cgpa >= 3.5) {
            eligible++;
        }

        if (count == 1 || cgpa > highestCGPA) {
            highestCGPA = cgpa;
            strcpy(topStudent, name);
        }
    }

    if (count > 0) {
        averageCGPA = totalCGPA / count;
    }
    cout << "Students: " << count << endl;
    outFile << "Students: " << count << endl;
    cout << "Average CGPA: " << averageCGPA << endl;
    outFile << "Average CGPA: " << averageCGPA << endl;

    cout << "Eligible for scholarship: " << eligible << endl;

    outFile << "Eligible for scholarship: " << eligible << endl;

    if (count > 0) {
        cout << "Top student: " << topStudent << " (" << highestCGPA << ")" << endl;

        outFile << "Top student: " << topStudent << " (" << highestCGPA << ")" << endl;
    }
    inFile.close();
    outFile.close();
    cout << endl;
    cout << "Data saved in schlorship.txt !!" << endl;

    return 0;
}