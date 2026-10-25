/*
 * Name       : Usman Waheed
 * Reg No     : L1S26BSCS0131
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("stock1.txt");
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt");
    if (!reorder) {
        cout << "Unable to create in reorder.txt" << endl;
        return 1;
    }

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    double total = 0;
    inFile.ignore(100, '\n');
    while (count < 10 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}