#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(100, 0);
    vector<vector<int>> paper(100, v);

    int n, area = 0;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        for (int i=y; i<y+10; i++) {
            for (int j=x;j<x+10;j++) {
                if (!paper[i][j]) {
                    paper[i][j] = 1;
                    area += 1;
                }
            }
        }
    }
    cout << area;

    return 0;
}