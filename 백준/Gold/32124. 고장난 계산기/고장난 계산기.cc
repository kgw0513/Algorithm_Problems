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

string input;

string setting(int s, int e) {
    int p = s;
    deque<string> now_state;
    bool multiple_visible = false;
    string now_number = "";
    for (; p <= e; p++) {
        if (input[p] == '*') {
            if (now_number != "") {
                if (multiple_visible) {
                    string h2 = now_state.back();
                    now_state.pop_back();
                    string h1 = now_state.back();
                    now_state.pop_back();
                    multiple_visible = false;
                    now_state.push_back("(" + h1 + h2 + now_number + ")");
                }
                else {
                    now_state.push_back(now_number);
                }
                now_number = "";
            }

            //어차피 나중에 괄호 뒤집어 쓸거라 (미리 안넣기
            string h = now_state.back();
            now_state.pop_back();
            now_state.push_back(h);
            now_state.push_back("*");
            multiple_visible = true;
            continue;
        }
        if (input[p] == '(') {
            //여긴 숫자다음 올 수 없음.
            int h = p + 1;
            int close_count = 1;
            for (; h <= e; h++) {
                if (input[h] != '(' && input[h] != ')')continue;
                if (input[h] == '(')close_count++;
                else close_count--;
                if (close_count <= 0)break;
            }
            assert(h <= e);
            if (multiple_visible) {
                string h2 = now_state.back();
                now_state.pop_back();
                string h1 = now_state.back();
                now_state.pop_back();
                multiple_visible = false;
                now_state.push_back("(" + h1 + h2 + "(" + setting(p + 1, h - 1) + "))");
            }
            else {
                now_state.push_back("(" + setting(p + 1, h - 1) + ")");
            }
            p = h;
            continue;
        }
        if (input[p] == '+') {
            if (now_number != "") {
                if (multiple_visible) {
                    string h2 = now_state.back();
                    now_state.pop_back();
                    string h1 = now_state.back();
                    now_state.pop_back();
                    multiple_visible = false;
                    now_state.push_back("(" + h1 + h2 + now_number + ")");
                }
                else {
                    now_state.push_back(now_number);
                }
                now_number = "";
            }

            now_state.push_back("+");
            continue;
        }

        //숫자구간
        now_number += input[p];
    }
    if (now_number != "") {
        if (multiple_visible) {
            string h2 = now_state.back();
            now_state.pop_back();
            string h1 = now_state.back();
            now_state.pop_back();
            multiple_visible = false;
            now_state.push_back("(" + h1 + h2 + now_number + ")");
            now_number = "";
        }
        else {
            now_state.push_back(now_number);
            now_number = "";
        }
    }

    string ans = "";
    while (now_state.size()) {
        ans += now_state.front();
        now_state.pop_front();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> input >> input >> input;

    string ans = setting(0, int(input.size()) - 1);
    cout << ans.size() << "\n" << ans;
}