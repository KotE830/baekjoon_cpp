#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    m["Sun"] = 0;
    m["Mon"] = 1;
    m["Tue"] = 2;
    m["Wed"] = 3;
    m["Thu"] = 4;
    m["Fri"] = 5;
    m["Sat"] = 6;

    string week[8] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "Month"};

    for (int i = 0; i < sizeof(week) / sizeof(*week); i++) {
        if (m.find(week[i]) != m.end()) {
            cout << week[i] << m[week[i]] << endl;
        } else {
            cout << week[i] << endl;
        }
    }

    return 0;
}