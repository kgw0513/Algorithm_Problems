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
#include <utility>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;
/*
rope c++
#include <ext/rope>
using namespace __gnu_cxx;
*/

/*
pbds c++ set전용
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset을 쓰고 싶으면 위의 코드에서 마지막 줄만 아래 코드로 변경.(대신 erase가 정상작동 되지 않는다.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

이외에 범위를 늘리고 싶으면 타입변경하면 된다.
ex. int->ll, less_equal<ll>
*/

constexpr double PI = 3.1415926535;
constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<double, double> dd;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<ll_ll, ll>ll2_ll;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;

bool visit[46342] = { 1,1, };
vector<ll>sosu;
//2 3 5 7 11
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 2; i <= 46340; i++) {
        if (visit[i])continue;
        for (ll j = i * i; j <= 46340; j += i) {
            visit[j] = true;
        }
    }

    for (ll i = 2; i <= 46340; i++) {
        if (visit[i])continue;
        sosu.push_back(i);
    }
    ll n;
    while (1) {
        cin >> n;
        if (n == 0)break;
        if (n <= 2) {
            cout << "No such base\n";
            continue;
        }
        if (n == 3) {
            cout << "4\n";
            continue;
        }
        n -= 3;
        map<ll, ll>arr;
        for (ll& h : sosu) {
            while (n % h == 0) {
                arr[h]++;
                n /= h;
            }
        }

        //cout << arr[2] << "개.\n";
        if (arr[2] >= 2) {
            cout << "4\n";
            continue;
        }
        if (arr[5] >= 1) {
            cout << "5\n";
            continue;
        }
        if (arr[2] >= 1 && arr[3]>=1) {
            cout << "6\n";
            continue;
        }
        if (arr[7] >= 1) {
            cout << "7\n";
            continue;
        }
        if (arr[3] >= 2) {
            cout << "9\n";
            continue;
        }
        bool bFind = false;
        for (int i = 4; i < sosu.size(); i++) {
            if (arr[sosu[i]] >= 1) {
                cout << sosu[i] << "\n";
                bFind = true;
                break;
            }
        }
        if (!bFind) {
            if (n >= 4)cout << n << "\n";
            else cout << "No such base\n";
        }
    }
}