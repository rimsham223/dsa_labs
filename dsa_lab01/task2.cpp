#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    // First loop: input values
    cout<< "Enter 5 elements of array: "<< endl;
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // Second loop: calculate total
    for (int i = 0; i < 5; i++) {
        total = total + numbers[i];
    }

    cout << "Total = " << total << endl;

    return 0;
}