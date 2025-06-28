#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> dance{"ChongChong"};
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (dance.find(s1) != dance.end()) {
            dance.insert(s2);
        } else if (dance.find(s2) != dance.end()) {
            dance.insert(s1);
        }
    }

    cout << dance.size();

    return 0;
}