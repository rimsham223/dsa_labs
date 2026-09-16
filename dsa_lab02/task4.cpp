#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of students and subjects: ";
    cin >> rows >> cols;

    // Validate rows and columns before allocation
    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Invalid input. Rows and columns must be between 1 and 10." << endl;
        return 1;
    }

    // Allocate array of row pointers
    int** marks = new int*[rows];

    // Allocate columns for each row
    for (int i = 0; i < rows; i++) {
        marks[i] = new int[cols];
    }

    // Read and validate marks
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter marks for student " << r + 1
                 << ", subject " << c + 1 << ": ";

            cin >> *(*(marks + r) + c);

            if (*(*(marks + r) + c) < 0 ||
                *(*(marks + r) + c) > 100) {

                cout << "Invalid input. Marks must be between 0 and 100." << endl;

                // Delete all allocated rows
                for (int k = 0; k < rows; k++) {
                    delete[] marks[k];
                }

                delete[] marks;
                marks = nullptr;

                return 1;
            }
        }
    }

    // Display matrix
    cout << "\nMarks Matrix:\n";

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << " ";
        }
        cout << endl;
    }

    // Calculate totals and find highest total
    int highestTotal = -1;
    int highestStudent = 0;

    for (int r = 0; r < rows; r++) {
        int total = 0;

        for (int c = 0; c < cols; c++) {
            total += *(*(marks + r) + c);
        }

        cout << "Total for student " << r + 1 << ": "
             << total << endl;

        // > ensures the first student is kept if totals tie
        if (total > highestTotal) {
            highestTotal = total;
            highestStudent = r;
        }
    }

    cout << "\nStudent with highest total: "
         << highestStudent + 1 << endl;

    cout << "Highest total: " << highestTotal << endl;

    // Delete all rows
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];
    }

    // Delete row-pointer array
    delete[] marks;

    // Set pointer to nullptr
    marks = nullptr;

    return 0;
}