#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n = 5, sum = 0, arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);

    cout << sum / n << endl
         << arr[n / 2];

    return 0;
}