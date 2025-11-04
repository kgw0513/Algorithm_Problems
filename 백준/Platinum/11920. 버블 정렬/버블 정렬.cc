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

map<ll, ll>val2num;
map<ll, ll>num2val;

ll n, k;
ll fenwick[500002];

void add_fenwick(int p,ll plus) {
    while (p <= n) {
        fenwick[p] += plus;
        p += (p & -p);
    }
}

ll get_fenwick(int p) { //1부터 p까지 범위의 갯수
    ll sum = 0;
    while (p > 0) {
        sum += fenwick[p];
        p -= (p & -p);
    }
    return sum;
}

ll bubble_swap_count(vector<ll>&inputs,int limit) {
    priority_queue<ll, vector<ll>, greater<ll>>arr; //진짜 혹시 모르는데 우선순위큐 시간복잡도 터지면 set으로 ㄱㄱ
    fill(fenwick, fenwick + n + 1, 0); // 펜윅 초기화.

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ll(arr.size()) - get_fenwick(inputs[i]);
        add_fenwick(inputs[i], 1);
        arr.push(inputs[i]);
        while (arr.size() >= limit) {
            ll h = arr.top();
            arr.pop();
            add_fenwick(h, -1);
        }
    }

    return sum;
}

vector<ll> setting_bubble_sort(vector<ll>&inputs,int limit) {
    priority_queue<ll, vector<ll>, greater<ll>>arr; //진짜 혹시 모르는데 우선순위큐 시간복잡도 터지면 set으로 ㄱㄱ
    vector<ll>outputs;

    for (int i = 0; i < n; i++) {
        arr.push(inputs[i]);
        while (arr.size() >= limit) {
            ll h = arr.top();
            arr.pop();
            outputs.push_back(h);
        }
    }
    while (arr.size()) {
        ll h = arr.top();
        arr.pop();
        outputs.push_back(h);
    }
    return outputs;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w;
    cin >> n >> k;
    vector<ll>arr;
    vector<ll>brr;
    for (int i = 0; i < n; i++) {
        cin >> w;
        arr.push_back(w);
        brr.push_back(w);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        val2num[arr[i]] = i + 1;
        num2val[i + 1] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        brr[i] = val2num[brr[i]];
    }

    brr = setting_bubble_sort(brr, k+1);

    for (int i = 0; i < n; i++) {
        cout << num2val[brr[i]] << (i + 1 != n ? " " : "");
    }
    return 0;
}