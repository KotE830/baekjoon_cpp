#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (1) {
        int n, sum = 0;
        vector<int> factors;
        cin >> n;

        if (n == -1)
            return 0;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                sum += i;
            }
        }

        if (n == sum) {
            cout << n << " = ";
            vector<int>::iterator iter;
            for (iter = factors.begin(); iter != factors.end(); iter++) {
                if (iter != factors.begin())
                    cout << " + ";
                cout << *iter;
            }
        } else {
            cout << n << " is NOT perfect.";
        }

        cout << endl;
    }  
}