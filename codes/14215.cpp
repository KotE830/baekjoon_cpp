#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int stacks[3];
    for (int i=0;i<3;i++) {
        cin >> stacks[i];
    }
    
    sort(stacks, stacks + 3);

    if (stacks[0] + stacks[1] <= stacks[2]) {
        cout << (stacks[0] + stacks[1]) * 2 - 1;
    } else {
        cout << stacks[0] + stacks[1] + stacks[2];
    }

    return 0;
}