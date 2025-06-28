#include <cmath>
#include <iostream>

using namespace std;

bool IsPrimeNumber(long long int n) {
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;

        if (n <= 2) {
            cout << 2 << "\n";
            continue;
        } else if (n % 2 == 0) {
            n++;
        }

        while (!IsPrimeNumber(n)) {
            n += 2;
        }

        cout << n << "\n";
    }

    return 0;
}