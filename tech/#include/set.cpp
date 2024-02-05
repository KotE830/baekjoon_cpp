#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> s;
    set<pair<int, string>> s1;

    s.clear();
    s.empty();
    s.insert("Hello");
    s.insert("World");
    s.insert("!");

    set<string>::iterator iter, start, end;
    for(iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }

    s.erase("Hello");
    
    s.size();
    s.max_size();

    return 0;
}