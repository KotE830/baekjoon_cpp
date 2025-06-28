#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, index = 1;
    cin >> n;

    list<list<int>> deque;

    while (n--) {
        int t;
        cin >> t;
        list<int> node {t, index++};
        deque.push_back(node);
    }

    while (true) {
        list<int> node = deque.front();
        int i = node.front();
        deque.pop_front();
        cout << node.back() << " ";

        if (deque.empty()) {
            return 0;
        } else if (i > 0) {
            while (--i) {
                deque.push_back(deque.front());
                deque.pop_front();
            }
        } else {
            while (i++) {
                deque.push_front(deque.back());
                deque.pop_back();
            }
        }
    }
}