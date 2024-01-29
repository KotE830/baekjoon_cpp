#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int t, sum = 0, n_round = round(double(n) * 3 / 20), difficulty[n];

    for (int i = 0; i < n; i++)
        cin >> difficulty[i];

    sort(difficulty, difficulty + n);

    for (int i = n_round; i < n - n_round; i++)
        sum += difficulty[i];

    cout << round(double(sum) / (n - n_round * 2));

    return 0;
}