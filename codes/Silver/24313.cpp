#include <iostream>

using namespace std;

int main() {
    int a1, a0, c, n;
    cin >> a1 >> a0 >> c >> n;

    if ((c - a1) * n >= a0 && c >= a1)
        cout << 1;
    else
        cout << 0;

    return 0;
}