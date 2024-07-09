#include <iostream>
#include <string>
using namespace std;

// Function to convert numbers 1-9 to words
string numberToWords(int num) {
    switch (num) {
        case 1: return "ONE";
        case 2: return "TWO";
        case 3: return "THREE";
        case 4: return "FOUR";
        case 5: return "FIVE";
        case 6: return "SIX";
        case 7: return "SEVEN";
        case 8: return "EIGHT";
        case 9: return "NINE";
        default: return "";
    }
}

int main() {
    int A, B;

    // Input two positive integers
    cout << "Enter two positive integers A and B: ";
    cin >> A >> B;

    // Ensure A is less than or equal to B
    if (A > B) {
        cout << "Invalid range. A should be less than or equal to B." << endl;
        return 1;
    }

    // Print numbers between A and B (inclusive) in words or "EVEN"/"ODD"
    for (int i = A; i <= B; ++i) {
        if (i >= 1 && i <= 9) {
            cout << numberToWords(i) << endl;
        } else if (i > 9) {
            if (i % 2 == 0) {
                cout << "EVEN" << endl;
            } else {
                cout << "ODD" << endl;
            }
        }
    }

    return 0;
}

