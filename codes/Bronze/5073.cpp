#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    while (true) {
        int lines[3];
        for (int i = 0; i < 3; i++) {
            cin >> lines[i];
        }

        if (lines[0] == 0)
            return 0;

        sort(lines, lines + 3);
        string result;

        if (lines[0] == lines[2]) {
            result = "Equilateral";
        } else if (lines[0] + lines[1] <= lines[2]) {
            result = "Invalid";
        } else if (lines[0] == lines[1] || lines[1] == lines[2] || lines[0] == lines[2]) {
            result = "Isosceles";
        } else {
            result = "Scalene";
        }

        cout << result << endl;
    }
}