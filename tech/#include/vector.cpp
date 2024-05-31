#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    vector<int> v1(5);
    vector<int> v2(5, 2);
    vector<int> v3(v2);

    for (int i = 1; i < 6; i++) {
        v.push_back(i);
    }

    cout << v.front(); // 1
    cout << v.back();  // 5

    int sum = accumulate(v.begin(), v.end(), 0); // 15, 0 : initialize sum

    remove(v.begin(), v.end(), 3);   // [1, 2, 4, 5], return v.end() iterator (index 5)
    v.erase(v.begin());              // [2, 4, 5], return 2 iterator (index 0)
    v.erase(v.begin() + 1, v.end()); // [2]
    v.size();

    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
    }

    sort(v.begin(), v.end());

    v.clear();

    return 0;
}