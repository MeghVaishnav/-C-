#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    // Ordered from largest to smallest
    int values[] =   {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5, 4,  1};
    string roman[] = {"M",  "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string result = "";

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += roman[i];
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Roman numeral: " << intToRoman(n) << endl;

    return 0;
}

