/*
 * Name       : Usman Waheed
 * Reg No     : L1S26BSCS0131
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking report
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream inFile("parking.txt");

    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }
    ofstream receipt("receipt.txt");

    if (!receipt) {
        cout << "Unable to create receipt.txt" << endl;
        return 1;
    }

    char date[30], header[100];
    inFile.getline(date, 30);
    inFile.getline(header, 100);

    char plate[20], type[10], inTime[10], outTime[10];
    char longestPlate[20];
    int cars = 0, bikes = 0;
    int totalCollected = 0;
    int longestStay = 0;
    int count = 0;

    cout << "Parking report for " << date << endl;
    receipt << "Parking report for " << date << endl;

    while (inFile >> plate >> type >> inTime >> outTime) {
        int inHour = (inTime[0] - '0') * 10 + (inTime[1] - '0');
        int inMin = (inTime[3] - '0') * 10 + (inTime[4] - '0');

        int outHour = (outTime[0] - '0') * 10 + (outTime[1] - '0');
        int outMin = (outTime[3] - '0') * 10 + (outTime[4] - '0');

        int start = inHour * 60 + inMin;
        int finish = outHour * 60 + outMin;
        int duration = finish - start;
        int hours = duration / 60;
        int minutes = duration % 60;
        int fee = 0;

        if (strcmp(type, "C") == 0) {
            fee = ((duration + 59) / 60) * 100;
            cars++;
        }
        else if (strcmp(type, "B") == 0) {
            fee = ((duration + 59) / 60) * 40;
            bikes++;
        }

        cout << plate << " ";
        receipt << plate << " ";

        if (strcmp(type, "C") == 0) {
            cout << "Car ";
            receipt << "Car ";
        }
        else if (strcmp(type, "B") == 0) {
            cout << "Bike ";
            receipt << "Bike ";
        }

        cout << hours << " h " << minutes << " min Fee: " << fee << endl;
        receipt << hours << " h " << minutes << " min Fee: " << fee << endl;

        totalCollected += fee;
        count++;
        if (duration > longestStay) {
            longestStay = duration;
            strcpy(longestPlate, plate);
        }
    }
    cout << "Vehicles: " << count << endl;
    receipt << "Vehicles: " << count << endl;

    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    receipt << "Cars: " << cars << " Bikes: " << bikes << endl;

    cout << "Total collected: " << totalCollected << endl;
    receipt << "Total collected: " << totalCollected << endl;

    cout << "Longest stay: " << longestPlate << " (" << longestStay / 60 << " h " << longestStay % 60 << " min)" << endl;

    receipt << "Longest stay: " << longestPlate << " (" << longestStay / 60 << " h " << longestStay % 60 << " min)" << endl;
    cout << endl;
    cout << "Data saved in receipt.txt !!" << endl;

    inFile.close();
    receipt.close();

    return 0;
}