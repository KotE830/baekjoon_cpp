#include <iostream>
#include <map>

using namespace std;

int main() {
    double gpa = 0, grades = 0;

    map<string, double> m;
    m["A+"] = 4.5;
    m["A0"] = 4.0;
    m["B+"] = 3.5;
    m["B0"] = 3.0;
    m["C+"] = 2.5;
    m["C0"] = 2.0;
    m["D+"] = 1.5;
    m["D0"] = 1.0;
    m["F"] = 0;

    for (int i = 0; i < 20; i++) {
        string subject, credit;
        double grade;
        cin >> subject >> grade >> credit;

        if (m.find(credit) != m.end()) {
            gpa += grade * m[credit];
            grades += grade;
        } else {
            continue;
        }
    }

    cout.precision(7);
    cout << gpa / grades;

    return 0;
}