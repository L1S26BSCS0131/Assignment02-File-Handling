/*
 * Name       : Usman Waheed
 * Reg No     : L1S26BSCS0131
 * Assignment : 02 - File Handling
 * Question   : Q5 - Personal Expense Tracker
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char items[100][50];
    int amounts[100];

    int count = 0;
    int choice = 0;
    int total = 0;

    ifstream inFile("expense.txt");

    if (inFile) {
        char heading[100];
        inFile.getline(heading, 100);

        while (count < 100 && inFile >> amounts[count]) {

            inFile.ignore(1, ' ');
            inFile.getline(items[count], 50);

            if (!inFile) {
                break;
            }
            count++;
        }
        inFile.close();
    }

    while (choice != 5) {
        cout << "\n===== Personal Expense Tracker by Ali Murtaza =====" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View All Expenses" << endl;
        cout << "3. Remove Expense" << endl;
        cout << "4. Total Expenses" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 100) {
                cout << "Expense list is full!" << endl;
            }
            else {
                cout << "Enter expense name: ";
                cin.ignore(1000, '\n');
                cin.getline(items[count], 50);

                cout << "Enter amount: ";
                cin >> amounts[count];

                if (amounts[count] > 0) {
                    count++;
                    cout << "Expense added successfully!" << endl;
                }
                else {
                    cout << "Invalid amount!" << endl;
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No previous expenses found!" << endl;
            }
            else {
                cout << "\n===== Previous Expenses =====" << endl;

                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". "
                        << items[i] << " - Rs. "
                        << amounts[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "No expenses to remove!" << endl;
            }
            else {
                cout << "\n===== Remove Expense =====" << endl;

                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". "
                        << items[i] << " - Rs. "
                        << amounts[i] << endl;
                }
                int remove;

                cout << "Enter expense number to remove: ";
                cin >> remove;

                if (remove >= 1 && remove <= count) {
                    for (int i = remove - 1; i < count - 1; i++) {
                        strcpy(items[i], items[i + 1]);
                        amounts[i] = amounts[i + 1];
                    }
                    count--;
                    cout << "Expense removed successfully!" << endl;
                }
                else {
                    cout << "Invalid expense number!" << endl;
                }
            }
        }
        else if (choice == 4) {
            total = 0;

            for (int i = 0; i < count; i++) {
                total += amounts[i];
            }

            cout << "Total Expenses: Rs. " << total << endl;
        }

        else if (choice == 5) {
            cout << "Exiting Expense Tracker..." << endl;
        }

        else {
            cout << "Invalid choice!" << endl;
        }

        // Save updated expenses
        if (choice >= 1 && choice <= 4) {
            ofstream outFile("expense.txt");

            if (!outFile) {
                cout << "Unable to save expenses!" << endl;
                return 1;
            }
            outFile << "EXPENSE RECORDS" << endl;
            total = 0;

            for (int i = 0; i < count; i++) {
                outFile << amounts[i] << " " << items[i] << endl;

                total += amounts[i];
            }

            outFile.close();
        }
    }
    return 0;
}