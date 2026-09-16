#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int* values = new int[n];

    // Read three integers
    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> values[i];
    }

    // Display integers
    for (int i = 0; i < n; i++) {
        cout << "Integer " << i + 1 << ": " << values[i] << " ";
    }

    cout << endl;

    // Release memory and reset pointer
    delete[] values;
    values = nullptr;

    return 0;
}