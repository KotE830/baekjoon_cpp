#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> dq;

    for (int i = 1; i < 6; i++) {
        dq.push_back(i);
    }

    cout << dq.front();
    cout << dq.back();

    dq.push_front(10);
    dq.push_back(20);

    dq.pop_front();
    dq.pop_back();

    deque<int>::iterator iter;
    for (iter = dq.begin(); iter != dq.end(); iter++) {
      cout << *iter << " ";
    }
}