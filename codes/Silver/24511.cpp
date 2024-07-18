#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, k;
    cin >> n;

    deque<int> dq, isQueueStack;

    for (i = 0; i < n; i++) {
        cin >> k;
        isQueueStack.push_back(k);
    }

    for (i = 0; i < n; i++) {
        cin >> k;
        if (!isQueueStack.front()) {
            dq.push_front(k);
        }
        isQueueStack.pop_front();
    }

    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> k;
        dq.push_back(k);
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}