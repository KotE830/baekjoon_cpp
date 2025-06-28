#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // on coordinate plane
    for (int i = 0; i < n * 2 - 1; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            if (i >= -j + n - 1 && i <= j + n - 1 && i <= -j + n * 3 - 3 && i >= j - n + 1) {
                cout << "*";
            } else if (j >= n) {
                break;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}