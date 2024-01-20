#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> result;

    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            if (j >= result.size()) {
                result.push_back({str[j]});
            } else {
                result[j] += str[j];
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    return 0;
}