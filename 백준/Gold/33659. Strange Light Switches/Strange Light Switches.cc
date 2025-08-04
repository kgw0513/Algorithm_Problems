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

string w;
queue<int>ans;
void insert_ans(int s, int e, bool is_circle) {
    if (s > e)e += w.size();
    int n = e - s + 1;

    for (int i = s; i <= e; i++) {
        w[i % w.size()] = '0';
    }
    if (n == 1) {
        ans.push(s);
        return;
    }
    if (n % 2 == is_circle) {
        //cout << s << "~" << e << "들옴.\n";
        int use_last_num = -1;
        if (is_circle) {
            for (int i = 0; i < n / 2; i++) {
                int new_num = s + 2 * i;
                new_num %= int(w.size());
                ans.push(new_num);
                use_last_num = new_num;
            }
            for (int i = 0; i < (n / 2) - 1; i++) {
                int new_num = s + 1 + 2 * i;
                new_num %= int(w.size());
                ans.push(new_num);
            }
        }
        else {
            for (int i = 0; i < (n / 2) - 1; i++) {
                int new_num = s + 1 + 2 * i;
                new_num %= int(w.size());
                ans.push(new_num);
                use_last_num = new_num;
            }
            for (int i = 0; i < (n / 2) - 1; i++) {
                int new_num = s + 2 * i;
                new_num %= int(w.size());
                ans.push(new_num);
            }
        }
        ans.push((use_last_num) % w.size());
        ans.push((use_last_num + 1) % w.size());
        ans.push((use_last_num + 2) % w.size());
        ans.push((use_last_num) % w.size());
    }
    else {
        //cout << s << "~" << e << "들.\n";
        for (int i = 0; i < n / 2; i++) {
            int new_num = s + 1 + 2 * i;
            new_num %= int(w.size());
            ans.push(new_num);
        }
        for (int i = 0; i < n / 2 + (is_circle ? 0 : 1); i++) {
            int new_num = s + 2 * i;
            new_num %= int(w.size());
            ans.push(new_num);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> w;

    int set_p = -1;
    bool is_empty = true;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '1') {
            is_empty = false;
            break;
        }
    }
    if (is_empty) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '0') {
            set_p = i;
            break;
        }
    }

    if (set_p == -1) {
        if (w.size() <= 3) {
            cout << -1;
            return 0;
        }
        insert_ans(0, w.size() - 1, true);
    }
    else {
        int s = -1;
        string h = w;
        for (int p = set_p; p <= set_p + w.size()*3; p++) {
            int now_p = p % w.size();
            if (w[now_p] == '0') {
                if (s != -1) {
                    int next_p = now_p + w.size();
                    next_p--;
                    next_p %= w.size();
                    if (((next_p + int(w.size()) - s + 1) % int(w.size())) != 2)insert_ans(s, next_p, false);
                    else {
                        //cout << s << "~" << next_p << "잖아.\n";
                        //cout << (s - 2 + int(w.size())) % w.size() << ":" << w[(s - 2 + int(w.size())) % w.size()] << "\n";
                        //cout << (next_p + 2 + int(w.size())) % w.size() << ":" << w[(next_p + 2 + int(w.size())) % w.size()] << "\n";
                        if (w[(s - 2 + int(w.size())) % w.size()] == '0') {
                            ans.push((s - 1 + int(w.size())) % w.size());
                            ans.push(s % w.size());
                            ans.push((s + 1) % w.size());
                            ans.push((s - 1 + int(w.size())) % w.size());
                            w[s] = '0';
                            w[next_p] = '0';
                        }
                        else if (w[(next_p + 2 + int(w.size())) % w.size()] == '0') {
                            ans.push((next_p + 1 + int(w.size())) % w.size());
                            ans.push(next_p % w.size());
                            ans.push(s % w.size());
                            ans.push((next_p + 1 + int(w.size())) % w.size());
                            w[s] = '0';
                            w[next_p] = '0';
                        }
                    }
                }
                s = -1;
            }
            else {
                if (s == -1)s = now_p;
            }
        }
        if (h == w) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < w.size(); i++) {
        if (w[i] != '0') {
            cout << -1;
            return 0;
        }
    }
    cout << ans.size() << "\n";
    while (ans.size()) {
        cout << (ans.front()+int(w.size())) % w.size() << "\n";
        ans.pop();
    }
}