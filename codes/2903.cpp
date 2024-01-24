#include <iostream>

using namespace std;

int main() {
    long long n, iter = 2;
    cin >> n;

    for (int i = 0; i < n; i++) {
        iter = iter * 2 - 1;
    }
    cout << iter * iter;

    return 0;
}