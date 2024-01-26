#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 5;         // 4 Bytes -2,147,483,648 ~ 2,147,483,647
    long long n1 = 44; // 8 Bytes -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807

    float f = 4.2;    // 4 Bytes
    double d = 12.34; // 8 Bytes

    long double ld = 12.35; // 8, 12, or 16 Bytes

    char c = 'w';
    string str = "word";

    bool b = false;

    return 0;
}