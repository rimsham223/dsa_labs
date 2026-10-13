#include <iostream>
using namespace std;

int main() {
    int numbers[6];

    cout << "Enter 6 integers: ";

    for (int i = 0; i < 6; i++) {
        cin >> numbers[i];
    }

    // Reverse the array
    for (int i = 0; i < 3; i++) {
        int temp = numbers[i];

        numbers[i] = numbers[5 - i];

        numbers[5 - i] = temp;
    }

    cout << "Reversed array: ";

    for (int i = 0; i < 6; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}