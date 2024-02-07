#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> stack;
    
    cin >> n;

    while (n--) {
        int command;
        cin >> command;

        switch (command) {
        case 1:
            int x;
            cin >> x;
            stack.push_back(x);
            break;
        case 2:
            if (stack.empty()) {
                cout << -1;
            } else {
                cout << stack.back();
                stack.pop_back();
            }
            cout << "\n";
            break;
        case 3:
            cout << stack.size() << "\n";
            break;
        case 4:
            if (stack.empty()) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << "\n";
            break;
        case 5:
            if (stack.empty()) {
                cout << -1;
            } else {
                cout << stack.back();
            }
            cout << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}