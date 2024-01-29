#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string result;

    if (a + b + c != 180) {
        result = "Error";
    } else if (a == b && a == 60) {
        result = "Equilateral";
    } else if (a == b || b == c || c == a) {
        result = "Isosceles";
    } else {
        result = "Scalene";
    }

    cout << result;

    return 0;
}