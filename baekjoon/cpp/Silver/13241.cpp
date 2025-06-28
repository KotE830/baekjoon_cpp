#include <iostream>

using namespace std;

int main() {
    long long int a, result;
    int b, r;

    cin >> a >> b;
    result = a * b;

    while (a % b) {
        r = a % b;
        a = b;
        b = r;
    }

    cout << result / b;

    return 0;
}