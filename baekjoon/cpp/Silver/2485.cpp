#include <algorithm>
#include <iostream>

using namespace std;

int GetGcd(int a, int b) {
    if (a % b)
        return GetGcd(b, a % b);
    return b;
}

int main() {
    int n, count = 0, min_dis;
    cin >> n;

    int trees[n];
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int distance = trees[i + 1] - trees[i];

        if (i == 0) {
            min_dis = distance;
        } else {
            min_dis = GetGcd(distance, min_dis);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        count += (trees[i + 1] - trees[i]) / min_dis - 1;
    }

    cout << count;

    return 0;
}