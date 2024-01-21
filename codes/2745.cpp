#include <cmath>
#include <iostream>

using namespace std;

int main() {
    string n;
    int b, result = 0;

    cin >> n >> b;
    int len = n.size();

    for (int i = 0; i < len; i++) {
        if (isdigit(n[i])) {
            result += (n[i] - 48) * pow(b, len - i - 1);
        } else {
            result += (n[i] - 55) * pow(b, len - i - 1);
        }
    }

    cout << result;

    return 0;
}