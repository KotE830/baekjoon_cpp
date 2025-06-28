#include <iostream>
#include <vector>

using namespace std;

int main() {
    int test_case;
	int T = 10;

    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;

        vector<int> arr(N), result(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            result[i] = arr[i];
        }

        for (int i = 2; i < N-2; i++) {
            result[i] = max(0, result[i] - max(max(arr[i-2], arr[i-1]), max(arr[i+1], arr[i+2])));
        }

        int sum = 0;
        for (int i = 2; i < N-2; i++) {
            sum += result[i];
        }

        cout << "#" << test_case << " " << sum << endl;
    }

    return 0;
}