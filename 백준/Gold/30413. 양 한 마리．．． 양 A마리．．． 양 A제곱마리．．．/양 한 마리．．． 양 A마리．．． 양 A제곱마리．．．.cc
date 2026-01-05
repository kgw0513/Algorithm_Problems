#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;

const int INF = 2147483647;
const int nINF = 10000000;

typedef long long ll;
typedef pair<int, int> intint;
typedef pair<int, ll> intlong;
typedef pair<intint, int> int2_int;
typedef pair<int, char> int_char;

const ll mod = 1000000007;

ll pow_ab(ll a,const ll n) {
    //cout << a << "," << n << "?ㅼ뼱 ??\n";
    if (n == 1)return a;
    ll h = pow_ab(a,n / 2);
    h *= h;
    h%=mod;
    if (n % 2 == 1)h *= a;
    //cout << "a:" << a << " / n:" << n << " / h:" << h % mod << "\n";
    return h % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin >> a >> b;
    if (a == 1) {
        cout << b % mod;
        return 0;
    }
    ll h = pow_ab(a,b) - 1;
    if (h < 0)h += mod;
    ll h_2 = pow_ab(a - 1, 1000000005);
    //cout << h << "," << h_2 << "愿怨?\n";
    h *= h_2;
    h %= mod;
    cout << h;
}