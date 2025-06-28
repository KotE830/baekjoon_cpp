#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    set<string, greater<string>> m;
    int n;
    
    cin >> n;
    while (n--) {
        string name, word;
        cin >> name >> word;

        if (word == "enter") {
            m.insert(name);
        } else {
            m.erase(name);
        }
    }

    for (auto iter : m) {
        cout << iter << "\n";
    }

    return 0;
}