#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers {1, 2, 3, 4, 5};
    list<int> numbers2 {7, 8, 9};

    numbers.front();
    numbers.back();
    for (int n : numbers) {
      cout << n << "\n";
    }

    numbers.push_front(0);
    numbers.push_back(6);

    numbers.pop_front();
    numbers.pop_back();

    numbers.reverse();
    numbers.sort();
    numbers.unique(); // Remove consecutive duplicate elements
    numbers.empty();
    numbers.size();
    numbers.clear();
    numbers.merge(numbers2);

    return 0;
}