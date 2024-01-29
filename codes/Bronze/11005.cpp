#include <iostream>

using namespace std;

int main() {
    long long n, b, index = 1;
    cin >> n >> b;

    while (n >= index) {
        index *= b;
    }

    while (index > 1) {
        index /= b;
        char c = n / index;

        if (c > 9) {
            c += 55;
        } else {
            c += 48;
        }

        cout << c;
        n %= index;
    }

    return 0;
}