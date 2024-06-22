#include <climits>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int level;
    vector<int> path;
    int bound;
    int length;
    vector<bool> visited;

    bool operator<(const node v) const {
        return this->bound > v.bound;
    }
};

int bound(node v, const vector<vector<int>> &W) {
    int i, j, n = W.size();
    int result = v.length, minLen;

    for (i = 1; i < n; i++) {
        if (!v.visited[i] || i == v.path.back()) {
            minLen = INT_MAX;
            for (j = 0; j < n; j++) {
                if (!v.visited[j] && i != j)
                    minLen = min(minLen, W[i][j]);
            }
            result += minLen;
        }
    }

    return result;
}

void put(node &v, int i, int weight) {
    v.path.push_back(i);
    v.length += weight;
    v.visited[i] = true;
}

void branchAndBound(int n, const vector<vector<int>> W, vector<int> &optTour, int &minLength, int &count) {
    priority_queue<node> pq;
    node u, v;
    int i;

    // initialize
    v.level = 0;
    v.path.push_back(0);
    v.bound = 0;
    v.length = 0;
    for (i = 0; i < n; i++)
        v.visited.push_back(false);
    pq.push(v);

    while (!pq.empty()) {
        count++;
        v = pq.top(); // dequeue(PQ, v)
        pq.pop();

        if (v.bound < minLength) { // v is promising
            u.level = v.level + 1;
            for (i = 1; i < n; i++) {
                if (!v.visited[i]) {
                    u.path = v.path;
                    u.visited = v.visited;
                    u.length = v.length;
                    put(u, i, W[u.path.back()][i]);

                    if (u.level == n - 2) {
                        // result
                        int j = 0;
                        while (++j) {
                            if (!u.visited[j])
                                break;
                        }
                        put(u, j, W[u.path.back()][j]);
                        put(u, 0, W[j][0]);

                        if (u.length < minLength) {
                            minLength = u.length;
                            optTour = u.path;
                            optTour.push_back(0);
                        }
                    } else {
                        u.bound = bound(u, W);
                        if (u.bound < minLength)
                            pq.push(u);
                    }
                }
            }
        }
    }
}

void printResult(const vector<vector<int>> W) {
    // initialize
    vector<int> optTour;
    int i, count = 0, minLength = INT_MAX;
    clock_t start, finish;
    double duration;

    // branch and bound
    start = clock();
    branchAndBound(W.size(), W, optTour, minLength, count);
    finish = clock();

    // print result
    cout << "minLength : " << minLength << "\noptTour : ";
    for (i = 0; i <= W.size(); i++)
        cout << optTour[i] + 1 << " ";
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\ncount : " << count << "\n"
         << duration << "s\n\n";
}

int main() {
    const vector<vector<int>> W1 = {
        {0, 14, 4, 10, 20},
        {14, 0, 7, 8, 7},
        {4, 5, 0, 7, 16},
        {11, 7, 9, 0, 2},
        {18, 7, 17, 4, 0}};

    const vector<vector<int>> W2 = {
        {0, 12, 10, 19, 8, 15, 14, 22, 17, 24},
        {20, 0, 18, 23, 25, 30, 5, 14, 21, 9},
        {11, 13, 0, 27, 16, 19, 8, 17, 12, 30},
        {6, 21, 7, 0, 20, 25, 11, 13, 19, 27},
        {9, 8, 12, 15, 0, 17, 23, 24, 13, 29},
        {14, 9, 11, 16, 18, 0, 22, 26, 19, 20},
        {7, 5, 20, 12, 11, 10, 0, 15, 21, 28},
        {10, 14, 9, 8, 7, 18, 20, 0, 6, 17},
        {11, 17, 15, 14, 9, 12, 25, 21, 0, 23},
        {13, 15, 18, 16, 10, 14, 19, 22, 11, 0}};

    const vector<vector<int>> W3 = {
        {0, 14, 9, 12, 18, 23, 15, 17, 19, 11},
        {21, 0, 11, 13, 24, 20, 19, 22, 16, 14},
        {15, 10, 0, 17, 22, 18, 11, 13, 9, 12},
        {12, 14, 13, 0, 15, 21, 24, 20, 18, 25},
        {18, 19, 15, 14, 0, 8, 7, 12, 11, 16},
        {20, 22, 19, 16, 10, 0, 15, 21, 17, 14},
        {14, 12, 20, 18, 17, 11, 0, 9, 10, 15},
        {9, 11, 8, 13, 12, 19, 16, 0, 14, 18},
        {11, 15, 7, 14, 8, 13, 21, 10, 0, 22},
        {16, 20, 18, 15, 14, 10, 12, 17, 19, 0}};

    const vector<vector<int>> W4 = {
        {0, 13, 15, 8, 10, 19, 14, 16, 20, 25},
        {17, 0, 18, 12, 21, 14, 20, 23, 19, 15},
        {10, 7, 0, 9, 16, 22, 12, 15, 8, 14},
        {13, 14, 18, 0, 11, 9, 8, 10, 17, 16},
        {12, 20, 14, 15, 0, 7, 6, 13, 18, 22},
        {18, 11, 20, 16, 10, 0, 9, 15, 14, 12},
        {9, 15, 11, 18, 8, 14, 0, 19, 12, 13},
        {14, 13, 10, 11, 12, 18, 20, 0, 8, 16},
        {12, 19, 14, 10, 17, 21, 9, 11, 0, 20},
        {15, 22, 18, 12, 20, 15, 13, 17, 16, 0}};

    const vector<vector<int>> W5 = {
        {0, 18, 11, 14, 13, 15, 9, 16, 19, 20},
        {15, 0, 9, 12, 16, 18, 13, 20, 14, 22},
        {10, 12, 0, 8, 17, 14, 15, 11, 13, 24},
        {11, 9, 13, 0, 15, 17, 10, 22, 19, 16},
        {16, 19, 14, 12, 0, 8, 11, 9, 17, 21},
        {13, 17, 15, 10, 14, 0, 9, 12, 16, 19},
        {12, 10, 20, 11, 8, 18, 0, 17, 15, 14},
        {14, 11, 9, 18, 16, 21, 13, 0, 10, 15},
        {16, 14, 7, 13, 9, 12, 18, 11, 0, 22},
        {20, 16, 15, 12, 10, 14, 19, 18, 17, 0}};

    const vector<vector<int>> W6 = {
        {0, 17, 13, 15, 18, 22, 11, 14, 19, 20},
        {10, 0, 14, 12, 16, 19, 13, 18, 21, 25},
        {9, 11, 0, 17, 14, 18, 16, 20, 12, 15},
        {12, 14, 9, 0, 15, 21, 13, 16, 17, 22},
        {13, 18, 14, 12, 0, 10, 8, 9, 20, 24},
        {15, 13, 17, 14, 8, 0, 12, 19, 22, 10},
        {11, 10, 15, 16, 17, 14, 0, 21, 13, 18},
        {12, 19, 14, 9, 11, 18, 20, 0, 7, 16},
        {14, 21, 12, 18, 15, 11, 19, 14, 0, 20},
        {18, 16, 17, 13, 20, 10, 14, 15, 22, 0}};

    const vector<vector<int>> W7 = {
        {0, 78, 32, 94, 49, 54, 76, 84, 61, 93, 5, 26, 34, 65, 79, 44, 56, 23, 77, 39},
        {75, 0, 24, 34, 93, 12, 89, 46, 58, 96, 67, 38, 55, 73, 20, 87, 61, 57, 38, 19},
        {18, 41, 0, 76, 81, 98, 42, 17, 55, 62, 33, 73, 69, 90, 91, 82, 35, 45, 21, 29},
        {11, 98, 37, 0, 27, 13, 65, 31, 26, 39, 55, 67, 61, 79, 91, 25, 34, 45, 83, 72},
        {39, 53, 28, 55, 0, 81, 52, 71, 88, 62, 14, 94, 85, 72, 30, 64, 47, 57, 50, 32},
        {64, 91, 88, 28, 59, 0, 77, 62, 32, 73, 47, 19, 75, 95, 83, 67, 48, 71, 25, 96},
        {37, 54, 61, 93, 77, 85, 0, 91, 11, 68, 24, 84, 73, 55, 52, 59, 32, 43, 16, 89},
        {67, 89, 27, 41, 56, 25, 74, 0, 12, 44, 95, 73, 36, 82, 59, 71, 53, 29, 68, 21},
        {13, 77, 43, 59, 38, 29, 82, 65, 0, 12, 96, 50, 41, 88, 94, 30, 75, 72, 15, 61},
        {35, 12, 84, 73, 25, 92, 17, 21, 56, 0, 53, 34, 96, 64, 86, 78, 82, 68, 71, 85},
        {95, 83, 13, 66, 42, 79, 52, 61, 26, 37, 0, 18, 23, 29, 14, 54, 61, 77, 83, 89},
        {51, 34, 47, 84, 53, 27, 68, 55, 21, 42, 13, 0, 75, 39, 81, 72, 49, 33, 64, 16},
        {79, 61, 19, 93, 14, 66, 24, 55, 61, 72, 15, 47, 0, 83, 48, 17, 92, 51, 89, 77},
        {45, 22, 33, 59, 11, 77, 91, 35, 28, 14, 82, 69, 38, 0, 86, 47, 91, 19, 50, 28},
        {82, 53, 16, 41, 39, 94, 64, 50, 33, 61, 87, 45, 72, 84, 0, 36, 18, 57, 63, 79},
        {25, 74, 31, 15, 22, 56, 39, 72, 50, 85, 64, 92, 37, 18, 45, 0, 28, 46, 55, 34},
        {62, 93, 81, 49, 14, 83, 61, 27, 56, 42, 53, 77, 48, 19, 95, 68, 0, 35, 66, 13},
        {34, 15, 63, 82, 11, 92, 72, 54, 95, 49, 27, 44, 16, 93, 71, 64, 38, 0, 69, 24},
        {28, 71, 15, 37, 68, 64, 95, 13, 82, 31, 27, 92, 45, 74, 59, 41, 15, 62, 0, 17},
        {18, 29, 54, 88, 36, 25, 91, 27, 68, 72, 47, 39, 81, 55, 53, 13, 35, 64, 79, 0}};

    printResult(W1);
    printResult(W2);
    printResult(W3);
    printResult(W4);
    printResult(W5);
    printResult(W6);
    printResult(W7);

    cout << "Press Enter to quit...";
    cin.ignore();

    return 0;
}