#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string str = "Hello world!";    // Hello world!
    string str1("Hello world!1");   // Hello world!1
    string str2(str);               // Hello world!

    str.at(6);        // w
    str[6];           // w
    str.front();      // H
    str.back();       // !

    str.length();     // 12
    str.size();       // 12
    str.capacity();   // 15  Allocated memory size

    str.resize(7);          // Hello w
    str.resize(13, 'a');    // Hello waaaaaa


    string hello = "Hello";
    string space = " ";
    string world = "world";

    hello.append(world);        // Helloworld
    hello.append(1, '!');       // Helloworld!
    hello.insert(5, space);     // Hello world!
    hello.replace(5, 3, "|");   // Hello|rld!
    hello.erase(5, 3);          // Hellod!


    string digit = "1234";
    string alpha = "abcd";


    cout << isdigit(digit[0]) << endl;
    cout << isalpha(alpha[0]) << endl;

    return 0;
}