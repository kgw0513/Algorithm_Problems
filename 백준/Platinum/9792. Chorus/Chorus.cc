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

int setting(string a) {
    vector<int>arr = { 0 };
    int p = 0;
    for (int i = 1; i < a.size(); i++) {
        while (p >= 0 && a[i] != a[p]) {
            p = arr[p] - 1;
        }
        arr.push_back(++p);
    }
    int max_len = 0;
    for (int& h : arr) {
        max_len = max(max_len, h);
    }
    return max_len;
}
void cal(vector<string>& arr) {
    for (string& a:arr) {
        //cout << a << "->";
        intint max_len = { 0,0 };
        for (int i = 0; i < a.size(); i++) {
            int h = setting(a.substr(i));
            if (max_len.fi < h) {
                max_len = { h,i };
            }
        }
        if (max_len.fi == 0)a.clear();
        else a = a.substr(max_len.se, max_len.fi);
        //cout << a << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<string>arr(n);
    for (string& w : arr) {
        cin >> w;
    }
    cal(arr);
    cin >> m;
    string w;
    while (m--) {
        cin >> w;
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            bool bFind = false;
            for (int j = 0; j <= int(arr[i].size()) - int(w.size()); j++) {
                bool bMatch = true;
                for (int k = 0; k < w.size(); k++) {
                    if (arr[i][j + k] != w[k]) {
                        bMatch = false;
                        break;
                    }
                }
                if (bMatch) {
                    bFind = true;
                    break;
                }
            }
            if (bFind)ans.push_back(i);
        }

        //cout << "답 : ";
        if (ans.empty()) {
            cout << "-1\n";
            continue;
        }

        cout << ans[0];
        for (int j = 1; j < ans.size(); j++) {
            cout << " " << ans[j];
        }
        cout << "\n";
    }
}