// 홀수만 더하기

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int result = 0;
        for (int j = 0; j < 10; j++) {
            int n;
            cin >> n;

            result += n % 2 != 0 ? n : 0;
        }
        cout << "#" << i + 1 << " " << result << endl;
    }

    return 0;
}