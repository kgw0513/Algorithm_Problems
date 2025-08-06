#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << min(a - 1, b) + min(b + 1, a);
}