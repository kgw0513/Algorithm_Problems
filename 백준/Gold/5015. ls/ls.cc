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
constexpr unsigned long long MOD1 = 1000000007;
constexpr unsigned long long MOD2 = 1000000009;
constexpr unsigned long long MOD3 = 998244353;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p, w;
    bool first_star=false, last_star = false;
    cin >> p;
    deque<string>p_str;
    string h = "";
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '*') {
            if(h!="")p_str.push_back(h);
            h = "";
        }
        else {
            h += p[i];
        }
    }
    if (h != "")p_str.push_back(h);

    if (p[0] == '*')first_star = true;
    if (p.back() == '*')last_star = true;

    int t;
    cin >> t;
    while (t--) {
        cin >> w;
        int now_start_p = 0, now_last_p = int(w.size()) - 1;
        deque<string>check = p_str;
        bool is_match = true;
        if (!first_star && !last_star) {
            if (check.size() == 1) {
                if (p.size() != w.size()) {
                    continue;
                }
                for (int i = 0; i < p.size(); i++) {
                    if (p[i] != w[i]) {
                        is_match = false;
                        break;
                    }
                }
                if (!is_match)continue;
                cout << w << "\n";
                continue;
            }
        }

        if (!first_star) {
            for (int i = 0; i < check.front().size(); i++) {
                int set_p = now_start_p + i;
                if (set_p >= w.size()) {
                    is_match = false;
                    break;
                }
                if (check.front()[i] != w[set_p]) {
                    is_match = false;
                    break;
                }
            }
            if (!is_match) {
                continue;
            }
            now_start_p += check.front().size();
            check.pop_front();
        }

        if (!last_star) {
            for (int i = 0; i < check.back().size(); i++) {
                int set_p = now_last_p - i;
                int check_p = int(check.back().size()) - 1 - i;
                if (set_p < 0) {
                    is_match = false;
                    break;
                }
                if (check.back()[check_p] != w[set_p]) {
                    is_match = false;
                    break;
                }
            }
            if (!is_match) {
                continue;
            }
            now_last_p -= check.back().size();
            check.pop_back();
        }

        while(check.size()) {
            string check_str=check.front();
            check.pop_front();
            int check_p = 0;
            for (; now_start_p <= now_last_p && check_p<check_str.size(); now_start_p++) {
                if (check_str[check_p] != w[now_start_p]) {
                    if (check_p > 0) {
                        check_p = 0;
                        now_start_p--;
                    }
                    else {
                        check_p = 0;
                    }
                    continue;
                }
                check_p++;
            }
            if (check_p == check_str.size())continue;
            is_match = false;
            break;
        }
        if (is_match && check.empty())cout << w << "\n";
    }
}
