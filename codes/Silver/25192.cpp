#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, result = 0;
    cin >> n;

    set<string> s;
    for (i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "ENTER") {
            result += s.size();
            s.clear();
        } else {
            s.insert(str);
        }
    }

    cout << result + s.size();

    return 0;
}