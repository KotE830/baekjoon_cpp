#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool IsPrimeNumber(int n) {
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int t, i = 3;
    vector<int> primes(1, 2);
    cin >> t;

    while (t--) {
        int n, count = 0;
        cin >> n;

        while (i < n) {
            if (IsPrimeNumber(i))
                primes.push_back(i);
            i += 2;
        }

        auto left = primes.begin();
        auto right = primes.end() - 1;

        while (*left <= *right) {
            if (*left + *right < n) {
                left++;
            } else if (*left + *right > n) {
                right--;
            } else {
                left++;
                right--;
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}