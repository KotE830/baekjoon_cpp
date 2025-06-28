#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

static bool comp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;

    if ((a.first).length() != (b.first).length())
        return (a.first).length() > (b.first).length();

    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> words;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() >= m) {
            if (words[s]) {
                words[s]++;
            } else {
                words[s] = 1;
            }
        }
    }

    vector<pair<string, int>> v(words.begin(), words.end());
    sort(v.begin(), v.end(), comp);

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->first << "\n";
    }

    return 0;
}