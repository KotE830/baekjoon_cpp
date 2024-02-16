#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    list<int> deque;

    cin >> n;

    while (n--) {
        int command, x;
        cin >> command;

        switch (command) {
        case 1:
            cin >> x;
            deque.push_front(x);
            break;
        case 2:
            cin >> x;
            deque.push_back(x);
            break;
        case 3:
            if (!deque.empty()) {
                cout << deque.front();
                deque.pop_front();
            } else {
                cout << -1;
            }
            cout << "\n";
            break;
        case 4:
            if (!deque.empty()) {
                cout << deque.back();
                deque.pop_back();
            } else {
                cout << -1;
            }
            cout << "\n";
            break;
        case 5:
            cout << deque.size() << "\n";
            break;
        case 6:
            if (deque.empty()) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << "\n";
            break;
        case 7:
            if (!deque.empty()) {
                cout << deque.front();
            } else {
                cout << -1;
            }
            cout << "\n";
            break;
        case 8:
            if (!deque.empty()) {
                cout << deque.back();
            } else {
                cout << -1;
            }
            cout << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}