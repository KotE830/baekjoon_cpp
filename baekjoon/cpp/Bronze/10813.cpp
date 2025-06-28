#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    for (int t = 0; t < n; t++) {
        arr[t] = t + 1;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        swap(arr[--i], arr[--j]);
    }

    for (int t = 0; t < n; t++) {
        cout << arr[t] << " ";
    }

    return 0;
}