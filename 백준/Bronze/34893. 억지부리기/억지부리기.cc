#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll h = (a - c) / 3;
    cout << (a >= c ? min({ b,a - 2 * h,c + h }) : min({ a,b,c }));
}