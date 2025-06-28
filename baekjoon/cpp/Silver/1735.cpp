#include <iostream>

using namespace std;

int GetGcd(int a, int b) {
    if (a % b)
        return GetGcd(b, a % b);
    return b;
}

int main() {
    int num[2], den[2], n, d, gcd;

    for (int i = 0; i < 2; i++) {
        cin >> num[i] >> den[i];
    }

    if (den[0] > den[1]) {
        gcd = GetGcd(den[0], den[1]);
    } else {
        gcd = GetGcd(den[1], den[0]);
    }

    n = num[0] * den[1] / gcd + num[1] * den[0] / gcd;
    d = den[0] * den[1] / gcd;

    gcd = GetGcd(d, n);
    cout << n / gcd << " " << d / gcd;

    return 0;
}