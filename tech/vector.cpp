#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    vector<int> v1(5);
    vector<int> v2(5, 2);
    vector<int> v3(v2);

    v.push_back(7);

    v.size();



    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        
    }

    return 0;
}