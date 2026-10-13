#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students (1-10): ";
    cin >> n;

    // Validate n
    if (n < 1 || n > 10) {
        cout << "Invalid size." << endl;
        return 1;
    }

    int* marks = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> *(marks + i);
    }

    int* newMarks = new int[n + 1];

    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    cout << "Enter new student's mark: ";
    cin >> *(newMarks + n);

    delete[] marks;

    marks = newMarks;

    n++;

    // Display all values
    cout << "\nAll marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}