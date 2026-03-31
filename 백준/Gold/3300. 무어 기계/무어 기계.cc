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
#include <complex>

#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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

//unordered_set, unordered_map 전용 (구조체로 쓸 경우 == operator도 필요)
//사용 예시 : unordered_set<intint,pair_hash> arr;
namespace std {
    struct default_hash {
        template <class T1>
        size_t operator()(const T1 n) const {
            hash<T1> a{}; size_t sa = a(n);
            return sa;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> n) const {
            hash<T1> a{}; size_t sa = a(n.fi);
            hash<T2> b{}; size_t sb = b(n.se);
            return sa ^ sb;
        }
    };
}

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
typedef pair<int, char> int_char;
typedef complex<double> cpx;

bool dfs(string a,string& b, int ap,int bp,stack<pair<string,int>>next_move) {
    //cout << a << "," << b << "에서 " << ap << "," << bp << "위치.\n";
    for (int i = ap; i < a.size(); i++) {
        if (a[i] == '(') {
            int si = i;
            int ei = -1;

            int open_count = 0;
            for (int j = si; j < a.size(); j++) {
                if (a[j] == '(') {
                    open_count++;
                }
                else if (a[j] == ')') {
                    open_count--;
                    if (open_count == 0) {
                        ei = j;
                        break;
                    }
                }
            }
            if (ei == -1)exit(-1);

            string s = "";
            open_count = 0;
            for (int j = si+1; j <= ei; j++) {
                if ((open_count==0 && a[j] == '|') || j == ei) {
                    if (s != "") {
                        stack<pair<string, int>>new_next_move = next_move;
                        new_next_move.push({ a,ei + 1 });
                        if (dfs(s, b, 0, bp, new_next_move)) {
                            return true;
                        }
                    }
                    s = "";
                }
                else {
                    if (a[j] == '(')open_count++;
                    else if (a[j] == ')')open_count--;
                    s += a[j];
                }
            }
            return false;
        }
        if (bp >= b.size())return false;
        if (a[i] != b[bp])return false;
        bp++;
    }

    if (!next_move.empty()) {
        a = next_move.top().fi;
        ap = next_move.top().se;
        next_move.pop();
        return dfs(a, b, ap, bp, next_move);
    }

    if (b.size() != bp)return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    string a, b;
    while (t--) {
        cin >> a >> b;
        bool is_visible = false;
        for (char& h : a) {
            if (h == '_')is_visible = true;
        }

        assert(is_visible);

        char ans = '!';
        for (char s = 'A'; s <= 'Z'; s++) {
            string new_a = a;
            for (char& h : new_a) {
                if (h == '_')h = s;
            }

            if (dfs(new_a, b, 0, 0, {})) {
                if (ans == '!')ans = s;
                else {
                    ans = '_';
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
}