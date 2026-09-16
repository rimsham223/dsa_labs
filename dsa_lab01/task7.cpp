#include <iostream>
using namespace std;

int main() {
    int numbers[10];

    cout << "Enter 10 integers: ";

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    int count = 0;

    for (int i = 0; i < 10; i++) {

        bool alreadyExists = false;

        // Check whether numbers[i] already exists
        // among the unique values
        for (int j = 0; j < count; j++) {
            if (numbers[j] == numbers[i]) {
                alreadyExists = true;
                break;
            }
        }

        // If value is new, move it to position count
        if (!alreadyExists) {
            numbers[count] = numbers[i];
            count++;
        }
    }

    cout << "Unique values: ";

    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    cout << "Count: " << count << endl;

    return 0;
}