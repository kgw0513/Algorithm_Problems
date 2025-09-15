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

struct cmp {
    bool operator()(ll2_ll& a, ll2_ll& b) {
        return a.se > b.se;
    }
};
//{{행성 번호1,행성 번호2},거리차}
priority_queue<ll2_ll, vector<ll2_ll>,cmp>MST;

ll Union[100002];

ll Find(ll n) {
    if (Union[n] == n)return n;
    return Union[n] = Find(Union[n]);
}

bool cmp_xyz(ll_ll& a, ll_ll& b) {
    return a.fi < b.fi;
}

//{값,행성 번호}
vector<ll_ll>x_array;
vector<ll_ll>y_array;
vector<ll_ll>z_array;

vector<ll2_ll>inputs;

void connect_MST(vector<ll_ll>& xyz_array) {
    //for (int i = 0; i < xyz_array.size(); i++) {
    //    cout << xyz_array[i].fi << "(" << xyz_array[i].se << ") , ";
    //}
    //cout << "\n";
    for (int i = 0; i + 1 < xyz_array.size(); i++) {
        int num1 = xyz_array[i].se;
        int num2 = xyz_array[i + 1].se;
        ll min_dist = min({ abs(inputs[num1].fi.fi - inputs[num2].fi.fi),
            abs(inputs[num1].fi.se - inputs[num2].fi.se),
            abs(inputs[num1].se - inputs[num2].se) });
        MST.push({ {num1,num2},min_dist });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b, c;
    inputs.push_back({ {-1,-1},-1 });
    cin >> n;
    for (int num = 1; num <= n; num++) {
        Union[num] = num;
        cin >> a >> b >> c;
        inputs.push_back({ {a,b},c });
        x_array.push_back({ a,num });
        y_array.push_back({ b,num });
        z_array.push_back({ c,num });
    }
    sort(x_array.begin(), x_array.end(), cmp_xyz);
    sort(y_array.begin(), y_array.end(), cmp_xyz);
    sort(z_array.begin(), z_array.end(), cmp_xyz);

    connect_MST(x_array);
    connect_MST(y_array);
    connect_MST(z_array);

    ll ans = 0;
    while (MST.size()) {
        a = MST.top().fi.fi;
        b = MST.top().fi.se;
        c = MST.top().se;
        MST.pop();
        //cout << a << "<->" << b << "(" << c << ")\n";

        a = Find(a);
        b = Find(b);
        if (a == b)continue;
        if (a > b)swap(a, b);
        Union[b] = a;
        ans += c;
    }
    cout << ans;
}