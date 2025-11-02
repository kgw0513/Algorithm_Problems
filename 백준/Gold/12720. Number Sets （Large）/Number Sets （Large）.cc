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

int Union[1000002];
int Find(int n) {
    if (Union[n] == n)return n;
    return Union[n] = Find(Union[n]);
}

vector<ll>sosu;
bool isnt_sosu[1000002] = { 1,1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 2; i <= 1000000; i++) {
        if (isnt_sosu[i])continue;
        sosu.push_back(i);
        for (ll j = i * i; j <= 1000000; j+=i) {
            isnt_sosu[j] = true;
        }
    }
    int t;
    cin >> t;
    for(int test=1;test<=t;test++){
        ll a, b, p;
        cin >> a >> b >> p;
        for (ll i = 1; i <= (b - a + 1); i++) {
            Union[i] = i;
        }
        
        for (ll now_num : sosu) {
            if (now_num < p)continue;
            ll s = (a / now_num) * now_num;
            if (s < a)s += now_num;
            while (s+now_num <= b) {
                //cout << s << "(" << now_num << ")" << "중.\n";
                ll e = s + now_num;
                ll s_p = s - a + 1;
                ll e_p = e - a + 1;

                s_p = Find(s_p);
                e_p = Find(e_p);

                if (s_p != e_p) {
                    //cout << s << "-" << e << "만남!\n";
                    if (s_p > e_p)swap(s_p, e_p);
                    Union[s_p] = e_p;
                }
                s += now_num;
            }
        }

        unordered_set<ll>arr;
        for (ll i = a; i <= b; i++) {
            ll p = i - a + 1;
            arr.insert(Find(p));
        }

        cout << "Case #" << test << ": " << arr.size() << "\n";
    }
}