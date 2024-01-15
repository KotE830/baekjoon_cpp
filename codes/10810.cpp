#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int baskets[n] = {0,};
    for (int t = 0; t < m; t++) {
        int i, j, k;
        cin >> i >> j >> k;

        while (j - i + 1) {
            baskets[i - 1] = k;
            i++;
        }
    }

    for (int t = 0; t < n; t++) {
        cout << baskets[t] << " ";
    }

    return 0;
}