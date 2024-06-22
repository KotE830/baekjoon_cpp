#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(7);

    pq.size();

    while (!pq.empty()) {   // 7 5 3
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}