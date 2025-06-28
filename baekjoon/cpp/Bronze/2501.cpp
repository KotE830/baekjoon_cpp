#include <iostream>

using namespace std;

int main() {
    int n, k, i;
    cin >> n >> k;

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) k--;
        if (!k) break;
    }

    if (k == 0) cout << i;
    else if (k == 1) cout << n;
    else cout << 0;

    return 0;
}