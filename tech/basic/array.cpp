#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7};
    int arr1[4];

    int size = (sizeof(arr) / sizeof(*arr));
    sort(arr1, arr + 4); // algorithm

    return 0;
}