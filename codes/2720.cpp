#include <iostream>

using namespace std;

int main() {
    int n, coins[] = {25, 10, 5, 1};
    cin >> n;

    while (n--) {
        int change;
        cin >> change;

        for (int i = 0; i < sizeof(coins) / sizeof(*coins); i++) {
            cout << change / coins[i] << " ";
            change %= coins[i];
        }

        cout << endl;
    }

    return 0;
}