#include <cmath>
#include <iostream>

using namespace std;

void cantor(int n) {
    if (n == 0) {
        cout << "-";
    } else if (n == -1) {
        cout << " ";
    } else {
        cantor(n - 1);
        for (int i = 0; i < pow(3, n - 1); i++) {
            cantor(-1);
        }
        cantor(n - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        cantor(n);
        cout << "\n";
    }
    return 0;
}