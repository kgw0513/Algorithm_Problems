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
#define print_end "\n"
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

void back_lines(queue<int>&, const int);
vector<int>inputs;

int s = 0;
void front_lines(stack<int>&back_state,const int now_lines) {
    queue<int>arr;
    for (; s < inputs.size(); s++) {
        if (inputs[s] != now_lines) {
            if (inputs[s] < now_lines)break;
            back_lines(arr, now_lines + 2);
        }
        else {
            arr.push(s + 1);
        }
    }
    arr.push(s + 1);
    stack<int>brr;
    while (arr.size()) {
        brr.push(arr.front());
        arr.pop();
    }
    while (brr.size()) {
        back_state.push(brr.top());
        brr.pop();
    }
}

void back_lines(queue<int>&front_state, const int now_lines) {
    stack<int>arr;
    for (; s < inputs.size(); s++) {
        if (inputs[s] != now_lines) {
            if (inputs[s] < now_lines)break;
            front_lines(arr, now_lines + 2);
        }
        else {
            arr.push(s + 1);
        }
    }
    arr.push(s + 1);
    while (arr.size()) {
        front_state.push(arr.top());
        arr.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> w;
        inputs.push_back(w);
    }

    stack<int>ans;
    front_lines(ans,1);
    while (ans.size()) {
        cout << ans.top()<<" ";
        ans.pop();
    }
}